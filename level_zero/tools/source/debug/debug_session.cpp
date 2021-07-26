/*
 * Copyright (C) 2021 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#include "level_zero/tools/source/debug/debug_session.h"

#include "shared/source/helpers/hw_info.h"

#include "level_zero/core/source/device/device_imp.h"

namespace L0 {

RootDebugSession::RootDebugSession(const zet_debug_config_t &config, Device *device) : DebugSession(config, device) {

    if (connectedDevice) {
        auto hwInfo = connectedDevice->getHwInfo();
        const uint32_t numSubslicesPerSlice = hwInfo.gtSystemInfo.MaxSubSlicesSupported / hwInfo.gtSystemInfo.MaxSlicesSupported;
        const uint32_t numEuPerSubslice = hwInfo.gtSystemInfo.MaxEuPerSubSlice;
        const uint32_t numThreadsPerEu = (hwInfo.gtSystemInfo.ThreadCount / hwInfo.gtSystemInfo.EUCount);
        uint32_t subDeviceCount = 1;

        for (uint32_t tileIndex = 0; tileIndex < subDeviceCount; tileIndex++) {
            for (uint32_t sliceID = 0; sliceID < hwInfo.gtSystemInfo.MaxSlicesSupported; sliceID++) {
                for (uint32_t subsliceID = 0; subsliceID < numSubslicesPerSlice; subsliceID++) {
                    for (uint32_t euID = 0; euID < numEuPerSubslice; euID++) {

                        for (uint32_t threadID = 0; threadID < numThreadsPerEu; threadID++) {

                            EuThread::ThreadId thread = {tileIndex, sliceID, subsliceID, euID, threadID};

                            allThreads[uint64_t(thread)] = std::make_unique<EuThread>(thread);
                        }
                    }
                }
            }
        }
    }
}

std::vector<ze_device_thread_t> RootDebugSession::getSingleThreads(ze_device_thread_t physicalThread, const NEO::HardwareInfo &hwInfo) {
    const uint32_t numSubslicesPerSlice = hwInfo.gtSystemInfo.MaxSubSlicesSupported / hwInfo.gtSystemInfo.MaxSlicesSupported;
    const uint32_t numEuPerSubslice = hwInfo.gtSystemInfo.MaxEuPerSubSlice;
    const uint32_t numThreadsPerEu = (hwInfo.gtSystemInfo.ThreadCount / hwInfo.gtSystemInfo.EUCount);

    UNRECOVERABLE_IF(numThreadsPerEu > 8);

    std::vector<ze_device_thread_t> threads;

    const uint32_t slice = physicalThread.slice;
    const uint32_t subslice = physicalThread.subslice;
    const uint32_t eu = physicalThread.eu;
    const uint32_t thread = physicalThread.thread;

    for (uint32_t sliceID = 0; sliceID < hwInfo.gtSystemInfo.MaxSlicesSupported; sliceID++) {
        if (slice != UINT32_MAX) {
            sliceID = slice;
        }

        for (uint32_t subsliceID = 0; subsliceID < numSubslicesPerSlice; subsliceID++) {
            if (subslice != UINT32_MAX) {
                subsliceID = subslice;
            }

            for (uint32_t euID = 0; euID < numEuPerSubslice; euID++) {
                if (eu != UINT32_MAX) {
                    euID = eu;
                }

                for (uint32_t threadID = 0; threadID < numThreadsPerEu; threadID++) {
                    if (thread != UINT32_MAX) {
                        threadID = thread;
                    }
                    threads.push_back({sliceID, subsliceID, euID, threadID});

                    if (thread != UINT32_MAX) {
                        break;
                    }
                }

                if (eu != UINT32_MAX) {
                    break;
                }
            }
            if (subslice != UINT32_MAX) {
                break;
            }
        }
        if (slice != UINT32_MAX) {
            break;
        }
    }

    return threads;
}

bool RootDebugSession::isBindlessSystemRoutine() {
    if (debugArea.reserved1 &= 1) {
        return true;
    }
    return false;
}

} // namespace L0

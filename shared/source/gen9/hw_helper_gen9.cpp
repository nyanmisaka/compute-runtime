/*
 * Copyright (C) 2018-2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#include "shared/source/gen9/aub_mapper.h"
#include "shared/source/gen9/hw_cmds_base.h"
#include "shared/source/helpers/flat_batch_buffer_helper_hw.inl"
#include "shared/source/helpers/hw_helper_base.inl"
#include "shared/source/helpers/hw_helper_bdw_and_later.inl"
#include "shared/source/helpers/hw_helper_bdw_to_icllp.inl"
#include "shared/source/helpers/logical_state_helper.inl"

#include <cstring>

namespace NEO {
typedef Gen9Family Family;

template <>
SipKernelType HwHelperHw<Family>::getSipKernelType(bool debuggingActive) const {
    if (!debuggingActive) {
        return SipKernelType::Csr;
    }
    return DebugManager.flags.UseBindlessDebugSip.get() ? SipKernelType::DbgBindless : SipKernelType::DbgCsrLocal;
}

template <>
uint32_t HwHelperHw<Family>::getMetricsLibraryGenId() const {
    return static_cast<uint32_t>(MetricsLibraryApi::ClientGen::Gen9);
}

template <>
int32_t HwHelperHw<Family>::getDefaultThreadArbitrationPolicy() const {
    return ThreadArbitrationPolicy::RoundRobin;
}

template <>
bool MemorySynchronizationCommands<Family>::isBarrierWaRequired(const HardwareInfo &hwInfo) { return true; }

template <>
bool HwHelperHw<Family>::isTimestampShiftRequired() const {
    return false;
}

template class HwHelperHw<Family>;
template class FlatBatchBufferHelperHw<Family>;
template struct MemorySynchronizationCommands<Family>;
template struct LriHelper<Family>;

template LogicalStateHelper *LogicalStateHelper::create<Family>();
} // namespace NEO

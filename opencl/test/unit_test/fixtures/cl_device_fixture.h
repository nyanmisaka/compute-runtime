/*
 * Copyright (C) 2020-2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#pragma once
#include "shared/test/common/mocks/mock_device.h"

#include "opencl/test/unit_test/mocks/mock_cl_device.h"

namespace NEO {
struct HardwareInfo;

struct ClDeviceFixture {
    void setUp();
    void setUpImpl(const NEO::HardwareInfo *hardwareInfo);
    void tearDown();

    MockDevice *createWithUsDeviceId(unsigned short usDeviceId);

    template <typename HelperType>
    HelperType &getHelper() const;

    MockDevice *pDevice = nullptr;
    MockClDevice *pClDevice = nullptr;
    volatile TagAddressType *pTagMemory = nullptr;
    HardwareInfo hardwareInfo = {};
    PLATFORM platformHelper = {};
    OsContext *osContext = nullptr;
    const uint32_t rootDeviceIndex = 0u;
    MockClExecutionEnvironment *pClExecutionEnvironment = nullptr;

    const RootDeviceEnvironment &getRootDeviceEnvironment() const;
};

} // namespace NEO

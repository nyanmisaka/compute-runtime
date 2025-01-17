/*
 * Copyright (C) 2018-2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#include "shared/source/gen9/hw_cmds.h"
#include "shared/test/common/cmd_parse/gen_cmd_parse.h"
#include "shared/test/common/helpers/hw_helper_tests.h"
#include "shared/test/common/test_macros/header/per_product_test_definitions.h"
#include "shared/test/unit_test/helpers/get_gpgpu_engines_tests.inl"

using HwHelperTestGen9 = HwHelperTest;

GEN9TEST_F(HwHelperTestGen9, WhenGettingMaxBarriersPerSliceThenCorrectSizeIsReturned) {
    auto &helper = getHelper<CoreHelper>();
    EXPECT_EQ(32u, helper.getMaxBarrierRegisterPerSlice());
}

GEN9TEST_F(HwHelperTestGen9, givenGen9WhenCallIsPackedSupportedThenReturnFalse) {
    auto &helper = HwHelper::get(renderCoreFamily);
    EXPECT_FALSE(helper.packedFormatsSupported());
}

GEN9TEST_F(HwHelperTestGen9, WhenGettingPitchAlignmentForImageThenCorrectValueIsReturned) {
    auto &coreHelper = getHelper<CoreHelper>();
    EXPECT_EQ(4u, coreHelper.getPitchAlignmentForImage(pDevice->getRootDeviceEnvironment()));
}

GEN9TEST_F(HwHelperTestGen9, WhenAdjustingDefaultEngineTypeThenEngineTypeIsSet) {
    auto engineType = hardwareInfo.capabilityTable.defaultEngineType;
    auto &coreHelper = getHelper<CoreHelper>();
    coreHelper.adjustDefaultEngineType(&hardwareInfo);
    EXPECT_EQ(engineType, hardwareInfo.capabilityTable.defaultEngineType);
}

GEN9TEST_F(HwHelperTestGen9, givenDebuggingActiveWhenSipKernelTypeIsQueriedThenDbgCsrLocalTypeIsReturned) {
    auto &coreHelper = getHelper<CoreHelper>();

    auto sipType = coreHelper.getSipKernelType(true);
    EXPECT_EQ(SipKernelType::DbgCsrLocal, sipType);
}

GEN9TEST_F(HwHelperTestGen9, whenGetGpgpuEnginesThenReturnThreeRcsEngines) {
    whenGetGpgpuEnginesThenReturnTwoRcsEngines<FamilyType>(pDevice->getHardwareInfo());
    EXPECT_EQ(3u, pDevice->allEngines.size());
}

GEN9TEST_F(HwHelperTestGen9, givenGen9WhenCallIsTimestampShiftRequiredThenFalseIsReturned) {
    auto &hwHelper = HwHelper::get(defaultHwInfo->platform.eRenderCoreFamily);
    EXPECT_FALSE(hwHelper.isTimestampShiftRequired());
}

using MemorySynchronizatiopCommandsTestsGen9 = ::testing::Test;
GEN9TEST_F(MemorySynchronizatiopCommandsTestsGen9, WhenProgrammingCacheFlushThenExpectConstantCacheFieldSet) {
    using PIPE_CONTROL = typename FamilyType::PIPE_CONTROL;
    std::unique_ptr<uint8_t> buffer(new uint8_t[128]);

    LinearStream stream(buffer.get(), 128);
    MemorySynchronizationCommands<FamilyType>::addFullCacheFlush(stream, *defaultHwInfo);
    PIPE_CONTROL *pipeControl = genCmdCast<PIPE_CONTROL *>(buffer.get());
    ASSERT_NE(nullptr, pipeControl);
    EXPECT_TRUE(pipeControl->getConstantCacheInvalidationEnable());
}

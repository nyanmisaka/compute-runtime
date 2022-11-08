/*
 * Copyright (C) 2021-2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#include "shared/test/common/test_macros/hw_test_base.h"

HWTEST_EXCLUDE_PRODUCT(CommandEncodeStatesTest, givenSlmTotalSizeEqualZeroWhenDispatchingKernelThenSharedMemorySizeIsSetCorrectly, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(CommandEncodeStatesTest, givenOverrideSlmTotalSizeDebugVariableWhenDispatchingKernelThenSharedMemorySizeIsSetCorrectly, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(CommandEncodeStatesTest, givenInterfaceDescriptorDataWhenForceThreadGroupDispatchSizeVariableIsDefaultThenThreadGroupDispatchSizeIsNotChanged, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(DrmMemoryManagerTest, givenDrmAllocationWithHostPtrWhenItIsCreatedWithIncorrectCacheRegionThenReturnNull, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(DrmMemoryManagerTest, givenDrmAllocationWithWithAlignmentFromUserptrWhenItIsCreatedWithIncorrectCacheRegionThenReturnNull, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(WalkerPartitionTests, givenMiAtomicWhenItIsProgrammedThenAllFieldsAreSetCorrectly, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(WalkerPartitionTests, givenProgramBatchBufferStartCommandWhenItIsCalledThenCommandIsProgrammedCorrectly, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(HwHelperTest, givenDefaultHwHelperHwWhenMinimalSIMDSizeIsQueriedThen8IsReturned, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(HwHelperTest, whenQueryingMaxNumSamplersThenReturnSixteen, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(HwHelperTest, givenHwHelperWhenGettingIfRevisionSpecificBinaryBuiltinIsRequiredThenFalseIsReturned, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(HwHelperTest, whenGettingNumberOfCacheRegionsThenReturnZero, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(PipeControlHelperTests, givenHwHelperwhenAskingForDcFlushThenReturnTrue, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(XeHPAndLaterPreemptionTests, GivenDebuggerUsedWhenProgrammingStateSipThenStateSipIsAdded, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(ComputeModeRequirements, givenComputeModeProgrammingWhenLargeGrfModeDoesntChangeThenSCMIsNotAdded, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(ComputeModeRequirements, givenCoherencyWithoutSharedHandlesWhenCommandSizeIsCalculatedThenCorrectCommandSizeIsReturned, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(ComputeModeRequirements, givenCoherencyWithSharedHandlesWhenCommandSizeIsCalculatedThenCorrectCommandSizeIsReturned, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(ComputeModeRequirements, givenCoherencyWithoutSharedHandlesWhenComputeModeIsProgrammedThenCorrectCommandsAreAdded_ForceNonCoherentSupportedMatcher, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(ComputeModeRequirements, givenCoherencyWithSharedHandlesWhenComputeModeIsProgrammedThenCorrectCommandsAreAdded_ForceNonCoherentSupportedMatcher, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(ComputeModeRequirements, givenComputeModeCmdSizeWhenLargeGrfModeChangeIsRequiredThenSCMCommandSizeIsCalculated, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(ComputeModeRequirements, givenComputeModeProgrammingWhenLargeGrfModeChangeIsRequiredThenCorrectCommandsAreAdded_ForceNonCoherentSupportedMatcher, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(ComputeModeRequirements, givenComputeModeProgrammingWhenRequiredGRFNumberIsLowerThan128ThenSmallGRFModeIsProgrammed_ForceNonCoherentSupportedMatcher, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(ComputeModeRequirements, givenComputeModeProgrammingWhenRequiredGRFNumberIsGreaterThan128ThenLargeGRFModeIsProgrammed_ForceNonCoherentSupportedMatcher, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(BlitTests, givenXyCopyBltCommandWhenAppendBlitCommandsMemCopyIsCalledThenNothingChanged, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(HwInfoConfigTest, givenHwInfoConfigWhenIsAdjustProgrammableIdPreferredSlmSizeRequiredThenFalseIsReturned, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(HwInfoConfigTest, givenHwInfoConfigWhenIsComputeDispatchAllWalkerEnableInCfeStateRequiredThenFalseIsReturned, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(HwInfoConfigTest, givenHwInfoConfigWhenIsComputeDispatchAllWalkerEnableInComputeWalkerRequiredThenFalseIsReturned, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(HwInfoConfigTest, givenHwInfoConfigWhenIsGlobalFenceInCommandStreamRequiredThenFalseIsReturned, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(HwInfoConfigTest, givenHwInfoConfigWhenIsSystolicModeConfigurabledThenFalseIsReturned, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(HwInfoConfigTest, givenHwInfoConfigWhenGetThreadEuRatioForScratchThen8IsReturned, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(HwInfoConfigTest, givenVariousValuesWhenConvertingHwRevIdAndSteppingThenConversionIsCorrect, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(HwInfoConfigTest, whenCallingGetDeviceMemoryNameThenDdrIsReturned, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(HwInfoConfigTest, givenHardwareInfoWhenCallingIsMaxThreadsForWorkgroupWARequiredThenFalseIsReturned, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(HwInfoConfigTest, givenHwInfoConfigWhenAskedIfPipeControlPriorToNonPipelinedStateCommandsWARequiredThenFalseIsReturned, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(HwInfoConfigTest, givenHwInfoConfigWhenAskedIfTile64With3DSurfaceOnBCSIsSupportedThenTrueIsReturned, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(HwInfoConfigTest, givenHwInfoConfigWhenIsPrefetcherDisablingInDirectSubmissionRequiredThenTrueIsReturned, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(DirectSubmissionTest, givenDebugFlagSetWhenDispatchingPrefetcherThenSetCorrectValue, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(GetAllocationDataTestHw, givenRingBufferAllocationWhenGetAllocationDataIsCalledThenItHasProperFieldsSet, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(GetAllocationDataTestHw, givenSemaphoreBufferAllocationWhenGetAllocationDataIsCalledThenItHasProperFieldsSet, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(MemoryManagerGetAlloctionDataTests, givenCommandBufferAllocationTypeWhenGetAllocationDataIsCalledThenSystemMemoryIsRequested, IGFX_XE_HPC_CORE);
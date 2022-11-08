/*
 * Copyright (C) 2021-2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#include "shared/test/common/test_macros/hw_test_base.h"

HWTEST_EXCLUDE_PRODUCT(BufferSetSurfaceTests, givenAlignedCacheableReadOnlyBufferThenChoseOclBufferPolicy, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(BufferSetSurfaceTests, givenBufferSetSurfaceThatMemoryIsUnalignedToCachelineButReadOnlyThenL3CacheShouldBeStillOn, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(HwHelperTestXeHPAndLater, givenVariousCachesRequestProperMOCSIndexesAreBeingReturned, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(PipeControlHelperTestsXeHPAndLater, WhenAddingPipeControlWAThenCorrectCommandsAreProgrammed, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(QueueFamilyNameTest, givenRcsWhenGettingQueueFamilyNameThenReturnProperValue, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(EnqueueCopyBufferToImageStatelessTest, givenBigBufferWhenCopyingBufferToImageStatelessThenSuccessIsReturned, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(EnqueueCopyImageToBufferHwStatelessTest, givenBigBufferWhenCopyingImageToBufferStatelessThenSuccessIsReturned, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(BuiltInTests, givenBigOffsetAndSizeWhenBuilderCopyImageToSystemBufferStatelessIsUsedThenParamsAreCorrect, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(BuiltInTests, givenBigOffsetAndSizeWhenBuilderCopyImageToLocalBufferStatelessIsUsedThenParamsAreCorrect, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(ClDeviceHelperTests, givenDeviceWithoutClosBasedCacheReservationSupportWhenQueryingNumCacheClosDeviceInfoThenReturnZeroCacheClosRegions, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(HwHelperTest, whenGettingNumberOfCacheRegionsThenReturnZero, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(LocalWorkSizeTest, givenDispatchInfoWhenWorkSizeInfoIsCreatedThenTestEuFusionFtr, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(CommandStreamReceiverFlushTaskDg2AndLaterTests, givenProgramExtendedPipeControlPriorToNonPipelinedStateCommandEnabledWhenPerDssBackedBufferThenThereIsPipeControlPriorToIt_MatcherIsRTCapable, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(CommandStreamReceiverHwTestDg2AndLater, givenGen12AndLaterWhenRayTracingEnabledThenCommandIsAddedToBatchBuffer_MatcherIsRTCapable, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(CommandStreamReceiverHwTestDg2AndLater, givenGen12AndLaterWhenRayTracingEnabledButAlreadySentThenCommandIsNotAddedToBatchBuffer_MatcherIsRTCapable, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(HardwareCommandsTest, GivenVariousValuesWhenAlignSlmSizeIsCalledThenCorrectValueIsReturned, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(HardwareCommandsTest, GivenVariousValuesWhenComputeSlmSizeIsCalledThenCorrectValueIsReturned, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(XeHPAndLaterDeviceCapsTests, givenHwInfoWhenSlmSizeIsRequiredThenReturnCorrectValue, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(DeviceGetCapsTest, givenDeviceWhenAskingForSubGroupSizesThenReturnCorrectValues, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(HwHelperTestXeHPAndLater, givenAllFlagsSetWhenGetGpgpuEnginesThenReturnThreeRcsEnginesFourCcsEnginesAndOneBcsEngine, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(HwHelperTestXeHPAndLater, givenCcsDisabledWhenGetGpgpuEnginesThenReturnRcsAndOneBcsEngine, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(HwHelperTestXeHPAndLater, givenBcsDisabledWhenGetGpgpuEnginesThenReturnThreeRcsEnginesFourCcsEngines, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(HwHelperTestXeHPAndLater, givenCcsDisabledAndNumberOfCcsEnabledWhenGetGpgpuEnginesThenReturnRcsAndOneBcsEngine, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(PipeControlHelperTestsXeHPAndLater, WhenGettingSizeForAdditionalSynchronizationThenCorrectValueIsReturned, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(MultiDeviceStorageInfoTest, givenSingleTileCsrWhenAllocatingCsrSpecificAllocationsThenStoreThemInSystemMemory, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(ClHwHelperTest, givenKernelInfoWhenCheckingRequiresAuxResolvesThenCorrectValuesAreReturned, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(BuiltInSharedTest, GivenBuiltinTypeBinaryWhenGettingBuiltinResourceForNotRegisteredRevisionThenBuiltinFromDefaultRevisionIsTaken, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(EnqueueReadBufferRectStatefulTest, WhenReadingBufferRectStatefulThenSuccessIsReturned, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(EnqueueCopyBufferRectStateful, GivenValidParametersWhenCopyingBufferRectStatefulThenSuccessIsReturned, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(EnqueueSvmMemCopyHwTest, givenEnqueueSVMMemCopyWhenUsingCopyBufferToBufferStatefulBuilderThenSuccessIsReturned, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(EnqueueSvmMemFillHwTest, givenEnqueueSVMMemFillWhenUsingCopyBufferToLocalBufferStatefulBuilderThenSuccessIsReturned, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(EnqueueFillBufferStatefulTest, givenBuffersWhenFillingBufferStatefulThenSuccessIsReturned, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(EnqueueCopyBufferStatefulTest, givenBuffersWhenCopyingBufferStatefulThenSuccessIsReturned, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(EnqueueWriteBufferStatefulTest, WhenWritingBufferStatefulThenSuccessIsReturned, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(EnqueueReadBufferStatefulTest, WhenReadingBufferStatefulThenSuccessIsReturned, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(EnqueueWriteBufferRectStatefulTest, WhenWritingBufferRectStatefulThenSuccessIsReturned, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(CommandStreamReceiverFlushTaskTests, givenOverrideThreadArbitrationPolicyDebugVariableSetWhenFlushingThenRequestRequiredMode, IGFX_XE_HPC_CORE);
HWTEST_EXCLUDE_PRODUCT(XeHPAndLaterAubCommandStreamReceiverWithoutFixtureTests, GivenCopyHostPtrAndHostNoAccessAndReadOnlyFlagsWhenAllocatingBufferThenAllocationIsCopiedToEveryTile, IGFX_XE_HPC_CORE);

/*
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#include "shared/source/device_binary_format/ar/ar.h"
#include "shared/source/device_binary_format/ar/ar_decoder.h"
#include "shared/source/device_binary_format/ar/ar_encoder.h"
#include "shared/source/device_binary_format/device_binary_formats.h"
#include "shared/source/device_binary_format/elf/elf_encoder.h"
#include "shared/source/device_binary_format/elf/ocl_elf.h"
#include "shared/source/helpers/hw_info.h"
#include "shared/source/helpers/product_config_helper.h"
#include "shared/source/os_interface/hw_info_config.h"
#include "shared/test/common/helpers/default_hw_info.h"
#include "shared/test/common/test_macros/test.h"
#include "shared/test/unit_test/device_binary_format/patchtokens_tests.h"

using PvcUnpackSingleDeviceBinaryAr = ::testing::Test;

PVCTEST_F(PvcUnpackSingleDeviceBinaryAr, WhenFailedToUnpackMatchWithPvcProductConfigThenTryUnpackAnotherBestMatch) {
    PatchTokensTestData::ValidEmptyProgram programTokens;
    PatchTokensTestData::ValidEmptyProgram programTokensWrongTokenVersion;

    std::string requiredProductConfig = NEO::ProductConfigHelper::parseMajorMinorRevisionValue(PVC_XL_A0);
    std::string anotherProductConfig = NEO::ProductConfigHelper::parseMajorMinorRevisionValue(PVC_XL_A0P);

    programTokensWrongTokenVersion.headerMutable->Version -= 1;
    NEO::Ar::ArEncoder encoder;
    std::string requiredProduct = NEO::hardwarePrefix[productFamily];
    std::string requiredStepping = std::to_string(programTokens.header->SteppingId);
    std::string requiredPointerSize = (programTokens.header->GPUPointerSizeInBytes == 4) ? "32" : "64";

    ASSERT_TRUE(encoder.appendFileEntry(requiredPointerSize, programTokens.storage));
    ASSERT_TRUE(encoder.appendFileEntry(requiredPointerSize + "." + requiredProduct, programTokens.storage));
    ASSERT_TRUE(encoder.appendFileEntry(requiredPointerSize + "." + anotherProductConfig, programTokens.storage));
    ASSERT_TRUE(encoder.appendFileEntry(requiredPointerSize + "." + requiredProductConfig, programTokensWrongTokenVersion.storage));
    ASSERT_TRUE(encoder.appendFileEntry(requiredPointerSize + "unk." + requiredStepping, programTokens.storage));

    NEO::TargetDevice target;
    target.coreFamily = static_cast<GFXCORE_FAMILY>(programTokens.header->Device);
    target.productConfig = PVC_XL_A0;
    target.stepping = programTokens.header->SteppingId;
    target.maxPointerSizeInBytes = programTokens.header->GPUPointerSizeInBytes;

    auto arData = encoder.encode();
    std::string unpackErrors;
    std::string unpackWarnings;
    auto unpacked = NEO::unpackSingleDeviceBinary<NEO::DeviceBinaryFormat::Archive>(arData, requiredProduct, target, unpackErrors, unpackWarnings);
    EXPECT_TRUE(unpackErrors.empty()) << unpackErrors;
    EXPECT_FALSE(unpackWarnings.empty());
    EXPECT_STREQ("Couldn't find perfectly matched binary in AR, using best usable", unpackWarnings.c_str());

    unpackErrors.clear();
    unpackWarnings.clear();
    auto decodedAr = NEO::Ar::decodeAr(arData, unpackErrors, unpackWarnings);
    EXPECT_NE(nullptr, decodedAr.magic);
    ASSERT_EQ(5U, decodedAr.files.size());
    EXPECT_EQ(unpacked.deviceBinary.begin(), decodedAr.files[2].fileData.begin());
    EXPECT_EQ(unpacked.deviceBinary.size(), decodedAr.files[2].fileData.size());
    EXPECT_EQ(NEO::DeviceBinaryFormat::Patchtokens, unpacked.format);
}
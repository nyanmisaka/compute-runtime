/*
 * Copyright (C) 2019-2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#pragma once
#include <stdint.h>

inline constexpr uint32_t L3SQC_BIT_LQSC_RO_PERF_DIS = 0x08000000;
inline constexpr uint32_t L3SQC_REG4 = 0xB118;

inline constexpr uint32_t GPGPU_WALKER_COOKIE_VALUE_BEFORE_WALKER = 0xFFFFFFFF;
inline constexpr uint32_t GPGPU_WALKER_COOKIE_VALUE_AFTER_WALKER = 0x00000000;

//Threads Dimension X/Y/Z
inline constexpr uint32_t GPUGPU_DISPATCHDIMX = 0x2500;
inline constexpr uint32_t GPUGPU_DISPATCHDIMY = 0x2504;
inline constexpr uint32_t GPUGPU_DISPATCHDIMZ = 0x2508;

inline constexpr uint32_t GPUGPU_DISPATCHDIM[3] = {GPUGPU_DISPATCHDIMX, GPUGPU_DISPATCHDIMY, GPUGPU_DISPATCHDIMZ};

inline constexpr uint32_t CS_GPR_R0 = 0x2600;
inline constexpr uint32_t CS_GPR_R1 = 0x2608;
inline constexpr uint32_t CS_GPR_R2 = 0x2610;
inline constexpr uint32_t CS_GPR_R3 = 0x2618;
inline constexpr uint32_t CS_GPR_R4 = 0x2620;
inline constexpr uint32_t CS_GPR_R5 = 0x2628;
inline constexpr uint32_t CS_GPR_R6 = 0x2630;
inline constexpr uint32_t CS_GPR_R7 = 0x2638;
inline constexpr uint32_t CS_GPR_R8 = 0x2640;
inline constexpr uint32_t CS_GPR_R9 = 0x2648;
inline constexpr uint32_t CS_GPR_R10 = 0x2650;
inline constexpr uint32_t CS_GPR_R11 = 0x2658;
inline constexpr uint32_t CS_GPR_R12 = 0x2660;
inline constexpr uint32_t CS_GPR_R13 = 0x2668;
inline constexpr uint32_t CS_GPR_R14 = 0x2670;
inline constexpr uint32_t CS_GPR_R15 = 0x2678;

inline constexpr uint32_t CS_PREDICATE_RESULT = 0x2418;
inline constexpr uint32_t CS_PREDICATE_RESULT_2 = 0x23BC;

inline constexpr uint32_t SEMA_WAIT_POLL = 0x0224c;
//Alu opcodes
inline constexpr uint32_t NUM_ALU_INST_FOR_READ_MODIFY_WRITE = 4;

enum class AluRegisters : uint32_t {
    OPCODE_NONE = 0x000,
    OPCODE_FENCE_RD = 0x001,
    OPCODE_FENCE_WR = 0x002,

    OPCODE_LOAD = 0x080,
    OPCODE_LOAD0 = 0x081,
    OPCODE_LOADIND = 0x082,
    OPCODE_STORE = 0x180,
    OPCODE_ADD = 0x100,
    OPCODE_SUB = 0x101,
    OPCODE_AND = 0x102,
    OPCODE_OR = 0x103,

    OPCODE_SHL = 0x105,
    OPCODE_STOREIND = 0x181,

    R_0 = 0x0,
    R_1 = 0x1,
    R_2 = 0x2,
    R_3 = 0x3,
    R_4 = 0x4,
    R_5 = 0x5,
    R_6 = 0x6,
    R_7 = 0x7,
    R_8 = 0x8,
    R_9 = 0x9,
    R_10 = 0xA,
    R_11 = 0xB,
    R_12 = 0xC,
    R_13 = 0xD,
    R_14 = 0xE,
    R_15 = 0xF,

    R_SRCA = 0x20,
    R_SRCB = 0x21,
    R_ACCU = 0x31,
    R_ZF = 0x32,
    R_CF = 0x33
};

inline constexpr uint32_t GP_THREAD_TIME_REG_ADDRESS_OFFSET_LOW = 0x23A8;

inline constexpr uint32_t REG_GLOBAL_TIMESTAMP_LDW = 0x2358;
inline constexpr uint32_t REG_GLOBAL_TIMESTAMP_UN = 0x235c;

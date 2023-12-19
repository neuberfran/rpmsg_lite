/*
 * Copyright 2017-2018, 2020-2021 NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FSL_MT9M114_H_
#define _FSL_MT9M114_H_

#include "fsl_common.h"
#include "fsl_camera_device.h"
#include "fsl_video_i2c.h"

/*
 * Change log:
 *
 *   1.0.2
 *     - Add RAW8 support.
 *
 *   1.0.1
 *     - Fixed MISRA-C 2012 issues.
 *
 *   1.0.0
 *     - Initial version
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define MT9M114_I2C_ADDR 0x48U
#define MT9M114_CHIP_ID  0x2481U

/*! @brief MT9M114 register definitions.*/

/* 1.Core registers */
#define MT9M114_REG_Y_ADDR_START            0x3002U
#define MT9M114_REG_X_ADDR_START            0x3004U
#define MT9M114_REG_Y_ADDR_END              0x3006U
#define MT9M114_REG_X_ADDR_END              0x3008U
#define MT9M114_REG_FRAME_LENGTH_LINES      0x300AU
#define MT9M114_REG_LINE_LENGTH_PCK_        0x300CU
#define MT9M114_REG_COARSE_INTEGRATION_TIME 0x3012U
#define MT9M114_REG_FINE_INTEGRATION_TIME   0x3014U
#define MT9M114_REG_RESET_REGISTER          0x301AU
#define MT9M114_REG_FLASH                   0x3046U
#define MT9M114_REG_FLASH_COUNT             0x3048U
#define MT9M114_REG_GREEN1_GAIN             0x3056U
#define MT9M114_REG_BLUE_GAIN               0x3058U
#define MT9M114_REG_RED_GAIN                0x305AU
#define MT9M114_REG_GREEN2_GAIN             0x305CU
#define MT9M114_REG_GLOBAL_GAIN             0x305EU
#define MT9M114_REG_FUSE_ID1                0x31F4U
#define MT9M114_REG_FUSE_ID2                0x31F6U
#define MT9M114_REG_FUSE_ID3                0x31F8U
#define MT9M114_REG_FUSE_ID4                0x31FAU
#define MT9M114_REG_CHAIN_CONTROL           0x31FCU
#define MT9M114_REG_CUSTOMER_REV            0x31FEU

/* 2.SOC1 registers */
#define MT9M114_REG_COLOR_PIPELINE_CONTROL 0x3210U

/* 3.SOC2 registers */
#define MT9M114_REG_P_G1_P0Q0     0x3640U
#define MT9M114_REG_P_G1_P0Q1     0x3642U
#define MT9M114_REG_P_G1_P0Q2     0x3644U
#define MT9M114_REG_P_G1_P0Q3     0x3646U
#define MT9M114_REG_P_G1_P0Q4     0x3648U
#define MT9M114_REG_P_R_P0Q0      0x364AU
#define MT9M114_REG_P_R_P0Q1      0x364CU
#define MT9M114_REG_P_R_P0Q2      0x364EU
#define MT9M114_REG_P_R_P0Q3      0x3650U
#define MT9M114_REG_P_R_P0Q4      0x3652U
#define MT9M114_REG_P_B_P0Q0      0x3654U
#define MT9M114_REG_P_B_P0Q1      0x3656U
#define MT9M114_REG_P_B_P0Q2      0x3658U
#define MT9M114_REG_P_B_P0Q3      0x365AU
#define MT9M114_REG_P_B_P0Q4      0x365CU
#define MT9M114_REG_P_G2_P0Q0     0x365EU
#define MT9M114_REG_P_G2_P0Q1     0x3660U
#define MT9M114_REG_P_G2_P0Q2     0x3662U
#define MT9M114_REG_P_G2_P0Q3     0x3664U
#define MT9M114_REG_P_G2_P0Q4     0x3666U
#define MT9M114_REG_P_G1_P1Q0     0x3680U
#define MT9M114_REG_P_G1_P1Q1     0x3682U
#define MT9M114_REG_P_G1_P1Q2     0x3684U
#define MT9M114_REG_P_G1_P1Q3     0x3686U
#define MT9M114_REG_P_G1_P1Q4     0x3688U
#define MT9M114_REG_P_R_P1Q0      0x368AU
#define MT9M114_REG_P_R_P1Q1      0x368CU
#define MT9M114_REG_P_R_P1Q2      0x368EU
#define MT9M114_REG_P_R_P1Q3      0x3690U
#define MT9M114_REG_P_R_P1Q4      0x3692U
#define MT9M114_REG_P_B_P1Q0      0x3694U
#define MT9M114_REG_P_B_P1Q1      0x3696U
#define MT9M114_REG_P_B_P1Q2      0x3698U
#define MT9M114_REG_P_B_P1Q3      0x369AU
#define MT9M114_REG_P_B_P1Q4      0x369CU
#define MT9M114_REG_P_G2_P1Q0     0x369EU
#define MT9M114_REG_P_G2_P1Q1     0x36A0U
#define MT9M114_REG_P_G2_P1Q2     0x36A2U
#define MT9M114_REG_P_G2_P1Q3     0x36A4U
#define MT9M114_REG_P_G2_P1Q4     0x36A6U
#define MT9M114_REG_P_G1_P2Q0     0x36C0U
#define MT9M114_REG_P_G1_P2Q1     0x36C2U
#define MT9M114_REG_P_G1_P2Q2     0x36C4U
#define MT9M114_REG_P_G1_P2Q3     0x36C6U
#define MT9M114_REG_P_G1_P2Q4     0x36C8U
#define MT9M114_REG_P_R_P2Q0      0x36CAU
#define MT9M114_REG_P_R_P2Q1      0x36CCU
#define MT9M114_REG_P_R_P2Q2      0x36CEU
#define MT9M114_REG_P_R_P2Q3      0x36D0U
#define MT9M114_REG_P_R_P2Q4      0x36D2U
#define MT9M114_REG_P_B_P2Q0      0x36D4U
#define MT9M114_REG_P_B_P2Q1      0x36D6U
#define MT9M114_REG_P_B_P2Q2      0x36D8U
#define MT9M114_REG_P_B_P2Q3      0x36DAU
#define MT9M114_REG_P_B_P2Q4      0x36DCU
#define MT9M114_REG_P_G2_P2Q0     0x36DEU
#define MT9M114_REG_P_G2_P2Q1     0x36E0U
#define MT9M114_REG_P_G2_P2Q2     0x36E2U
#define MT9M114_REG_P_G2_P2Q3     0x36E4U
#define MT9M114_REG_P_G2_P2Q4     0x36E6U
#define MT9M114_REG_P_G1_P3Q0     0x3700U
#define MT9M114_REG_P_G1_P3Q1     0x3702U
#define MT9M114_REG_P_G1_P3Q2     0x3704U
#define MT9M114_REG_P_G1_P3Q3     0x3706U
#define MT9M114_REG_P_G1_P3Q4     0x3708U
#define MT9M114_REG_P_R_P3Q0      0x370AU
#define MT9M114_REG_P_R_P3Q1      0x370CU
#define MT9M114_REG_P_R_P3Q2      0x370EU
#define MT9M114_REG_P_R_P3Q3      0x3710U
#define MT9M114_REG_P_R_P3Q4      0x3712U
#define MT9M114_REG_P_B_P3Q0      0x3714U
#define MT9M114_REG_P_B_P3Q1      0x3716U
#define MT9M114_REG_P_B_P3Q2      0x3718U
#define MT9M114_REG_P_B_P3Q3      0x371AU
#define MT9M114_REG_P_B_P3Q4      0x371CU
#define MT9M114_REG_P_G2_P3Q0     0x371EU
#define MT9M114_REG_P_G2_P3Q1     0x3720U
#define MT9M114_REG_P_G2_P3Q2     0x3722U
#define MT9M114_REG_P_G2_P3Q3     0x3724U
#define MT9M114_REG_P_G2_P3Q4     0x3726U
#define MT9M114_REG_P_G1_P4Q0     0x3740U
#define MT9M114_REG_P_G1_P4Q1     0x3742U
#define MT9M114_REG_P_G1_P4Q2     0x3744U
#define MT9M114_REG_P_G1_P4Q3     0x3746U
#define MT9M114_REG_P_G1_P4Q4     0x3748U
#define MT9M114_REG_P_R_P4Q0      0x374AU
#define MT9M114_REG_P_R_P4Q1      0x374CU
#define MT9M114_REG_P_R_P4Q2      0x374EU
#define MT9M114_REG_P_R_P4Q3      0x3750U
#define MT9M114_REG_P_R_P4Q4      0x3752U
#define MT9M114_REG_P_B_P4Q0      0x3754U
#define MT9M114_REG_P_B_P4Q1      0x3756U
#define MT9M114_REG_P_B_P4Q2      0x3758U
#define MT9M114_REG_P_B_P4Q3      0x375AU
#define MT9M114_REG_P_B_P4Q4      0x375CU
#define MT9M114_REG_P_G2_P4Q0     0x375EU
#define MT9M114_REG_P_G2_P4Q1     0x3760U
#define MT9M114_REG_P_G2_P4Q2     0x3762U
#define MT9M114_REG_P_G2_P4Q3     0x3764U
#define MT9M114_REG_P_G2_P4Q4     0x3766U
#define MT9M114_REG_CENTER_ROW    0x3782U
#define MT9M114_REG_CENTER_COLUMN 0x3784U

/* 4.SYSCTL registers */
#define MT9M114_REG_CHIP_ID                        0x0000U
#define MT9M114_REG_CLOCKS_CONTROL                 0x0016U
#define MT9M114_REG_RESET_AND_MISC_CONTROL         0x001AU
#define MT9M114_REG_PAD_SLEW                       0x001EU
#define MT9M114_REG_USER_DEFINED_DEVICE_ADDRESS_ID 0x002EU
#define MT9M114_REG_PAD_CONTROL                    0x0032U
#define MT9M114_REG_COMMAND_REGISTER               0x0080U

/* 5.XDMA registers */
#define MT9M114_REG_ACCESS_CTL_STAT         0x0982U
#define MT9M114_REG_PHYSICAL_ADDRESS_ACCESS 0x098AU
#define MT9M114_REG_LOGICAL_ADDRESS_ACCESS  0x098EU
#define MT9M114_REG_MCU_VARIABLE_DATA0      0x0990U
#define MT9M114_REG_MCU_VARIABLE_DATA1      0x0992U
#define MT9M114_REG_MCU_VARIABLE_DATA2      0x0994U
#define MT9M114_REG_MCU_VARIABLE_DATA3      0x0996U
#define MT9M114_REG_MCU_VARIABLE_DATA4      0x0998U
#define MT9M114_REG_MCU_VARIABLE_DATA5      0x099AU
#define MT9M114_REG_MCU_VARIABLE_DATA6      0x099CU
#define MT9M114_REG_MCU_VARIABLE_DATA7      0x099EU

/*! @brief MT9M114 variables definitions.*/

/* 01.Monitor variables */
#define MT9M114_VAR_MON_MAJOR_VERSION   0x8000U
#define MT9M114_VAR_MON_MINOR_VERSION   0x8002U
#define MT9M114_VAR_MON_RELEASE_VERSION 0x8004U
#define MT9M114_VAR_MON_HEARTBEAT       0x8006U

/* 02.Sequencer variables */
#define MT9M114_VAR_SEQ_ERROR_CODE 0x8406U

/* 03.AE_Rule variables */
#define MT9M114_VAR_AE_RULE_ALGO                 0xA404U
#define MT9M114_VAR_AE_RULE_AVG_Y_FROM_STATS     0xA406U
#define MT9M114_VAR_AE_RULE_AE_WEIGHT_TABLE_0_0  0xA407U
#define MT9M114_VAR_AE_RULE_AE_WEIGHT_TABLE_0_1  0xA408U
#define MT9M114_VAR_AE_RULE_AE_WEIGHT_TABLE_0_2  0xA409U
#define MT9M114_VAR_AE_RULE_AE_WEIGHT_TABLE_0_3  0xA40AU
#define MT9M114_VAR_AE_RULE_AE_WEIGHT_TABLE_0_4  0xA40BU
#define MT9M114_VAR_AE_RULE_AE_WEIGHT_TABLE_1_0  0xA40CU
#define MT9M114_VAR_AE_RULE_AE_WEIGHT_TABLE_1_1  0xA40DU
#define MT9M114_VAR_AE_RULE_AE_WEIGHT_TABLE_1_2  0xA40EU
#define MT9M114_VAR_AE_RULE_AE_WEIGHT_TABLE_1_3  0xA40FU
#define MT9M114_VAR_AE_RULE_AE_WEIGHT_TABLE_1_4  0xA410U
#define MT9M114_VAR_AE_RULE_AE_WEIGHT_TABLE_2_0  0xA411U
#define MT9M114_VAR_AE_RULE_AE_WEIGHT_TABLE_2_1  0xA412U
#define MT9M114_VAR_AE_RULE_AE_WEIGHT_TABLE_2_2  0xA413U
#define MT9M114_VAR_AE_RULE_AE_WEIGHT_TABLE_2_3  0xA414U
#define MT9M114_VAR_AE_RULE_AE_WEIGHT_TABLE_2_4  0xA415U
#define MT9M114_VAR_AE_RULE_AE_WEIGHT_TABLE_3_0  0xA416U
#define MT9M114_VAR_AE_RULE_AE_WEIGHT_TABLE_3_1  0xA417U
#define MT9M114_VAR_AE_RULE_AE_WEIGHT_TABLE_3_2  0xA418U
#define MT9M114_VAR_AE_RULE_AE_WEIGHT_TABLE_3_3  0xA419U
#define MT9M114_VAR_AE_RULE_AE_WEIGHT_TABLE_3_4  0xA41AU
#define MT9M114_VAR_AE_RULE_AE_WEIGHT_TABLE_4_0  0xA41BU
#define MT9M114_VAR_AE_RULE_AE_WEIGHT_TABLE_4_1  0xA41CU
#define MT9M114_VAR_AE_RULE_AE_WEIGHT_TABLE_4_2  0xA41DU
#define MT9M114_VAR_AE_RULE_AE_WEIGHT_TABLE_4_3  0xA41EU
#define MT9M114_VAR_AE_RULE_AE_WEIGHT_TABLE_4_4  0xA41FU
#define MT9M114_VAR_AE_RULE_AE_ADAPTIVE_STRENGTH 0xA420U

/* 04.AE_Track variables */
#define MT9M114_VAR_AE_TRACK_STATUS                      0xA800U
#define MT9M114_VAR_AE_TRACK_ALGO                        0xA804U
#define MT9M114_VAR_AE_TRACK_TARGET_AVERAGE_LUMA         0xA807U
#define MT9M114_VAR_AE_TRACK_GATE_PERCENTAGE             0xA808U
#define MT9M114_VAR_AE_TRACK_CURRENT_AVERAGE_LUMA        0xA809U
#define MT9M114_VAR_AE_TRACK_AE_TRACKING_DAMPENING_SPEED 0xA80AU
#define MT9M114_VAR_AE_TRACK_AE_DAMPENING_SPEED          0xA80BU
#define MT9M114_VAR_AE_TRACK_SKIP_FRAMES_COUNTER         0xA80DU
#define MT9M114_VAR_AE_TRACK_CURRENT_FLICKER_LINES       0xA80EU
#define MT9M114_VAR_AE_TRACK_FDZONE                      0xA818U
#define MT9M114_VAR_AE_TRACK_ZONE                        0xA81BU
#define MT9M114_VAR_AE_TRACK_FLICKER_LINES_50HZ          0xA826U
#define MT9M114_VAR_AE_TRACK_VIRT_EXPOSURE_LOG           0xA828U
#define MT9M114_VAR_AE_TRACK_MIN_VIRT_EXPOSURE_LOG_ZONE0 0xA82AU
#define MT9M114_VAR_AE_TRACK_MAX_VIRT_EXPOSURE_LOG_ZONE0 0xA82CU
#define MT9M114_VAR_AE_TRACK_MAX_VIRT_EXPOSURE_LOG_ZONE1 0xA82EU
#define MT9M114_VAR_AE_TRACK_VIRT_GAIN                   0xA838U

/* 05.AWB variables */
#define MT9M114_VAR_AWB_STATUS                        0xAC00U
#define MT9M114_VAR_AWB_MODE                          0xAC02U
#define MT9M114_VAR_AWB_R_RATIO_LOWER                 0xAC06U
#define MT9M114_VAR_AWB_R_RATIO_UPPER                 0xAC07U
#define MT9M114_VAR_AWB_B_RATIO_LOWER                 0xAC08U
#define MT9M114_VAR_AWB_B_RATIO_UPPER                 0xAC09U
#define MT9M114_VAR_AWB_R_SCENE_RATIO_LOWER           0xAC0AU
#define MT9M114_VAR_AWB_R_SCENE_RATIO_UPPER           0xAC0BU
#define MT9M114_VAR_AWB_B_SCENE_RATIO_LOWER           0xAC0CU
#define MT9M114_VAR_AWB_B_SCENE_RATIO_UPPER           0xAC0DU
#define MT9M114_VAR_AWB_R_RATIO_PRE_AWB               0xAC0EU
#define MT9M114_VAR_AWB_B_RATIO_PRE_AWB               0xAC0FU
#define MT9M114_VAR_AWB_R_GAIN                        0xAC12U
#define MT9M114_VAR_AWB_B_GAIN                        0xAC14U
#define MT9M114_VAR_AWB_PRE_AWB_RATIOS_TRACKING_SPEED 0xAC16U
#define MT9M114_VAR_AWB_PIXEL_THRESHOLD_COUNT         0xAC18U

/* 06.BlackLevel variables */
#define MT9M114_VAR_BLACKLEVEL_ALGO                  0xB004U
#define MT9M114_VAR_BLACKLEVEL_MAX_BLACK_LEVEL       0xB00CU
#define MT9M114_VAR_BLACKLEVEL_BLACK_LEVEL_DAMPENING 0xB00DU

/* 07.CCM variables */
#define MT9M114_VAR_CCM_ALGO           0xB404U
#define MT9M114_VAR_CCM_0              0xB406U
#define MT9M114_VAR_CCM_1              0xB408U
#define MT9M114_VAR_CCM_2              0xB40AU
#define MT9M114_VAR_CCM_3              0xB40CU
#define MT9M114_VAR_CCM_4              0xB40EU
#define MT9M114_VAR_CCM_5              0xB410U
#define MT9M114_VAR_CCM_6              0xB412U
#define MT9M114_VAR_CCM_7              0xB414U
#define MT9M114_VAR_CCM_8              0xB416U
#define MT9M114_VAR_CCM_LL_DELTA_CCM_0 0xB418U
#define MT9M114_VAR_CCM_LL_DELTA_CCM_1 0xB41AU
#define MT9M114_VAR_CCM_LL_DELTA_CCM_2 0xB41CU
#define MT9M114_VAR_CCM_LL_DELTA_CCM_3 0xB41EU
#define MT9M114_VAR_CCM_LL_DELTA_CCM_4 0xB420U
#define MT9M114_VAR_CCM_LL_DELTA_CCM_5 0xB422U
#define MT9M114_VAR_CCM_LL_DELTA_CCM_6 0xB424U
#define MT9M114_VAR_CCM_LL_DELTA_CCM_7 0xB426U
#define MT9M114_VAR_CCM_LL_DELTA_CCM_8 0xB428U
#define MT9M114_VAR_CCM_DELTA_GAIN     0xB42AU
#define MT9M114_VAR_CCM_DELTA_THRESH   0xB42BU

/* 08.LowLight variables */
#define MT9M114_VAR_LL_MODE                          0xBC02U
#define MT9M114_VAR_LL_ALGO                          0xBC04U
#define MT9M114_VAR_LL_GAMMA_SELECT                  0xBC07U
#define MT9M114_VAR_LL_GAMMA_CONTRAST_CURVE_0        0xBC0AU
#define MT9M114_VAR_LL_GAMMA_CONTRAST_CURVE_1        0xBC0BU
#define MT9M114_VAR_LL_GAMMA_CONTRAST_CURVE_2        0xBC0CU
#define MT9M114_VAR_LL_GAMMA_CONTRAST_CURVE_3        0xBC0DU
#define MT9M114_VAR_LL_GAMMA_CONTRAST_CURVE_4        0xBC0EU
#define MT9M114_VAR_LL_GAMMA_CONTRAST_CURVE_5        0xBC0FU
#define MT9M114_VAR_LL_GAMMA_CONTRAST_CURVE_6        0xBC10U
#define MT9M114_VAR_LL_GAMMA_CONTRAST_CURVE_7        0xBC11U
#define MT9M114_VAR_LL_GAMMA_CONTRAST_CURVE_8        0xBC12U
#define MT9M114_VAR_LL_GAMMA_CONTRAST_CURVE_9        0xBC13U
#define MT9M114_VAR_LL_GAMMA_CONTRAST_CURVE_10       0xBC14U
#define MT9M114_VAR_LL_GAMMA_CONTRAST_CURVE_11       0xBC15U
#define MT9M114_VAR_LL_GAMMA_CONTRAST_CURVE_12       0xBC16U
#define MT9M114_VAR_LL_GAMMA_CONTRAST_CURVE_13       0xBC17U
#define MT9M114_VAR_LL_GAMMA_CONTRAST_CURVE_14       0xBC18U
#define MT9M114_VAR_LL_GAMMA_CONTRAST_CURVE_15       0xBC19U
#define MT9M114_VAR_LL_GAMMA_CONTRAST_CURVE_16       0xBC1AU
#define MT9M114_VAR_LL_GAMMA_CONTRAST_CURVE_17       0xBC1BU
#define MT9M114_VAR_LL_GAMMA_CONTRAST_CURVE_18       0xBC1CU
#define MT9M114_VAR_LL_GAMMA_NRCURVE_0               0xBC1DU
#define MT9M114_VAR_LL_GAMMA_NRCURVE_1               0xBC1EU
#define MT9M114_VAR_LL_GAMMA_NRCURVE_2               0xBC1FU
#define MT9M114_VAR_LL_GAMMA_NRCURVE_3               0xBC20U
#define MT9M114_VAR_LL_GAMMA_NRCURVE_4               0xBC21U
#define MT9M114_VAR_LL_GAMMA_NRCURVE_5               0xBC22U
#define MT9M114_VAR_LL_GAMMA_NRCURVE_6               0xBC23U
#define MT9M114_VAR_LL_GAMMA_NRCURVE_7               0xBC24U
#define MT9M114_VAR_LL_GAMMA_NRCURVE_8               0xBC25U
#define MT9M114_VAR_LL_GAMMA_NRCURVE_9               0xBC26U
#define MT9M114_VAR_LL_GAMMA_NRCURVE_10              0xBC27U
#define MT9M114_VAR_LL_GAMMA_NRCURVE_11              0xBC28U
#define MT9M114_VAR_LL_GAMMA_NRCURVE_12              0xBC29U
#define MT9M114_VAR_LL_GAMMA_NRCURVE_13              0xBC2AU
#define MT9M114_VAR_LL_GAMMA_NRCURVE_14              0xBC2BU
#define MT9M114_VAR_LL_GAMMA_NRCURVE_15              0xBC2CU
#define MT9M114_VAR_LL_GAMMA_NRCURVE_16              0xBC2DU
#define MT9M114_VAR_LL_GAMMA_NRCURVE_17              0xBC2EU
#define MT9M114_VAR_LL_GAMMA_NRCURVE_18              0xBC2FU
#define MT9M114_VAR_LL_BM_PRECISION_BITS             0xBC31U
#define MT9M114_VAR_LL_AVERAGE_LUMA_FADE_TO_BLACK    0xBC3AU
#define MT9M114_VAR_LL_FADE_TO_BLACK_DAMPENING_SPEED 0xBC3CU

/* 09.CameraControl variables */
#define MT9M114_VAR_CAM_SENSOR_CFG_Y_ADDR_START                0xC800U
#define MT9M114_VAR_CAM_SENSOR_CFG_X_ADDR_START                0xC802U
#define MT9M114_VAR_CAM_SENSOR_CFG_Y_ADDR_END                  0xC804U
#define MT9M114_VAR_CAM_SENSOR_CFG_X_ADDR_END                  0xC806U
#define MT9M114_VAR_CAM_SENSOR_CFG_PIXCLK                      0xC808U
#define MT9M114_VAR_CAM_SENSOR_CFG_ROW_SPEED                   0xC80CU
#define MT9M114_VAR_CAM_SENSOR_CFG_FINE_INTEG_TIME_MIN         0xC80EU
#define MT9M114_VAR_CAM_SENSOR_CFG_FINE_INTEG_TIME_MAX         0xC810U
#define MT9M114_VAR_CAM_SENSOR_CFG_FRAME_LENGTH_LINES          0xC812U
#define MT9M114_VAR_CAM_SENSOR_CFG_LINE_LENGTH_PCK             0xC814U
#define MT9M114_VAR_CAM_SENSOR_CFG_FINE_CORRECTION             0xC816U
#define MT9M114_VAR_CAM_SENSOR_CFG_CPIPE_LAST_ROW              0xC818U
#define MT9M114_VAR_CAM_SENSOR_CFG_REG_0_DATA                  0xC826U
#define MT9M114_VAR_CAM_SENSOR_CONTROL_READ_MODE               0xC834U
#define MT9M114_VAR_CAM_SENSOR_CONTROL_ANALOG_GAIN             0xC836U
#define MT9M114_VAR_CAM_SENSOR_CONTROL_VIRT_COLUMN_GAIN        0xC838U
#define MT9M114_VAR_CAM_SENSOR_CONTROL_FRAME_LENGTH_LINES      0xC83AU
#define MT9M114_VAR_CAM_SENSOR_CONTROL_COARSE_INTEGRATION_TIME 0xC83CU
#define MT9M114_VAR_CAM_SENSOR_CONTROL_FINE_INTEGRATION_TIME   0xC83EU
#define MT9M114_VAR_CAM_CPIPE_CONTROL_DGAIN_RED                0xC840U
#define MT9M114_VAR_CAM_CPIPE_CONTROL_DGAIN_GREEN1             0xC842U
#define MT9M114_VAR_CAM_CPIPE_CONTROL_DGAIN_GREEN2             0xC844U
#define MT9M114_VAR_CAM_CPIPE_CONTROL_DGAIN_BLUE               0xC846U
#define MT9M114_VAR_CAM_CPIPE_CONTROL_DGAIN_SECOND             0xC848U
#define MT9M114_VAR_CAM_CPIPE_CONTROL_SECOND_BLACK_LEVEL       0xC84BU
#define MT9M114_VAR_CAM_MODE_SELECT                            0xC84CU
#define MT9M114_VAR_CAM_MODE_TEST_PATTERN_SELECT               0xC84DU
#define MT9M114_VAR_CAM_MODE_TEST_PATTERN_RED                  0xC84EU
#define MT9M114_VAR_CAM_MODE_TEST_PATTERN_GREEN                0xC850U
#define MT9M114_VAR_CAM_MODE_TEST_PATTERN_BLUE                 0xC852U
#define MT9M114_VAR_CAM_CROP_WINDOW_XOFFSET                    0xC854U
#define MT9M114_VAR_CAM_CROP_WINDOW_YOFFSET                    0xC856U
#define MT9M114_VAR_CAM_CROP_WINDOW_WIDTH                      0xC858U
#define MT9M114_VAR_CAM_CROP_WINDOW_HEIGHT                     0xC85AU
#define MT9M114_VAR_CAM_CROP_CROPMODE                          0xC85CU
#define MT9M114_VAR_CAM_SCALE_VERTICAL_TC_MODE                 0xC85EU
#define MT9M114_VAR_CAM_SCALE_VERTICAL_TC_PERCENTAGE           0xC860U
#define MT9M114_VAR_CAM_SCALE_VERTICAL_TC_STRETCH_FACTOR       0xC862U
#define MT9M114_VAR_CAM_OUTPUT_WIDTH                           0xC868U
#define MT9M114_VAR_CAM_OUTPUT_HEIGHT                          0xC86AU
#define MT9M114_VAR_CAM_OUTPUT_FORMAT                          0xC86CU
#define MT9M114_VAR_CAM_OUTPUT_FORMAT_YUV                      0xC86EU
#define MT9M114_VAR_CAM_OUTPUT_Y_OFFSET                        0xC870U
#define MT9M114_VAR_CAM_HUE_ANGLE                              0xC873U
#define MT9M114_VAR_CAM_SFX_CONTROL                            0xC874U
#define MT9M114_VAR_CAM_SFX_SOLARIZATION_THRESH                0xC875U
#define MT9M114_VAR_CAM_SFX_SEPIA_CR                           0xC876U
#define MT9M114_VAR_CAM_SFX_SEPIA_CB                           0xC877U
#define MT9M114_VAR_CAM_AET_AEMODE                             0xC878U
#define MT9M114_VAR_CAM_AET_SKIP_FRAMES                        0xC879U
#define MT9M114_VAR_CAM_AET_TARGET_AVERAGE_LUMA                0xC87AU
#define MT9M114_VAR_CAM_AET_TARGET_AVERAGE_LUMA_DARK           0xC87BU
#define MT9M114_VAR_CAM_AET_BLACK_CLIPPING_TARGET              0xC87CU
#define MT9M114_VAR_CAM_AET_AE_MIN_VIRT_INT_TIME_PCLK          0xC87EU
#define MT9M114_VAR_CAM_AET_AE_MIN_VIRT_DGAIN                  0xC880U
#define MT9M114_VAR_CAM_AET_AE_MAX_VIRT_DGAIN                  0xC882U
#define MT9M114_VAR_CAM_AET_AE_MIN_VIRT_AGAIN                  0xC884U
#define MT9M114_VAR_CAM_AET_AE_MAX_VIRT_AGAIN                  0xC886U
#define MT9M114_VAR_CAM_AET_AE_VIRT_GAIN_TH_EG                 0xC888U
#define MT9M114_VAR_CAM_AET_AE_EG_GATE_PERCENTAGE              0xC88AU
#define MT9M114_VAR_CAM_AET_FLICKER_FREQ_HZ                    0xC88BU
#define MT9M114_VAR_CAM_AET_MAX_FRAME_RATE                     0xC88CU
#define MT9M114_VAR_CAM_AET_MIN_FRAME_RATE                     0xC88EU
#define MT9M114_VAR_CAM_AET_TARGET_GAIN                        0xC890U
#define MT9M114_VAR_CAM_AWB_CCM_L_0                            0xC892U
#define MT9M114_VAR_CAM_AWB_CCM_L_1                            0xC894U
#define MT9M114_VAR_CAM_AWB_CCM_L_2                            0xC896U
#define MT9M114_VAR_CAM_AWB_CCM_L_3                            0xC898U
#define MT9M114_VAR_CAM_AWB_CCM_L_4                            0xC89AU
#define MT9M114_VAR_CAM_AWB_CCM_L_5                            0xC89CU
#define MT9M114_VAR_CAM_AWB_CCM_L_6                            0xC89EU
#define MT9M114_VAR_CAM_AWB_CCM_L_7                            0xC8A0U
#define MT9M114_VAR_CAM_AWB_CCM_L_8                            0xC8A2U
#define MT9M114_VAR_CAM_AWB_CCM_M_0                            0xC8A4U
#define MT9M114_VAR_CAM_AWB_CCM_M_1                            0xC8A6U
#define MT9M114_VAR_CAM_AWB_CCM_M_2                            0xC8A8U
#define MT9M114_VAR_CAM_AWB_CCM_M_3                            0xC8AAU
#define MT9M114_VAR_CAM_AWB_CCM_M_4                            0xC8ACU
#define MT9M114_VAR_CAM_AWB_CCM_M_5                            0xC8AEU
#define MT9M114_VAR_CAM_AWB_CCM_M_6                            0xC8B0U
#define MT9M114_VAR_CAM_AWB_CCM_M_7                            0xC8B2U
#define MT9M114_VAR_CAM_AWB_CCM_M_8                            0xC8B4U
#define MT9M114_VAR_CAM_AWB_CCM_R_0                            0xC8B6U
#define MT9M114_VAR_CAM_AWB_CCM_R_1                            0xC8B8U
#define MT9M114_VAR_CAM_AWB_CCM_R_2                            0xC8BAU
#define MT9M114_VAR_CAM_AWB_CCM_R_3                            0xC8BCU
#define MT9M114_VAR_CAM_AWB_CCM_R_4                            0xC8BEU
#define MT9M114_VAR_CAM_AWB_CCM_R_5                            0xC8C0U
#define MT9M114_VAR_CAM_AWB_CCM_R_6                            0xC8C2U
#define MT9M114_VAR_CAM_AWB_CCM_R_7                            0xC8C4U
#define MT9M114_VAR_CAM_AWB_CCM_R_8                            0xC8C6U
#define MT9M114_VAR_CAM_AWB_CCM_L_RG_GAIN                      0xC8C8U
#define MT9M114_VAR_CAM_AWB_CCM_L_BG_GAIN                      0xC8CAU
#define MT9M114_VAR_CAM_AWB_CCM_M_RG_GAIN                      0xC8CCU
#define MT9M114_VAR_CAM_AWB_CCM_M_BG_GAIN                      0xC8CEU
#define MT9M114_VAR_CAM_AWB_CCM_R_RG_GAIN                      0xC8D0U
#define MT9M114_VAR_CAM_AWB_CCM_R_BG_GAIN                      0xC8D2U
#define MT9M114_VAR_CAM_AWB_CCM_L_CTEMP                        0xC8D4U
#define MT9M114_VAR_CAM_AWB_CCM_M_CTEMP                        0xC8D6U
#define MT9M114_VAR_CAM_AWB_CCM_R_CTEMP                        0xC8D8U
#define MT9M114_VAR_CAM_AWB_LL_CCM_0                           0xC8DAU
#define MT9M114_VAR_CAM_AWB_LL_CCM_1                           0xC8DCU
#define MT9M114_VAR_CAM_AWB_LL_CCM_2                           0xC8DEU
#define MT9M114_VAR_CAM_AWB_LL_CCM_3                           0xC8E0U
#define MT9M114_VAR_CAM_AWB_LL_CCM_4                           0xC8E2U
#define MT9M114_VAR_CAM_AWB_LL_CCM_5                           0xC8E4U
#define MT9M114_VAR_CAM_AWB_LL_CCM_6                           0xC8E6U
#define MT9M114_VAR_CAM_AWB_LL_CCM_7                           0xC8E8U
#define MT9M114_VAR_CAM_AWB_LL_CCM_8                           0xC8EAU
#define MT9M114_VAR_CAM_AWB_COLOR_TEMPERATURE_MIN              0xC8ECU
#define MT9M114_VAR_CAM_AWB_COLOR_TEMPERATURE_MAX              0xC8EEU
#define MT9M114_VAR_CAM_AWB_COLOR_TEMPERATURE                  0xC8F0U
#define MT9M114_VAR_CAM_AWB_AWB_XSCALE                         0xC8F2U
#define MT9M114_VAR_CAM_AWB_AWB_YSCALE                         0xC8F3U
#define MT9M114_VAR_CAM_AWB_AWB_WEIGHTS_0                      0xC8F4U
#define MT9M114_VAR_CAM_AWB_AWB_WEIGHTS_1                      0xC8F6U
#define MT9M114_VAR_CAM_AWB_AWB_WEIGHTS_2                      0xC8F8U
#define MT9M114_VAR_CAM_AWB_AWB_WEIGHTS_3                      0xC8FAU
#define MT9M114_VAR_CAM_AWB_AWB_WEIGHTS_4                      0xC8FCU
#define MT9M114_VAR_CAM_AWB_AWB_WEIGHTS_5                      0xC8FEU
#define MT9M114_VAR_CAM_AWB_AWB_WEIGHTS_6                      0xC900U
#define MT9M114_VAR_CAM_AWB_AWB_WEIGHTS_7                      0xC902U
#define MT9M114_VAR_CAM_AWB_AWB_XSHIFT_PRE_ADJ                 0xC904U
#define MT9M114_VAR_CAM_AWB_AWB_YSHIFT_PRE_ADJ                 0xC906U
#define MT9M114_VAR_CAM_AWB_AWBMODE                            0xC909U
#define MT9M114_VAR_CAM_AWB_TINTS_CTEMP_THRESHOLD              0xC90AU
#define MT9M114_VAR_CAM_AWB_K_R_L                              0xC90CU
#define MT9M114_VAR_CAM_AWB_K_G_L                              0xC90DU
#define MT9M114_VAR_CAM_AWB_K_B_L                              0xC90EU
#define MT9M114_VAR_CAM_AWB_K_R_R                              0xC90FU
#define MT9M114_VAR_CAM_AWB_K_G_R                              0xC910U
#define MT9M114_VAR_CAM_AWB_K_B_R                              0xC911U
#define MT9M114_VAR_CAM_STAT_AWB_CLIP_WINDOW_XSTART            0xC914U
#define MT9M114_VAR_CAM_STAT_AWB_CLIP_WINDOW_YSTART            0xC916U
#define MT9M114_VAR_CAM_STAT_AWB_CLIP_WINDOW_XEND              0xC918U
#define MT9M114_VAR_CAM_STAT_AWB_CLIP_WINDOW_YEND              0xC91AU
#define MT9M114_VAR_CAM_STAT_AE_INITIAL_WINDOW_XSTART          0xC91CU
#define MT9M114_VAR_CAM_STAT_AE_INITIAL_WINDOW_YSTART          0xC91EU
#define MT9M114_VAR_CAM_STAT_AE_INITIAL_WINDOW_XEND            0xC920U
#define MT9M114_VAR_CAM_STAT_AE_INITIAL_WINDOW_YEND            0xC922U
#define MT9M114_VAR_CAM_LL_LLMODE                              0xC924U
#define MT9M114_VAR_CAM_LL_START_BRIGHTNESS                    0xC926U
#define MT9M114_VAR_CAM_LL_STOP_BRIGHTNESS                     0xC928U
#define MT9M114_VAR_CAM_LL_START_SATURATION                    0xC92AU
#define MT9M114_VAR_CAM_LL_END_SATURATION                      0xC92BU
#define MT9M114_VAR_CAM_LL_START_DESATURATION                  0xC92CU
#define MT9M114_VAR_CAM_LL_END_DESATURATION                    0xC92DU
#define MT9M114_VAR_CAM_LL_START_DEMOSAIC                      0xC92EU
#define MT9M114_VAR_CAM_LL_START_AP_GAIN                       0xC92FU
#define MT9M114_VAR_CAM_LL_START_AP_THRESH                     0xC930U
#define MT9M114_VAR_CAM_LL_STOP_DEMOSAIC                       0xC931U
#define MT9M114_VAR_CAM_LL_STOP_AP_GAIN                        0xC932U
#define MT9M114_VAR_CAM_LL_STOP_AP_THRESH                      0xC933U
#define MT9M114_VAR_CAM_LL_START_NR_RED                        0xC934U
#define MT9M114_VAR_CAM_LL_START_NR_GREEN                      0xC935U
#define MT9M114_VAR_CAM_LL_START_NR_BLUE                       0xC936U
#define MT9M114_VAR_CAM_LL_START_NR_THRESH                     0xC937U
#define MT9M114_VAR_CAM_LL_STOP_NR_RED                         0xC938U
#define MT9M114_VAR_CAM_LL_STOP_NR_GREEN                       0xC939U
#define MT9M114_VAR_CAM_LL_STOP_NR_BLUE                        0xC93AU
#define MT9M114_VAR_CAM_LL_STOP_NR_THRESH                      0xC93BU
#define MT9M114_VAR_CAM_LL_START_CONTRAST_BM                   0xC93CU
#define MT9M114_VAR_CAM_LL_STOP_CONTRAST_BM                    0xC93EU
#define MT9M114_VAR_CAM_LL_GAMMA                               0xC940U
#define MT9M114_VAR_CAM_LL_START_CONTRAST_GRADIENT             0xC942U
#define MT9M114_VAR_CAM_LL_STOP_CONTRAST_GRADIENT              0xC943U
#define MT9M114_VAR_CAM_LL_START_CONTRAST_LUMA_PERCENTAGE      0xC944U
#define MT9M114_VAR_CAM_LL_STOP_CONTRAST_LUMA_PERCENTAGE       0xC945U
#define MT9M114_VAR_CAM_LL_START_GAIN_METRIC                   0xC946U
#define MT9M114_VAR_CAM_LL_STOP_GAIN_METRIC                    0xC948U
#define MT9M114_VAR_CAM_LL_START_FADE_TO_BLACK_LUMA            0xC94AU
#define MT9M114_VAR_CAM_LL_STOP_FADE_TO_BLACK_LUMA             0xC94CU
#define MT9M114_VAR_CAM_LL_CLUSTER_DC_TH_BM                    0xC94EU
#define MT9M114_VAR_CAM_LL_CLUSTER_DC_GATE_PERCENTAGE          0xC950U
#define MT9M114_VAR_CAM_LL_SUMMING_SENSITIVITY_FACTOR          0xC951U
#define MT9M114_VAR_CAM_LL_START_TARGET_LUMA_BM                0xC952U
#define MT9M114_VAR_CAM_LL_STOP_TARGET_LUMA_BM                 0xC954U
#define MT9M114_VAR_CAM_LL_INV_BRIGHTNESS_METRIC               0xC956U
#define MT9M114_VAR_CAM_LL_GAIN_METRIC                         0xC958U
#define MT9M114_VAR_CAM_SEQ_UV_COLOR_BOOST                     0xC95AU
#define MT9M114_VAR_CAM_PGA_PGA_CONTROL                        0xC95EU
#define MT9M114_VAR_CAM_PGA_L_CONFIG_COLOUR_TEMP               0xC960U
#define MT9M114_VAR_CAM_PGA_L_CONFIG_GREEN_RED_Q14             0xC962U
#define MT9M114_VAR_CAM_PGA_L_CONFIG_RED_Q14                   0xC964U
#define MT9M114_VAR_CAM_PGA_L_CONFIG_GREEN_BLUE_Q14            0xC966U
#define MT9M114_VAR_CAM_PGA_L_CONFIG_BLUE_Q14                  0xC968U
#define MT9M114_VAR_CAM_PGA_M_CONFIG_COLOUR_TEMP               0xC96AU
#define MT9M114_VAR_CAM_PGA_M_CONFIG_GREEN_RED_Q14             0xC96CU
#define MT9M114_VAR_CAM_PGA_M_CONFIG_RED_Q14                   0xC96EU
#define MT9M114_VAR_CAM_PGA_M_CONFIG_GREEN_BLUE_Q14            0xC970U
#define MT9M114_VAR_CAM_PGA_M_CONFIG_BLUE_Q14                  0xC972U
#define MT9M114_VAR_CAM_PGA_R_CONFIG_COLOUR_TEMP               0xC974U
#define MT9M114_VAR_CAM_PGA_R_CONFIG_GREEN_RED_Q14             0xC976U
#define MT9M114_VAR_CAM_PGA_R_CONFIG_RED_Q14                   0xC978U
#define MT9M114_VAR_CAM_PGA_R_CONFIG_GREEN_BLUE_Q14            0xC97AU
#define MT9M114_VAR_CAM_PGA_R_CONFIG_BLUE_Q14                  0xC97CU
#define MT9M114_VAR_CAM_SYSCTL_PLL_ENABLE                      0xC97EU
#define MT9M114_VAR_CAM_SYSCTL_PLL_DIVIDER_M_N                 0xC980U
#define MT9M114_VAR_CAM_SYSCTL_PLL_DIVIDER_P                   0xC982U
#define MT9M114_VAR_CAM_PORT_OUTPUT_CONTROL                    0xC984U
#define MT9M114_VAR_CAM_PORT_PORCH                             0xC986U
#define MT9M114_VAR_CAM_PORT_MIPI_TIMING_T_HS_ZERO             0xC988U
#define MT9M114_VAR_CAM_PORT_MIPI_TIMING_T_HS_EXIT_HS_TRAIL    0xC98AU
#define MT9M114_VAR_CAM_PORT_MIPI_TIMING_T_CLK_POST_CLK_PRE    0xC98CU
#define MT9M114_VAR_CAM_PORT_MIPI_TIMING_T_CLK_TRAIL_CLK_ZERO  0xC98EU
#define MT9M114_VAR_CAM_PORT_MIPI_TIMING_T_LPX                 0xC990U
#define MT9M114_VAR_CAM_PORT_MIPI_TIMING_INIT_TIMING           0xC992U

/* 10.UVC_Control variables */
#define MT9M114_VAR_UVC_AE_MODE_CONTROL                        0xCC00U
#define MT9M114_VAR_UVC_WHITE_BALANCE_TEMPERATURE_AUTO_CONTROL 0xCC01U
#define MT9M114_VAR_UVC_AE_PRIORITY_CONTROL                    0xCC02U
#define MT9M114_VAR_UVC_POWER_LINE_FREQUENCY_CONTROL           0xCC03U
#define MT9M114_VAR_UVC_EXPOSURE_TIME_ABSOLUTE_CONTROL         0xCC04U
#define MT9M114_VAR_UVC_BACKLIGHT_COMPENSATION_CONTROL         0xCC08U
#define MT9M114_VAR_UVC_BRIGHTNESS_CONTROL                     0xCC0AU
#define MT9M114_VAR_UVC_CONTRAST_CONTROL                       0xCC0CU
#define MT9M114_VAR_UVC_GAIN_CONTROL                           0xCC0EU
#define MT9M114_VAR_UVC_HUE_CONTROL                            0xCC10U
#define MT9M114_VAR_UVC_SATURATION_CONTROL                     0xCC12U
#define MT9M114_VAR_UVC_SHARPNESS_CONTROL                      0xCC14U
#define MT9M114_VAR_UVC_GAMMA_CONTROL                          0xCC16U
#define MT9M114_VAR_UVC_WHITE_BALANCE_TEMPERATURE_CONTROL      0xCC18U
#define MT9M114_VAR_UVC_FRAME_INTERVAL_CONTROL                 0xCC1CU
#define MT9M114_VAR_UVC_MANUAL_EXPOSURE_CONFIGURATION          0xCC20U
#define MT9M114_VAR_UVC_FLICKER_AVOIDANCE_CONFIGURATION        0xCC21U
#define MT9M114_VAR_UVC_ALGO                                   0xCC22U
#define MT9M114_VAR_UVC_RESULT_STATUS                          0xCC24U

/* 11.SystemManager variables */
#define MT9M114_VAR_SYSMGR_NEXT_STATE    0xDC00U
#define MT9M114_VAR_SYSMGR_CURRENT_STATE 0xDC01U
#define MT9M114_VAR_SYSMGR_CMD_STATUS    0xDC02U

/* 12.PatchLoader variables */
#define MT9M114_VAR_PATCHLDR_LOADER_ADDRESS 0xE000U
#define MT9M114_VAR_PATCHLDR_PATCH_ID       0xE002U
#define MT9M114_VAR_PATCHLDR_FIRMWARE_ID    0xE004U
#define MT9M114_VAR_PATCHLDR_APPLY_STATUS   0xE008U
#define MT9M114_VAR_PATCHLDR_NUM_PATCHES    0xE009U
#define MT9M114_VAR_PATCHLDR_PATCH_ID_0     0xE00AU
#define MT9M114_VAR_PATCHLDR_PATCH_ID_1     0xE00CU
#define MT9M114_VAR_PATCHLDR_PATCH_ID_2     0xE00EU
#define MT9M114_VAR_PATCHLDR_PATCH_ID_3     0xE010U
#define MT9M114_VAR_PATCHLDR_PATCH_ID_4     0xE012U
#define MT9M114_VAR_PATCHLDR_PATCH_ID_5     0xE014U
#define MT9M114_VAR_PATCHLDR_PATCH_ID_6     0xE016U
#define MT9M114_VAR_PATCHLDR_PATCH_ID_7     0xE018U

/* 13.Patch variables */
#define MT9M114_VAR_PATCHVARS_DELTA_DK_CORRECTION_FACTOR 0xE400U

/* 14.CommandHandler variables */
#define MT9M114_VAR_CMD_HANDLER_WAIT_EVENT_ID 0xFC00U
#define MT9M114_VAR_CMD_HANDLER_NUM_EVENTS    0xFC02U

/*! @brief MT9M114 command definitions. */
#define MT9M114_COMMAND_APPLY_PATCH    0x0001U
#define MT9M114_COMMAND_SET_STATE      0x0002U
#define MT9M114_COMMAND_REFRESH        0x0004U
#define MT9M114_COMMAND_WAIT_FOR_EVENT 0x0008U
#define MT9M114_COMMAND_OK             0x8000U

/*! @brief MT9M114 system state definitions. */
#define MT9M114_SYS_STATE_ENTER_CONFIG_CHANGE 0x28U
#define MT9M114_SYS_STATE_STREAMING           0x31U
#define MT9M114_SYS_STATE_START_STREAMING     0x34U
#define MT9M114_SYS_STATE_ENTER_SUSPEND       0x40U
#define MT9M114_SYS_STATE_SUSPENDED           0x41U
#define MT9M114_SYS_STATE_ENTER_STANDBY       0x50U
#define MT9M114_SYS_STATE_STANDBY             0x52U
#define MT9M114_SYS_STATE_LEAVE_STANDBY       0x54U

/*! @brief MT9M114 system set-state command retults. */
#define MT9M114_SYS_STATE_SET_RESULT_ENOERR 0x00U /* command successful */
#define MT9M114_SYS_STATE_SET_RESULTEINVAL  0x0CU /* invalid configuration */
#define MT9M114_SYS_STATE_SET_RESULTENOSPC  0x0DU /* resource not available */

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*!
 * @brief MT9M114 resource.
 *
 * Before initialize the MT9M114, the resource must be initialized that the
 * Two-Wire-Serial-Interface I2C could start to work.
 */
typedef struct _mt9m114_resource
{
    video_i2c_send_func_t i2cSendFunc;       /*!< I2C send function. */
    video_i2c_receive_func_t i2cReceiveFunc; /*!< I2C receive function. */
    void (*pullResetPin)(bool pullUp);       /*!< Function to pull reset pin high or low. */
    uint32_t inputClockFreq_Hz;              /*!< Input clock frequency, EXTCLK. */
} mt9m114_resource_t;

/*! @brief MT9M114 operation functions. */
extern const camera_device_operations_t mt9m114_ops;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

#if defined(__cplusplus)
}
#endif

#endif /* _FSL_MT9M114_H_ */
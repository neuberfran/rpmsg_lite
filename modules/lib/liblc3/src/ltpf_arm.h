/******************************************************************************
 *
 *  Copyright 2022 Google LLC
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at:
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 ******************************************************************************/

#if __ARM_FEATURE_SIMD32 || defined(TEST_ARM)

#ifndef TEST_ARM

#include <arm_acle.h>

static inline int16x2_t __pkhbt(int16x2_t a, int16x2_t b)
{
    int16x2_t r;
    __asm("pkhbt %0, %1, %2" : "=r" (r) : "r" (a), "r" (b));
    return r;
}

#endif /* TEST_ARM */


/**
 * Import
 */

static inline int32_t filter_hp50(struct lc3_ltpf_hp50_state *, int32_t);
static inline float dot(const int16_t *, const int16_t *, int);


/**
 * Resample from 8 / 16 / 32 KHz to 12.8 KHz Template
 */
#if !defined(resample_8k_12k8) || !defined(resample_16k_12k8) \
    || !defined(resample_32k_12k8)
static inline void arm_resample_x64k_12k8(const int p, const int16x2_t *h,
    struct lc3_ltpf_hp50_state *hp50, const int16x2_t *x, int16_t *y, int n)
{
    const int w = 40 / p;

    x -= w;

    for (int i = 0; i < 5*n; i += 5) {
        const int16x2_t *hn = h + (i % (2*p)) * (48 / p);
        const int16x2_t *xn = x + (i / (2*p));

        int32_t un = __smlad(*(xn++), *(hn++), 0);

        for (int k = 0; k < w; k += 5) {
            un = __smlad(*(xn++), *(hn++), un);
            un = __smlad(*(xn++), *(hn++), un);
            un = __smlad(*(xn++), *(hn++), un);
            un = __smlad(*(xn++), *(hn++), un);
            un = __smlad(*(xn++), *(hn++), un);
        }

        int32_t yn = filter_hp50(hp50, un);
        *(y++) = (yn + (1 << 15)) >> 16;
    }
}
#endif

/**
 * Resample from 24 / 48 KHz to 12.8 KHz Template
 */
#if !defined(resample_24k_12k8) || !defined(resample_48k_12k8)
static inline void arm_resample_x192k_12k8(const int p, const int16x2_t *h,
    struct lc3_ltpf_hp50_state *hp50, const int16x2_t *x, int16_t *y, int n)
{
    const int w = 120 / p;

    x -= w;

    for (int i = 0; i < 15*n; i += 15) {
        const int16x2_t *hn = h + (i % (2*p)) * (128 / p);
        const int16x2_t *xn = x + (i / (2*p));

        int32_t un = __smlad(*(xn++), *(hn++), 0);

        for (int k = 0; k < w; k += 15) {
            un = __smlad(*(xn++), *(hn++), un);
            un = __smlad(*(xn++), *(hn++), un);
            un = __smlad(*(xn++), *(hn++), un);
            un = __smlad(*(xn++), *(hn++), un);
            un = __smlad(*(xn++), *(hn++), un);
            un = __smlad(*(xn++), *(hn++), un);
            un = __smlad(*(xn++), *(hn++), un);
            un = __smlad(*(xn++), *(hn++), un);
            un = __smlad(*(xn++), *(hn++), un);
            un = __smlad(*(xn++), *(hn++), un);
            un = __smlad(*(xn++), *(hn++), un);
            un = __smlad(*(xn++), *(hn++), un);
            un = __smlad(*(xn++), *(hn++), un);
            un = __smlad(*(xn++), *(hn++), un);
            un = __smlad(*(xn++), *(hn++), un);
        }

        int32_t yn = filter_hp50(hp50, un);
        *(y++) = (yn + (1 << 15)) >> 16;
    }
}
#endif

/**
 * Resample from 8 Khz to 12.8 KHz
 */
#ifndef resample_8k_12k8

static void arm_resample_8k_12k8(
    struct lc3_ltpf_hp50_state *hp50, const int16_t *x, int16_t *y, int n)
{
    static const int16_t alignas(int32_t) h[2*8*12] = {
        0, 214,  417, -1052, -4529, 26233, -4529, -1052,   417,  214,   0, 0,
        0, 180,    0, -1522, -2427, 24506, -5289,     0,   763,  156, -28, 0,
        0,  92, -323, -1361,     0, 19741, -3885,  1317,   861,    0, -61, 0,
        0,   0, -457,  -752,  1873, 13068,     0,  2389,   598, -213, -79, 0,
        0, -61, -398,     0,  2686,  5997,  5997,  2686,     0, -398, -61, 0,
        0, -79, -213,   598,  2389,     0, 13068,  1873,  -752, -457,   0, 0,
        0, -61,    0,   861,  1317, -3885, 19741,     0, -1361, -323,  92, 0,
        0, -28,  156,   763,     0, -5289, 24506, -2427, -1522,    0, 180, 0,
        0, 0, 214,  417, -1052, -4529, 26233, -4529, -1052,   417,  214,   0,
        0, 0, 180,    0, -1522, -2427, 24506, -5289,     0,   763,  156, -28,
        0, 0,  92, -323, -1361,     0, 19741, -3885,  1317,   861,    0, -61,
        0, 0,   0, -457,  -752,  1873, 13068,     0,  2389,   598, -213, -79,
        0, 0, -61, -398,     0,  2686,  5997,  5997,  2686,     0, -398, -61,
        0, 0, -79, -213,   598,  2389,     0, 13068,  1873,  -752, -457,   0,
        0, 0, -61,    0,   861,  1317, -3885, 19741,     0, -1361, -323,  92,
        0, 0, -28,  156,   763,     0, -5289, 24506, -2427, -1522,    0, 180,
    };

    arm_resample_x64k_12k8(
        8, (const int16x2_t *)h, hp50, (int16x2_t *)x, y, n);
}

#ifndef TEST_ARM
#define resample_8k_12k8 arm_resample_8k_12k8
#endif

#endif /* resample_8k_12k8 */

/**
 * Resample from 16 Khz to 12.8 KHz
 */
#ifndef resample_16k_12k8

static void arm_resample_16k_12k8(
    struct lc3_ltpf_hp50_state *hp50, const int16_t *x, int16_t *y, int n)
{
    static const int16_t alignas(int32_t) h[2*4*24] = {

            0,   -61,   214,  -398,   417,     0, -1052,  2686,
        -4529,  5997, 26233,  5997, -4529,  2686, -1052,     0,
          417,  -398,   214,   -61,     0,     0,     0,     0,


            0,   -79,   180,  -213,     0,   598, -1522,  2389,
        -2427,     0, 24506, 13068, -5289,  1873,     0,  -752,
          763,  -457,   156,     0,   -28,     0,     0,     0,


            0,   -61,    92,     0,  -323,   861, -1361,  1317,
            0, -3885, 19741, 19741, -3885,     0,  1317, -1361,
          861,  -323,     0,    92,   -61,     0,     0,     0,

            0,   -28,     0,   156,  -457,   763,  -752,     0,
         1873, -5289, 13068, 24506,     0, -2427,  2389, -1522,
          598,     0,  -213,   180,   -79,     0,     0,     0,


            0,     0,   -61,   214,  -398,   417,     0, -1052,
         2686, -4529,  5997, 26233,  5997, -4529,  2686, -1052,
            0,   417,  -398,   214,   -61,     0,     0,     0,


            0,     0,   -79,   180,  -213,     0,   598, -1522,
         2389, -2427,     0, 24506, 13068, -5289,  1873,     0,
         -752,   763,  -457,   156,     0,   -28,     0,     0,


            0,     0,   -61,    92,     0,  -323,   861, -1361,
         1317,     0, -3885, 19741, 19741, -3885,     0,  1317,
        -1361,   861,  -323,     0,    92,   -61,     0,     0,

            0,     0,   -28,     0,   156,  -457,   763,  -752,
            0,  1873, -5289, 13068, 24506,     0, -2427,  2389,
        -1522,   598,     0,  -213,   180,   -79,     0,     0,
    };

    arm_resample_x64k_12k8(
        4, (const int16x2_t *)h, hp50, (int16x2_t *)x, y, n);
}

#ifndef TEST_ARM
#define resample_16k_12k8 arm_resample_16k_12k8
#endif

#endif /* resample_16k_12k8 */

/**
 * Resample from 32 Khz to 12.8 KHz
 */
#ifndef resample_32k_12k8

static void arm_resample_32k_12k8(
    struct lc3_ltpf_hp50_state *hp50, const int16_t *x, int16_t *y, int n)
{
    static const int16_t alignas(int32_t) h[2*2*48] = {

            0,   -30,   -31,    46,   107,     0,  -199,  -162,
          209,   430,     0,  -681,  -526,   658,  1343,     0,
        -2264, -1943,  2999,  9871, 13116,  9871,  2999, -1943,
        -2264,     0,  1343,   658,  -526,  -681,     0,   430,
          209,  -162,  -199,     0,   107,    46,   -31,   -30,
            0,     0,     0,     0,     0,     0,     0,     0,

            0,   -14,   -39,     0,    90,    78,  -106,  -229,
            0,   382,   299,  -376,  -761,     0,  1194,   937,
        -1214, -2644,     0,  6534, 12253, 12253,  6534,     0,
        -2644, -1214,   937,  1194,     0,  -761,  -376,   299,
          382,     0,  -229,  -106,    78,    90,     0,   -39,
          -14,     0,     0,     0,     0,     0,     0,     0,

            0,     0,   -30,   -31,    46,   107,     0,  -199,
         -162,   209,   430,     0,  -681,  -526,   658,  1343,
            0, -2264, -1943,  2999,  9871, 13116,  9871,  2999,
        -1943, -2264,     0,  1343,   658,  -526,  -681,     0,
          430,   209,  -162,  -199,     0,   107,    46,   -31,
          -30,     0,     0,     0,     0,     0,     0,     0,

            0,     0,   -14,   -39,     0,    90,    78,  -106,
         -229,     0,   382,   299,  -376,  -761,     0,  1194,
          937, -1214, -2644,     0,  6534, 12253, 12253,  6534,
            0, -2644, -1214,   937,  1194,     0,  -761,  -376,
          299,   382,     0,  -229,  -106,    78,    90,     0,
          -39,   -14,     0,     0,     0,     0,     0,     0,
    };

    arm_resample_x64k_12k8(
        2, (const int16x2_t *)h, hp50, (int16x2_t *)x, y, n);
}

#ifndef TEST_ARM
#define resample_32k_12k8 arm_resample_32k_12k8
#endif

#endif /* resample_32k_12k8 */

/**
 * Resample from 24 Khz to 12.8 KHz
 */
#ifndef resample_24k_12k8

static void arm_resample_24k_12k8(
    struct lc3_ltpf_hp50_state *hp50, const int16_t *x, int16_t *y, int n)
{
    static const int16_t alignas(int32_t) h[2*8*32] = {

            0,   -50,    19,   143,   -93,  -290,   278,   485,
         -658,  -701,  1396,   901, -3019, -1042, 10276, 17488,
        10276, -1042, -3019,   901,  1396,  -701,  -658,   485,
          278,  -290,   -93,   143,    19,   -50,     0,     0,

            0,   -46,     0,   141,   -45,  -305,   185,   543,
         -501,  -854,  1153,  1249, -2619, -1908,  8712, 17358,
        11772,     0, -3319,   480,  1593,  -504,  -796,   399,
          367,  -261,  -142,   138,    40,   -52,    -5,     0,

            0,   -41,   -17,   133,     0,  -304,    91,   574,
         -334,  -959,   878,  1516, -2143, -2590,  7118, 16971,
        13161,  1202, -3495,     0,  1731,  -267,  -908,   287,
          445,  -215,  -188,   125,    62,   -52,   -12,     0,

            0,   -34,   -30,   120,    41,  -291,     0,   577,
         -164, -1015,   585,  1697, -1618, -3084,  5534, 16337,
        14406,  2544, -3526,  -523,  1800,     0,  -985,   152,
          509,  -156,  -230,   104,    83,   -48,   -19,     0,

            0,   -26,   -41,   103,    76,  -265,   -83,   554,
            0, -1023,   288,  1791, -1070, -3393,  3998, 15474,
        15474,  3998, -3393, -1070,  1791,   288, -1023,     0,
          554,   -83,  -265,    76,   103,   -41,   -26,     0,

            0,   -19,   -48,    83,   104,  -230,  -156,   509,
          152,  -985,     0,  1800,  -523, -3526,  2544, 14406,
        16337,  5534, -3084, -1618,  1697,   585, -1015,  -164,
          577,     0,  -291,    41,   120,   -30,   -34,     0,

            0,   -12,   -52,    62,   125,  -188,  -215,   445,
          287,  -908,  -267,  1731,     0, -3495,  1202, 13161,
        16971,  7118, -2590, -2143,  1516,   878,  -959,  -334,
          574,    91,  -304,     0,   133,   -17,   -41,     0,

            0,    -5,   -52,    40,   138,  -142,  -261,   367,
          399,  -796,  -504,  1593,   480, -3319,     0, 11772,
        17358,  8712, -1908, -2619,  1249,  1153,  -854,  -501,
          543,   185,  -305,   -45,   141,     0,   -46,     0,

            0,     0,   -50,    19,   143,   -93,  -290,   278,
          485,  -658,  -701,  1396,   901, -3019, -1042, 10276,
        17488, 10276, -1042, -3019,   901,  1396,  -701,  -658,
          485,   278,  -290,   -93,   143,    19,   -50,     0,

            0,     0,   -46,     0,   141,   -45,  -305,   185,
          543,  -501,  -854,  1153,  1249, -2619, -1908,  8712,
        17358, 11772,     0, -3319,   480,  1593,  -504,  -796,
          399,   367,  -261,  -142,   138,    40,   -52,    -5,

            0,     0,   -41,   -17,   133,     0,  -304,    91,
          574,  -334,  -959,   878,  1516, -2143, -2590,  7118,
        16971, 13161,  1202, -3495,     0,  1731,  -267,  -908,
          287,   445,  -215,  -188,   125,    62,   -52,   -12,

            0,     0,   -34,   -30,   120,    41,  -291,     0,
          577,  -164, -1015,   585,  1697, -1618, -3084,  5534,
        16337, 14406,  2544, -3526,  -523,  1800,     0,  -985,
          152,   509,  -156,  -230,   104,    83,   -48,   -19,

            0,     0,   -26,   -41,   103,    76,  -265,   -83,
          554,     0, -1023,   288,  1791, -1070, -3393,  3998,
        15474, 15474,  3998, -3393, -1070,  1791,   288, -1023,
            0,   554,   -83,  -265,    76,   103,   -41,   -26,

            0,     0,   -19,   -48,    83,   104,  -230,  -156,
          509,   152,  -985,     0,  1800,  -523, -3526,  2544,
        14406, 16337,  5534, -3084, -1618,  1697,   585, -1015,
         -164,   577,     0,  -291,    41,   120,   -30,   -34,

            0,     0,   -12,   -52,    62,   125,  -188,  -215,
          445,   287,  -908,  -267,  1731,     0, -3495,  1202,
        13161, 16971,  7118, -2590, -2143,  1516,   878,  -959,
         -334,   574,    91,  -304,     0,   133,   -17,   -41,

            0,     0,    -5,   -52,    40,   138,  -142,  -261,
          367,   399,  -796,  -504,  1593,   480, -3319,     0,
        11772, 17358,  8712, -1908, -2619,  1249,  1153,  -854,
         -501,   543,   185,  -305,   -45,   141,     0,   -46,
    };

    arm_resample_x192k_12k8(
        8, (const int16x2_t *)h, hp50, (int16x2_t *)x, y, n);
}

#ifndef TEST_ARM
#define resample_24k_12k8 arm_resample_24k_12k8
#endif

#endif /* resample_24k_12k8 */

/**
 * Resample from 48 Khz to 12.8 KHz
 */
#ifndef resample_48k_12k8

static void arm_resample_48k_12k8(
    struct lc3_ltpf_hp50_state *hp50, const int16_t *x, int16_t *y, int n)
{
    static const int16_t alignas(int32_t) h[2*4*64] = {

            0,   -13,   -25,   -20,    10,    51,    71,    38,
          -47,  -133,  -145,   -42,   139,   277,   242,     0,
         -329,  -511,  -351,   144,   698,   895,   450,  -535,
        -1510, -1697,  -521,  1999,  5138,  7737,  8744,  7737,
         5138,  1999,  -521, -1697, -1510,  -535,   450,   895,
          698,   144,  -351,  -511,  -329,     0,   242,   277,
          139,   -42,  -145,  -133,   -47,    38,    71,    51,
           10,   -20,   -25,   -13,     0,     0,     0,     0,

            0,    -9,   -23,   -24,     0,    41,    71,    52,
          -23,  -115,  -152,   -78,    92,   254,   272,    76,
         -251,  -493,  -427,     0,   576,   900,   624,  -262,
        -1309, -1763,  -954,  1272,  4356,  7203,  8679,  8169,
         5886,  2767,     0, -1542, -1660,  -809,   240,   848,
          796,   292,  -252,  -507,  -398,   -82,   199,   288,
          183,     0,  -130,  -145,   -71,    20,    69,    60,
           20,   -15,   -26,   -17,    -3,     0,     0,     0,

            0,    -6,   -20,   -26,    -8,    31,    67,    62,
            0,   -94,  -152,  -108,    45,   223,   287,   143,
         -167,  -454,  -480,  -134,   439,   866,   758,     0,
        -1071, -1748, -1295,   601,  3559,  6580,  8485,  8485,
         6580,  3559,   601, -1295, -1748, -1071,     0,   758,
          866,   439,  -134,  -480,  -454,  -167,   143,   287,
          223,    45,  -108,  -152,   -94,     0,    62,    67,
           31,    -8,   -26,   -20,    -6,     0,     0,     0,

            0,    -3,   -17,   -26,   -15,    20,    60,    69,
           20,   -71,  -145,  -130,     0,   183,   288,   199,
          -82,  -398,  -507,  -252,   292,   796,   848,   240,
         -809, -1660, -1542,     0,  2767,  5886,  8169,  8679,
         7203,  4356,  1272,  -954, -1763, -1309,  -262,   624,
          900,   576,     0,  -427,  -493,  -251,    76,   272,
          254,    92,   -78,  -152,  -115,   -23,    52,    71,
           41,     0,   -24,   -23,    -9,     0,     0,     0,

            0,     0,   -13,   -25,   -20,    10,    51,    71,
           38,   -47,  -133,  -145,   -42,   139,   277,   242,
            0,  -329,  -511,  -351,   144,   698,   895,   450,
         -535, -1510, -1697,  -521,  1999,  5138,  7737,  8744,
         7737,  5138,  1999,  -521, -1697, -1510,  -535,   450,
          895,   698,   144,  -351,  -511,  -329,     0,   242,
          277,   139,   -42,  -145,  -133,   -47,    38,    71,
           51,    10,   -20,   -25,   -13,     0,     0,     0,

            0,     0,    -9,   -23,   -24,     0,    41,    71,
           52,   -23,  -115,  -152,   -78,    92,   254,   272,
           76,  -251,  -493,  -427,     0,   576,   900,   624,
         -262, -1309, -1763,  -954,  1272,  4356,  7203,  8679,
         8169,  5886,  2767,     0, -1542, -1660,  -809,   240,
          848,   796,   292,  -252,  -507,  -398,   -82,   199,
          288,   183,     0,  -130,  -145,   -71,    20,    69,
           60,    20,   -15,   -26,   -17,    -3,     0,     0,

            0,     0,    -6,   -20,   -26,    -8,    31,    67,
           62,     0,   -94,  -152,  -108,    45,   223,   287,
          143,  -167,  -454,  -480,  -134,   439,   866,   758,
            0, -1071, -1748, -1295,   601,  3559,  6580,  8485,
         8485,  6580,  3559,   601, -1295, -1748, -1071,     0,
          758,   866,   439,  -134,  -480,  -454,  -167,   143,
          287,   223,    45,  -108,  -152,   -94,     0,    62,
           67,    31,    -8,   -26,   -20,    -6,     0,     0,

            0,     0,    -3,   -17,   -26,   -15,    20,    60,
           69,    20,   -71,  -145,  -130,     0,   183,   288,
          199,   -82,  -398,  -507,  -252,   292,   796,   848,
          240,  -809, -1660, -1542,     0,  2767,  5886,  8169,
         8679,  7203,  4356,  1272,  -954, -1763, -1309,  -262,
          624,   900,   576,     0,  -427,  -493,  -251,    76,
          272,   254,    92,   -78,  -152,  -115,   -23,    52,
           71,    41,     0,   -24,   -23,    -9,     0,     0,
    };

    arm_resample_x192k_12k8(
        4, (const int16x2_t *)h, hp50, (int16x2_t *)x, y, n);
}

#ifndef TEST_ARM
#define resample_48k_12k8 arm_resample_48k_12k8
#endif

#endif /* resample_48k_12k8 */

/**
 * Return vector of correlations
 */
#ifndef correlate

static void arm_correlate(
    const int16_t *a, const int16_t *b, int n, float *y, int nc)
{
    /* --- Check alignment of `b` --- */

    if ((uintptr_t)b & 3)
        *(y++) = dot(a, b--, n), nc--;

    /* --- Processing by pair --- */

    for ( ; nc >= 2; nc -= 2) {
        const int16x2_t *an = (const int16x2_t *)(a  );
        const int16x2_t *bn = (const int16x2_t *)(b--);

        int16x2_t ax, b0, b1;
        int64_t v0 = 0, v1 = 0;

        b1 = (int16x2_t)*(b--) << 16;

        for (int i = 0; i < (n >> 4); i++ )
            for (int j = 0; j < 4; j++) {

                ax = *(an++), b0 = *(bn++);
                v0 = __smlald (ax, b0, v0);
                v1 = __smlaldx(ax, __pkhbt(b0, b1), v1);

                ax = *(an++), b1 = *(bn++);
                v0 = __smlald (ax, b1, v0);
                v1 = __smlaldx(ax, __pkhbt(b1, b0), v1);
            }

        *(y++) = (float)((int32_t)((v0 + (1 << 5)) >> 6));
        *(y++) = (float)((int32_t)((v1 + (1 << 5)) >> 6));
    }

    /* --- Odd element count --- */

    if (nc > 0)
        *(y++) = dot(a, b, n);
}

#ifndef TEST_ARM
#define correlate arm_correlate
#endif

#endif /* correlate */

#endif /* __ARM_FEATURE_SIMD32 */

/* Copyright 2019 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#ifndef TENSORFLOW_LITE_MICRO_EXAMPLES_NETWORK_TESTER_EXPECTED_OUTPUT_DATA_H_
#define TENSORFLOW_LITE_MICRO_EXAMPLES_NETWORK_TESTER_EXPECTED_OUTPUT_DATA_H_

#ifdef ETHOS_U
static unsigned char expected_output_data[] = {143, 113};
#else
static unsigned char expected_output_data[] = {
    0x07, 0xf3, 0x16, 0xf3, 0x3a, 0x1f, 0xb1, 0x45, 0xce, 0x12, 0xc2, 0xbb,
    0xf5, 0x47, 0x45, 0x91, 0x13, 0x21, 0xc7, 0x07, 0xa2, 0x2c, 0xf2, 0xf7,
    0xd1, 0xe1, 0x08, 0xf5, 0x0a, 0x58, 0x40, 0xb0, 0xd9, 0xf1, 0x37, 0x1e,
    0xf1, 0x0d, 0xea, 0x05, 0xf9, 0xee, 0xfa, 0xca, 0x37, 0xb9, 0xc4, 0xd8,
    0x15, 0xe3, 0xd7, 0xd3, 0x36, 0x14, 0xb7, 0xed, 0x43, 0xfa, 0x29, 0xbe,
    0xff, 0xdb, 0x38, 0xc7, 0x00, 0xf1, 0x06, 0xbe, 0x31, 0x5b, 0xe9, 0x02,
    0xf0, 0x07, 0x13, 0x25, 0xe1, 0xf0, 0x0e, 0x12, 0x17, 0xd2, 0x51, 0x48,
    0x2a, 0x24, 0xf2, 0x0a, 0x3d, 0x05, 0x0b, 0x67, 0xc3, 0xea, 0x0a, 0xbf,
    0x22, 0x40, 0x20, 0x18, 0x54, 0xd3, 0x31, 0xef, 0xe7, 0x04, 0x3c, 0xf6,
    0xcf, 0xe2, 0x79, 0xed, 0xec, 0xff, 0xfa, 0xcf, 0xc2, 0x42, 0x1f, 0x0d,
    0xf8, 0xc2, 0x36, 0x1d, 0x09, 0x01, 0xd2, 0x09, 0xda, 0xdf, 0xe8, 0x1f,
    0x06, 0xdf, 0xf7, 0x3c, 0x4d, 0xe5, 0xb4, 0xc1, 0xfa, 0x03, 0x22, 0xbc,
    0x08, 0xea, 0x72, 0x3a, 0xc8, 0x0b, 0xe6, 0x1c, 0x00, 0xef, 0xf1, 0x34,
    0x01, 0xbe, 0xf7, 0x92, 0xe6, 0xc1, 0xe3, 0x25, 0xe5, 0x4c, 0xf1, 0xbb,
    0x6f, 0x07, 0x63, 0x80, 0x2a, 0xae, 0x46, 0xf1, 0x3c, 0x01, 0xe8, 0xda,
    0xed, 0x15, 0xfc, 0x56, 0x18, 0x16, 0x16, 0xc1, 0xf5, 0xef, 0x64, 0x03,
    0xa5, 0x0c, 0x15, 0x25, 0xe0, 0x51, 0x23, 0xec, 0x31, 0xfe, 0xe9, 0xd9,
    0x0c, 0x09, 0x42, 0xd8, 0xbc, 0x15, 0xe1, 0x21, 0xe4, 0x09, 0x4f, 0xb5,
    0xd6, 0x0c, 0x04, 0x20, 0xdf, 0x99, 0x2e, 0xe8, 0x06, 0xad, 0xf5, 0x04,
    0xf7, 0x1b, 0x5b, 0x63, 0xaa, 0xf3, 0xf0, 0xfc, 0x05, 0x35, 0xf1, 0x1d,
    0x40, 0x2d, 0xf6, 0xfa, 0xdd, 0x07, 0xfe, 0x32, 0x6d, 0x1b, 0x01, 0x31,
    0x39, 0xcb, 0x22, 0xf8};
#endif

#endif  // TENSORFLOW_LITE_MICRO_EXAMPLES_NETWORK_TESTER_EXPECTED_OUTPUT_DATA_H_
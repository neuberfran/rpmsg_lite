/*
 * Generated using zcbor version 0.3.99
 * https://github.com/NordicSemiconductor/zcbor
 * Generated with a --default-max-qty of 3
 */

#ifndef EDHOC_ENCODE_DATA_2_H__
#define EDHOC_ENCODE_DATA_2_H__

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include "zcbor_encode.h"
#include "cbor/edhoc_encode_data_2_types.h"

#if DEFAULT_MAX_QTY != 3
#error "The type file was generated with a different default_max_qty than this file"
#endif


bool cbor_encode_data_2(
		uint8_t *payload, size_t payload_len,
		const struct data_2 *input,
		size_t *payload_len_out);


#endif /* EDHOC_ENCODE_DATA_2_H__ */
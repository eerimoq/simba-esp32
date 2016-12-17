/*
 * Big number math
 * Copyright (c) 2006, Jouni Malinen <j@w1.fi>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Alternatively, this software may be distributed under the terms of BSD
 * license.
 *
 * See README and COPYING for more details.
 */

#ifndef BIGNUM_H
#define BIGNUM_H

struct bignum;

struct bignum * esp_bignum_init(void);
void esp_bignum_deinit(struct bignum *n);
size_t esp_bignum_get_unsigned_bin_len(struct bignum *n);
int esp_bignum_get_unsigned_bin(const struct bignum *n, u8 *buf, size_t *len);
int esp_bignum_set_unsigned_bin(struct bignum *n, const u8 *buf, size_t len);
int esp_bignum_cmp(const struct bignum *a, const struct bignum *b);
int esp_bignum_cmp_d(const struct bignum *a, unsigned long b);
int esp_bignum_add(const struct bignum *a, const struct bignum *b,
	       struct bignum *c);
int esp_bignum_sub(const struct bignum *a, const struct bignum *b,
	       struct bignum *c);
int esp_bignum_mul(const struct bignum *a, const struct bignum *b,
	       struct bignum *c);
int esp_bignum_mulmod(const struct bignum *a, const struct bignum *b,
		  const struct bignum *c, struct bignum *d);
int esp_bignum_exptmod(const struct bignum *a, const struct bignum *b,
		   const struct bignum *c, struct bignum *d);

#endif /* BIGNUM_H */

/*
 * berrors.h
 *
 * Copyright (C) 2022 DELLFER, INC
 *
 * BATTLEWISE is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License.
 *
 * The code is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this code. If not, see <http://www.gnu.org/licenses/>.
 *
 * This software is available for commercial license, please contact
 * license@dellfer.com.
 */

#if (!(defined(BERRORS_H)))
#define BERRORS_H


/*------------------------------------------------------------------------*/

#if (!(defined(BERRORS_STRING_LOOKUP_TABLE)))
#define ERROR_DEF(X,Y)                          X=Y
#else
#undef  ERROR_DEF
#define ERROR_DEF(X,Y)                         {X,#X}
#endif


/*------------------------------------------------------------------------*/

#if (!(defined(BERRORS_STRING_LOOKUP_TABLE)))
typedef enum ENUM_STATUS                        STATUS;

enum ENUM_STATUS
#else
STATIC berrorsDescr m_berrorsTable[] =
#endif
{
    ERROR_DEF (OK,                               0),			/* SUCCESS */

    ERROR_DEF (ERR_GEN,                         -1000),
    ERROR_DEF (ERR_GEN_NULL_PTR,                -1001),
    ERROR_DEF (ERR_GEN_BAD_LENGTH,              -1002),
    ERROR_DEF (ERR_GEN_INT_OVERFLOW,            -1003),
    ERROR_DEF (ERR_GEN_DIV_BY_ZERO,             -1004),
    ERROR_DEF (ERR_GEN_NOT_FOUND,               -1005),

    ERROR_DEF (ERR_MEM,                         -1500),
    ERROR_DEF (ERR_MEM_ALLOC,                   -1501),
    ERROR_DEF (ERR_MEM_ALLOC_LENGTH,            -1502),
    ERROR_DEF (ERR_MEM_POOL_ALLOC,              -1520),
    ERROR_DEF (ERR_MEM_POOL_EMPTY,              -1521),
    ERROR_DEF (ERR_MEM_POOL_SIZE,               -1522),
    ERROR_DEF (ERR_MEM_BUF_ALLOC,               -1540),
    ERROR_DEF (ERR_MEM_BUF_LENGTH,              -1541),
    ERROR_DEF (ERR_MEM_BUF_MISMATCH,            -1542),

    ERROR_DEF (ERR_STR,                         -2000),
    ERROR_DEF (ERR_STR_BAD_LENGTH,              -2001),
    ERROR_DEF (ERR_STR_TRUNCATE,                -2002),
    ERROR_DEF (ERR_STR_BAD_FORMAT_OPTION,       -2003),

    ERROR_DEF (ERR_HASH,                        -3600),
    ERROR_DEF (ERR_HASH_UNKNOWN_ALGO,           -3601),

    ERROR_DEF (ERR_BIGINT,                      -4800),
    ERROR_DEF (ERR_BIGINT_ALLOC,                -4801),
    ERROR_DEF (ERR_BIGINT_ASSIGN,               -4802),
    ERROR_DEF (ERR_BIGINT_COPY,                 -4803),
    ERROR_DEF (ERR_BIGINT_SET_UNIT,             -4804),
    ERROR_DEF (ERR_BIGINT_MOD,                  -4805),
    ERROR_DEF (ERR_BIGINT_MODEXP,               -4806),

    ERROR_DEF (ERR_CRYPTO,                      -5000),
    ERROR_DEF (ERR_CRYPTO_ALLOC,                -5001),
    ERROR_DEF (ERR_CRYPTO_KEY_SIZE,             -5002),
    ERROR_DEF (ERR_CRYPTO_KEY_TYPE,             -5003),
    ERROR_DEF (ERR_CRYPTO_ALGO_UNKNOWN,         -5004),

    ERROR_DEF (ERR_CRYPTO_PSS,                  -5100),
    ERROR_DEF (ERR_CRYPTO_PSS_VER_FAIL,         -5101),

    ERROR_DEF (ERR_CRYPTO_SHA1,                 -5200),
    ERROR_DEF (ERR_CRYPTO_SHA1_ALLOC_FAIL,      -5201),

    ERROR_DEF (ERR_CRYPTO_SHA256,               -5300),
    ERROR_DEF (ERR_CRYPTO_SHA256_ALLOC_FAIL,    -5301),

    ERROR_DEF (ERR_CRYPTO_SHA512,               -5400),
    ERROR_DEF (ERR_CRYPTO_SHA512_ALLOC_FAIL,    -5401),

    ERROR_DEF (ERR_CRYPTO_TSS,                  -5500),
    ERROR_DEF (ERR_CRYPTO_TSS_ALLOC_FAIL,       -5501),

    ERROR_DEF (ERR_END_OF_LIST,                 -(1 << 31))
};


/*------------------------------------------------------------------------*/

#if (defined(ENABLE_BERRORS_LOOKUP_TABLE))
EXTERN bool32 BERRORS_lookup(const STATUS lookupStatus, sbyte **ppRetCodeString);
#endif

#endif /* BERRORS_H */

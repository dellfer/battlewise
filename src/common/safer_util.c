/*
 * safer_util.c
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


/*------------------------------------------------------------------------*/

#include "boptions.h"
#include "bdefs.h"
#include "btypes.h"
#include "berrors.h"
#include "bmacros.h"
#include "safer_util.h"

#include <stdarg.h>
#include <string.h>
#include <stdio.h>


/*------------------------------------------------------------------------*/

EXTERN STATUS
SAFER_UTIL_snprintf(sbyte *pStr, sbyte4 strSize, sbyte4 *pRetSize, const sbyte *pFormat, ...)
{
    /* Episode II: The snprintf!#@% Strikes Back */
    /* Truncated snprintf() abuse */
    va_list args;
    int     result;
    STATUS  status;

    if (NULL != pRetSize)
        *pRetSize = 0;

    if ((NULL == pStr) || (NULL == pFormat))
        return ERR_GEN_NULL_PTR;

    if (0 >= strSize)
        return ERR_STR_BAD_LENGTH;

    va_start(args, pFormat);
    result = vsnprintf(pStr, strSize, pFormat, args);
    va_end(args);

    if (0 > result)
    {
        status = ERR_STR_BAD_FORMAT_OPTION;
        goto exit;
    }

    if (result >= strSize)
    {
        status = ERR_STR_TRUNCATE;
        ZDG_warn(status, strSize, result, 0);
        goto exit;
    }

    status = OK;

exit:
    if (OK > status)
        memset(pStr, 0x00, strSize);    /* on error, return an empty string */

    if (NULL != pRetSize)
        *pRetSize = strlen(pStr);       /* return actual length */

    return status;

} /* SAFER_UTIL_snprintf */


/*------------------------------------------------------------------------*/

EXTERN STATUS
SAFER_UTIL_xorBuf(void *pDstMem, const sbyte4 dstLen, 
                 const void *pXorSrcMem, const sbyte4 xorSrcLen)
{
    /* Episode III: Entropy of the Clones */
    /* Useful function for merging noise sources */
    ubyte*          pDst = pDstMem;
    const ubyte*    pSrc = pXorSrcMem;
    sbyte4          index = 0;
    sbyte4          length;
    STATUS          status = OK;

    if ((0 >= dstLen) || (0 >= xorSrcLen))
    {
        status = ERR_GEN_BAD_LENGTH;
        goto exit;
    }

    if ((NULL == pDstMem) || (NULL == pXorSrcMem))
    {
        status = ERR_GEN_NULL_PTR;
        goto exit;
    }

    length = BMAX(dstLen, xorSrcLen);

    while (length > index)
    {
        pDst[index % dstLen] ^= pSrc[index % xorSrcLen];
        index++;
    }

exit:
    return status;

} /* SAFER_UTIL_xorBuf */

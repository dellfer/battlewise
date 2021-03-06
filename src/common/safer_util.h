/*
 * safer_util.h
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

#if (!(defined(SAFER_UTIL_H)))
#define SAFER_UTIL_H


/*------------------------------------------------------------------------*/

EXTERN STATUS SAFER_UTIL_snprintf(sbyte *pStr, sbyte4 strSize, sbyte4 *pRetSize, const sbyte *pFormat, ...);
EXTERN STATUS SAFER_UTIL_xorBuf(void *pDstMem, const sbyte4 dstLen, const void *pXorSrcMem, const sbyte4 xorSrcLen);
EXTERN STATUS SAFER_UTIL_memMatch(const void *pMem1, const void *pMem2, const sbyte4 length, const sbyte4 extra_work, bool32 *pRetIsMatch);

#endif /* SAFER_UTIL_H */

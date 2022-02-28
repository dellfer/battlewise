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
#include "safer_util.h"

#include <stdarg.h>
#include <string.h>
#include <stdio.h>


/*------------------------------------------------------------------------*/

EXTERN STATUS
SAFER_UTIL_snprintf(sbyte *pStr, sbyte4 strSize, sbyte4 *pRetSize, const sbyte *pFormat, ...)
{
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
        memset(pStr, 0x00, strSize); 	/* on error, return an empty string */

    if (NULL != pRetSize)
        *pRetSize = strlen(pStr);		/* return actual length */

    return status;

} /* SAFER_UTIL_snprintf */

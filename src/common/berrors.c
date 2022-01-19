/*
 * berrors.c
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

#if (ENABLE_BERRORS_LOOKUP_TABLE)
#undef BERRORS_H

typedef struct
{
    int		berrorsCode;
    char*	pBerrorsLabel;

} berrorsDescr;

#define BERRORS_STRING_LOOKUP_TABLE
#include "berrors.h"

#define NUM_BERRORS_TABLE_ENTRIES    (sizeof(m_berrorsTable) / sizeof(berrorsDescr))
#endif


/*------------------------------------------------------------------------*/

#if (ENABLE_BERRORS_LOOKUP_TABLE)
EXTERN bool32
BERRORS_lookup(const STATUS lookupStatus, sbyte **ppRetCodeString)
{
    sbyte*  pRetCodeString = NULL;
    sbyte4  index;
    bool32  isFound = FALSE;

    for (index = 0; index < NUM_BERRORS_TABLE_ENTRIES; index++)
    {
        if (lookupStatus == m_berrorsTable[index].berrorsCode)
        {
            pRetCodeString = m_berrorsTable[index].pBerrorsLabel;
            isFound = TRUE;
            break;
        }
    }

    if (NULL != *ppRetCodeString)
        *ppRetCodeString = pRetCodeString;

    return isFound;
}
#endif /* (ENABLE_BERRORS_LOOKUP_TABLE) */

/******************************************************************************
 * Copyright (C) 2008  Michael Hofmann <mh21@piware.de>                       *
 *                                                                            *
 * This program is free software; you can redistribute it and/or modify       *
 * it under the terms of the GNU General Public License as published by       *
 * the Free Software Foundation; either version 3 of the License, or          *
 * (at your option) any later version.                                        *
 *                                                                            *
 * This program is distributed in the hope that it will be useful,            *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 * GNU General Public License for more details.                               *
 *                                                                            *
 * You should have received a copy of the GNU General Public License along    *
 * with this program; if not, write to the Free Software Foundation, Inc.,    *
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.                *
 ******************************************************************************/

#ifndef _EXPORL_COH_LIB_COH_COHLEVELCHECKER_H_
#define _EXPORL_COH_LIB_COH_COHLEVELCHECKER_H_

#include "coh.h"

#include <QMap>
#include <QPair>

namespace coh
{

/** Checks that a CI command sequence does not exceed the given current level.
 *
 * @param sequence CI command sequence to check
 * @return true if the CI command sequence does not exceed the given current
 * level, false otherwise
 *
 * @relates CohSequence
 */
COH_EXPORT bool checkCohSequenceLevel(coh::CohSequence *sequence,
                                      unsigned comfortLevel);

COH_EXPORT bool checkCohSequenceLevel(
    coh::CohSequence *sequence,
    const QMap<QPair<coh::Coh::Electrode, coh::Coh::Electrode>, unsigned>
        &electrodes);

} // namespace coh

#endif

/******************************************************************************
 * Copyright (C) 2008  Tom Francart <tom.francart@med.kuleuven.be>            *
 *                                                                            *
 * This file is part of APEX 4.                                               *
 *                                                                            *
 * APEX 4 is free software: you can redistribute it and/or modify             *
 * it under the terms of the GNU General Public License as published by       *
 * the Free Software Foundation, either version 2 of the License, or          *
 * (at your option) any later version.                                        *
 *                                                                            *
 * APEX 4 is distributed in the hope that it will be useful,                  *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 * GNU General Public License for more details.                               *
 *                                                                            *
 * You should have received a copy of the GNU General Public License          *
 * along with APEX 4.  If not, see <http://www.gnu.org/licenses/>.            *
 *****************************************************************************/

#ifndef _EXPORL_SRC_LIB_APEXDATA_PROCEDURE_MULTIPROCEDUREDATA_H_
#define _EXPORL_SRC_LIB_APEXDATA_PROCEDURE_MULTIPROCEDUREDATA_H_

#include "apextools/global.h"

#include "proceduredata.h"
#include "procedureinterface.h"

#include <QVector>

namespace apex
{
namespace data
{
typedef QVector<const ProcedureData *> tProcConfigList;

/**
@author Tom Francart,,,
*/
class APEXDATA_EXPORT MultiProcedureData : public ProcedureData
{

public:
    MultiProcedureData();

    ~MultiProcedureData();

    void addProcedure(ProcedureData *procedure);
    tProcConfigList procedures() const;

    virtual Type type() const;
    virtual QString name() const;

private:
    QVector<ProcedureData *> m_procedureDatas;

    // ProcedureData contains functions that aren't valid for MultiProcedureData
    void setPresentations(int presentations);
    void setSkip(int skip);
    void setNumberOfChoices(int nb);
    void setDefaultStandard(const QString &defStd);
    void setUniqueStandard(bool u);
    void setPauseBetweenStimuli(int pause);
    void setTimeBeforeFirstStimulus(int tbfs);
    void setInputDuringStimulus(bool ids);
};
}
}
#endif

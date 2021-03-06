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

#ifndef _EXPORL_SRC_LIB_APEXDATA_PARAMETERS_APEXPARAMETERS_H_
#define _EXPORL_SRC_LIB_APEXDATA_PARAMETERS_APEXPARAMETERS_H_

#include "apextools/global.h"

#include "apextools/xml/xmltools.h"

#include <QMap>
#include <QString>

namespace apex
{

class ApexErrorHandler;
namespace data
{
/**
Parses, holds and checks parameters for a procedure

@author Tom Francart,,,
*/
class APEXDATA_EXPORT ApexParameters
{
    typedef std::pair<QString, QString> tParamMapPair;

public:
    ApexParameters();
    virtual ~ApexParameters();

    /**
        * Used to iterate the parameters. I know it looks strange but M$VC
        * cannot handle template inheritance across libraries...
        */
    struct APEXDATA_EXPORT const_iterator {
        const_iterator(const QMap<QString, QString>::const_iterator &it);
        const_iterator()
        {
        }

        const_iterator &
        operator=(const QMap<QString, QString>::const_iterator &it);
        const_iterator &operator++();   // prefix++
        const_iterator operator++(int); // postfix++
        bool operator==(const const_iterator &other) const;
        bool operator!=(const const_iterator &other) const;
        const QString &key();
        const QString &value();

    private:
        QMap<QString, QString>::const_iterator it;
    };

    QMap<QString, QString>::const_iterator begin() const;
    QMap<QString, QString>::const_iterator end() const;

    virtual bool Parse(const QDomElement &p_paramElement); // don't do this in
                                                           // the constructor
                                                           // because of
                                                           // overriding of the
                                                           // SetParameter
                                                           // function

    virtual QString GetParameter(const QString &p_name) const; //[ stijn ]
                                                               // changed to
    // reference
    // again; no need
    // to make extra
    // copies

    virtual bool HasParameter(const QString &p_name) const;

    virtual void SetParameter(const QString &ac_sName, const QString &ac_sValue)
    {
        parameters[ac_sName] = ac_sValue;
    }

    virtual bool CheckParameters();

    virtual bool operator==(const ApexParameters &other) const;

protected:
    // virtual bool SetParameter(const QString& p_name, const QString& p_id,
    // const QString& p_value, QDomElement base=0)
    virtual bool SetParameter(const QString &, const QString &, const QString &,
                              const QDomElement &)
    {
        //              qCDebug(APEX_RS, "ApexParameters: SetParameter: should
        //              not come here?");
        return true;
    }

private:
    QDomElement m_paramElement;

    QMap<QString, QString> parameters;
};
}
}

#endif

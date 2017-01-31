/******************************************************************************
 * Copyright (C) 2008  Tom Francart <tom.francart@med.kuleuven.be>            *
 *                                                                            *
 * This file is part of APEX 3.                                               *
 *                                                                            *
 * APEX 3 is free software: you can redistribute it and/or modify             *
 * it under the terms of the GNU General Public License as published by       *
 * the Free Software Foundation, either version 2 of the License, or          *
 * (at your option) any later version.                                        *
 *                                                                            *
 * APEX 3 is distributed in the hope that it will be useful,                  *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 * GNU General Public License for more details.                               *
 *                                                                            *
 * You should have received a copy of the GNU General Public License          *
 * along with APEX 3.  If not, see <http://www.gnu.org/licenses/>.            *
 *****************************************************************************/

#ifndef APEXRANDOMGENERATORPARAMETERS_H
#define APEXRANDOMGENERATORPARAMETERS_H

#include "global.h"

#include "parameters/apexparameters.h"

#include <qstring.h>

namespace apex
{

class RandomGenerator;
class UniformRandomGenerator;
class GaussianRandomGenerator;
class RandomGeneratorFactory;

namespace data
{
/**
@author Tom Francart,,,
*/
class APEXDATA_EXPORT RandomGeneratorParameters : public data::ApexParameters
{
    public:
        RandomGeneratorParameters();

        ~RandomGeneratorParameters();

        virtual bool Parse(XERCES_CPP_NAMESPACE::DOMElement* p_paramElement=0);

        enum {TYPE_UNIFORM, TYPE_GAUSSIAN};
        enum {VALUE_INT, VALUE_DOUBLE};
        
        bool operator==(const RandomGeneratorParameters& other) const;

    protected:
        virtual bool SetParameter(const QString& , const QString& , const QString& , XERCES_CPP_NAMESPACE::DOMElement*);


        friend class apex::RandomGenerator;
        friend class apex::UniformRandomGenerator;
        friend class apex::GaussianRandomGenerator;
        friend class apex::RandomGeneratorFactory;

    protected:
        double m_dMin;
        double m_dMax;
        QString m_sParam;           // parameter to be set by this generator
        int m_nType;
        int m_nValueType;

};

}
}

#endif
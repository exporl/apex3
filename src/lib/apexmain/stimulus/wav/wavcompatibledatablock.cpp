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
 
#include "wavcompatibledatablock.h"
#include "stimulus/wav/streamgenerator.h"
#include "stimulus/datablock.h"
#include "file/wavefile.h"
#include "silentreader.h"
#include "datablock/datablockdata.h"

#include <qstring.h>

using namespace apex;
using namespace stimulus;
using namespace streamapp;

WavCompatibleDataBlock::WavCompatibleDataBlock(const data::DatablockData& data,
                                               const QUrl& filename,
                                               const ExperimentRunDelegate* experiment) :
    DataBlock(data, filename, experiment)
{
}

WavCompatibleDataBlock::~WavCompatibleDataBlock() {}

void WavCompatibleDataBlock::SetParameter( const QString& ac_sID, const QString& ac_sVal )
{
  if( ac_sID == "loop" )
    this->data.setNbLoops(ac_sVal.toUInt());
  else
    DataBlock::SetParameter( ac_sID, ac_sVal );
}



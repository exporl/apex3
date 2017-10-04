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

#ifndef _EXPORL_SRC_LIB_APEXMAIN_RESULTSINK_RESULTVIEWER_H_
#define _EXPORL_SRC_LIB_APEXMAIN_RESULTSINK_RESULTVIEWER_H_

#include "apextools/global.h"

#include <QUrl>

namespace apex
{
namespace data
{
class ResultParameters;
}

class RTResultSink;

class APEX_EXPORT ResultViewer : public QObject
{
    Q_OBJECT
public:
    ResultViewer(const data::ResultParameters *p_param,
                 const QString &p_resultfile);
    void show(bool ask);
    bool addtofile(const QString &p_filename);

    ~ResultViewer();

Q_SIGNALS:
    void viewClosed();

private Q_SLOTS:
    void loadingFinished(bool ok);

private:
    bool findResultPage();

    const data::ResultParameters *m_pParam;
    QString m_sResultfile;
    QUrl m_resultPagePath;
    QScopedPointer<RTResultSink> rtResultSink;
};
}

#endif
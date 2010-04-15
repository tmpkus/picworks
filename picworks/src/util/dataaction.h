//
// Copyright (C) 2006-2009  by the original authors of Galaxy
// and all its contributors ("Galaxy.org").
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

/*!
  \file dataaction.h
  \ingroup Utilities
  \brief This file contains
  - class Action::DataAction declaration
  \author Cheng Liang <changliang.soft@gmail.com>
  \date 2009-11-26 Created.
 */

#ifndef DATAACTION_H
#define DATAACTION_H

#include <QAction>

class QVariant;

namespace Action {

class DataAction : public QAction
{
    Q_OBJECT

public:

    DataAction(const QVariant &data, QObject * parent = 0);

    virtual ~DataAction();

signals:

    void actionPerformed(const QVariant &data);

private slots:

    void actionTriggered();

}; // end of class

} // end of namespace

#endif // DATAACTION_H

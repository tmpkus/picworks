//
// Copyright (C) 2006-2010  by the original authors of Galaxy
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
  \file actionmanager.h
  \ingroup Utilities
  \brief This file contains
  - class Core::ActionManager declaration
  \author Cheng Liang <changliang.soft@gmail.com>
  \date 2010-4-18 Created.
 */

#ifndef ACTIONMANAGER_H
#define ACTIONMANAGER_H

#include <QObject>

namespace Core {

class ActionContainer;

class ActionManager : public QObject
{
public:
    ActionManager(QObject * parent = 0) : QObject(parent) {}
    ~ActionManager() {}

    ActionContainer * createMenuBar(const QString & id);

}; // end of class

} // end of namespace

#endif // ACTIONMANAGER_H

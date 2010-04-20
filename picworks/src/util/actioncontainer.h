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
  \file actioncontainer.h
  \ingroup Utilities
  \brief This file contains
  - class Core::ActionContainer declaration
  - class Core::MenuBarActionContainer declaration
  \author Cheng Liang <changliang.soft@gmail.com>
  \date 2010-4-19 Created.
 */

#ifndef ACTIONCONTAINER_H
#define ACTIONCONTAINER_H

#include <QObject>

class QMenuBar;

namespace Core {

class ActionContainer : public QObject
{
public:
    enum {
        COMP_MENUBAR,
        COMP_TOOLBOX
    };
    ActionContainer();
    virtual ~ActionContainer() {}

}; // end of class ActionContainer

class MenuBarActionContainer : public ActionContainer
{
public:
    MenuBarActionContainer();
    ~MenuBarActionContainer() {}

    QMenuBar * menuBar() { return mb; }

private:
    QMenuBar *mb;
}; // end of class MenuBarActionContainer

} // end of namespace

#endif // ACTIONCONTAINER_H

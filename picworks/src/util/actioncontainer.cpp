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
  \file actioncontainer.cpp
  \ingroup Utilities
  \brief This file contains
  - class Core::ActionContainer implemtation
  - class Core::MenuActionContainer implemtation
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2010-4-19 Created.
 */

#include "actioncontainer.h"

/*!
  \class Core::ActionContainer actioncontainer.h
  \brief Base class of all action containers.
  An action container maybe a UI component that actions can be added to,
  such as a menu bar or tool box.
  \version 0.0.1
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2010-4-20 Created.
 */

Core::ActionContainer::ActionContainer()
{
}

/*!
  \class Core::MenuBarActionContainer actioncontainer.h
  \brief The action container for menu bar.
  \version 0.0.1
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2010-4-20 Created.
 */

/*!
  \fn QMenuBar * Core::MenuBarActionContainer::menuBar()
  \brief Gets the menu bar managed by the container.
  \return menu bar
 */

Core::MenuBarActionContainer::MenuBarActionContainer()
{
    mb = new QMenuBar;
}

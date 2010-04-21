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
  \file action.cpp
  \ingroup Utilities
  \brief This file contains
  - class Core::Action implemtation
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2010-4-21 Created.
 */

#include "action.h"

/*!
  \class Core::Action action.h
  \brief Action wrapper used in PicWorks.
  \version 0.0.1
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2010-4-21 Created.
 */

/*!
  \fn QAction* Core::Action::action() const
  \brief Gets action used inside.
  \return action inside

  \fn void Core::Action::setAction(QAction *a)
  \brief Sets inside action.
  \param a action inside

  \fn QVariant Core::Action::data()
  \brief Gets data related to action.
  \return data related to this action

  \fn void Core::Action::setData(const QVariant &d)
  \brief Sets data.
  \param d data added into this action

  \fn void Core::Action::setText(const QString &text)
  \brief Sets text displayed on UI components
  \param text text to be set
 */

Core::Action::Action(QAction *a /* = 0 */)
    : qa(a)
{
}

Core::Action::~Action()
{
    if(qa) {
        delete qa;
        qa = NULL;
    }
}

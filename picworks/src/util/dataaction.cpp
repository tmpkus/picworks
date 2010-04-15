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
  \file dataaction.cpp
  \ingroup Utilities
  \brief This file contains
  - class Action::DataAction implemtation
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2009-11-26 Created.
 */

#include <QVariant>

#include "dataaction.h"
#include "appcontext.h"

#include "../view/commonbar.h"

using namespace Action;

/*!
  \class Action::DataAction dataaction.h
  \brief This is the action which contains data, such as \a AppResource::Action.
  \version 0.0.1
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2009-11-26 Created.
 */

/*!
  \fn void Action::DataAction::actionPerformed(const QVariant &data)
  \brief Signal when action triggered.
  \param data data related to this action
 */

/*!
  \brief Construct an action.
  This action is quite like \a QAction except it must have data, that is, data
  have to be set. When this action is triggered, \a AppContext function \a setCurrentAction
  will be invoked as callback function.
  \param d data related to this action
  \param parent parent object pointer, default is 0
 */
DataAction::DataAction(const QVariant &d, QObject * parent /* = 0 */)
        : QAction(parent)
{
    setData(d);

    connect(this, SIGNAL(triggered()), this, SLOT(actionTriggered()));
    connect(this, SIGNAL(actionPerformed(const QVariant &)), &AppCtx, SLOT(setCurrentAction(const QVariant &)));
    connect(this, SIGNAL(actionPerformed(const QVariant &)), &View::CommonBar::instance(), SLOT(createCommonBar(const QVariant &)));
}

/*!
  \brief Destructs this action.
 */
DataAction::~DataAction()
{
}

/*!
  \brief When the action triggered, this function will be called.
  A signal \a actionPerformed will be emited if the action is triggered.
 */
void DataAction::actionTriggered()
{
    emit actionPerformed(data());
}

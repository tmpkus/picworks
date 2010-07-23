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
  \file actionmanager.cpp
  \ingroup Core
  \brief This file contains
  - class Core::ActionManager implemtation
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2010-4-17 Created.
 */

#include <QAction>
#include <QString>
#include <QMenuBar>
#include <QToolBar>
#include <QIcon>

#include "actionmanager.h"
#include "appresource.h"
#include "idmanager.h"
#include "constants.h"
#include "commonbar.h"

/*!
  \class Core::ActionManager actionmanager.h
  \brief Application action manager.
  Action manager is a manager for actions. Actions and action containers
  can be added into this manager. Also it is easy to get containers in order to
  add more actions. Action containers may be a menu, a tool bar or something else.
  \version 0.0.1
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2009-10-14 Created.
 */

Core::ActionManager::ActionManager()
    : idManager(Core::Singleton<Core::IdManager>::instance()),
      mb(new QMenuBar)
{
    // insert action containers
    int tbUid = idManager->uid(Core::ID::TOOL_BAR);
    toolBarMap.insert(tbUid, new QToolBar);
    int tbxUid = idManager->uid(Core::ID::TOOL_BOX);
    toolBarMap.insert(tbxUid, new QToolBar);
    int cbUid = idManager->uid(Core::ID::COMMON_BAR);
    toolBarMap.insert(cbUid, new Ui::CommonBar);
}

QMenuBar * Core::ActionManager::menuBar(const QString & id /* = QString("mb") */)
{
    Q_UNUSED(id)
    return mb;
}

/*!
  \brief Gets the menu related to given id.
  \param id id of a menu
  \param text menu text
  \return menu with the given id
 */
QMenu * Core::ActionManager::menu(const QString & id, const QString & text /* = QString() */)
{
    int uid = idManager->uid(id);
    const QHash<int, QMenu *>::const_iterator it = menuMap.constFind(uid);
    if(it == menuMap.constEnd()) {
        QMenu * menu = new QMenu(text);
        menuMap.insert(uid, menu);
        return menu;
    }
    return it.value();
}

/*!
  \brief Gets the tool bar related to given id.
  \param id id of a tool bar
  \return tool bar with the given id
 */
QToolBar * Core::ActionManager::toolBar(const QString & id)
{
    int uid = idManager->uid(id);
    const QHash<int, QToolBar *>::const_iterator it = toolBarMap.constFind(uid);
    if(it == toolBarMap.constEnd()) {
        return NULL;
    }
    return it.value();
}

/*!
  \brief Register an action to action manager.
  \param id string id related this action
  \param act action to insert
  \return action registered
 */
QAction * Core::ActionManager::registerAction(const QString & id, QAction * act)
{
    int uid = idManager->uid(id);
    QAction *action = actionMap.value(uid, 0);
    if(!action) {
        actionMap.insert(uid, act);
    }
    return act;
}

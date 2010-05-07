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

#include "actionmanager.h"
#include "actioncontainer.h"
#include "appresource.h"
#include "idmanager.h"
#include "action.h"
#include "constants.h"

/*!
  \class Core::ActionManager actionmanager.h
  \brief Application action manager.
  <p>Actions used in PicWorks should be added into this manager. This manager
  should not get instance by using new operater, call
  \a appCtx.actionManager() instead.
  Almost all actions that can be added into main window should be managed by
  this manager.</p>
  <p>If you want to add menus into menu bar, you can follow code shown below.
  \code
  // use ActionManager to get menu bar instance
  ActionContainer *mbc = actionManager->actionContainer(Core::AppResource::DEFAULT_MENUBAR);
  // register actions
  Core::Action *a = actionManager->registerAction(Core::AppResource::MENU_ITEM_NEW, new QAction);
  // register menus
  Core::ActionContainer *mc = actionManager->createMenu(Core::AppResource::MENU_FILE, tr("&File"));
  // add actions to menus
  mc->addAction(a);
  // add menus to menu bar
  mbc->addMenu(mc);
  \endcode</p>
  \version 0.0.1
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2009-10-14 Created.
 */

Core::ActionManager::ActionManager()
{
    // insert menu bar
    int mbUid = idManager->uid(ID->compMenuBar());
    containerMap.insert(mbUid, new Core::MenuBarActionContainer);
    int tbUid = idManager->uid(ID->compToolBar());
    containerMap.insert(tbUid, new Core::ToolBarActionContainer);
}

/*!
  \brief Gets the action container related to given id.
  \param id id of action container
  \return action container with the given id
 */
Core::ActionContainer * Core::ActionManager::actionContainer(const QString &id)
{
    int uid = idManager->uid(id);
    const QHash<int, ActionContainer *>::const_iterator it = containerMap.constFind(uid);
    if(it == containerMap.constEnd()) {
        qDebug() << "ActionManager cannot find action container with id " << id;
        return NULL;
    }
    return it.value();
}

/*!
  \brief Register menu into this container.
  \param sid string id of this menu
  \return menu action container added
 */
Core::ActionContainer * Core::ActionManager::createMenu(const QString &sid,
                                                        const QString &text /* = QString() */)
{
    Core::ActionContainer *mc = actionContainer(sid);
    if(!mc) {
        int uid = idManager->uid(sid);
        mc = new Core::MenuActionContainer;
        mc->setText(text);
        containerMap.insert(uid, mc);
    }
    return mc;
}

/*!
  \brief Register action into action manager.
  \param id string id related this action
  \param a action
  \return action wrapper
 */
Core::Action* Core::ActionManager::registerAction(const QString &id, QAction *a)
{
    int uid = idManager->uid(id);
    Core::Action *action = actionMap.value(uid, 0);
    if(!action) {
        action = new Core::Action(a);
        actionMap.insert(uid, action);
    }
    return action;
}

/*!
  \brief Gets registered action with string id \a id.
  \param id string id of this action
  \return action, NULL if
 */
Core::Action* Core::ActionManager::action(const QString &id)
{
    return actionMap.value(idManager->uid(id), NULL);
}

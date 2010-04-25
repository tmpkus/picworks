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

#include <QMenu>
#include <QMenuBar>

#include "action.h"
#include "actioncontainer.h"

/*!
  \class Core::ActionContainer actioncontainer.h
  \brief Base class of all action containers.
  An action container maybe a UI component that actions can be added to,
  such as a menu bar or tool box.
  \version 0.0.1
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2010-4-20 Created.

  \fn virtual void Core::ActionContainer::addAction(Core::Action *a) = 0
  \brief Adds an action into this container.
  \param a action to be added

  \fn virtual Core::Action* Core::ActionContainer::addMenu(ActionContainer * c, Core::Action *a = NULL) = 0
  \brief Adds menu into menu bar.
  \param c action container added
  \param a insert container before action \a a

  \fn virtual void Core::ActionContainer::setText(const QString &text) = 0;
  \brief Sets the text displayed on menu.
  \param text text displayed

  \fn virtual QMenu * Core::ActionContainer::menu() = 0;
  \brief Gets menu wrapped.
  \return the menu wrapped inside

  \fn virtual QMenuBar * Core::ActionContainer::menuBar() = 0
  \brief Gets menu bar wrapped.
  \return the menu bar wrapped inside
 */

Core::ActionContainer::ActionContainer()
{
}

/*!
  \class Core::MenuActionContainer actioncontainer.h
  \brief The action container for menu.
  \version 0.0.1
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2010-4-20 Created.
 */

/*!
  \fn QMenu * Core::MenuActionContainer::menu()
  \brief Gets the menu managed by the container.
  \return menu
 */

Core::MenuActionContainer::MenuActionContainer()
{
    m = new QMenu;
}

/*!
  \brief Adds action to menu.
  \param a action
 */
void Core::MenuActionContainer::addAction(Core::Action *a)
{
    m->addAction(a->action());
}

/*!
  \brief Adds submenu to menu.
  Menu can be added only if the action container is a MenuActionContainer.
  \param c action container
  \param before insert container before action \a before
 */
Core::Action* Core::MenuActionContainer::addMenu(ActionContainer *c,
                                                 Core::Action *before /* = NULL */)
{
    Core::MenuActionContainer *mc = dynamic_cast<Core::MenuActionContainer *>(c);
    QAction *qa = NULL;
    if(mc) {
        qa = before ? m->insertMenu(before, mc->menu()) : m->addMenu(mc->menu());
    }
    return new Core::Action(qa);
}

/*!
  \brief Sets the text of the menu.
  \param text text displayed on menu
 */
void Core::MenuActionContainer::setText(const QString &text)
{
    m->setTitle(text);
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

/*!
  \brief Adds menu to menu bar.
  Menu can be added only if the action container is a MenuActionContainer.
  \param c action container
  \param before insert this contanier before action \a before
 */
Core::Action* Core::MenuBarActionContainer::addMenu(ActionContainer *c,
                                                    Core::Action *before /* = NULL */)
{
    Core::MenuActionContainer *mc = dynamic_cast<Core::MenuActionContainer *>(c);
    QAction *qa = NULL;
    if(mc) {
        qa = before ? m->insertMenu(before, mc->menu()) : m->addMenu(mc->menu());
    }
    return new Core::Action(qa);
}

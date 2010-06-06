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
  \ingroup Core
  \brief This file contains
  - class Core::ActionContainer declaration
  - class Core::MenuActionContainer declaration
  - class Core::MenuBarActionContainer declaration
  \author Cheng Liang <changliang.soft@gmail.com>
  \date 2010-4-19 Created.
 */

#ifndef ACTIONCONTAINER_H
#define ACTIONCONTAINER_H

#include <QObject>
#include <QDebug>

class QMenuBar;
class QMenu;
class QToolBar;

namespace Core {

class Action;

class ActionContainer : public QObject
{
public:
    ActionContainer() {}
    virtual ~ActionContainer() {}

    virtual void addAction(Core::Action *a)
    {
        qWarning() << "class does not support addAction(Core::Action *)";
    }

    virtual Core::Action* addMenu(ActionContainer * c, Core::Action *a = NULL)
    {
        qWarning() << "class does not support addMenu(ActionContainer *, Core::Action *)";
        return NULL;
    }

    virtual void setText(const QString &text)
    {
        qWarning() << "class does not support setText(const QString &)";
    }

    virtual void addSeparator()
    {
        qWarning() << "class does not support addSeparator()";
    }

    virtual QMenu * menu()
    {
        qWarning() << "class does not support menu()";
        return NULL;
    }

    virtual QMenuBar * menuBar()
    {
        qWarning() << "class does not support menuBar()";
        return NULL;
    }

    virtual QToolBar * toolBar()
    {
        qWarning() << "class does not support toolBar()";
        return NULL;
    }

}; // end of class ActionContainer

class MenuActionContainer : public ActionContainer
{
public:
    MenuActionContainer();
    ~MenuActionContainer() {}

    QMenu * menu() { return m; }
    void addAction(Core::Action *a);
    void setText(const QString &text);
    Core::Action* addMenu(ActionContainer * c, Core::Action *a = NULL);
    void addSeparator();
private:
    QMenu *m;
}; // end of class MenuActionContainer

class MenuBarActionContainer : public ActionContainer
{
public:
    MenuBarActionContainer();
    ~MenuBarActionContainer() {}

    QMenuBar * menuBar() { return mb; }
    Core::Action* addMenu(ActionContainer * c, Core::Action *a = NULL);
    void addSeparator();
private:
    QMenuBar *mb;
}; // end of class MenuBarActionContainer

class ToolBarActionContainer : public ActionContainer
{
public:
    ToolBarActionContainer();
    ~ToolBarActionContainer() {}

    QToolBar * toolBar() { return tb; }
    void addAction(Core::Action *a);
    void addSeparator();
private:
    QToolBar *tb;
};

} // end of namespace

#endif // ACTIONCONTAINER_H

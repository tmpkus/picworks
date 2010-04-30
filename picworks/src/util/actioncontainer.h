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
  - class Core::MenuActionContainer declaration
  - class Core::MenuBarActionContainer declaration
  \author Cheng Liang <changliang.soft@gmail.com>
  \date 2010-4-19 Created.
 */

#ifndef ACTIONCONTAINER_H
#define ACTIONCONTAINER_H

#include <QObject>

class QMenuBar;
class QMenu;

namespace Core {

class Action;

class ActionContainer : public QObject
{
public:
    enum {
        ACTION,
        SEPERATOR
    };
    
    ActionContainer();
    virtual ~ActionContainer() {}

    virtual void addAction(Core::Action *a) = 0;
    virtual Core::Action* addMenu(ActionContainer * c, Core::Action *a = NULL) = 0;
    virtual void setText(const QString &text) = 0;
    virtual void addSeparator() = 0;
    virtual QMenu * menu() = 0;
    virtual QMenuBar * menuBar() = 0;
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

    QMenuBar * menuBar()
    {
        qDebug() << "This class does not support menuBar().";
        return NULL;
    }
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

    void addAction(Core::Action *a)
    {
        qDebug() << "This class does not support setText(Core::Action *).";
    }

    void setText(const QString &text)
    {
        qDebug() << "This class does not support setText(const QString &).";
    }

    QMenu * menu()
    {
        qDebug() << "This class does not support menu().";
        return NULL;
    }
private:
    QMenuBar *mb;
}; // end of class MenuBarActionContainer

class ToolBarActionContainer : public ActionContainer
{

};

} // end of namespace

#endif // ACTIONCONTAINER_H

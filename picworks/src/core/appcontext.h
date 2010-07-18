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
  \file appcontext.h
  \ingroup Core
  \brief This file contains
  - class Core::AppContext declaration
  \author Cheng Liang <changliang.soft@gmail.com>
  \date 2009-10-13 Created.
 */

#ifndef APPCONTEXT_H
#define APPCONTEXT_H

#include <QObject>
#include <QVariant>

#include "appresource.h"
#include "singleton.h"
#include "actionmanager.h"
#include "../ui/mainwindow.h"

#define appCtx (Core::Singleton<Core::AppContext>::instance())

class QColor;

namespace Core {

class ActionManager;

class AppContext : public QObject
{
    Q_OBJECT

public:
    AppContext();

    ~AppContext() {}

    inline const QString & version() const { return appVersion; }

    //inline Action currentAction() const { return currAction; }

    inline const QColor & penColor() const { return pColor; }

    inline int penWidth() const { return pWidth; }

    inline int maxPenWidth() const { return maxPWidth; }

    inline ActionManager * actionManager() const { return actMgr; }

    inline Ui::MainWindow * mainWindow() const { return win; }

    inline void setMainWindow(Ui::MainWindow * mw)
    {
        if(win != mw) {
            win = mw;
        }
    }

public slots:
    inline void setCurrentAction(const QVariant & data)
    {
//        if(data.canConvert(QVariant::Int)) {
//            Action a = static_cast<Action>(data.toInt());
//            if(currAction != a) {
//                emit currentActionChanged(a, currAction);
//                currAction = a;
//            }
//        }
    }

    inline void setPenColor(const QColor &c)
    {
        if(c != pColor) {
            emit penColorChanged(c, pColor);
            pColor = c;
        }
    }

    inline void setPenWidth(int w)
    {
        if(w != pWidth) {
            emit penWidthChanged(w, pWidth);
            pWidth = w;
        }
    }

    inline void setMaxPenWidth(int mw)
    {
        if(mw != maxPWidth) {
            emit maxPenWidthChanged(mw, maxPWidth);
            maxPWidth = mw;
        }
    }

signals:
    //void currentActionChanged(const Action & newCurrAction, const Action & oldCurrAction);
    void penColorChanged(const QColor & newColor, const QColor & oldColor);
    void penWidthChanged(int newWidth, int oldWidth);
    void maxPenWidthChanged(int newValue, int oldValue);

private:
    QString appVersion;
    //Action currAction;
    QColor pColor;
    int pWidth;
    int maxPWidth;
    Ui::MainWindow * win;
    ActionManager *actMgr;

}; // end of class

} // end of namespace

#endif // APPCONTEXT_H

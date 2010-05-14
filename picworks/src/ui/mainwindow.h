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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "ui_global.h"

class QMdiArea;
class QLabel;
class QDockWidget;

namespace Core {
    class ActionManager;
};

namespace Ui {

class UISHARED_EXPORT MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    //------------------------------
    // fields
    //------------------------------
    Core::ActionManager *actionManager;
    QMdiArea *mdiArea;
    QLabel *statusLabel;
    QDockWidget *dockSet;

    //------------------------------
    // private functions
    //------------------------------
    void createActions();
    void createMenus();
    void createStatusBar();
    void createDockPanels();
    void createToolBar();
    void establishConnections();

private slots:
    void showProjectCreateDialog();
    void showAboutDialog();
};

}

#endif // MAINWINDOW_H

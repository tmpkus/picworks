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

class QMdiArea;
class QLabel;
class QDockWidget;
class QToolButton;

namespace Core {
    class Action;
    class ActionManager;
    class Project;
};

namespace Ui {

class MainWindow : public QMainWindow
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

    Core::Action *newAction;
    Core::Action *openAction;
    Core::Action *saveAction;
    Core::Action *saveAsAction;
    Core::Action *saveAllAction;
    Core::Action *printAction;
    Core::Action *exitAction;
    Core::Action *undoAction;
    Core::Action *redoAction;
    Core::Action *cutAction;
    Core::Action *copyAction;
    Core::Action *pasteAction;
    Core::Action *preferencesAction;
    Core::Action *helpAction;
    Core::Action *aboutAction;
    Core::Action *selectToolAction;
    Core::Action *moveToolAction;
    Core::Action *brushToolAction;
    Core::Action *eraserToolAction;
    Core::Action *paintCanToolAction;
    Core::Action *textToolAction;
    Core::Action *lineToolAction;
    Core::Action *curveToolAction;
    Core::Action *ellipseToolAction;
    Core::Action *polygonToolAction;
    Core::Action *rectangleToolAction;
    Core::Action *roundRectangleToolAction;

    //------------------------------
    // private functions
    //------------------------------
    void createActions();
    void createMenus();
    void createStatusBar();
    void createDockPanels();
    void createToolBar();
    void createToolBox();
    void establishConnections();
    QToolButton * createToolButton(Core::Action *action, QWidget *parent = 0);

private slots:
    void showProjectCreateDialog();
    void showAboutDialog();
    void showOpenDialog();
    void addProjectWindow(Core::Project *pro);
};

}

#endif // MAINWINDOW_H

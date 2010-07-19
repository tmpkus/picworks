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
class QAction;
class QLabel;
class QDockWidget;
class QToolButton;
class QSignalMapper;

namespace Core {
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
    QSignalMapper *mapper;
    QMdiArea *mdiArea;
    QLabel *statusLabel;
    QDockWidget *dockSet;

    QAction *newAction;
    QAction *openAction;
    QAction *saveAction;
    QAction *saveAsAction;
    QAction *saveAllAction;
    QAction *printAction;
    QAction *exitAction;
    QAction *undoAction;
    QAction *redoAction;
    QAction *cutAction;
    QAction *copyAction;
    QAction *pasteAction;
    QAction *preferencesAction;
    QAction *helpAction;
    QAction *aboutAction;
    QAction *selectToolAction;
    QAction *moveToolAction;
    QAction *brushToolAction;
    QAction *eraserToolAction;
    QAction *paintCanToolAction;
    QAction *textToolAction;
    QAction *lineToolAction;
    QAction *curveToolAction;
    QAction *ellipseToolAction;
    QAction *polygonToolAction;
    QAction *rectangleToolAction;
    QAction *roundRectangleToolAction;

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
    QToolButton * createToolButton(QAction *action, QWidget *parent = 0);

private slots:
    void showProjectCreateDialog();
    void showAboutDialog();
    void showOpenDialog();
    void addProjectWindow(Core::Project *pro);
    void toolBoxActionTriggered(QString);
};

}

#endif // MAINWINDOW_H

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
  \file mainwindow.h
  \ingroup View
  \brief This file contains
  - class View::MainWindow declaration
  \author Cheng Liang <changliang.soft@gmail.com>
  \date 2009-9-5 Created.
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QAction;
class QActionGroup;
class QMenu;
class QToolBar;
class QLabel;
class QMdiArea;
class QToolButton;
class QDockWidget;
class QCloseEvent;

namespace Data {
    class Project;
};

namespace Action {
    class DataAction;
};

namespace Core {
    class ActionManager;
};

namespace Ext {
    class QtWindowListMenu;
};

namespace View {

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    QMenu* createPopupMenu();
    void closeEvent(QCloseEvent * event);

private:
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
    Action::DataAction *lineToolAction;
    Action::DataAction *curveToolAction;
    Action::DataAction *ellipseToolAction;
    Action::DataAction *polygonToolAction;
    Action::DataAction *rectangleToolAction;
    Action::DataAction *roundRectangleToolAction;

    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *toolsMenu;
    Ext::QtWindowListMenu *subwindowMenu;
    QMenu *helpMenu;

    QActionGroup *toolBoxActionGroup;

    QToolBar *toolBar;
    QToolBar *toolBox;
    QToolBar *commonBar;

    QLabel *statusLabel;

    QDockWidget *dockPanelsSet;

    QMdiArea *mdiArea;

    Core::ActionManager *actionManager;

    void createActions();
    void createMenus();
    void createToolBars();
    void createStatusBar();
    void createDockPanelsSet();
    void establishConnections();
    void writeSettings();
    void readSettings();
    QToolButton * createToolButton(QAction *action);

private slots:
    void showProjectCreateDialog();
    void showAboutDialog();
    void showPreferencesDialog();
    void showFileOpenDialog();
    void getProject(Data::Project & project);

}; // end of class

} // end of namespace

#endif // MAINWINDOW_H

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
  \class Ui::MainWindow mainwindow.h
  \brief Main window of PicWorks.
  This is the main application window of PicWorks. PicWorks default main window is a MDI
  (Multiple Document Interface) window which can open many documents at the same time.
  \note There should be only one application window running at the same time.
  \version 0.0.1
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2009-9-5 Created.
  \date 2010-5-3 move from View namespace to Ui
 */

#include <QAction>
#include <QMdiArea>
#include <QMenu>
#include <QMenuBar>
#include <QLabel>
#include <QStatusBar>
#include <QDockWidget>
#include <QToolBar>

#include "QtWindowListMenu"
#include "appcontext.h"
#include "appresource.h"
#include "mainwindow.h"
#include "constants.h"
#include "actioncontainer.h"
#include "projectcreator.h"
#include "action.h"
#include "aboutdialog.h"
#include "projectwindow.h"

/*!
  \brief Constructor.
  Creates a new MainWindow instance.
  \param parent parent widget of this window, default value is \a NULL
 */
Ui::MainWindow::MainWindow(QWidget *parent /* = NULL */)
    : QMainWindow(parent)
{
    setWindowIcon(appRes->icon(Core::AppResource::ApplicationIcon));
    setWindowTitle(tr("PicWorks v%1", "Main window title with version number.").arg(appCtx->version()));

    actionManager = appCtx->actionManager();

    mdiArea = new QMdiArea;
    setCentralWidget(mdiArea);

    createActions();
    createMenus();
    createStatusBar();
    createDockPanels();
    createToolBar();
    establishConnections();
}

/*!
  \brief Destructor.
  Destructs a main window.
 */
Ui::MainWindow::~MainWindow()
{

}

void Ui::MainWindow::createMenus()
{
    Core::ActionContainer *menuBarContainer = actionManager->actionContainer(ID->compMenuBar());
    QMenuBar *mb = menuBarContainer->menuBar();
#ifndef Q_WS_MAC // System menu bar on Mac
    setMenuBar(mb);
#endif
    Core::ActionContainer *fileMenu = actionManager->createMenu(ID->menuFile(), tr("&File", "[File] on menu bar."));
    fileMenu->addAction(actionManager->action(ID->actionNew()));
    fileMenu->addAction(actionManager->action(ID->actionOpen()));
    fileMenu->addSeparator();
    fileMenu->addAction(actionManager->action(ID->actionSave()));
    fileMenu->addAction(actionManager->action(ID->actionSaveAs()));
    fileMenu->addAction(actionManager->action(ID->actionSaveAll()));
    fileMenu->addSeparator();
    fileMenu->addAction(actionManager->action(ID->actionPrint()));
    fileMenu->addSeparator();
    fileMenu->addAction(actionManager->action(ID->actionExit()));
    mb->addMenu(fileMenu->menu());

    Core::ActionContainer *editMenu = actionManager->createMenu(ID->menuEdit(), tr("&Edit", "[Edit] on menu bar."));
    editMenu->addAction(actionManager->action(ID->actionUndo()));
    editMenu->addAction(actionManager->action(ID->actionRedo()));
    editMenu->addSeparator();
    editMenu->addAction(actionManager->action(ID->actionCut()));
    editMenu->addAction(actionManager->action(ID->actionCopy()));
    editMenu->addAction(actionManager->action(ID->actionPaste()));
    mb->addMenu(editMenu->menu());

    Core::ActionContainer *toolMenu = actionManager->createMenu(ID->menuTool(), tr("&Tools", "[Tools] on menu bar."));
    Core::ActionContainer *langMenu = actionManager->createMenu(ID->menuLang(), tr("Languages", "[Language] under menu [Tool]"));
    toolMenu->addMenu(langMenu);
    toolMenu->addAction(actionManager->action(ID->actionOpenReference()));
    mb->addMenu(toolMenu->menu());

    QtWindowListMenu *subwindowMenu = new QtWindowListMenu;
    subwindowMenu->attachToMdiArea(mdiArea);
    subwindowMenu->setCascadeIcon(appRes->icon(Core::AppResource::CascadeIcon));
    subwindowMenu->setTileIcon(appRes->icon(Core::AppResource::TileIcon));
    mb->addMenu(subwindowMenu);

    mb->addSeparator();

    Core::ActionContainer *helpMenu = actionManager->createMenu(ID->menuHelp(), tr("&Help", "[Help] on menu bar."));
    helpMenu->addAction(actionManager->action(ID->actionOpenHelp()));
    helpMenu->addAction(actionManager->action(ID->actionOpenAbout()));
    mb->addMenu(helpMenu->menu());
}

/*!
  \internal
  \brief Creates actions used in application.
 */
void Ui::MainWindow::createActions()
{
    // Common Actions
    QAction *newAction = new QAction(tr("&New...", "[New] action text."), this);
    newAction->setIcon(appRes->icon(Core::AppResource::NewIcon));
    newAction->setShortcut(QKeySequence::New);
    newAction->setStatusTip(tr("Create a new image file.", "[New] action tip on status bar."));
    actionManager->registerAction(ID->actionNew(), newAction);

    QAction *openAction = new QAction(tr("&Open...", "[Open] action text."), this);
    openAction->setIcon(appRes->icon(Core::AppResource::OpenIcon));
    openAction->setShortcut(QKeySequence::Open);
    openAction->setStatusTip(tr("Open an image file.", "[Open] action tip on status bar."));
    actionManager->registerAction(ID->actionOpen(), openAction);

    QAction *saveAction = new QAction(tr("&Save", "[Save] action text."), this);
    saveAction->setIcon(appRes->icon(Core::AppResource::SaveIcon));
    saveAction->setShortcut(QKeySequence::Save);
    saveAction->setStatusTip(tr("Save the project into a file.", "[Save] action tip on status bar."));
    actionManager->registerAction(ID->actionSave(), saveAction);

    QAction *saveAsAction = new QAction(tr("Save &As...", "[Save As] action text."), this);
    saveAsAction->setIcon(appRes->icon(Core::AppResource::SaveAsIcon));
    saveAsAction->setShortcut(QKeySequence::SaveAs);
    saveAsAction->setStatusTip(tr("Save the project as another file.", "[Save As] action tip on status bar."));
    actionManager->registerAction(ID->actionSaveAs(), saveAsAction);

    QAction *saveAllAction = new QAction(tr("Save &All", "[Save All] action text."), this);
    saveAllAction->setIcon(appRes->icon(Core::AppResource::SaveAllIcon));
    saveAllAction->setStatusTip(tr("Save all the projects.", "[Save All] action tip on status bar."));
    actionManager->registerAction(ID->actionSaveAll(), saveAllAction);

    QAction *printAction = new QAction(tr("&Print...", "[Print] action text."), this);
    printAction->setIcon(appRes->icon(Core::AppResource::PrintIcon));
    printAction->setShortcut(QKeySequence::Print);
    printAction->setStatusTip(tr("Print the project.", "[Print] action tip on status bar."));
    actionManager->registerAction(ID->actionPrint(), printAction);

    QAction *exitAction = new QAction(tr("E&xit", "[Exit] action text."), this);
    exitAction->setIcon(appRes->icon(Core::AppResource::ExitIcon));
    exitAction->setShortcut(tr("Ctrl+Q", "[Exit] action shortcut."));
    exitAction->setStatusTip(tr("Exit PicWorks.", "[Exit] action tip on status bar."));
    actionManager->registerAction(ID->actionExit(), exitAction);

    QAction *undoAction = new QAction(tr("&Undo", "[Undo] action text."), this);
    undoAction->setIcon(appRes->icon(Core::AppResource::UndoIcon));
    undoAction->setShortcut(QKeySequence::Undo);
    undoAction->setStatusTip(tr("Undo the last action.", "[Undo] action tip on status bar."));
    actionManager->registerAction(ID->actionUndo(), undoAction);

    QAction *redoAction = new QAction(tr("&Redo", "[Redo] action text."), this);
    redoAction->setIcon(appRes->icon(Core::AppResource::RedoIcon));
    redoAction->setShortcut(QKeySequence::Redo);
    redoAction->setStatusTip(tr("Redo the next action.", "[Redo] action tip on status bar."));
    actionManager->registerAction(ID->actionRedo(), redoAction);

    QAction *cutAction = new QAction(tr("Cu&t", "[Cut] action text."), this);
    cutAction->setIcon(appRes->icon(Core::AppResource::CutIcon));
    cutAction->setShortcut(QKeySequence::Cut);
    cutAction->setStatusTip(tr("Cut selected area.", "[Cut] action tip on status bar."));
    actionManager->registerAction(ID->actionCut(), cutAction);

    QAction *copyAction = new QAction(tr("&Copy", "[Copy] action text."), this);
    copyAction->setIcon(appRes->icon(Core::AppResource::CopyIcon));
    copyAction->setShortcut(QKeySequence::Copy);
    copyAction->setStatusTip(tr("Copy selected area.", "[Copy] action tip on status bar."));
    actionManager->registerAction(ID->actionCopy(), copyAction);

    QAction *pasteAction = new QAction(tr("&Paste", "[Paste] action text."), this);
    pasteAction->setIcon(appRes->icon(Core::AppResource::PasteIcon));
    pasteAction->setShortcut(QKeySequence::Paste);
    pasteAction->setStatusTip(tr("Paste the cut or copied area.", "[Paste] action tip on status bar."));
    actionManager->registerAction(ID->actionPaste(), pasteAction);

    QAction *preferencesAction = new QAction(tr("&Preferences...", "[Preferences] action text."), this);
    preferencesAction->setIcon(appRes->icon(Core::AppResource::PreferencesIcon));
    preferencesAction->setStatusTip(tr("Open preferences dialog.", "[Preferences] action tip on status bar."));
    actionManager->registerAction(ID->actionOpenReference(), preferencesAction);

    QAction *helpAction = new QAction(tr("&Help...", "[Help] action text."), this);
    helpAction->setIcon(appRes->icon(Core::AppResource::HelpIcon));
    helpAction->setShortcut(QKeySequence::HelpContents);
    helpAction->setStatusTip(tr("Open help contents.", "[Help] action tip on status bar."));
    actionManager->registerAction(ID->actionOpenHelp(), helpAction);

    QAction *aboutAction = new QAction(tr("&About...", "[About] action text."), this);
    aboutAction->setIcon(appRes->icon(Core::AppResource::AboutIcon));
    aboutAction->setStatusTip(tr("About PicWorks.", "[About] action tip on status bar."));
    actionManager->registerAction(ID->actionOpenAbout(), aboutAction);
}

/*!
  \internal
  \brief Creates status bars used in application.
 */
void Ui::MainWindow::createStatusBar()
{
    statusLabel = new QLabel(tr("Galaxy (C) PicWorks v%1", "Status bar startup label.").arg(appCtx->version()));
    statusLabel->setMinimumSize(statusLabel->sizeHint());

    statusBar()->addWidget(statusLabel);
    statusBar()->setStyleSheet(QString("QStatusBar::item{border: 0px}"));
}
/*!
  \internal
  \brief Creates function panel. The function panel is on the right edge of
  main window. Many panels such as layers and history operations will be added
  to this panel.
 */
void Ui::MainWindow::createDockPanels()
{
    dockSet = new QDockWidget(tr("Panels", "Title of dock panels."));
    dockSet->setObjectName("DockPanels");
    dockSet->setMinimumWidth(200);
    dockSet->setAllowedAreas(Qt::RightDockWidgetArea);
    QTabWidget *tabbedWidget = new QTabWidget;
    dockSet->setWidget(tabbedWidget);

    // add properties panels
    // layer preview panel
    // LayerPreviewPanel *layerPreviewPanel = new LayerPreviewPanel;
    // tabbedWidget->addTab(layerPreviewPanel, tr("Layer", "Layer panel title."));

    addDockWidget(Qt::RightDockWidgetArea, dockSet);
}

/*!
  \internal
  \brief Creates tool bar used in application.
 */
void Ui::MainWindow::createToolBar()
{
    Core::ActionContainer *toolBarContainer = actionManager->actionContainer(ID->compToolBar());
    QToolBar *toolBar = toolBarContainer->toolBar();
    toolBar->setObjectName("ToolBar");
    addToolBar(toolBar);

    toolBarContainer->addAction(actionManager->action(ID->actionNew()));
    toolBarContainer->addAction(actionManager->action(ID->actionOpen()));
    toolBarContainer->addAction(actionManager->action(ID->actionSave()));
    toolBarContainer->addSeparator();
    toolBarContainer->addAction(actionManager->action(ID->actionUndo()));
    toolBarContainer->addAction(actionManager->action(ID->actionRedo()));
    toolBarContainer->addSeparator();
    toolBarContainer->addAction(actionManager->action(ID->actionCut()));
    toolBarContainer->addAction(actionManager->action(ID->actionCopy()));
    toolBarContainer->addAction(actionManager->action(ID->actionPaste()));
    toolBarContainer->addSeparator();
    toolBarContainer->addAction(actionManager->action(ID->actionOpenReference()));
    toolBar->setIconSize(QSize(16, 16));
    addToolBarBreak();
}

/*!
  \internal
  \brief Establishes all connections.
 */
void Ui::MainWindow::establishConnections()
{
    connect(actionManager->action(ID->actionNew())->action(), SIGNAL(triggered()), this, SLOT(showProjectCreateDialog()));
    //connect(actionManager->action(ID->actionOpen())->action(), SIGNAL(triggered()), this, SLOT(showFileOpenDialog()));
    //connect(actionManager->action(Core::ID::Action::NEW), SIGNAL(triggered()), this, SLOT(showPreferencesDialog()));
    connect(actionManager->action(ID->actionOpenAbout())->action(), SIGNAL(triggered()), this, SLOT(showAboutDialog()));

    // connect(lineToolAction, SIGNAL(triggered()), AppCtx, SLOT(setCurrentAction()));
}

/*!
  \internal
  \brief Creates a new project.
  This slot will show a "new dialog" first, in order to get data from users
  and then try to construct a Project instance using \a getProject slot.
 */
void Ui::MainWindow::showProjectCreateDialog()
{
    ProjectCreator *pcd = new ProjectCreator(this); // Qt::WindowSystemMenuHint | Qt::WindowTitleHint
    // block...
    int rtn = pcd->exec();
    // get project
    if(rtn == QDialog::Accepted) {
        ProjectWindow * pw = new ProjectWindow(pcd->project());
        mdiArea->addSubWindow(pw);
        pw->show();
    }
    delete pcd;
}

/*!
  \internal
  \brief Shows the about dialog.
 */
void Ui::MainWindow::showAboutDialog()
{
    AboutDialog *ad = new AboutDialog(this);
    ad->exec();
}

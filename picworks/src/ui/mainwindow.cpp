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
    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addSeparator();
    fileMenu->addAction(saveAction);
    fileMenu->addAction(saveAsAction);
    fileMenu->addAction(saveAllAction);
    fileMenu->addSeparator();
    fileMenu->addAction(printAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);
    mb->addMenu(fileMenu->menu());

    Core::ActionContainer *editMenu = actionManager->createMenu(ID->menuEdit(), tr("&Edit", "[Edit] on menu bar."));
    editMenu->addAction(undoAction);
    editMenu->addAction(redoAction);
    editMenu->addSeparator();
    editMenu->addAction(cutAction);
    editMenu->addAction(copyAction);
    editMenu->addAction(pasteAction);
    mb->addMenu(editMenu->menu());

    Core::ActionContainer *toolMenu = actionManager->createMenu(ID->menuTool(), tr("&Tools", "[Tools] on menu bar."));
    Core::ActionContainer *langMenu = actionManager->createMenu(ID->menuLang(), tr("Languages", "[Language] under menu [Tool]"));
    toolMenu->addMenu(langMenu);
    toolMenu->addAction(preferencesAction);
    mb->addMenu(toolMenu->menu());

    QtWindowListMenu *subwindowMenu = new QtWindowListMenu;
    subwindowMenu->attachToMdiArea(mdiArea);
    subwindowMenu->setCascadeIcon(appRes->icon(Core::AppResource::CascadeIcon));
    subwindowMenu->setTileIcon(appRes->icon(Core::AppResource::TileIcon));
    mb->addMenu(subwindowMenu);

    mb->addSeparator();

    Core::ActionContainer *helpMenu = actionManager->createMenu(ID->menuHelp(), tr("&Help", "[Help] on menu bar."));
    helpMenu->addAction(helpAction);
    helpMenu->addAction(aboutAction);
    mb->addMenu(helpMenu->menu());
}

/*!
  \internal
  \brief Creates actions used in application.
 */
void Ui::MainWindow::createActions()
{
    // Common Actions
    QAction *newQAction = new QAction(tr("&New...", "[New] action text."), this);
    newQAction->setIcon(appRes->icon(Core::AppResource::NewIcon));
    newQAction->setShortcut(QKeySequence::New);
    newQAction->setStatusTip(tr("Create a new image file.", "[New] action tip on status bar."));
    newAction = actionManager->registerAction(ID->actionNew(), newQAction);

    QAction *openQAction = new QAction(tr("&Open...", "[Open] action text."), this);
    openQAction->setIcon(appRes->icon(Core::AppResource::OpenIcon));
    openQAction->setShortcut(QKeySequence::Open);
    openQAction->setStatusTip(tr("Open an image file.", "[Open] action tip on status bar."));
    openAction = actionManager->registerAction(ID->actionOpen(), openQAction);

    QAction *saveQAction = new QAction(tr("&Save", "[Save] action text."), this);
    saveQAction->setIcon(appRes->icon(Core::AppResource::SaveIcon));
    saveQAction->setShortcut(QKeySequence::Save);
    saveQAction->setStatusTip(tr("Save the project into a file.", "[Save] action tip on status bar."));
    saveAction = actionManager->registerAction(ID->actionSave(), saveQAction);

    QAction *saveAsQAction = new QAction(tr("Save &As...", "[Save As] action text."), this);
    saveAsQAction->setIcon(appRes->icon(Core::AppResource::SaveAsIcon));
    saveAsQAction->setShortcut(QKeySequence::SaveAs);
    saveAsQAction->setStatusTip(tr("Save the project as another file.", "[Save As] action tip on status bar."));
    saveAsAction = actionManager->registerAction(ID->actionSaveAs(), saveAsQAction);

    QAction *saveAllQAction = new QAction(tr("Save &All", "[Save All] action text."), this);
    saveAllQAction->setIcon(appRes->icon(Core::AppResource::SaveAllIcon));
    saveAllQAction->setStatusTip(tr("Save all the projects.", "[Save All] action tip on status bar."));
    saveAllAction = actionManager->registerAction(ID->actionSaveAll(), saveAllQAction);

    QAction *printQAction = new QAction(tr("&Print...", "[Print] action text."), this);
    printQAction->setIcon(appRes->icon(Core::AppResource::PrintIcon));
    printQAction->setShortcut(QKeySequence::Print);
    printQAction->setStatusTip(tr("Print the project.", "[Print] action tip on status bar."));
    printAction = actionManager->registerAction(ID->actionPrint(), printQAction);

    QAction *exitQAction = new QAction(tr("E&xit", "[Exit] action text."), this);
    exitQAction->setIcon(appRes->icon(Core::AppResource::ExitIcon));
    exitQAction->setShortcut(tr("Ctrl+Q", "[Exit] action shortcut."));
    exitQAction->setStatusTip(tr("Exit PicWorks.", "[Exit] action tip on status bar."));
    exitAction = actionManager->registerAction(ID->actionExit(), exitQAction);

    QAction *undoQAction = new QAction(tr("&Undo", "[Undo] action text."), this);
    undoQAction->setIcon(appRes->icon(Core::AppResource::UndoIcon));
    undoQAction->setShortcut(QKeySequence::Undo);
    undoQAction->setStatusTip(tr("Undo the last action.", "[Undo] action tip on status bar."));
    undoAction = actionManager->registerAction(ID->actionUndo(), undoQAction);

    QAction *redoQAction = new QAction(tr("&Redo", "[Redo] action text."), this);
    redoQAction->setIcon(appRes->icon(Core::AppResource::RedoIcon));
    redoQAction->setShortcut(QKeySequence::Redo);
    redoQAction->setStatusTip(tr("Redo the next action.", "[Redo] action tip on status bar."));
    redoAction = actionManager->registerAction(ID->actionRedo(), redoQAction);

    QAction *cutQAction = new QAction(tr("Cu&t", "[Cut] action text."), this);
    cutQAction->setIcon(appRes->icon(Core::AppResource::CutIcon));
    cutQAction->setShortcut(QKeySequence::Cut);
    cutQAction->setStatusTip(tr("Cut selected area.", "[Cut] action tip on status bar."));
    cutAction = actionManager->registerAction(ID->actionCut(), cutQAction);

    QAction *copyQAction = new QAction(tr("&Copy", "[Copy] action text."), this);
    copyQAction->setIcon(appRes->icon(Core::AppResource::CopyIcon));
    copyQAction->setShortcut(QKeySequence::Copy);
    copyQAction->setStatusTip(tr("Copy selected area.", "[Copy] action tip on status bar."));
    copyAction = actionManager->registerAction(ID->actionCopy(), copyQAction);

    QAction *pasteQAction = new QAction(tr("&Paste", "[Paste] action text."), this);
    pasteQAction->setIcon(appRes->icon(Core::AppResource::PasteIcon));
    pasteQAction->setShortcut(QKeySequence::Paste);
    pasteQAction->setStatusTip(tr("Paste the cut or copied area.", "[Paste] action tip on status bar."));
    pasteAction = actionManager->registerAction(ID->actionPaste(), pasteQAction);

    QAction *preferencesQAction = new QAction(tr("&Preferences...", "[Preferences] action text."), this);
    preferencesQAction->setIcon(appRes->icon(Core::AppResource::PreferencesIcon));
    preferencesQAction->setStatusTip(tr("Open preferences dialog.", "[Preferences] action tip on status bar."));
    preferencesAction = actionManager->registerAction(ID->actionOpenReference(), preferencesQAction);

    QAction *helpQAction = new QAction(tr("&Help...", "[Help] action text."), this);
    helpQAction->setIcon(appRes->icon(Core::AppResource::HelpIcon));
    helpQAction->setShortcut(QKeySequence::HelpContents);
    helpQAction->setStatusTip(tr("Open help contents.", "[Help] action tip on status bar."));
    helpAction = actionManager->registerAction(ID->actionOpenHelp(), helpQAction);

    QAction *aboutQAction = new QAction(tr("&About...", "[About] action text."), this);
    aboutQAction->setIcon(appRes->icon(Core::AppResource::AboutIcon));
    aboutQAction->setStatusTip(tr("About PicWorks.", "[About] action tip on status bar."));
    aboutAction = actionManager->registerAction(ID->actionOpenAbout(), aboutQAction);
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

    toolBarContainer->addAction(newAction);
    toolBarContainer->addAction(openAction);
    toolBarContainer->addAction(saveAction);
    toolBarContainer->addSeparator();
    toolBarContainer->addAction(undoAction);
    toolBarContainer->addAction(redoAction);
    toolBarContainer->addSeparator();
    toolBarContainer->addAction(cutAction);
    toolBarContainer->addAction(copyAction);
    toolBarContainer->addAction(pasteAction);
    toolBarContainer->addSeparator();
    toolBarContainer->addAction(preferencesAction);
    toolBar->setIconSize(QSize(16, 16));
    addToolBarBreak();
}

/*!
  \internal
  \brief Establishes all connections.
 */
void Ui::MainWindow::establishConnections()
{
    connect(newAction->action(), SIGNAL(triggered()), this, SLOT(showProjectCreateDialog()));
    //connect(actionManager->action(ID->actionOpen())->action(), SIGNAL(triggered()), this, SLOT(showFileOpenDialog()));
    //connect(actionManager->action(Core::ID::Action::NEW), SIGNAL(triggered()), this, SLOT(showPreferencesDialog()));
    connect(aboutAction->action(), SIGNAL(triggered()), this, SLOT(showAboutDialog()));

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

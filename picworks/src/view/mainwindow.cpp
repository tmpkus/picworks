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
  \file mainwindow.cpp
  \ingroup View
  \brief This file contains
  - class View::MainWindow implemtation
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2009-9-5 Created.
 */

#include <QAction>
#include <QActionGroup>
#include <QApplication>
#include <QMenu>
#include <QKeySequence>
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QLabel>
#include <QMdiArea>
#include <QGridLayout>
#include <QDockWidget>
#include <QCloseEvent>
#include <QToolButton>
#include <QSettings>
#include <QTabWidget>
#include <QFileDialog>
#include <QMessageBox>

#include "../model/project.h"
#include "../util/appresource.h"
#include "../util/appcontext.h"
#include "../util/actionmanager.h"
#include "../util/actioncontainer.h"
#include "../util/action.h"
#include "../util/dataaction.h"
#include "mainwindow.h"
#include "projectwindow.h"
#include "projectcreatedialog.h"
#include "aboutdialog.h"
#include "preferencesdialog.h"
#include "qtwindowlistmenu.h"
#include "twocolorselector.h"
#include "commonbar.h"
#include "layerpreviewpanel.h"

/*!
  \class View::MainWindow mainwindow.h
  \brief Main window of PicWorks.
  This is the main application window of PicWorks. PicWorks default main window is a MDI
  (Multiple Document Interface) window which can open many documents at the same time.
  \note There should be only one application window running at the same time.
  \version 0.0.1
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2009-9-5 Created.
 */

/*!
  \brief Constructor.
  Creates a new MainWindow instance.
  \param parent parent widget of this window, default value is \a NULL
 */
View::MainWindow::MainWindow(QWidget *parent /* = 0 */)
    : QMainWindow(parent)
{
    setWindowIcon(appRes->icon(Core::AppResource::ApplicationIcon));
    setWindowTitle(tr("PicWorks v%1", "Main window title with version number.").arg(appCtx->version()));
    //setMinimumSize(800, 600);

    actionManager = appCtx->actionManager();
    toolBoxActionGroup = new QActionGroup(this);

    mdiArea = new QMdiArea;
    setCentralWidget(mdiArea);

    createActions();
    establishConnections();
    createMenus();
    createToolBars();
    createStatusBar();
    createDockPanelsSet();

    readSettings();
}

/*!
  \brief Destructor.
  Destructs a main window.
 */
View::MainWindow::~MainWindow()
{
}

/* [private]
 * Creates menus used in application.
 */
void View::MainWindow::createMenus()
{
    Core::ActionContainer *menuBarContainer = actionManager->actionContainer(Core::AppResource::DEFAULT_MENUBAR);
    QMenuBar *mb = menuBarContainer->menuBar();
#ifndef Q_WS_MAC // System menu bar on Mac
    setMenuBar(mb);
#endif
    Core::ActionContainer *mc = actionManager->createMenu(Core::AppResource::MENU_FILE, "cheng");
    Core::Action *na = actionManager->registerAction(Core::AppResource::MENU_ITEM_NEW, new QAction(this));
    na->setText("New");
    mc->addAction(na);

    Core::ActionContainer *mc0 = actionManager->createMenu(Core::AppResource::MENU_EDIT, "liang");
    Core::ActionContainer *mc1 = actionManager->createMenu(Core::AppResource::MENU_TOOL, "tools");

    Core::Action *a = menuBarContainer->addMenu(mc);
    menuBarContainer->addMenu(mc0);
    menuBarContainer->addMenu(mc1, a);

    /*
    // Common Actions
    newAction = new QAction(tr("&New...", "[New] action text."), this);
    newAction->setIcon(appRes->icon(Core::AppResource::NewIcon));
    newAction->setShortcut(QKeySequence::New);
    newAction->setStatusTip(tr("Create a new image file.", "[New] action tip on status bar."));
    */

    fileMenu = mb->addMenu(tr("&File", "[File] on menu bar."));
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

    editMenu = mb->addMenu(tr("&Edit", "[Edit] on menu bar."));
    editMenu->addAction(undoAction);
    editMenu->addAction(redoAction);
    editMenu->addSeparator();
    editMenu->addAction(cutAction);
    editMenu->addAction(copyAction);
    editMenu->addAction(pasteAction);

    toolsMenu = mb->addMenu(tr("&Tools", "[Tools] on menu bar."));
    toolsMenu->addAction(preferencesAction);

    subwindowMenu = new Ext::QtWindowListMenu(menuBar());
    subwindowMenu->attachToMdiArea(mdiArea);
    subwindowMenu->setCascadeIcon(appRes->icon(Core::AppResource::CascadeIcon));
    subwindowMenu->setTileIcon(appRes->icon(Core::AppResource::TileIcon));
    menuBar()->addMenu(subwindowMenu);

    menuBar()->addSeparator();

    helpMenu = mb->addMenu(tr("&Help", "[Help] on menu bar."));
    helpMenu->addAction(helpAction);
    helpMenu->addAction(aboutAction);
}

/*!
  \brief Override QMainWindow::createPopupMenu().
  \sa QMainWindow::createPopupMenu()
  \return application context menu
 */
QMenu* View::MainWindow::createPopupMenu()
{
    QMenu* menu = QMainWindow::createPopupMenu();
    menu->addSeparator();
    menu->addAction(aboutAction);
    return menu;
}

/*!
  \internal
  \brief Close event when try to close this window.
  In this function PicWorks will try to do the followings:
  - Save positions of tool boxes and tool bars;
  \param event the close event
 */
void View::MainWindow::closeEvent(QCloseEvent *event)
{
    writeSettings();
}

/*!
  \internal
  \brief Creates function panel. The function panel is on the right edge of
  main window. Many panels such as layers and history operations will be added
  to this panel.
 */
void View::MainWindow::createDockPanelsSet()
{
    dockPanelsSet = new QDockWidget(tr("Panels Set", "Title of panel set."));
    dockPanelsSet->setObjectName("DockPanelsSet");
    dockPanelsSet->setMinimumWidth(200);
    dockPanelsSet->setAllowedAreas(Qt::RightDockWidgetArea);
    QTabWidget *tabbedWidget = new QTabWidget;
    dockPanelsSet->setWidget(tabbedWidget);

    // add properties panels
    // layer preview panel
    LayerPreviewPanel *layerPreviewPanel = new LayerPreviewPanel;
    tabbedWidget->addTab(layerPreviewPanel, tr("Layer", "Layer panel title."));

    addDockWidget(Qt::RightDockWidgetArea, dockPanelsSet);
}

/*!
  \internal
  \brief Creates tool bars used in application.
 */
void View::MainWindow::createToolBars()
{
    // tool bar for commands
    toolBar = addToolBar(tr("Commands Bar", "Common bar title when floating."));
    toolBar->setObjectName("ToolBar");
    toolBar->addAction(newAction);
    toolBar->addAction(openAction);
    toolBar->addAction(saveAction);
    toolBar->addSeparator();
    toolBar->addAction(undoAction);
    toolBar->addAction(redoAction);
    toolBar->addSeparator();
    toolBar->addAction(cutAction);
    toolBar->addAction(copyAction);
    toolBar->addAction(pasteAction);
    toolBar->addSeparator();
    toolBar->addAction(preferencesAction);
    toolBar->setIconSize(QSize(16, 16));
    addToolBarBreak();

    // comm bar which is a tool bar
    // for layouting properties of several tools
    commonBar = CommonBar::instance().createCommonBar(Core::AppResource::DrawLineAction);
    commonBar->setObjectName("CommonBar");
    addToolBar(Qt::TopToolBarArea, commonBar);

    // tool box of several tools
    QWidget *gridToolBox = new QWidget;
    QGridLayout *layout = new QGridLayout;
    layout->setMargin(1);
    layout->setSpacing(2);
    QToolButton *selectToolButton = createToolButton(selectToolAction);
    layout->addWidget(selectToolButton, 0, 0, 1, 1);
    QToolButton *moveToolButton = createToolButton(moveToolAction);
    layout->addWidget(moveToolButton, 0, 1, 1, 1);
    QToolButton *brushToolButton = createToolButton(brushToolAction);
    layout->addWidget(brushToolButton, 1, 0, 1, 1);
    QToolButton *eraserToolButton = createToolButton(eraserToolAction);
    layout->addWidget(eraserToolButton, 1, 1, 1, 1);
    QToolButton *textToolButton = createToolButton(textToolAction);
    layout->addWidget(textToolButton, 2, 0, 1, 1);
    QToolButton *paintCanToolButton = createToolButton(paintCanToolAction);
    layout->addWidget(paintCanToolButton, 2, 1, 1, 1);
    QToolButton *lineToolButton = createToolButton(lineToolAction);
    layout->addWidget(lineToolButton, 3, 0, 1, 1);
    QToolButton *curveToolButton = createToolButton(curveToolAction);
    layout->addWidget(curveToolButton, 3, 1, 1, 1);
    QToolButton *ellipseToolButton = createToolButton(ellipseToolAction);
    layout->addWidget(ellipseToolButton, 4, 0, 1, 1);
    QToolButton *rectangleToolButton = createToolButton(rectangleToolAction);
    layout->addWidget(rectangleToolButton, 4, 1, 1, 1);
    QToolButton *roundRectangleToolButton = createToolButton(roundRectangleToolAction);
    layout->addWidget(roundRectangleToolButton, 5, 0, 1, 1);
    QToolButton *polygonToolButton = createToolButton(polygonToolAction);
    layout->addWidget(polygonToolButton, 5, 1, 1, 1);
    TwoColorSelector *selector = new TwoColorSelector(gridToolBox);
    layout->addWidget(selector, 6, 0, 2, 2, Qt::AlignCenter);
    gridToolBox->setLayout(layout);
    toolBox = new QToolBar(tr("Tools Box", "Tool box title when floating."), this);
    toolBox->setObjectName("ToolBox");
    toolBox->setOrientation(Qt::Vertical);
    toolBox->addWidget(gridToolBox);
    toolBox->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);
    addToolBar(Qt::LeftToolBarArea, toolBox);
}

/*!
  \internal
  \brief Creates a tool button using given action.
  This action will set as the default action instead of adding into its action list.
  @return the pointer to a QToolButton instance by "new" operation
 */
QToolButton * View::MainWindow::createToolButton(QAction *action)
{
    QToolButton *button = new QToolButton;
    button->setDefaultAction(action);
    button->setAutoRaise(true);
    button->setFocusPolicy(Qt::NoFocus);
    return button;
}

/*!
  \internal
  \brief Creates status bars used in application.
 */
void View::MainWindow::createStatusBar()
{
    statusLabel = new QLabel(tr("Galaxy (C) PicWorks v%1", "Status bar startup label.").arg(appCtx->version()));
    statusLabel->setMinimumSize(statusLabel->sizeHint());

    statusBar()->addWidget(statusLabel);
    statusBar()->setStyleSheet(QString("QStatusBar::item{border: 0px}"));
}

/*!
  \internal
  \brief Creates actions used in application.
 */
void View::MainWindow::createActions()
{
    // Common Actions
    newAction = new QAction(tr("&New...", "[New] action text."), this);
    newAction->setIcon(appRes->icon(Core::AppResource::NewIcon));
    newAction->setShortcut(QKeySequence::New);
    newAction->setStatusTip(tr("Create a new image file.", "[New] action tip on status bar."));

    openAction = new QAction(tr("&Open...", "[Open] action text."), this);
    openAction->setIcon(appRes->icon(Core::AppResource::OpenIcon));
    openAction->setShortcut(QKeySequence::Open);
    openAction->setStatusTip(tr("Open an image file.", "[Open] action tip on status bar."));

    saveAction = new QAction(tr("&Save", "[Save] action text."), this);
    saveAction->setIcon(appRes->icon(Core::AppResource::SaveIcon));
    saveAction->setShortcut(QKeySequence::Save);
    saveAction->setStatusTip(tr("Save the project into a file.", "[Save] action tip on status bar."));

    saveAsAction = new QAction(tr("Save &As...", "[Save As] action text."), this);
    saveAsAction->setIcon(appRes->icon(Core::AppResource::SaveAsIcon));
    saveAsAction->setShortcut(QKeySequence::SaveAs);
    saveAsAction->setStatusTip(tr("Save the project as another file.", "[Save As] action tip on status bar."));

    saveAllAction = new QAction(tr("Save &All", "[Save All] action text."), this);
    saveAllAction->setIcon(appRes->icon(Core::AppResource::SaveAllIcon));
    saveAllAction->setStatusTip(tr("Save all the projects.", "[Save All] action tip on status bar."));

    printAction = new QAction(tr("&Print...", "[Print] action text."), this);
    printAction->setIcon(appRes->icon(Core::AppResource::PrintIcon));
    printAction->setShortcut(QKeySequence::Print);
    printAction->setStatusTip(tr("Print the project.", "[Print] action tip on status bar."));

    exitAction = new QAction(tr("E&xit", "[Exit] action text."), this);
    exitAction->setIcon(appRes->icon(Core::AppResource::ExitIcon));
    exitAction->setShortcut(tr("Ctrl+Q", "[Exit] action shortcut."));
    exitAction->setStatusTip(tr("Exit PicWorks.", "[Exit] action tip on status bar."));

    undoAction = new QAction(tr("&Undo", "[Undo] action text."), this);
    undoAction->setIcon(appRes->icon(Core::AppResource::UndoIcon));
    undoAction->setShortcut(QKeySequence::Undo);
    undoAction->setStatusTip(tr("Undo the last action.", "[Undo] action tip on status bar."));

    redoAction = new QAction(tr("&Redo", "[Redo] action text."), this);
    redoAction->setIcon(appRes->icon(Core::AppResource::RedoIcon));
    redoAction->setShortcut(QKeySequence::Redo);
    redoAction->setStatusTip(tr("Redo the next action.", "[Redo] action tip on status bar."));

    cutAction = new QAction(tr("Cu&t", "[Cut] action text."), this);
    cutAction->setIcon(appRes->icon(Core::AppResource::CutIcon));
    cutAction->setShortcut(QKeySequence::Cut);
    cutAction->setStatusTip(tr("Cut selected area.", "[Cut] action tip on status bar."));

    copyAction = new QAction(tr("&Copy", "[Copy] action text."), this);
    copyAction->setIcon(appRes->icon(Core::AppResource::CopyIcon));
    copyAction->setShortcut(QKeySequence::Copy);
    copyAction->setStatusTip(tr("Copy selected area.", "[Copy] action tip on status bar."));

    pasteAction = new QAction(tr("&Paste", "[Paste] action text."), this);
    pasteAction->setIcon(appRes->icon(Core::AppResource::PasteIcon));
    pasteAction->setShortcut(QKeySequence::Paste);
    pasteAction->setStatusTip(tr("Paste the cut or copied area.", "[Paste] action tip on status bar."));

    preferencesAction = new QAction(tr("&Preferences...", "[Preferences] action text."), this);
    preferencesAction->setIcon(appRes->icon(Core::AppResource::PreferencesIcon));
    preferencesAction->setStatusTip(tr("Open preferences dialog.", "[Preferences] action tip on status bar."));

    helpAction = new QAction(tr("&Help...", "[Help] action text."), this);
    helpAction->setIcon(appRes->icon(Core::AppResource::HelpIcon));
    helpAction->setShortcut(QKeySequence::HelpContents);
    helpAction->setStatusTip(tr("Open help contents.", "[Help] action tip on status bar."));

    aboutAction = new QAction(tr("&About...", "[About] action text."), this);
    aboutAction->setIcon(appRes->icon(Core::AppResource::AboutIcon));
    aboutAction->setStatusTip(tr("About PicWorks.", "[About] action tip on status bar."));

    // Tool Box Actions
    selectToolAction = new QAction(this);
    selectToolAction->setIcon(appRes->icon(Core::AppResource::SelectIcon));
    selectToolAction->setToolTip(tr("Select[S]", "[Select] action tip with shortcut."));
    selectToolAction->setStatusTip(tr("Select an area.", "[Select] action tip on status bar."));
    selectToolAction->setShortcut(tr("S"));
    toolBoxActionGroup->addAction(selectToolAction);

    moveToolAction = new QAction(this);
    moveToolAction->setIcon(appRes->icon(Core::AppResource::MoveIcon));
    moveToolAction->setToolTip(tr("Move[M]", "[Move] action tip with shortcut."));
    moveToolAction->setStatusTip(tr("Move the selected area or the whole page.", "[Move] action tip on status bar."));
    moveToolAction->setShortcut(tr("M"));
    toolBoxActionGroup->addAction(moveToolAction);

    brushToolAction = new QAction(this);
    brushToolAction->setIcon(appRes->icon(Core::AppResource::BrushIcon));
    brushToolAction->setToolTip(tr("Brush[B]", "[Brush] action tip with shortcut."));
    brushToolAction->setStatusTip(tr("Use brush.", "[Brush] action tip on status bar."));
    brushToolAction->setShortcut(tr("B"));
    toolBoxActionGroup->addAction(brushToolAction);

    eraserToolAction = new QAction(this);
    eraserToolAction->setIcon(appRes->icon(Core::AppResource::EraserIcon));
    eraserToolAction->setToolTip(tr("Eraser[E]", "[Eraser] action tip with shortcut."));
    eraserToolAction->setStatusTip(tr("Use eraser.", "[Eraser] action tip on status bar."));
    eraserToolAction->setShortcut(tr("E"));
    toolBoxActionGroup->addAction(eraserToolAction);

    paintCanToolAction = new QAction(this);
    paintCanToolAction->setIcon(appRes->icon(Core::AppResource::PaintCanIcon));
    paintCanToolAction->setToolTip(tr("Paint Can[P]", "[Paint Can] action tip with shortcut."));
    paintCanToolAction->setStatusTip(tr("Fill the area with selected color.", "[Paint Can] action tip on status bar."));
    paintCanToolAction->setShortcut(tr("P"));
    toolBoxActionGroup->addAction(paintCanToolAction);

    textToolAction = new QAction(this);
    textToolAction->setIcon(appRes->icon(Core::AppResource::TextIcon));
    textToolAction->setToolTip(tr("Text[T]", "[Text] action tip with shortcut."));
    textToolAction->setStatusTip(tr("Add text.", "[Text] action tip on status bar."));
    textToolAction->setShortcut(tr("T"));
    toolBoxActionGroup->addAction(textToolAction);

    lineToolAction = new Action::DataAction(appRes->DrawLineAction, this);
    lineToolAction->setIcon(appRes->icon(Core::AppResource::LineIcon));
    lineToolAction->setToolTip(tr("Line[L]", "[Line] action tip with shortcut."));
    lineToolAction->setStatusTip(tr("Draw a line.", "[Line] action tip on status bar."));
    lineToolAction->setShortcut(tr("L"));
    toolBoxActionGroup->addAction(lineToolAction);

    curveToolAction = new Action::DataAction(appRes->DrawCurveAction, this);
    curveToolAction->setIcon(appRes->icon(Core::AppResource::CurveIcon));
    curveToolAction->setToolTip(tr("Curve[C]", "[Curve] action tip with shortcut."));
    curveToolAction->setStatusTip(tr("Draw a curve.", "[Curve] action tip on status bar."));
    curveToolAction->setShortcut(tr("C"));
    toolBoxActionGroup->addAction(curveToolAction);

    ellipseToolAction = new Action::DataAction(appRes->DrawEllipseAction, this);
    ellipseToolAction->setIcon(appRes->icon(Core::AppResource::EllipseIcon));
    ellipseToolAction->setToolTip(tr("Ellipse[P]", "[Ellipse] action tip with shortcut."));
    ellipseToolAction->setStatusTip(tr("Draw an ellipse.", "[Ellipse] action tip on status bar."));
    ellipseToolAction->setShortcut(tr("L"));
    toolBoxActionGroup->addAction(ellipseToolAction);

    polygonToolAction = new Action::DataAction(appRes->DrawPolygonAction, this);
    polygonToolAction->setIcon(appRes->icon(Core::AppResource::PolygonIcon));
    polygonToolAction->setToolTip(tr("Polygon[O]", "[Polygon] action tip with shortcut."));
    polygonToolAction->setStatusTip(tr("Draw a polygon.", "[Polygon] action tip on status bar."));
    polygonToolAction->setShortcut(tr("O"));
    toolBoxActionGroup->addAction(polygonToolAction);

    rectangleToolAction = new Action::DataAction(appRes->DrawRectAction, this);
    rectangleToolAction->setIcon(appRes->icon(Core::AppResource::RectangleIcon));
    rectangleToolAction->setToolTip(tr("Rectangle[R]", "[Rectangle] action tip with shortcut."));
    rectangleToolAction->setStatusTip(tr("Draw a rectangle.", "[Rectangle] action tip on status bar."));
    rectangleToolAction->setShortcut(tr("R"));
    toolBoxActionGroup->addAction(rectangleToolAction);

    roundRectangleToolAction = new Action::DataAction(appRes->DrawRoundRectAction, this);
    roundRectangleToolAction->setIcon(appRes->icon(Core::AppResource::RoundRectangleIcon));
    roundRectangleToolAction->setToolTip(tr("Round corner rectangle[U]", "[Round Cornor Rectangle] action tip with shortcut."));
    roundRectangleToolAction->setStatusTip(tr("Draw a round corner rectangle.", "[Round Cornor Rectangle] action tip on status bar."));
    roundRectangleToolAction->setShortcut(tr("U"));
    toolBoxActionGroup->addAction(roundRectangleToolAction);

    QAction *action;
    foreach(action, toolBoxActionGroup->actions()) {
        action->setCheckable(true);
    }
    selectToolAction->setChecked(true);
}

/*!
  \internal
  \brief Establishes all connections.
 */
void View::MainWindow::establishConnections()
{
    connect(newAction, SIGNAL(triggered()), this, SLOT(showProjectCreateDialog()));
    connect(openAction, SIGNAL(triggered()), this, SLOT(showFileOpenDialog()));
    connect(preferencesAction, SIGNAL(triggered()), this, SLOT(showPreferencesDialog()));
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(showAboutDialog()));

    // connect(lineToolAction, SIGNAL(triggered()), AppCtx, SLOT(setCurrentAction()));
}

/*!
  \internal
  \brief Creates a new project.
  This slot will show a "new dialog" first, in order to get data from users
  and then try to construct a Project instance using \a getProject slot.
 */
void View::MainWindow::showProjectCreateDialog()
{
    ProjectCreateDialog *pcd = new ProjectCreateDialog(this);// Qt::WindowSystemMenuHint | Qt::WindowTitleHint
    // block...
    int rtn = pcd->exec();
    // get project
    if(rtn == QDialog::Accepted) {
        ProjectWindow * pw = new ProjectWindow(pcd->getProject());
        mdiArea->addSubWindow(pw);
        pw->show();
    }
    delete pcd;
}

/*!
  \internal
  \brief Shows the about dialog.
 */
void View::MainWindow::showAboutDialog()
{
    AboutDialog *ad = new AboutDialog(this);
    ad->exec();
}

/*!
  \internal
  \brief Shows preferences dialog.
 */
void View::MainWindow::showPreferencesDialog()
{
    PreferencesDialog *pd = new PreferencesDialog(this);
    pd->exec();
}

/*!
  \internal
  \brief Shows file open dialog.
 */
void View::MainWindow::showFileOpenDialog()
{
    QString path = QFileDialog::getOpenFileName(this, tr("Open File"), ".", tr("All support formats(*.jpg; *.png);;JPEG Files(*.jpg);;PNG Files(*.png)"));
    if(path.isEmpty()) {
        QMessageBox::information(NULL, tr("Path"), tr("Please select an image to open."));
    } else {
        QMessageBox::information(NULL, tr("Path"), tr("You selected: ") + path);
    }
}

/*!
  \internal
  \brief Gets the project created by "new dialog" to create project window view.
  At last this slot will show a subwindow that is an instance of ProjectWindow.
  \param project project created by dialog
 */
void View::MainWindow::getProject(Data::Project & project)
{
    ProjectWindow * pw = new ProjectWindow(&project);
    mdiArea->addSubWindow(pw);
    pw->show();
}

/*!
  \internal
  \brief Writes settings of main window.
 */
void View::MainWindow::writeSettings()
{
    QSettings settings(qApp->applicationDirPath().append("/PicWorks.ini"), QSettings::IniFormat);
    settings.beginGroup("MainWindow");
    settings.setValue("geometry", saveGeometry());
    settings.setValue("state", saveState());
    settings.endGroup();
}

/*!
  \internal
  \brief Reads stored settings.
 */
void View::MainWindow::readSettings()
{
    QSettings settings(qApp->applicationDirPath().append("/PicWorks.ini"), QSettings::IniFormat);
    settings.beginGroup("MainWindow");
    restoreGeometry(settings.value("geometry").toByteArray());
    restoreState(settings.value("state").toByteArray());
    settings.endGroup();
}

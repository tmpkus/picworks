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
#include <QActionGroup>
#include <QMdiArea>
#include <QMenu>
#include <QMenuBar>
#include <QLabel>
#include <QStatusBar>
#include <QDockWidget>
#include <QToolBar>
#include <QGridLayout>
#include <QToolButton>
#include <QFileDialog>
#include <QMessageBox>
#include <QSignalMapper>

#include "qtwindowlistmenu.h"
#include "appcontext.h"
#include "appresource.h"
#include "mainwindow.h"
#include "constants.h"
#include "projectcreator.h"
#include "aboutdialog.h"
#include "projectwindow.h"
#include "colorindicator.h"
#include "project.h"
#include "commonbar.h"

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

    mapper = new QSignalMapper(this);

    mdiArea = new QMdiArea;
    setCentralWidget(mdiArea);

    createActions();
    createMenus();
    createStatusBar();
    createDockPanels();
    createToolBar();
    createToolBox();
    createCommonBar();
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
    QMenuBar *mb = actionManager->menuBar(Core::ID::MENU_BAR);
#ifndef Q_WS_MAC // System menu bar on Mac
    setMenuBar(mb);
#endif
    QMenu *fileMenu = actionManager->menu(Core::ID::MENU_FILE, tr("&File", "[File] on menu bar."));
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
    mb->addMenu(fileMenu);

    QMenu *editMenu = actionManager->menu(Core::ID::MENU_EDIT, tr("&Edit", "[Edit] on menu bar."));
    editMenu->addAction(undoAction);
    editMenu->addAction(redoAction);
    editMenu->addSeparator();
    editMenu->addAction(cutAction);
    editMenu->addAction(copyAction);
    editMenu->addAction(pasteAction);
    mb->addMenu(editMenu);

    QMenu *toolMenu = actionManager->menu(Core::ID::MENU_TOOL, tr("&Tools", "[Tools] on menu bar."));
    QMenu *langMenu = actionManager->menu(Core::ID::MENU_LANG, tr("Languages", "[Language] under menu [Tool]"));
    toolMenu->addMenu(langMenu);
    toolMenu->addAction(preferencesAction);
    mb->addMenu(toolMenu);

    QtWindowListMenu *subwindowMenu = new QtWindowListMenu;
    subwindowMenu->attachToMdiArea(mdiArea);
    subwindowMenu->setCascadeIcon(appRes->icon(Core::AppResource::CascadeIcon));
    subwindowMenu->setTileIcon(appRes->icon(Core::AppResource::TileIcon));
    mb->addMenu(subwindowMenu);

    mb->addSeparator();

    QMenu *helpMenu = actionManager->menu(Core::ID::MENU_HELP, tr("&Help", "[Help] on menu bar."));
    helpMenu->addAction(helpAction);
    helpMenu->addAction(aboutAction);
    mb->addMenu(helpMenu);
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
    newAction = actionManager->registerAction(Core::ID::ACTION_NEW, newQAction);

    QAction *openQAction = new QAction(tr("&Open...", "[Open] action text."), this);
    openQAction->setIcon(appRes->icon(Core::AppResource::OpenIcon));
    openQAction->setShortcut(QKeySequence::Open);
    openQAction->setStatusTip(tr("Open an image file.", "[Open] action tip on status bar."));
    openAction = actionManager->registerAction(Core::ID::ACTION_OPEN, openQAction);

    QAction *saveQAction = new QAction(tr("&Save", "[Save] action text."), this);
    saveQAction->setIcon(appRes->icon(Core::AppResource::SaveIcon));
    saveQAction->setShortcut(QKeySequence::Save);
    saveQAction->setStatusTip(tr("Save the project into a file.", "[Save] action tip on status bar."));
    saveAction = actionManager->registerAction(Core::ID::ACTION_SAVE, saveQAction);

    QAction *saveAsQAction = new QAction(tr("Save &As...", "[Save As] action text."), this);
    saveAsQAction->setIcon(appRes->icon(Core::AppResource::SaveAsIcon));
    saveAsQAction->setShortcut(QKeySequence::SaveAs);
    saveAsQAction->setStatusTip(tr("Save the project as another file.", "[Save As] action tip on status bar."));
    saveAsAction = actionManager->registerAction(Core::ID::ACTION_SAVE_AS, saveAsQAction);

    QAction *saveAllQAction = new QAction(tr("Save &All", "[Save All] action text."), this);
    saveAllQAction->setIcon(appRes->icon(Core::AppResource::SaveAllIcon));
    saveAllQAction->setStatusTip(tr("Save all the projects.", "[Save All] action tip on status bar."));
    saveAllAction = actionManager->registerAction(Core::ID::ACTION_SAVE_ALL, saveAllQAction);

    QAction *printQAction = new QAction(tr("&Print...", "[Print] action text."), this);
    printQAction->setIcon(appRes->icon(Core::AppResource::PrintIcon));
    printQAction->setShortcut(QKeySequence::Print);
    printQAction->setStatusTip(tr("Print the project.", "[Print] action tip on status bar."));
    printAction = actionManager->registerAction(Core::ID::ACTION_PRINT, printQAction);

    QAction *exitQAction = new QAction(tr("E&xit", "[Exit] action text."), this);
    exitQAction->setIcon(appRes->icon(Core::AppResource::ExitIcon));
    exitQAction->setShortcut(tr("Ctrl+Q", "[Exit] action shortcut."));
    exitQAction->setStatusTip(tr("Exit PicWorks.", "[Exit] action tip on status bar."));
    exitAction = actionManager->registerAction(Core::ID::ACTION_EXIT, exitQAction);

    QAction *undoQAction = new QAction(tr("&Undo", "[Undo] action text."), this);
    undoQAction->setIcon(appRes->icon(Core::AppResource::UndoIcon));
    undoQAction->setShortcut(QKeySequence::Undo);
    undoQAction->setStatusTip(tr("Undo the last action.", "[Undo] action tip on status bar."));
    undoAction = actionManager->registerAction(Core::ID::ACTION_UNDO, undoQAction);

    QAction *redoQAction = new QAction(tr("&Redo", "[Redo] action text."), this);
    redoQAction->setIcon(appRes->icon(Core::AppResource::RedoIcon));
    redoQAction->setShortcut(QKeySequence::Redo);
    redoQAction->setStatusTip(tr("Redo the next action.", "[Redo] action tip on status bar."));
    redoAction = actionManager->registerAction(Core::ID::ACTION_REDO, redoQAction);

    QAction *cutQAction = new QAction(tr("Cu&t", "[Cut] action text."), this);
    cutQAction->setIcon(appRes->icon(Core::AppResource::CutIcon));
    cutQAction->setShortcut(QKeySequence::Cut);
    cutQAction->setStatusTip(tr("Cut selected area.", "[Cut] action tip on status bar."));
    cutAction = actionManager->registerAction(Core::ID::ACTION_CUT, cutQAction);

    QAction *copyQAction = new QAction(tr("&Copy", "[Copy] action text."), this);
    copyQAction->setIcon(appRes->icon(Core::AppResource::CopyIcon));
    copyQAction->setShortcut(QKeySequence::Copy);
    copyQAction->setStatusTip(tr("Copy selected area.", "[Copy] action tip on status bar."));
    copyAction = actionManager->registerAction(Core::ID::ACTION_COPY, copyQAction);

    QAction *pasteQAction = new QAction(tr("&Paste", "[Paste] action text."), this);
    pasteQAction->setIcon(appRes->icon(Core::AppResource::PasteIcon));
    pasteQAction->setShortcut(QKeySequence::Paste);
    pasteQAction->setStatusTip(tr("Paste the cut or copied area.", "[Paste] action tip on status bar."));
    pasteAction = actionManager->registerAction(Core::ID::ACTION_PASTE, pasteQAction);

    QAction *preferencesQAction = new QAction(tr("&Preferences...", "[Preferences] action text."), this);
    preferencesQAction->setIcon(appRes->icon(Core::AppResource::PreferencesIcon));
    preferencesQAction->setStatusTip(tr("Open preferences dialog.", "[Preferences] action tip on status bar."));
    preferencesAction = actionManager->registerAction(Core::ID::ACTION_OPEN_REFERENCE_DIALOG, preferencesQAction);

    QAction *helpQAction = new QAction(tr("&Help...", "[Help] action text."), this);
    helpQAction->setIcon(appRes->icon(Core::AppResource::HelpIcon));
    helpQAction->setShortcut(QKeySequence::HelpContents);
    helpQAction->setStatusTip(tr("Open help contents.", "[Help] action tip on status bar."));
    helpAction = actionManager->registerAction(Core::ID::ACTION_OPEN_HELP_DIALOG, helpQAction);

    QAction *aboutQAction = new QAction(tr("&About...", "[About] action text."), this);
    aboutQAction->setIcon(appRes->icon(Core::AppResource::AboutIcon));
    aboutQAction->setStatusTip(tr("About PicWorks.", "[About] action tip on status bar."));
    aboutAction = actionManager->registerAction(Core::ID::ACTION_OPEN_HELP_DIALOG, aboutQAction);

    // Tool Box Actions
    QActionGroup *group = new QActionGroup(this);
    QAction *selectToolQAction = new QAction(this);
    selectToolQAction->setIcon(appRes->icon(Core::AppResource::SelectIcon));
    selectToolQAction->setToolTip(tr("Select[S]", "[Select] action tip with shortcut."));
    selectToolQAction->setStatusTip(tr("Select an area.", "[Select] action tip on status bar."));
    selectToolQAction->setShortcut(tr("S"));
    selectToolQAction->setCheckable(true);
    selectToolQAction->setChecked(true);
    selectToolQAction->setData(Core::ID::ACTION_SELECT);
    group->addAction(selectToolQAction);
    selectToolAction = actionManager->registerAction(Core::ID::ACTION_SELECT, selectToolQAction);

    QAction *moveToolQAction = new QAction(this);
    moveToolQAction->setIcon(appRes->icon(Core::AppResource::MoveIcon));
    moveToolQAction->setToolTip(tr("Move[M]", "[Move] action tip with shortcut."));
    moveToolQAction->setStatusTip(tr("Move the selected area or the whole page.", "[Move] action tip on status bar."));
    moveToolQAction->setShortcut(tr("M"));
    moveToolQAction->setCheckable(true);
    moveToolQAction->setData(Core::ID::ACTION_MOVE);
    group->addAction(moveToolQAction);
    moveToolAction = actionManager->registerAction(Core::ID::ACTION_MOVE, moveToolQAction);

    QAction *brushToolQAction = new QAction(this);
    brushToolQAction->setIcon(appRes->icon(Core::AppResource::BrushIcon));
    brushToolQAction->setToolTip(tr("Brush[B]", "[Brush] action tip with shortcut."));
    brushToolQAction->setStatusTip(tr("Use brush.", "[Brush] action tip on status bar."));
    brushToolQAction->setShortcut(tr("B"));
    brushToolQAction->setCheckable(true);
    brushToolQAction->setData(Core::ID::ACTION_BRUSH);
    group->addAction(brushToolQAction);
    brushToolAction = actionManager->registerAction(Core::ID::ACTION_BRUSH, brushToolQAction);

    QAction *eraserToolQAction = new QAction(this);
    eraserToolQAction->setIcon(appRes->icon(Core::AppResource::EraserIcon));
    eraserToolQAction->setToolTip(tr("Eraser[E]", "[Eraser] action tip with shortcut."));
    eraserToolQAction->setStatusTip(tr("Use eraser.", "[Eraser] action tip on status bar."));
    eraserToolQAction->setShortcut(tr("E"));
    eraserToolQAction->setCheckable(true);
    eraserToolQAction->setData(Core::ID::ACTION_ERASER);
    group->addAction(eraserToolQAction);
    eraserToolAction = actionManager->registerAction(Core::ID::ACTION_ERASER, eraserToolQAction);

    QAction *paintCanToolQAction = new QAction(this);
    paintCanToolQAction->setIcon(appRes->icon(Core::AppResource::PaintCanIcon));
    paintCanToolQAction->setToolTip(tr("Paint Can[P]", "[Paint Can] action tip with shortcut."));
    paintCanToolQAction->setStatusTip(tr("Fill the area with selected color.", "[Paint Can] action tip on status bar."));
    paintCanToolQAction->setShortcut(tr("P"));
    paintCanToolQAction->setCheckable(true);
    paintCanToolQAction->setData(Core::ID::ACTION_PAINT_CAN);
    group->addAction(paintCanToolQAction);
    paintCanToolAction = actionManager->registerAction(Core::ID::ACTION_PAINT_CAN, paintCanToolQAction);

    QAction *textToolQAction = new QAction(this);
    textToolQAction->setIcon(appRes->icon(Core::AppResource::TextIcon));
    textToolQAction->setToolTip(tr("Text[T]", "[Text] action tip with shortcut."));
    textToolQAction->setStatusTip(tr("Add text.", "[Text] action tip on status bar."));
    textToolQAction->setShortcut(tr("T"));
    textToolQAction->setCheckable(true);
    textToolQAction->setData(Core::ID::ACTION_DRAW_TEXT);
    group->addAction(textToolQAction);
    textToolAction = actionManager->registerAction(Core::ID::ACTION_DRAW_TEXT, textToolQAction);

    QAction *lineToolQAction = new QAction(this);
    lineToolQAction->setIcon(appRes->icon(Core::AppResource::LineIcon));
    lineToolQAction->setToolTip(tr("Line[L]", "[Line] action tip with shortcut."));
    lineToolQAction->setStatusTip(tr("Draw a line.", "[Line] action tip on status bar."));
    lineToolQAction->setShortcut(tr("L"));
    lineToolQAction->setCheckable(true);
    lineToolQAction->setData(Core::ID::ACTION_DRAW_LINE);
    group->addAction(lineToolQAction);
    lineToolAction = actionManager->registerAction(Core::ID::ACTION_DRAW_LINE, lineToolQAction);

    QAction *curveToolQAction = new QAction(this);
    curveToolQAction->setIcon(appRes->icon(Core::AppResource::CurveIcon));
    curveToolQAction->setToolTip(tr("Curve[C]", "[Curve] action tip with shortcut."));
    curveToolQAction->setStatusTip(tr("Draw a curve.", "[Curve] action tip on status bar."));
    curveToolQAction->setShortcut(tr("C"));
    curveToolQAction->setCheckable(true);
    curveToolQAction->setData(Core::ID::ACTION_DRAW_CURVE);
    group->addAction(curveToolQAction);
    curveToolAction = actionManager->registerAction(Core::ID::ACTION_DRAW_CURVE, curveToolQAction);

    QAction *ellipseToolQAction = new QAction(this);
    ellipseToolQAction->setIcon(appRes->icon(Core::AppResource::EllipseIcon));
    ellipseToolQAction->setToolTip(tr("Ellipse[P]", "[Ellipse] action tip with shortcut."));
    ellipseToolQAction->setStatusTip(tr("Draw an ellipse.", "[Ellipse] action tip on status bar."));
    ellipseToolQAction->setShortcut(tr("L"));
    ellipseToolQAction->setCheckable(true);
    ellipseToolQAction->setData(Core::ID::ACTION_DRAW_ELLIPSE);
    group->addAction(ellipseToolQAction);
    ellipseToolAction = actionManager->registerAction(Core::ID::ACTION_DRAW_ELLIPSE, ellipseToolQAction);

    QAction *polygonToolQAction = new QAction(this);
    polygonToolQAction->setIcon(appRes->icon(Core::AppResource::PolygonIcon));
    polygonToolQAction->setToolTip(tr("Polygon[O]", "[Polygon] action tip with shortcut."));
    polygonToolQAction->setStatusTip(tr("Draw a polygon.", "[Polygon] action tip on status bar."));
    polygonToolQAction->setShortcut(tr("O"));
    polygonToolQAction->setCheckable(true);
    polygonToolQAction->setData(Core::ID::ACTION_DRAW_POLYGON);
    group->addAction(polygonToolQAction);
    polygonToolAction = actionManager->registerAction(Core::ID::ACTION_DRAW_POLYGON, polygonToolQAction);

    QAction *rectangleToolQAction = new QAction(this);
    rectangleToolQAction->setIcon(appRes->icon(Core::AppResource::RectangleIcon));
    rectangleToolQAction->setToolTip(tr("Rectangle[R]", "[Rectangle] action tip with shortcut."));
    rectangleToolQAction->setStatusTip(tr("Draw a rectangle.", "[Rectangle] action tip on status bar."));
    rectangleToolQAction->setShortcut(tr("R"));
    rectangleToolQAction->setCheckable(true);
    rectangleToolQAction->setData(Core::ID::ACTION_DRAW_RECT);
    group->addAction(rectangleToolQAction);
    rectangleToolAction = actionManager->registerAction(Core::ID::ACTION_DRAW_RECT, rectangleToolQAction);

    QAction *roundRectangleToolQAction = new QAction(this);
    roundRectangleToolQAction->setIcon(appRes->icon(Core::AppResource::RoundRectangleIcon));
    roundRectangleToolQAction->setToolTip(tr("Round corner rectangle[U]", "[Round Cornor Rectangle] action tip with shortcut."));
    roundRectangleToolQAction->setStatusTip(tr("Draw a round corner rectangle.", "[Round Cornor Rectangle] action tip on status bar."));
    roundRectangleToolQAction->setShortcut(tr("U"));
    roundRectangleToolQAction->setCheckable(true);
    roundRectangleToolQAction->setData(Core::ID::ACTION_DRAW_ROUND_RECT);
    group->addAction(roundRectangleToolQAction);
    roundRectangleToolAction = actionManager->registerAction(Core::ID::ACTION_DRAW_ROUND_RECT, roundRectangleToolQAction);
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
    QToolBar *toolBar = actionManager->toolBar(Core::ID::TOOL_BAR);
    toolBar->setObjectName("ToolBar");
    addToolBar(toolBar);

    toolBar->addAction(newAction);
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
}

/*!
  \internal
  \brief Creates tool box on the right side.
 */
void Ui::MainWindow::createToolBox()
{
    // tool box of several tools
    QWidget *toolBoxContent = new QWidget;
    QGridLayout *layout = new QGridLayout(toolBoxContent);
    layout->setMargin(1);
    layout->setSpacing(2);
    toolBoxContent->setLayout(layout);

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
    ci = new ColorIndicator(toolBoxContent);
    layout->addWidget(ci, 6, 0, 2, 2, Qt::AlignCenter);

    QToolBar *toolBox = actionManager->toolBar(Core::ID::TOOL_BOX);
    toolBox->setObjectName("ToolBox");
    toolBox->setOrientation(Qt::Vertical);
    toolBox->addWidget(toolBoxContent);
    toolBox->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);
    addToolBar(Qt::LeftToolBarArea, toolBox);
}

void Ui::MainWindow::createCommonBar()
{
    Ui::CommonBar *commonBar = qobject_cast<Ui::CommonBar *>(actionManager->toolBar(Core::ID::COMMON_BAR));
    commonBar->setObjectName("CommonBar");
    addToolBar(Qt::TopToolBarArea, commonBar);
}

/*!
  \internal
  \brief Establishes all connections.
 */
void Ui::MainWindow::establishConnections()
{
    connect(newAction, SIGNAL(triggered()), this, SLOT(showProjectCreateDialog()));
    connect(openAction, SIGNAL(triggered()), this, SLOT(showOpenDialog()));
    //connect(actionManager->action(Core::ID::Action::NEW), SIGNAL(triggered()), this, SLOT(showPreferencesDialog()));
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(showAboutDialog()));

    // tool box actions
    connect(lineToolAction, SIGNAL(triggered()), mapper, SLOT(map()));
    mapper->setMapping(lineToolAction, Core::ID::ACTION_DRAW_LINE);
    connect(textToolAction, SIGNAL(triggered()), mapper, SLOT(map()));
    mapper->setMapping(textToolAction, Core::ID::ACTION_DRAW_TEXT);
    connect(curveToolAction, SIGNAL(triggered()), mapper, SLOT(map()));
    mapper->setMapping(curveToolAction, Core::ID::ACTION_DRAW_CURVE);
    connect(ellipseToolAction, SIGNAL(triggered()), mapper, SLOT(map()));
    mapper->setMapping(ellipseToolAction, Core::ID::ACTION_DRAW_ELLIPSE);
    connect(polygonToolAction, SIGNAL(triggered()), mapper, SLOT(map()));
    mapper->setMapping(polygonToolAction, Core::ID::ACTION_DRAW_POLYGON);
    connect(rectangleToolAction, SIGNAL(triggered()), mapper, SLOT(map()));
    mapper->setMapping(rectangleToolAction, Core::ID::ACTION_DRAW_RECT);
    connect(roundRectangleToolAction, SIGNAL(triggered()), mapper, SLOT(map()));
    mapper->setMapping(roundRectangleToolAction, Core::ID::ACTION_DRAW_ROUND_RECT);
    connect(mapper, SIGNAL(mapped(QString)), appCtx, SLOT(setCurrentAction(QString)));
    Ui::CommonBar *commonBar = qobject_cast<Ui::CommonBar *>(actionManager->toolBar(Core::ID::COMMON_BAR));
    connect(mapper, SIGNAL(mapped(QString)), commonBar, SLOT(resetCommonBar(QString)));

    connect(ci, SIGNAL(foregroundColorChanged(QColor)), appCtx, SLOT(setPenColor(const QColor &)));
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
         addProjectWindow(pcd->project());
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

/*!
  \internal
  \brief Creates a tool button using given action.
  This action will set as the default action instead of adding into its action list.
  @return the pointer to a QToolButton instance by "new" operation
 */
QToolButton * Ui::MainWindow::createToolButton(QAction *action, QWidget *parent /* = 0 */)
{
    QToolButton *button = new QToolButton(parent);
    button->setDefaultAction(action);
    button->setAutoRaise(true);
    button->setFocusPolicy(Qt::NoFocus);
    return button;
}

/*!
  \internal
  \brief Shows file open dialog.
 */
void Ui::MainWindow::showOpenDialog()
{
    QString path = QFileDialog::getOpenFileName(
            this,
            tr("Open File"),
            ".",
            tr("All support formats(*.jpg; *.png);;JPEG Files(*.jpg);;PNG Files(*.png)"));
    if(!path.isEmpty()) {
        Core::Project *pro = new Core::Project;
        QPixmap bg(path);
        pro->setBackgroundImage(bg);
        pro->setPath(path);
        QFileInfo pathInfo(path);
        QString name(pathInfo.fileName());
        pro->setPath(path);
        pro->setName(name);
        addProjectWindow(pro);
    }
}

/*!
  \internal
  \brief Adds a project window into application workspace.
 */
void Ui::MainWindow::addProjectWindow(Core::Project *pro)
{
    ProjectWindow *pw = new ProjectWindow(pro);
    mdiArea->addSubWindow(pw);
    pw->show();
}

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
  \file projectwindow.cpp
  \ingroup Ui
  \brief This file contains
  - class Ui::ProjectWindow implemtation
  \author Cheng Liang <changliang.soft@gmail.com>
  \date 2009-9-5 Created.
 */

#include <QSize>
#include <QApplication>
#include <QIcon>
#include <QStatusBar>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QStyle>
#include <QLineEdit>
#include <QLabel>
#include <QPaintEvent>
#include <QPainter>
#include <QBrush>
#include <QScrollBar>

#include "projectwindow.h"
#include "projectview.h"
#include "projectscene.h"
#include "project.h"
#include "appresource.h"

/*!
  \class Ui::ProjectWindow projectwindow.h
  \brief Project window in PicWorks.
  Project window is used for processing project data in PicWorks.
  This is the main graphics view of subwindow added in MDI space.
  \version 0.0.1
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2009-9-5 Created.
 */

/*!
  \brief Constructor.
  Creates a new instance of ProjectWindow.
  \param pro project data to show, not null.
  \param parent parent widgets of this window, default value is 0.
 */
Ui::ProjectWindow::ProjectWindow(Core::Project *pro, QWidget *parent /* = 0 */)
        : QMdiSubWindow(parent),
          project(pro)
{
    // entry conditions
    Q_CHECK_PTR(pro);

    setAttribute(Qt::WA_DeleteOnClose);

    setWindowIcon(appRes->icon(Core::AppResource::ProjectIcon));
    setWindowTitle(project->name());
    setMinimumSize(200, 200);

    // project view, the main widget
    view = new ProjectView(this);
    scene = new ProjectScene(project, this);
    view->setScene(scene);
    view->setSceneRect(0, 0, project->width(), project->height());
    QScrollArea* centerPanel = new QScrollArea(this);
    centerPanel->viewport()->setStyleSheet(QString("background-color:#C0C0C0"));
    centerPanel->setAlignment(Qt::AlignCenter);
    centerPanel->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    centerPanel->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    centerPanel->setWidget(view);

    // status bar
    statusBar = new QWidget(this);
    QHBoxLayout *statusLayout = new QHBoxLayout(statusBar);
    statusLayout->setMargin(0);
    statusBar->setLayout(statusLayout);
    QLineEdit* percentInput = new QLineEdit(statusBar);
    percentInput->setText("100");
    percentInput->setFixedSize(40, 18);
    QLabel *msgLabel = new QLabel(statusBar);
    msgLabel->setText("%");
    msgLabel->setFixedWidth(8);
    QLabel *ctrlLabel = new QLabel(statusBar);
    ctrlLabel->setFixedWidth(qApp->style()->pixelMetric(QStyle::PM_ScrollBarExtent) - 6);
    statusLayout->addWidget(percentInput);
    statusLayout->addWidget(msgLabel);
    statusLayout->addWidget(centerPanel->horizontalScrollBar(), 100);
    statusLayout->addWidget(ctrlLabel);

    QWidget *mainPanel = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setMargin(0);
    mainLayout->setSpacing(0);
    mainLayout->addWidget(centerPanel);
    mainLayout->addWidget(statusBar);
    mainPanel->setLayout(mainLayout);
    setWidget(mainPanel);
}

/*!
  \brief Gets the suitable size of project window.
  This size is just suitable for the whole project area with 1px border and
  the scroll bar.
  \return suitable size of this project window
 */
QSize Ui::ProjectWindow::sizeHint() const
{
    QStyle *style = qApp->style();
    int frameBorderWidth = style->pixelMetric(QStyle::PM_MdiSubWindowFrameWidth);
    int frameTitleHeight = style->pixelMetric(QStyle::PM_TitleBarHeight);
    int scrollBarWidth = style->pixelMetric(QStyle::PM_ScrollBarExtent);
    return QSize(view->width() + (frameBorderWidth << 1) + scrollBarWidth + 2,
                 view->height() + frameTitleHeight + frameBorderWidth + statusBar->height() - 10);
}

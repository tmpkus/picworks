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
  \ingroup View
  \brief This file contains
  - class View::ProjectWindow implemtation
  \author Cheng Liang <changliang.soft@gmail.com>
  \date 2009-9-5 Created.
 */

#include <QDebug>
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

#include "projectwindow.h"
#include "projectview.h"
#include "../model/project.h"
#include "../util/appresource.h"

using namespace View;

/*!
  \class View::ProjectWindow projectwindow.h
  \brief Project window in PicWorks.
  Project window is used for showing project data in PicWorks.
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
ProjectWindow::ProjectWindow(Data::Project *pro, QWidget *parent /* = 0 */)
        : QMdiSubWindow(parent), project(pro)
{
    // entry conditions
    Q_CHECK_PTR(pro);

    setAttribute(Qt::WA_DeleteOnClose);

    setWindowIcon(AppRes.icon(Global::AppResource::ProjectIcon));
    setWindowTitle(project->name());
    setMinimumSize(200, 200);

    // project view, the main widget
    view = new ProjectView(project, this);
    QScrollArea* centerPanel = new QScrollArea;
    centerPanel->setAlignment(Qt::AlignCenter);
    centerPanel->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    centerPanel->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    centerPanel->setWidget(view);

    // status bar
    statusBar = new QStatusBar(this);
    statusBar->setStyleSheet(QString("QStatusBar::item{border: 0px}"));
    QLineEdit* percentInput = new QLineEdit;
    percentInput->setText("100");
    percentInput->setFixedSize(40, 18);
    QLabel *msgLabel = new QLabel;
    msgLabel->setText("%");
    msgLabel->setFixedWidth(8);
    statusBar->addWidget(percentInput);
    statusBar->addWidget(msgLabel);

    QWidget *mainPanel = new QWidget;
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setMargin(0);
    mainLayout->setSpacing(0);
    mainLayout->addWidget(centerPanel);
    mainLayout->addWidget(statusBar);
    mainPanel->setLayout(mainLayout);
    setWidget(mainPanel);
}

/*!
  \brief Destructor.
 */
ProjectWindow::~ProjectWindow()
{
}

/*!
  \brief Gets the suitable size of project window.
  This size is just suitable for the whole project area with 1px border and
  the scroll bar.
  \return suitable size of this project window
 */
QSize ProjectWindow::sizeHint() const
{
    QStyle *style = qApp->style();
    int frameBorderWidth = style->pixelMetric(QStyle::PM_MdiSubWindowFrameWidth);
    int frameTitleHeight = style->pixelMetric(QStyle::PM_TitleBarHeight);
    int scrollBarWidth = style->pixelMetric(QStyle::PM_ScrollBarExtent);
    return QSize(view->width() + (frameBorderWidth << 1) + scrollBarWidth + 2,
                 view->height() + frameTitleHeight + frameBorderWidth + scrollBarWidth + statusBar->height() - 4);
}

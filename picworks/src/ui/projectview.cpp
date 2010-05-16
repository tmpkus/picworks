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
  \file projectview.cpp
  \ingroup Ui
  \brief This file contains
  - class Ui::ProjectView implemtation
  \author Cheng Liang <changliang.soft@gmail.com>
  \date 2009-9-19 Created.
 */

#include <QSize>

#include <QAction>
#include <QIcon>
#include <QStatusBar>

#include "projectview.h"
#include "projectscene.h"

/*!
  \class Ui::ProjectView projectview.h
  \brief Project view in PicWorks.
  Project view is used for viewing project scene in PicWorks. This is the main
  graphics view of subwindow added in MDI space. The difference between this
  and project scene is that this view only has operations of view component
  such as mouse control and message to show in status bar while the scene can
  show a project by its data such as background color and so on. They are quite
  similar to the whole world and a view port of a camera.
  \sa ProjectScene
  \version 0.0.1
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2009-9-5 Created.
 */

/*!
  \brief Constructor.
  Creates a new instance of ProjectView.
  \param parent parent widgets of this window, default value is 0.
 */
Ui::ProjectView::ProjectView(QWidget *parent /* = 0 */)
        : QGraphicsView(parent)
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setStyleSheet("border: 1px solid black");
}

/*!
  \brief Resizes graphics panel to be fit for project.
  \return Size to be fit for project, that is
  (project->width() + 2) * (project->height() + 2)
  for each side has 1px border
 */
QSize Ui::ProjectView::sizeHint() const
{
    return QSize(sceneRect().width() + 2, sceneRect().height() + 2);
}

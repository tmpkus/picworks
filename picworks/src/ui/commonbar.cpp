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
  \file commonbar.cpp
  \ingroup Ui
  \brief This file contains
  - class Ui::CommonBar implemtation
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2010-7-23 Created.
 */

#include <QAction>

#include "appcontext.h"
#include "commonbar.h"
#include "qtcolorpicker.h"
#include "penwidthpicker.h"
#include "constants.h"

/*!
  \class Ui::CommonBar commonbar.h
  \brief Common bar of application.
  The common bar is a bar that serveral tools shared. For example, line button
  and rectangle button properties can be added on one common bar.
  \version 0.0.1
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2010-7-23 Created.
 */

Ui::CommonBar::CommonBar(QWidget *parent /* = 0 */)
    : QToolBar(parent),
      penColorAction(NULL),
      penWidthAction(NULL)
{
    QtColorPicker *penColorPicker = new QtColorPicker(this, -1, true, false);
    penColorPicker->setStandardColors();
    penColorPicker->setCurrentColor(Qt::black);
    penColorPicker->setMaximumSize(20, 20);
    penColorPicker->setToolTip(tr("Choose pen color.", "Pen color button on Common Bar."));
    penColorAction = addWidget(penColorPicker);

    PenWidthPicker *penWidthPicker = new PenWidthPicker(true, this);
    penWidthPicker->setToolTip(tr("Choose pen width.", "Pen width button on Common Bar."));
    penWidthPicker->setWidthRange(1, appCtx->maxPenWidth());
    penWidthAction = addWidget(penWidthPicker);

    setStyleSheet(QString("QToolBar{spacing: 2px;}"));
    this->setFixedHeight(25);

    connect(penColorPicker, SIGNAL(colorChanged(const QColor &)),
            appCtx, SLOT(setPenColor(const QColor &)));
    connect(penWidthPicker, SIGNAL(penWidthChanged(int,int)),
            appCtx, SLOT(setPenWidth(int)));
}

/*!
  \brief Resets common bar by action id.
  \param actId action id
 */
void Ui::CommonBar::resetCommonBar(const QString &actId)
{
    if(actId == Core::ID::ACTION_DRAW_TEXT) {

    } else if(actId == Core::ID::ACTION_DRAW_CURVE) {

    } else if(actId == Core::ID::ACTION_DRAW_ELLIPSE) {

    } else if(actId == Core::ID::ACTION_DRAW_LINE) {
//        penColorAction->setVisible(true);
//        penWidthAction->setVisible(true);
    } else if(actId == Core::ID::ACTION_DRAW_POLYGON) {

    } else if(actId == Core::ID::ACTION_DRAW_RECT) {

    } else if(actId == Core::ID::ACTION_DRAW_ROUND_RECT) {

    } else {
        // no such action id, do nothing...
    }
}

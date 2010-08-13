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
#include <QActionGroup>
#include <QMenu>
#include <QHBoxLayout>
#include <QSpinBox>
#include <QSignalMapper>

#include "appcontext.h"
#include "commonbar.h"
#include "qtcolorpicker.h"
#include "constants.h"
#include "appresource.h"

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
      penWidthAction(NULL)
{
    // pen width picker
    PenWidthPicker *penWidthPicker = new PenWidthPicker(true, this);
    penWidthPicker->setToolTip(tr("Choose pen width.", "Pen width button on Common Bar."));
    penWidthPicker->setWidthRange(1, appCtx->maxPenWidth());
    penWidthAction = addWidget(penWidthPicker);
    penWidthAction->setVisible(false);

    // antialiasing
    AntialiasingPicker *antiBox = new AntialiasingPicker(this);
    antialiasingBoxAction = addWidget(antiBox);
    antialiasingBoxAction->setVisible(false);

    setStyleSheet(QString("QToolBar{spacing: 2px;}"));
    this->setFixedHeight(25);

    connect(penWidthPicker, SIGNAL(penWidthChanged(int, int)),
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
        penWidthAction->setVisible(true);
        antialiasingBoxAction->setVisible(true);
    } else if(actId == Core::ID::ACTION_DRAW_POLYGON) {

    } else if(actId == Core::ID::ACTION_DRAW_RECT) {

    } else if(actId == Core::ID::ACTION_DRAW_ROUND_RECT) {

    } else {
        // no such action id, do nothing...
    }
}

/*!
  \class Ui::PenWidthPicker commonbar.h
  \brief Picker for pen width.
  \version 0.0.1
  \version 0.0.2 Changed to spin box.
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2010-7-23 Created.

  \fn void View::PenWidthPicker::penWidthChanged(int newValue, int oldValue)
  \brief Emits when pen width value changed.
  \param newValue the new value of pen width
  \param oldValue the old value of pen width

  \fn void View::PenWidthPicker::setPenWidth(int w)
  \brief Sets pen width.
  This setter will emit \a penWidthChanged signal if pen width value changed.
  \param w the new value of pen width
 */

/*!
  \brief Constructs a chooser.
  \param showLabel \a true if show text label
  \param parent parent widget pointer
 */
Ui::PenWidthPicker::PenWidthPicker(bool showLabel /* = true */, QWidget *parent /* = 0*/)
    : QWidget(parent),
      pw(1)
{
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setMargin(0);

    if(showLabel) {
        QLabel *label = new QLabel(this);
        label->setText(tr("Pen Width", "Pen width text on Common Bar."));
        layout->addWidget(label);
    }
    widthBox = new QSpinBox(this);
    widthBox->setFixedWidth(45);
    widthBox->setValue(1);
    layout->addWidget(widthBox);
    setLayout(layout);

    connect(widthBox, SIGNAL(valueChanged(int)), this, SLOT(setPenWidth(int)));
}

/*!
  \brief Sets pen width range.
  \param min minimum value of pen width
  \param max maximum value of pen width
 */
void Ui::PenWidthPicker::setWidthRange(int min, int max)
{
    if(widthBox) {
        widthBox->setRange(min, max);
    }
}

/*!
  \class Ui::AntialiasingPicker commonbar.h
  \brief Picker for antialiasing or not.
  \version 0.0.1
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2010-7-24 Created.
 */

Ui::AntialiasingPicker::AntialiasingPicker(QWidget *parent /* = 0 */)
    : QToolButton(parent)
{
    setPopupMode(QToolButton::InstantPopup);

    QMenu *antiMenu = new QMenu(this);
    QAction *antiAction = new QAction(appRes->icon(Core::AppResource::AntialiasingIcon), tr("turn on antialiasing"), antiMenu);
    antiAction->setCheckable(true);
    antiAction->setChecked(true);
    antiAction->setData(1);
    QAction *aliasingAction = new QAction(appRes->icon(Core::AppResource::AliasingIcon), tr("turn off antialiasing"), antiMenu);
    aliasingAction->setCheckable(true);
    aliasingAction->setData(0);
    antiMenu->addAction(antiAction);
    antiMenu->addAction(aliasingAction);
    setMenu(antiMenu);
    setIcon(appRes->icon(Core::AppResource::AntialiasingIcon));

    QActionGroup *actGroup = new QActionGroup(antiMenu);
    actGroup->addAction(antiAction);
    actGroup->addAction(aliasingAction);

    QSignalMapper *mapper = new QSignalMapper(this);
    mapper->setMapping(aliasingAction, 0);
    mapper->setMapping(antiAction, 1);

    connect(antiAction, SIGNAL(triggered()), mapper, SLOT(map()));
    connect(aliasingAction, SIGNAL(triggered()), mapper, SLOT(map()));
    connect(mapper, SIGNAL(mapped(int)), this, SLOT(enableAntialiasing(int)));
}

void Ui::AntialiasingPicker::enableAntialiasing(int enable)
{
    if(enable) {
        setIcon(appRes->icon(Core::AppResource::AntialiasingIcon));
    } else {
        setIcon(appRes->icon(Core::AppResource::AliasingIcon));
    }
}

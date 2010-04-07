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
  \file penwidthchooser.cpp
  \ingroup View
  \brief This file contains
  - class PicWorks::PenWidthChooser implemtation
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2009-12-4 Created.
 */

#include <QDebug>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QLabel>

#include "penwidthchooser.h"
#include "../util/appcontext.h"

/*!
  \class PicWorks::PenWidthChooser penwidthchooser.h
  \brief Chooser for pen width.
  \version 0.0.1
  \version 0.0.2 Changed to spin box.
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2009-12-4 Created.
 */

/*!
  \fn void PicWorks::PenWidthChooser::penWidthChanged(int newValue, int oldValue)
  \brief Emits when pen width value changed.
  \param newValue the new value of pen width
  \param oldValue the old value of pen width
 */

/*!
  \fn void PicWorks::PenWidthChooser::setPenWidth(int w)
  \brief Sets pen width.
  This setter will emit \a penWidthChanged signal if pen width value changed.
  \param w the new value of pen width
 */

/*!
  \brief Constructs a chooser.
  \param showLabel \a true if show text label
  \param parent parent widget pointer
 */
PicWorks::PenWidthChooser::PenWidthChooser(bool showLabel /* = true */, QWidget *parent /* = 0 */)
    : QWidget(parent), pw(1)
{
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setMargin(0);

    if(showLabel) {
        QLabel *label = new QLabel(this);
        label->setText(tr("Pen Width", "Pen width text on Common Bar."));
        layout->addWidget(label);
    }
    QSpinBox *penWidthBox = new QSpinBox(this);
    penWidthBox->setFixedWidth(45);
    penWidthBox->setRange(1, AppCtx.maxPenWidth());
    penWidthBox->setValue(1);
    layout->addWidget(penWidthBox);

    setLayout(layout);

    connect(penWidthBox, SIGNAL(valueChanged(int)), this, SLOT(setPenWidth(int)));
}

/*!
  \brief Destructs this chooser.
 */
PicWorks::PenWidthChooser::~PenWidthChooser()
{
}

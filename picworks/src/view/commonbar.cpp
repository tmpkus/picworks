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
  \file commonbar.cpp
  \ingroup View
  \brief This file contains
  - class View::CommonBar implemtation
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2009-11-27 Created.
 */

#include <QAction>
#include <QToolBar>

#include "commonbar.h"
#include "qtcolorpicker.h"
#include "penwidthchooser.h"
#include "../util/appcontext.h"

/*!
  \class View::CommonBar commonbar.h
  \brief This is the common bar of PicWorks.
  Common bar usually below the commands bar. In PicWorks, many tools have their
  own properties you can set. These properties setting controls are added in this
  common bar.
  \note This class is not a QToolBar or even not a QWidget. In order to get
  the bar, you should use the signlton instance's function \a setCommonBar().
  \version 0.0.1
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2009-11-27 Created.
 */

/*!
  \brief Constructor.
  Creates a new common bar instance.
  \param parent parent widget pointer, default value is 0
 */
View::CommonBar::CommonBar(const QString &title /* = "CommonBar" */, QWidget *parent /* = 0 */)
{
    bar = new QToolBar(title, parent);
    //bar->setContentsMargins(2, 2, 2, 2);

    QtColorPicker *penColorPicker = new QtColorPicker(bar, -1, true, false);
    penColorPicker->setStandardColors();
    penColorPicker->setCurrentColor(appCtx->penColor());
    penColorPicker->setMaximumSize(20, 20);
    penColorPicker->setToolTip(tr("Choose pen color.", "Pen color button on Common Bar."));

    PenWidthChooser *penWidthChooser = new PenWidthChooser(true, bar);
    penWidthChooser->setToolTip(tr("Choose pen width.", "Pen width button on Common Bar."));

    //bar->setStyleSheet(QString("QToolBar{spacing: 2px;}"));
    penColorAction = bar->addWidget(penColorPicker);
    penWidthAction = bar->addWidget(penWidthChooser);

    connect(penColorPicker, SIGNAL(colorChanged(QColor)), appCtx, SLOT(setPenColor(QColor)));
    connect(penWidthChooser, SIGNAL(penWidthChanged(int,int)), appCtx, SLOT(setPenWidth(int)));
}

/*!
  \brief Destructor.
  Destructs the common bar.
 */
View::CommonBar::~CommonBar()
{
}

/*!
  \brief Gets the singleton instance of common bar.
  \param title title of this common bar, default is "CommonBar"
  \param parent pointer of parent widget, default is NULL
  \return the singleton instance of common bar.
 */
View::CommonBar & View::CommonBar::instance(const QString &title /* = "CommonBar" */, QWidget *parent /* = 0 */)
{
    static CommonBar cb(title, parent);
    return cb;
}

/*!
  \brief Gets different common bars according to current action.
  \param data current action
 */
QToolBar * View::CommonBar::createCommonBar(const QVariant & data)
{
    if(data.canConvert(QVariant::Int)) {
        Core::AppResource::Action a = static_cast<Core::AppResource::Action>(data.toInt());
        switch(a) {
        case Core::AppResource::DrawLineAction:
            {
                penColorAction->setVisible(true);
                penWidthAction->setVisible(true);
                break;
            }
        default:
            {
                penColorAction->setVisible(false);
                penWidthAction->setVisible(false);
                break;
            }
        }
    }
    return bar;
}

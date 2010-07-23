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
  \file penwidthpicker.h
  \ingroup Ui
  \brief This file contains
  - class Ui::PenWidthPicker declaration
  \author Cheng Liang <changliang.soft@gmail.com>
  \date 2010-7-23 Created.
 */

#ifndef PENWIDTHPICKER_H
#define PENWIDTHPICKER_H

#include <QWidget>

class QSpinBox;

namespace Ui {

class PenWidthPicker : public QWidget
{
    Q_OBJECT
public:
    PenWidthPicker(bool showLabel = true, QWidget *parent = 0);
    ~PenWidthPicker() {}

signals:
    void penWidthChanged(int newWidth, int oldWidth);

public slots:
    void setPenWidth(int w)
    {
        if(w != pw) {
            emit penWidthChanged(w, pw);
            pw = w;
        }
    }

    void setWidthRange(int min, int max);

private:
    QSpinBox *widthBox;
    int pw;

}; // end of class

} // end of namespace

#endif // PENWIDTHPICKER_H

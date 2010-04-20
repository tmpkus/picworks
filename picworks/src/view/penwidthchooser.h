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
  \file penwidthchooser.h
  \ingroup View
  \brief This file contains
  - class View::PenWidthChooser declaration
  \author Cheng Liang <changliang.soft@gmail.com>
  \date 2009-12-4 Created.
 */

#ifndef PENWIDTHCHOOSER_H
#define PENWIDTHCHOOSER_H

#include <QWidget>

namespace View {

class PenWidthChooser : public QWidget
{
    Q_OBJECT

public:
    PenWidthChooser(bool showLabel = true, QWidget *parent = 0);
    ~PenWidthChooser() {}

public slots:

    void setPenWidth(int w)
    {
        if(w != pw) {
            emit penWidthChanged(w, pw);
            pw = w;
        }
    }

signals:
    void penWidthChanged(int newWidth, int oldWidth);

private:
    int pw;
};

} // end of namespace

#endif // PENWIDTHCHOOSER_H

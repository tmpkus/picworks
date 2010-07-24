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
  \file commonbar.h
  \ingroup Ui
  \brief This file contains
  - class Ui::CommonBar declaration
  \author Cheng Liang <changliang.soft@gmail.com>
  \date 2010-7-23 Created.
 */

#ifndef COMMONBAR_H
#define COMMONBAR_H

#include <QToolBar>

namespace Ui {

class CommonBar : public QToolBar
{
    Q_OBJECT
public:
    explicit CommonBar(QWidget *parent = 0);

signals:

public slots:
    void resetCommonBar(const QString &actId);

private:
    QAction *penColorAction;
    QAction *penWidthAction;

}; // end of class

} // end of namespace

#endif // COMMONBAR_H

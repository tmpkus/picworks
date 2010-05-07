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
  \file aboutdialog.h
  \ingroup View
  \brief This file contains
  - class View::AboutDialog declaration
  \author Cheng Liang <changliang.soft@gmail.com>
  \date 2009-10-8 Created.
 */

#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>

class QMouseEvent;
class QPaintEvent;
class QPixmap;

namespace Ui {

class AboutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AboutDialog(QWidget *parent = 0);
    ~AboutDialog();

protected:
    void paintEvent(QPaintEvent* event);
    void mousePressEvent(QMouseEvent* event);

private slots:
    void showLicenseDialog();
    void showAboutQtDialog();

private:
    QPixmap backgroundImage;

}; // end of class

} // end of namespace

#endif // ABOUTDIALOG_H

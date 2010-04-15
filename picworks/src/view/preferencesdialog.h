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
  \file preferencesdialog.h
  \ingroup View
  \brief This file contains
  - class View::PreferencesDialog declaration
  \author Cheng Liang <changliang.soft@gmail.com>
  \date 2009-10-17 Created.
 */

#ifndef PREFERENCESDIALOG_H
#define PREFERENCESDIALOG_H

#include <QDialog>

namespace View {

class PreferencesDialog : public QDialog
{
Q_OBJECT
public:
    explicit PreferencesDialog(QWidget *parent = 0);
    virtual ~PreferencesDialog();

}; // end of class

} // end of namespace

#endif // PREFERENCESDIALOG_H

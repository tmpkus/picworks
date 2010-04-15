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
  \file preferencesdialog.cpp
  \ingroup View
  \brief This file contains
  - class View::PreferencesDialog implemtation
  \author Cheng Liang <changliang.soft@gmail.com>
  \date 2009-10-17 Created.
 */

#include <QDebug>
#include <QApplication>

#include "preferencesdialog.h"

using namespace View;

/*!
  \class View::PreferencesDialog preferencesdialog.h
  \brief Preferences dialog in PicWorks.
  PreferencesDialog is a dialog to configure PicWorks. It supplied a friendly UI
  to set PicWorks attributes.
  \version 0.0.1
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2009-10-17 Created.
 */

/*!
  \brief Constructor.
  Creates a new PreferencesDialog instance.
  \param parent parent widget of this dialog, default value is 0
 */
PreferencesDialog::PreferencesDialog(QWidget *parent /* = 0 */)
        : QDialog(parent)
{
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowTitle(tr("Preferences", "Preferences dialog title."));
}

/*!
  \brief Destructs this dialog.
 */
PreferencesDialog::~PreferencesDialog()
{
}

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
  \file projectcreatedialog.h
  \ingroup View
  \brief This file contains
  - class View::ProjectCreateDialog declaration
  \author Cheng Liang <changliang.soft@gmail.com>
  \date 2009-9-5 Created.
 */

#ifndef PROCREATOR_H
#define PROCREATOR_H

#include <QDialog>

class QComboBox;
class QColor;
class QDialogButtonBox;
class QLineEdit;
class QSpinBox;
class QPixmap;
class QStringList;
class QPaintEvent;
class QtColorPicker;

namespace Data {
    class Project;
};

namespace View {

class ProjectCreateDialog : public QDialog
{
    Q_OBJECT
public:
    ProjectCreateDialog(QWidget *parent = 0, Qt::WindowFlags flags = 0);
    virtual ~ProjectCreateDialog();
    Data::Project * getProject();

private:
    QLineEdit *proNameEdit;
    QSpinBox *proWidthBox;
    QSpinBox *proHeightBox;
    QComboBox *proWidthUnitBox;
    QComboBox *proHeightUnitBox;
    QSpinBox *proDpiBox;
    QComboBox *proDpiUnitBox;
    QtColorPicker *proBackgroundColorPicker;
    QDialogButtonBox *buttonBox;
    QColor backgroundColor;

}; // end of class

} // end of namespace

#endif // PROCREATOR_H

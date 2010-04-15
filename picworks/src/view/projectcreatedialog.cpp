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
  \file projectcreatedialog.cpp
  \ingroup View
  \brief This file contains
  - class View::ProjectCreateDialog implemtation
  \author Cheng Liang <changliang.soft@gmail.com>
  \date 2009-9-5 Created.
 */

#include <QDebug>
#include <QString>
#include <QStringList>
#include <QComboBox>
#include <QDialogButtonBox>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QPaintEvent>
#include <QPainter>
#include <QBrush>

#include "qtcolorpicker.h"
#include "projectcreatedialog.h"
#include "../model/project.h"
#include "../util/appresource.h"

using namespace View;

/*!
  \class View::ProjectCreateDialog projectcreatedialog.h
  \brief Creator of project in PicWorks.
  ProjectCreateDialog is a dialog when the action "new" is actived.
  The dialog is used for collecting data from user in order to construct a new project.
  \version 0.0.1
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2009-9-5 Created.
 */

/*!
  \fn void View::ProjectCreateDialog::accept()
  \brief Closes the dialog and emits projectCreated(Project&) signal.
 */

/*!
  \brief Constructor.
  Creates a new ProjectCreateDialog instance.
  \param parent parent widget of this dialog, default value is 0
 */
ProjectCreateDialog::ProjectCreateDialog(QWidget *parent /* = 0 */, Qt::WindowFlags flags /* = 0 */)
        : QDialog(parent, flags), backgroundColor(Qt::white)
{
    // init locale attributes
    // Measurement unit for creating a new project. The sequence of this list must be the
    // same as enum MeasureUnitEnum which defines in global.h.
    QStringList unitList;
    unitList<<AppRes.measurementUnitName(Global::AppResource::pxMeasurementUnit)
            <<AppRes.measurementUnitName(Global::AppResource::cmMeasurementUnit);
    // DPI unit for creating a new project. The sequence of this list must be the
    // same as enum DpiUnit which defines in global.h.
    QStringList dpiList;
    dpiList<<AppRes.dpiUnitName(Global::AppResource::perInchDpiUnit)
           <<AppRes.dpiUnitName(Global::AppResource::perCmDpiUnit);

    setWindowTitle(tr("New", "Project creating dialog title."));
    setWindowIcon(AppRes.icon(Global::AppResource::ApplicationIcon));
    setFixedSize(260, 240);

    // project name
    QLabel *nameLabel = new QLabel(tr("Project &Name:", "Project name text on Project creating dialog."));
    nameLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    nameLabel->setFixedWidth(nameLabel->sizeHint().width());
    proNameEdit = new QLineEdit(tr("untitled", "Default project name."));
    nameLabel->setBuddy(proNameEdit);

    // project properties
    QLabel *widthLabel = new QLabel(tr("&Width:", "Project width text on Project creating dialog."));
    widthLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    proWidthBox = new QSpinBox;
    proWidthBox->setFixedWidth(50);
    proWidthBox->setMaximum(5000);
    proWidthBox->setMinimum(1);
    proWidthBox->setValue(800);
    widthLabel->setBuddy(proWidthBox);
    proWidthUnitBox = new QComboBox;
    proWidthUnitBox->setFixedWidth(50);
    proWidthUnitBox->addItems(unitList);

    QLabel *heightLabel = new QLabel(tr("&Height:", "Project height text on Project creating dialog."));
    heightLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    proHeightBox = new QSpinBox;
    proHeightBox->setFixedWidth(50);
    proHeightBox->setMaximum(5000);
    proHeightBox->setMinimum(1);
    proHeightBox->setValue(600);
    heightLabel->setBuddy(proHeightBox);
    proHeightUnitBox = new QComboBox;
    proHeightUnitBox->setFixedWidth(50);
    proHeightUnitBox->addItems(unitList);

    QLabel *dpiLabel = new QLabel(tr("&DPI:", "Project DPI text on Project creating dialog."));
    dpiLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    proDpiBox = new QSpinBox;
    proDpiBox->setFixedWidth(50);
    proDpiBox->setMaximum(9999);
    proDpiBox->setMinimum(1);
    proDpiBox->setValue(72);
    dpiLabel->setBuddy(proDpiBox);
    proDpiUnitBox = new QComboBox;
    proDpiUnitBox->addItems(dpiList);
    proDpiUnitBox->setFixedWidth(90);

    QLabel *backgroundColorLabel = new QLabel(tr("&Background:", "Project background color text on Project creating dialog."));
    backgroundColorLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    backgroundColorLabel->setFixedWidth(backgroundColorLabel->sizeHint().width());
    backgroundColorLabel->setWhatsThis(tr("Click the following button to choose a background color.", "Project background color help context."));
    proBackgroundColorPicker = new QtColorPicker(this);
    proBackgroundColorPicker->setStandardColors();
    proBackgroundColorPicker->setCurrentColor(Qt::white);
    backgroundColorLabel->setBuddy(proBackgroundColorPicker);

    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
                                  | QDialogButtonBox::Cancel);

    QGroupBox *propertiesGroup = new QGroupBox(tr("Project Properties", "Project properties group title."));
    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->addWidget(widthLabel, 0, 0);
    gridLayout->addWidget(proWidthBox, 0, 1);
    gridLayout->addWidget(proWidthUnitBox, 0, 2);
    gridLayout->addWidget(heightLabel, 1, 0);
    gridLayout->addWidget(proHeightBox, 1, 1);
    gridLayout->addWidget(proHeightUnitBox, 1, 2);
    gridLayout->addWidget(dpiLabel, 2, 0);
    gridLayout->addWidget(proDpiBox, 2, 1);
    gridLayout->addWidget(proDpiUnitBox, 2, 2);
    gridLayout->addWidget(backgroundColorLabel, 3, 0);
    gridLayout->addWidget(proBackgroundColorPicker, 3, 1, 1, 3);
    propertiesGroup->setLayout(gridLayout);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(nameLabel, 0, 0);
    mainLayout->addWidget(proNameEdit, 0, 1);
    mainLayout->addWidget(propertiesGroup, 1, 0, 1, 2);
    mainLayout->addWidget(buttonBox, 2, 0, 1, 2);
    setLayout(mainLayout);

    // establish connections
    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
}

/*!
  \brief Destructor.
  Destructs this dialog.
 */
ProjectCreateDialog::~ProjectCreateDialog()
{
}

/*!
  \brief Gets the project data.
  \return pointer of project instance
 */
Data::Project * ProjectCreateDialog::getProject()
{
    Data::Project *p = new Data::Project;
    p->setName(proNameEdit->text());
    p->setWidth(proWidthBox->value());
    p->setHeight(proHeightBox->value());
    p->setWidthUnit(static_cast<Global::AppResource::MeasurementUnit>(proWidthUnitBox->currentIndex()));
    p->setHeightUnit(static_cast<Global::AppResource::MeasurementUnit>(proHeightUnitBox->currentIndex()));
    p->setDpi(proDpiBox->value());
    p->setDpiUnit(static_cast<Global::AppResource::DpiUnit>(proDpiUnitBox->currentIndex()));
    p->setBackgroundColor(proBackgroundColorPicker->currentColor());
    return p;
}

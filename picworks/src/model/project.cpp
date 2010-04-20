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
  \file project.cpp
  \ingroup Model
  \brief This file contains
  - class Data::Project implemtation
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2009-9-5 Created.
 */

#include "project.h"

/*!
  \brief Project data in PicWorks.
  This is the set of data used for PicWorks project. A project is usually an opened image
  file or empty file created by PicWorks itself. The pws format, which can be generated
  by PicWorks, is saved according to the data stored in Project class.
  All data of a single project is saved here. Each project should include these data.
  Views to show project can be created by this class. Each setter function will emit a signal.
  Notice the data of project has default values:
  - name: "untitled", not empty
  - width: 800, positive integer, in \a widthUnit
  - height: 600, positive integer, in \a heightUnit
  - widthUnit: "px", not empty, valid values are
       - pxMeasurementUnit, pixel
       - cmMeasurementUnit, centimeter
  - heightUnit: "px", not empty, valid values are
       - pxMeasurementUnit, pixel
       - cmMeasurementUnit, centimeter
  - DPI: 72, positive integer, in \a dpiUnit
  - dpiUnit: "preInch", not empty, valid values are
       - preInchDpiUnit, dots/inch
       - preCmDpiUnit, dots/centimeter
  - backgroundColor: Qt::white
  \note This is a subclass of class QObject, so there are some signals and slots in this class.
  \version 0.0.1
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2009-9-5 Created.
 */

/*!
  \fn void Data::Project::setName(const QString& n)
  \brief Sets project name.
  \a projectNameChanged signal will be emited if new name
  is different from the old one.
  \param n new name of this project, default value is "untitled"

  \fn void Data::Project::setWidth(const int w)
  \brief Sets width of the project in \a widthUnit.
  \a projectWidthChanged signal will be emited if new width value
  is different from the old one.
  \param w new width of the project, positive integer, default value is 800

  \fn void Data::Project::setHeight(const int h)
  \brief Sets height of the project in \a heightUnit.
  \a projectHeightChanged signal will be emited if new height value
  is different from the old one.
  \param h new height of the project, positive integer, default value is 600

  \fn void Data::Project::setWidthUnit(Core::AppResource::MeasurementUnit wu)
  \brief Sets measure unit of width.
  \a projectWidthUnitChanged signal will be emited if new unit
  is different from the old one.
  \param wu new measure unit of width, default value is AppResource::pxMeasurementUnit,
  which stand for px, other valid value is:
   - pxMeasurementUnit: pixel
   - cmMeasurementUnit: centimeter
  which defines in global.h

  \fn void Data::Project::setHeightUnit(AppResource::MeasurementUnit wu)
  \brief Sets measure unit of height.
  \a projectHeightUnitChanged signal will be emited if new unit
  is different from the old one.
  \param wu new measure unit of height, default value is AppResource::pxMeasurementUnit,
  which stand for px, other valid value is:
   - pxMeasurementUnit: pixel
   - cmMeasurementUnit: centimeter
  which defines in global.h

  \fn void Data::Project::setDpi(const int dpi)
  \brief Sets DPI for project in \a dpiUnit.
  \a projectDpiChanged signal will be emited if new DPI value
  is different from the old one.
  \param dpi new dpi value, positive integer, default value is 72.

  \fn void Data::Project::setDpiUnit(AppResource::DpiUnit dpiUnit)
  \brief Sets measure unit of dpi.
  \a projectDpiUnitChanged signal will be emited if new unit
  is different from the old one.
  \param dpiUnit new measure unit of dpi, default value is AppResource::perInchDpiUnit,
  which stard for pixel per inch, other valid values is:
   - perInchDpiUnit: pixel per inch
   - perCmDpiUnit: pixel per centimeter
  which defines in global.h

  \fn void Data::Project::setBackgroundColor(const QColor& color)
  \brief Sets background color.
  \a projectBackgroundColorChanged signal will be emited if new color
  is different from the old one.
  \param color new background color, default value is Qt::white

  \fn const QString & Data::Project::name() const
  \brief Gets the name of the project.
  \return name of this project

  \fn int Data::Project::width() const
  \brief Gets the width of the project.
  \return width of this project

  \fn int Data::Project::height() const
  \brief Gets the height of the project.
  \return height of this project

  \fn AppResource::MeasurementUnit Data::Project::widthUnit() const
  \brief Gets the measure unit code of width.
  \return measure unit code of width, that is defined in global.h

  \fn AppResource::MeasurementUnit Data::Project::heightUnit() const
  \brief Gets the measure unit code of height.
  \return measure unit code of height, that is defined in global.h

  \fn int Data::Project::dpi() const
  \brief Gets dpi of the project.
  \return dpi of this project

  \fn AppResource::DpiUnit Data::Project::dpiUnit() const
  \brief Gets the measure unit code of dpi.
  \return measure unit of dpi, that is defined in global.h

  \fn const QColor & Data::Project::backgroundColor() const
  \brief Gets background color of the project.
  \return background color of the project

  \fn void Data::Project::projectNameChanged(const QString &newName, const QString &oldName)
  \brief Emits when project name has been changed.
  \param newName new project name
  \param oldName old project name

  \fn void Data::Project::projectWidthChanged(const int newWidth, const int oldWidth)
  \brief Emits when project width has been changed.
  \param newWidth new project width
  \param oldWidth old project width

  \fn void Data::Project::projectHeightChanged(const int newHeight, const int oldHeight)
  \brief Emits when project height has been changed.
  \param newHeight new project height
  \param oldHeight old project height

  \fn void Data::Project::projectWidthUnitChanged(const AppResource::MeasurementUnit newWidthUnit, const AppResource::MeasurementUnit oldWidthUnit)
  \brief Emits when project width unit code has been changed.
  \param oldHeightUnit old project width unit code
  \param oldWidthUnit old project width unit code

  \fn void Data::Project::projectHeightUnitChanged(const AppResource::MeasurementUnit newHeightUnit, const AppResource::MeasurementUnit oldHeightUnit)
  \brief Emits when project height unit code has been changed.
  \param newHeightUnit new project height unit code
  \param oldHeightUnit old project height unit code

  \fn void Data::Project::projectDpiChanged(const int newDpi, const int oldDpi)
  \brief Emits when project DPI has been changed.
  \param newDpi new project DPI
  \param oldDpi old project DPI

  \fn void Data::Project::projectDpiUnitChanged(const AppResource::DpiUnit newDpiUnit, const AppResource::DpiUnit oldDpiUnit)
  \brief Emits when project DPI unit has been changed.
  \param newDpiUnit new project DPI unit
  \param oldDpiUnit old project DPI unit

  \fn void Data::Project::projectBackgroundColorChanged(const QColor &newColor, const QColor &oldColor)
  \brief Emits when project background color has been changed.
  \param newColor old project background color
  \param oldColor old project background color
 */

/*!
  \brief Constructor.
  Creates a new project.
 */
Data::Project::Project()
    : projectName(tr("untitled", "Init Project name.")),
      projectWidth(800),
      projectHeight(600),
      projectWidthUnit(Core::AppResource::pxMeasurementUnit),
      projectHeightUnit(Core::AppResource::pxMeasurementUnit),
      projectDpi(72),
      projectDpiUnit(Core::AppResource::perInchDpiUnit),
      projectBackgroundColor(Qt::white)
{
}

/*!
  \brief Destructor.
  Destructs a project.
 */
Data::Project::~Project()
{
}

/*!
  \brief Shows project data as a string.
  This is useful for some debug text.
  \return projct data as a string
 */
QString Data::Project::toString() const
{
    return QString("Project: [name=%1;\n\twidth=%2 %3;\n\theight=%4 %5;\n\tDPI: %6 %7\n\tbackground color=RBGA(%8, %9, %10, %11)]")
            .arg(projectName)
            .arg(projectWidth).arg(appRes->measurementUnitName(projectWidthUnit))
            .arg(projectHeight).arg(appRes->measurementUnitName(projectHeightUnit))
            .arg(projectDpi).arg(appRes->dpiUnitName(projectDpiUnit))
            .arg(projectBackgroundColor.red())
            .arg(projectBackgroundColor.green())
            .arg(projectBackgroundColor.blue())
            .arg(projectBackgroundColor.alpha());
}

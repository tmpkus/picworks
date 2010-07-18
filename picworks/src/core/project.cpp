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
  \file project.cpp
  \ingroup Core
  \brief This file contains
  - class Core::Project implemtation
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2010-5-6 Created.
 */

#include <QPixmap>
#include "project.h"

/*!
  \brief Project unit data in PicWorks.
  This is the set of data used for PicWorks project. A project is usually an opened image
  file or empty file created by PicWorks itself. The "gpw" format, which can be generated
  by PicWorks, is saved according to the data stored in Project class.
  All data of a single project is saved here. Each project should include these data.
  Views to show project can be created by this class. Each setter function will emit a signal.
  Note the data of project has default values:
  - name: "untitled", not empty
  - path: ""
  - width: 800, positive integer, in \a widthUnit
  - height: 600, positive integer, in \a heightUnit
  - widthUnit: "px", not empty, valid values are
       - Core::AppResource::px, pixel
       - Core::AppResource::cm, centimeter
  - heightUnit: "px", not empty, valid values are
       - Core::AppResource::px, pixel
       - Core::AppResource::cm, centimeter
  - DPI: 72, positive integer, in \a dpiUnit
  - dpiUnit: "preInch", not empty, valid values are
       - Core::AppResource::preInch, dots/inch
       - Core::AppResource::preCmDpi, dots/centimeter
  - backgroundColor: Qt::white
  - backgroundImage: QPixmap()
  \note This is a subclass of class QObject, so there are some signals and slots in this class.
  \version 0.0.1
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2009-9-5 Created.
 */

/*!
  \fn void Core::Project::setName(const QString & n)
  \brief Sets project name.
  \a projectNameChanged signal will be emited if new name
  is different from the old one.
  \param n new name of this project, default value is "untitled"

  \fn void Core::Project::setPath(const QString & p)
  \brief Sets project path.
  \a projectPathChanged signal will be emited if new path
  is different from the old one.
  \param p new path of this project, default value is \a QString::Null

  \fn void Core::Project::setWidth(int w)
  \brief Sets width of the project in \a widthUnit.
  \a projectWidthChanged signal will be emited if new width value
  is different from the old one.
  \param w new width of the project, positive integer, default value is 800

  \fn void Core::Project::setHeight(int h)
  \brief Sets height of the project in \a heightUnit.
  \a projectHeightChanged signal will be emited if new height value
  is different from the old one.
  \param h new height of the project, positive integer, default value is 600

  \fn void Core::Project::setWidthUnit(Core::AppResource::MeasurementUnit wu)
  \brief Sets measure unit of width.
  \a projectWidthUnitChanged signal will be emited if new unit
  is different from the old one.
  \param wu new measure unit of width, default value is
  Core::AppResource::px, which stand for px, other valid value is:
   - px: pixel
   - cm: centimeter
  which defines in Core::AppResource

  \fn void Core::Project::setHeightUnit(AppResource::MeasurementUnit hu)
  \brief Sets measure unit of height.
  \a projectHeightUnitChanged signal will be emited if new unit
  is different from the old one.
  \param hu new measure unit of height, default value is
  Core::AppResource::px, which stand for px, other valid value is:
   - px: pixel
   - cm: centimeter
  which defines in Core::AppResource

  \fn void Core::Project::setDpi(int dpi)
  \brief Sets DPI for project in \a dpiUnit.
  \a projectDpiChanged signal will be emited if new DPI value
  is different from the old one.
  \param dpi new dpi value, positive integer, default value is 72.

  \fn void Core::Project::setDpiUnit(AppResource::DpiUnit dpiUnit)
  \brief Sets measure unit of dpi.
  \a projectDpiUnitChanged signal will be emited if new unit
  is different from the old one.
  \param dpiUnit new measure unit of dpi, default value is Core::AppResource::perInch,
  which stard for pixel per inch, other valid values is:
   - perInch: pixel per inch
   - perCm: pixel per centimeter
  which defines in Core::AppResource

  \fn void Core::Project::setBackgroundColor(const QColor& color)
  \brief Sets background color.
  \a projectBackgroundColorChanged signal will be emited if new color
  is different from the old one.
  \param color new background color, default value is Qt::white

  \fn void Core::Project::setBackgroundImage(const QPixmap& img)
  \brief Sets background image.
  \note Project width and height will be set as the width and height of image.
  \param img new background image, default value is QPixmap()

  \fn const QString & Core::Project::name() const
  \brief Gets the name of the project.
  \return name of this project

  \fn const QString & Core::Project::path() const
  \brief Gets the path of the project.
  Path is the full path of the file. If project is read from file,
  the path will be set as the file path.
  \return path of this project

  \fn int Core::Project::width() const
  \brief Gets the width of the project.
  \return width of this project

  \fn int Core::Project::height() const
  \brief Gets the height of the project.
  \return height of this project

  \fn AppResource::MeasurementUnit Core::Project::widthUnit() const
  \brief Gets the measure unit code of width.
  \return measure unit code of width, that is defined in global.h

  \fn AppResource::MeasurementUnit Core::Project::heightUnit() const
  \brief Gets the measure unit code of height.
  \return measure unit code of height, that is defined in global.h

  \fn int Core::Project::dpi() const
  \brief Gets dpi of the project.
  \return dpi of this project

  \fn AppResource::DpiUnit Core::Project::dpiUnit() const
  \brief Gets the measure unit code of dpi.
  \return measure unit of dpi, that is defined in global.h

  \fn const QColor & Core::Project::backgroundColor() const
  \brief Gets background color of the project.
  \return background color of the project

  \fn const QPixmap & Core::Project::backgroundImage() const
  \brief Gets background image of the project.
  \return background image of the project

  \fn void Core::Project::projectNameChanged(const QString &oldName)
  \brief Emits when project name has been changed.
  \param oldName old project name

  \fn void Core::Project::projectPathChanged(const QString &oldPath)
  \brief Emits when project path has been changed.
  \param oldPath old project path

  \fn void Core::Project::projectWidthChanged(int oldWidth)
  \brief Emits when project width has been changed.
  \param oldWidth old project width

  \fn void Core::Project::projectHeightChanged(int oldHeight)
  \brief Emits when project height has been changed.
  \param oldHeight old project height

  \fn void Core::Project::projectWidthUnitChanged(AppResource::MeasurementUnit oldWidthUnit)
  \brief Emits when project width unit code has been changed.
  \param oldWidthUnit old project width unit code

  \fn void Core::Project::projectHeightUnitChanged(AppResource::MeasurementUnit oldHeightUnit)
  \brief Emits when project height unit code has been changed.
  \param oldHeightUnit old project height unit code

  \fn void Core::Project::projectDpiChanged(int oldDpi)
  \brief Emits when project DPI has been changed.
  \param oldDpi old project DPI

  \fn void Core::Project::projectDpiUnitChanged(AppResource::DpiUnit oldDpiUnit)
  \brief Emits when project DPI unit has been changed.
  \param oldDpiUnit old project DPI unit

  \fn void Core::Project::projectBackgroundColorChanged(const QColor &oldColor)
  \brief Emits when project background color has been changed.
  \param oldColor old project background color
 */

Core::Project::Project()
    : dName(tr("untitled", "Init Project name.")),
      dPath(QString()),
      w(800),
      h(600),
      wUnit(Core::AppResource::px),
      hUnit(Core::AppResource::px),
      d(72),
      dUnit(Core::AppResource::perInch),
      bgColor(Qt::white),
      bgImage(QPixmap())
{
}

/*!
  \brief Shows project data as a string.
  \return projct data as a string
 */
QString Core::Project::toString() const
{
    return QString("Project: [name=%1;\n\tpath=%2;\n\twidth=%3 %4;\n\theight=%5 %6;\n\tDPI=%7 %8\n\tbackground color=RBGA(%9, %10, %11, %12)]")
            .arg(dName)
            .arg(dPath)
            .arg(w).arg(appRes->measurementUnitName(wUnit))
            .arg(h).arg(appRes->measurementUnitName(hUnit))
            .arg(d).arg(appRes->dpiUnitName(dUnit))
            .arg(bgColor.red())
            .arg(bgColor.green())
            .arg(bgColor.blue())
            .arg(bgColor.alpha());
}

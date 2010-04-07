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
  \file project.h
  \ingroup Model
  \brief This file contains
  - class PicWorks::Project declaration
  \author Cheng Liang <changliang.soft@gmail.com>
  \date 2009-9-5 Created.
 */

#ifndef PROJECT_H
#define PROJECT_H

#include <QString>
#include <QObject>
#include <QColor>
#include "../util/appresource.h"

namespace PicWorks {

class Project : public QObject
{
    Q_OBJECT

public:
    Project();
    virtual ~Project();
    QString toString() const;

    inline const QString & name() const { return projectName; }

    inline int width() const { return projectWidth; }

    inline int height() const { return projectHeight; }

    inline AppResource::MeasurementUnit widthUnit() const { return projectWidthUnit; }

    inline AppResource::MeasurementUnit heightUnit() const { return projectHeightUnit; }

    inline int dpi() const { return projectDpi; }

    inline AppResource::DpiUnit dpiUnit() const { return projectDpiUnit; }

    inline const QColor & backgroundColor() const { return projectBackgroundColor; }

public slots:
    inline void setName(const QString& n)
    {
        if(n != projectName) {
            emit projectNameChanged(n, projectName);
            projectName = n;
        }
    }

    inline void setWidth(const int w)
    {
        Q_ASSERT(w > 0);
        if(w != projectWidth) {
            emit projectWidthChanged(w, projectWidth);
            projectWidth = w;
        }
    }

    inline void setHeight(const int h)
    {
        Q_ASSERT(h > 0);
        if(h != projectHeight) {
            emit projectHeightChanged(h, projectHeight);
            projectHeight = h;
        }
    }

    inline void setWidthUnit(AppResource::MeasurementUnit wu)
    {
        if(wu != projectWidthUnit) {
            emit projectWidthUnitChanged(wu, projectWidthUnit);
            projectWidthUnit = wu;
        }
    }

    inline void setHeightUnit(AppResource::MeasurementUnit hu)
    {
        if(hu != projectHeightUnit) {
            emit projectHeightUnitChanged(hu, projectHeightUnit);
            projectHeightUnit = hu;
        }
    }

    inline void setDpi(const int dpi)
    {
        Q_ASSERT(dpi > 0);
        if(dpi != projectDpi) {
            emit projectDpiChanged(dpi, projectDpi);
            projectDpi = dpi;
        }
    }

    inline void setDpiUnit(AppResource::DpiUnit dpiUnit)
    {
        if(dpiUnit != projectDpiUnit) {
            emit projectDpiUnitChanged(dpiUnit, projectDpiUnit);
            projectDpiUnit = dpiUnit;
        }
    }

    inline void setBackgroundColor(const QColor& color)
    {
        if(color != projectBackgroundColor) {
            emit projectBackgroundColorChanged(color, projectBackgroundColor);
            projectBackgroundColor = color;
        }
    }

signals:
    void projectNameChanged(const QString &newName, const QString &oldName);
    void projectWidthChanged(const int newWidth, const int oldWidth);
    void projectHeightChanged(const int newHeight, const int oldHeight);
    void projectWidthUnitChanged(const AppResource::MeasurementUnit newWidthUnit, const AppResource::MeasurementUnit oldWidthUnit);
    void projectHeightUnitChanged(const AppResource::MeasurementUnit newHeightUnit, const AppResource::MeasurementUnit oldHeightUnit);
    void projectDpiChanged(const int newDpi, const int oldDpi);
    void projectDpiUnitChanged(const AppResource::DpiUnit newDpiUnit, const AppResource::DpiUnit oldDpiUnit);
    void projectBackgroundColorChanged(const QColor &newColor, const QColor &oldColor);

private:
    QString projectName;
    int projectWidth;
    int projectHeight;
    AppResource::MeasurementUnit projectWidthUnit;
    AppResource::MeasurementUnit projectHeightUnit;
    int projectDpi;
    AppResource::DpiUnit projectDpiUnit;
    QColor projectBackgroundColor;

}; // end of class

} // end of namespace

#endif // PROJECT_H

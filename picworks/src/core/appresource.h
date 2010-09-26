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
  \file appresource.h
  \ingroup Core
  \brief This file contains
  - class Core::AppResource declaration
  \author Cheng Liang <changliang.soft@gmail.com>
  \date 2009-10-13 Created.
 */

#ifndef APPRESOURCE_H
#define APPRESOURCE_H

#include <QObject>
#include <QPixmap>
#include "singleton.h"

#define appRes (Core::Singleton<Core::AppResource>::instance())

namespace Core {

class AppResource : public QObject
{
    Q_OBJECT

public:

    enum MeasurementUnit
    {
        px = 0, //!< Pixel.
        cm      //!< Centimeter.
    };

    enum DpiUnit
    {
       perInch = 0, //!< Pixel per inch.
       perCm      //!< Pixel per centimeter.
    };

    AppResource();

    ~AppResource() {}

    const QString& measurementUnitName(MeasurementUnit unit) const
    {
        return measurementUnitNames[unit];
    }

    const QString& dpiUnitName(DpiUnit unit) const
    {
        return dpiUnitNames[unit];
    }

    const QPixmap& grayGridImage() const
    {
        return grayGrid;
    }

private:
    QString measurementUnitNames[2];
    QString dpiUnitNames[2];

    QPixmap grayGrid;

}; // end of class

} // end of namespace

#endif // APPRESOURCE_H

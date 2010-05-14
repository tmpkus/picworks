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
  \file project.h
  \ingroup Core
  \brief This file contains
  - class Core::Project declaration
  \author Cheng Liang <changliang.soft@gmail.com>
  \date 2010-5-6 Created.
 */

#ifndef PROJECT_H
#define PROJECT_H

#include <QObject>

#include "appresource.h"
#include "util_global.h"

class QColor;

namespace Core {

class AppResource;

class CORESHARED_EXPORT Project : public QObject
{
    Q_OBJECT

    typedef AppResource::MeasurementUnit MUnit;
    typedef AppResource::DpiUnit DUnit;

public:
    Project();
    ~Project() {}

    inline QString name() const
    {
        return dName;
    }

    inline int width() const
    {
        return w;
    }

    inline int height() const
    {
        return h;
    }

    inline AppResource::MeasurementUnit widthUnit() const
    {
        return wUnit;
    }

    inline AppResource::MeasurementUnit heightUnit() const
    {
        return hUnit;
    }

    inline int dpi() const
    {
        return d;
    }

    inline AppResource::DpiUnit dpiUnit() const
    {
        return dUnit;
    }

    inline QColor backgroundColor() const
    {
        return bgColor;
    }

public slots:
    inline void setName(const QString & n)
    {
        if(n != dName) {
            emit projectNameChanged(dName);
            dName = n;
        }
    }

    inline void setWidth(int tw)
    {
        Q_ASSERT(tw > 0);
        if(w != tw) {
            emit projectWidthChanged(w);
            w = tw;
        }
    }

    inline void setHeight(int th)
    {
        Q_ASSERT(th > 0);
        if(h != th) {
            emit projectHeightChanged(h);
            h = th;
        }
    }

    inline void setWidthUnit(Core::AppResource::MeasurementUnit wu)
    {
        if(wu != wUnit) {
            emit projectWidthUnitChanged(wUnit);
            hUnit = wu;
        }
    }

    inline void setHeightUnit(Core::AppResource::MeasurementUnit hu)
    {
        if(hu != hUnit) {
            emit projectHeightUnitChanged(hUnit);
            hUnit = hu;
        }
    }

    inline void setDpi(int td)
    {
        Q_ASSERT(td > 0);
        if(td != d) {
            emit projectDpiChanged(d);
            d = td;
        }
    }

    inline void setDpiUnit(Core::AppResource::DpiUnit du)
    {
        if(dUnit != du) {
            emit projectDpiUnitChanged(dUnit);
            dUnit = du;
        }
    }

    inline void setBackgroundColor(const QColor& c)
    {
        if(c != bgColor) {
            emit projectBackgroundColorChanged(bgColor);
            bgColor = c;
        }
    }

signals:
    void projectNameChanged(const QString &oldName);
    void projectWidthChanged(int oldWidth);
    void projectHeightChanged(int oldHeight);
    void projectWidthUnitChanged(Core::AppResource::MeasurementUnit oldWidthUnit);
    void projectHeightUnitChanged(Core::AppResource::MeasurementUnit oldHeightUnit);
    void projectDpiChanged(int oldDpi);
    void projectDpiUnitChanged(Core::AppResource::DpiUnit oldDpiUnit);
    void projectBackgroundColorChanged(const QColor &oldColor);

private:
    QString dName;
    int w;
    int h;
    MUnit wUnit;
    MUnit hUnit;
    int d;
    DUnit dUnit;
    QColor bgColor;

}; // end of class

} // end of namespace

#endif // PROJECT_H

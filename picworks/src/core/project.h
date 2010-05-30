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
#include <QPixmap>

#include "appresource.h"
#include "core_global.h"

class QColor;
class QPixmap;

namespace Core {

class CORESHARED_EXPORT Project : public QObject
{
    Q_OBJECT

    typedef AppResource::MeasurementUnit MUnit;
    typedef AppResource::DpiUnit DUnit;

public:
    Project();
    ~Project() {}

    QString toString() const;

    const QString& name() const
    {
        return dName;
    }

    const QString& path() const
    {
        return dPath;
    }

    int width() const
    {
        return w;
    }

    int height() const
    {
        return h;
    }

    Core::AppResource::MeasurementUnit widthUnit() const
    {
        return wUnit;
    }

    Core::AppResource::MeasurementUnit heightUnit() const
    {
        return hUnit;
    }

    int dpi() const
    {
        return d;
    }

    Core::AppResource::DpiUnit dpiUnit() const
    {
        return dUnit;
    }

    const QColor& backgroundColor() const
    {
        return bgColor;
    }

    const QPixmap& backgroundImage() const
    {
        return bgImage;
    }

public slots:
    void setName(const QString & n)
    {
        if(n != dName) {
            emit projectNameChanged(dName);
            dName = n;
        }
    }

    void setPath(const QString & p)
    {
        if(p != dPath) {
            emit projectPathChanged(dPath);
            dPath = p;
        }
    }

    void setWidth(int tw)
    {
        Q_ASSERT(tw > 0);
        if(w != tw) {
            emit projectWidthChanged(w);
            w = tw;
        }
    }

    void setHeight(int th)
    {
        Q_ASSERT(th > 0);
        if(h != th) {
            emit projectHeightChanged(h);
            h = th;
        }
    }

    void setWidthUnit(Core::AppResource::MeasurementUnit wu)
    {
        if(wu != wUnit) {
            emit projectWidthUnitChanged(wUnit);
            hUnit = wu;
        }
    }

    void setHeightUnit(Core::AppResource::MeasurementUnit hu)
    {
        if(hu != hUnit) {
            emit projectHeightUnitChanged(hUnit);
            hUnit = hu;
        }
    }

    void setDpi(int td)
    {
        Q_ASSERT(td > 0);
        if(td != d) {
            emit projectDpiChanged(d);
            d = td;
        }
    }

    void setDpiUnit(Core::AppResource::DpiUnit du)
    {
        if(dUnit != du) {
            emit projectDpiUnitChanged(dUnit);
            dUnit = du;
        }
    }

    void setBackgroundColor(const QColor& c)
    {
        if(c != bgColor) {
            emit projectBackgroundColorChanged(bgColor);
            bgColor = c;
        }
    }

    void setBackgroundImage(const QPixmap& img)
    {
        bgImage = img;
        w = bgImage.width();
        h = bgImage.height();
    }

signals:
    void projectNameChanged(const QString &oldName);
    void projectPathChanged(const QString &oldPath);
    void projectWidthChanged(int oldWidth);
    void projectHeightChanged(int oldHeight);
    void projectWidthUnitChanged(Core::AppResource::MeasurementUnit oldWidthUnit);
    void projectHeightUnitChanged(Core::AppResource::MeasurementUnit oldHeightUnit);
    void projectDpiChanged(int oldDpi);
    void projectDpiUnitChanged(Core::AppResource::DpiUnit oldDpiUnit);
    void projectBackgroundColorChanged(const QColor &oldColor);

private:
    QString dName;
    QString dPath;
    int w;
    int h;
    MUnit wUnit;
    MUnit hUnit;
    int d;
    DUnit dUnit;
    QColor bgColor;
    QPixmap bgImage;

}; // end of class

} // end of namespace

#endif // PROJECT_H

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
#include "core_global.h"

#define appRes (Core::Singleton<Core::AppResource>::instance())

namespace Core {

class CORESHARED_EXPORT AppResource : public QObject
{
    Q_OBJECT

public:
    enum Icon
    {
        ApplicationIcon = 0, //!< Icon for application icon on main window title bar.
        NewIcon,             //!< Icon for the action of new.
        OpenIcon,            //!< Icon for the action of open.
        SaveIcon,            //!< Icon for the action of save.
        PreferencesIcon,     //!< Icon for the action of preferences dialog.
        UndoIcon,            //!< Icon for the action of undo.
        RedoIcon,            //!< Icon for the action of redo.
        CutIcon,             //!< Icon for the action of cut.
        CopyIcon,            //!< Icon for the action of copy.
        PasteIcon,           //!< Icon for the action of paste.
        SaveAsIcon,          //!< Icon for the action of save as.
        SaveAllIcon,         //!< Icon for the action of save all.
        PrintIcon,           //!< Icon for the action of print.
        AboutIcon,           //!< Icon for the action of about.
        HelpIcon,            //!< Icon for the action of help.
        TileIcon,            //!< Icon for the action of tile project windows.
        CascadeIcon,         //!< Icon for the action of cascade project windows.
        ProjectIcon,         //!< Icon for the action of project window.
        ExitIcon,            //!< Icon for the action of exit application.
        EraserIcon,          //!< Icon for the eraser tool.
        MoveIcon,            //!< Icon for the move tool.
        BrushIcon,           //!< Icon for the brush tool.
        CurveIcon,           //!< Icon for drawing a curve tool.
        PaintCanIcon,        //!< Icon for paint can tool.
        SelectIcon,          //!< Icon for select tool.
        EllipseIcon,         //!< Icon for drawing an ellipse tool.
        PolygonIcon,         //!< Icon for drawing a polygon tool.
        RectangleIcon,       //!< Icon for drawing a rectangle tool.
        RoundRectangleIcon,  //!< Icon for drawing a round corner rectangle tool.
        TextIcon,            //!< Icon for text tool.
        LineIcon             //!< Icon for straight line.
    };

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

    inline const QString measurementUnitName(MeasurementUnit unit) const
    {
        return measurementUnitNames[unit];
    }

    inline const QString dpiUnitName(DpiUnit unit) const
    {
        return dpiUnitNames[unit];
    }

    inline const QPixmap icon(Icon iconCode) const
    {
        return icons[iconCode];
    }

    inline const QPixmap splashImage() const
    {
        return splash;
    }

    inline const QPixmap grayGridImage() const
    {
        return grayGrid;
    }

private:
    QString measurementUnitNames[2];
    QString dpiUnitNames[2];

    QPixmap *icons;
    QPixmap splash;
    QPixmap grayGrid;

}; // end of class

} // end of namespace

#endif // APPRESOURCE_H

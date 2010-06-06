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
  \file constants.h
  \ingroup Core
  \brief This file contains
  - class Core::ID declaration
  \author Cheng Liang <changliang.soft@gmail.com>
  \date 2010-4-30 Created.
 */

#ifndef CONSTANTS_H
#define CONSTANTS_H

class QString;

namespace Core {

class ID {
public:
    static const QString actionNew;
    static const QString actionOpen;
    static const QString actionSave;
    static const QString actionSaveAs;
    static const QString actionSaveAll;
    static const QString actionPrint;
    static const QString actionExit;
    static const QString actionUndo;
    static const QString actionRedo;
    static const QString actionCut;
    static const QString actionCopy;
    static const QString actionPaste;
    static const QString actionOpenReference;
    static const QString actionOpenHelp;
    static const QString actionOpenAbout;
    static const QString actionSelect;
    static const QString actionMove;
    static const QString actionBrush;
    static const QString actionEraser;
    static const QString actionPaintCan;
    static const QString actionDrawText;
    static const QString actionDrawLine;
    static const QString actionDrawCurve;
    static const QString actionDrawEllipse;
    static const QString actionDrawRect;
    static const QString actionDrawRoundRect;
    static const QString actionDrawPolygon;
    static const QString menuFile;
    static const QString menuEdit;
    static const QString menuTool;
    static const QString menuLang;
    static const QString menuHelp;
    static const QString menubar;
    static const QString toolbar;
    static const QString toolbox;
};

};

#endif // CONSTANTS_H

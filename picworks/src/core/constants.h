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

#include <QString>

namespace Core {

namespace ID {

    const QString ACTION_NEW = QString("anew");
    const QString ACTION_OPEN = QString("aopen");
    const QString ACTION_SAVE = QString("asave");
    const QString ACTION_SAVE_AS = QString("asas");
    const QString ACTION_SAVE_ALL = QString("asall");
    const QString ACTION_PRINT = QString("aprint");
    const QString ACTION_EXIT = QString("aexit");

    const QString ACTION_UNDO = QString("aundo");
    const QString ACTION_REDO = QString("aredo");
    const QString ACTION_CUT = QString("acut");
    const QString ACTION_COPY = QString("acopy");
    const QString ACTION_PASTE = QString("apaste");
    const QString ACTION_OPEN_REFERENCE_DIALOG = QString("aoreferd");
    const QString ACTION_OPEN_HELP_DIALOG = QString("aohelpd");
    const QString ACTION_OPEN_ABOUT_DIALOG = QString("aoabout");

    const QString ACTION_SELECT = QString("aselect");
    const QString ACTION_MOVE = QString("amove");
    const QString ACTION_BRUSH = QString("abrush");
    const QString ACTION_ERASER = QString("aeraser");
    const QString ACTION_PAINT_CAN = QString("apcan");

    const QString ACTION_DRAW_TEXT = QString("adtext");
    const QString ACTION_DRAW_LINE = QString("adline");
    const QString ACTION_DRAW_CURVE = QString("adcurve");
    const QString ACTION_DRAW_ELLIPSE = QString("adellipse");
    const QString ACTION_DRAW_RECT = QString("adrect");
    const QString ACTION_DRAW_ROUND_RECT = QString("adrrect");
    const QString ACTION_DRAW_POLYGON = QString("adpolygon");

    const QString MENU_FILE = QString("mfile");
    const QString MENU_EDIT = QString("medit");
    const QString MENU_TOOL = QString("mtool");
    const QString MENU_LANG = QString("mlang");
    const QString MENU_HELP = QString("mhelp");

    const QString MENU_BAR = QString("mbar");
    const QString TOOL_BAR = QString("tbar");
    const QString TOOL_BOX = QString("tbox");
    const QString COMMON_BAR = QString("cbar");
}

};

#endif // CONSTANTS_H

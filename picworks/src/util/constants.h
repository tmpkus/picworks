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
  \ingroup Utilities
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
    struct Action {
        static const QString NEW;
        static const QString OPEN;
        static const QString SAVE;
        static const QString SAVE_AS;
        static const QString SAVE_ALL;
        static const QString PRINT;
        static const QString EXIT;
        static const QString UNDO;
        static const QString REDO;
        static const QString CUT;
        static const QString COPY;
        static const QString PASTE;
        static const QString OPEN_PREFERENCE;
        static const QString OPEN_HELP;
        static const QString ABOUT;
        static const QString DRAW_LINE;
        static const QString DRAW_CURVE;
        static const QString DRAW_ELLIPSE;
        static const QString DRAW_RECT;
        static const QString DRAW_ROUNDRECT;
        static const QString DRAW_POLYGON;
    };

    struct Menu {
        static const QString FILE;
        static const QString EDIT;
        static const QString TOOL;
        static const QString HELP;
    };
};

};

#endif // CONSTANTS_H

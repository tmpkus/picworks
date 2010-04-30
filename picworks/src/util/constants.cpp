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
  \file constants.cpp
  \ingroup Utilities
  \brief This file contains
  - class Core::ID implemtation
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2010-4-30 Created.
 */

#include <QString>

#include "constants.h"

/*!
  \brief String id of menu [File].
 */
const QString Core::ID::Menu::FILE = QString("menu_file");

/*!
  \brief String id of menu [Edit].
 */
const QString Core::ID::Menu::EDIT = QString("menu_edit");

/*!
  \brief String id of menu [Tool].
 */
const QString Core::ID::Menu::TOOL = QString("menu_tool");

/*!
  \brief String id of menu [Help].
 */
const QString Core::ID::Menu::HELP = QString("menu_help");

/*!
  \brief String id of action new.
 */
const QString Core::ID::Action::NEW = QString("action_new");

/*!
  \brief String id of action open.
 */
const QString Core::ID::Action::OPEN = QString("action_open");

/*!
  \brief String id of action save.
 */
const QString Core::ID::Action::SAVE = QString("action_save");

/*!
  \brief String id of action save as.
 */
const QString Core::ID::Action::SAVE_AS = QString("action_save_as");

/*!
  \brief String id of action save all.
 */
const QString Core::ID::Action::SAVE_ALL = QString("action_save_all");

/*!
  \brief String id of action print.
 */
const QString Core::ID::Action::PRINT = QString("action_print");

/*!
  \brief String id of action exit.
 */
const QString Core::ID::Action::EXIT = QString("action_exit");

/*!
  \brief String id of action undo.
 */
const QString Core::ID::Action::UNDO = QString("action_undo");

/*!
  \brief String id of action redo.
 */
const QString Core::ID::Action::REDO = QString("action_redo");

/*!
  \brief String id of action cut.
 */
const QString Core::ID::Action::CUT = QString("action_cut");

/*!
  \brief String id of action copy.
 */
const QString Core::ID::Action::COPY = QString("action_copy");

/*!
  \brief String id of action paste.
 */
const QString Core::ID::Action::PASTE = QString("action_paste");

/*!
  \brief String id of action open preference dialog.
 */
const QString Core::ID::Action::OPEN_PREFERENCE = QString("action_open_preference");

/*!
  \brief String id of action open help dialog.
 */
const QString Core::ID::Action::OPEN_HELP = QString("action_open_help");

/*!
  \brief String id of action about.
 */
const QString Core::ID::Action::ABOUT = QString("action_about");

/*!
  \brief String id of action draw a line.
 */
const QString Core::ID::Action::DRAW_LINE = QString("action_draw_line");

/*!
  \brief String id of action draw a curve.
 */
const QString Core::ID::Action::DRAW_CURVE = QString("action_draw_curve");

/*!
  \brief String id of action draw an ellipse.
 */
const QString Core::ID::Action::DRAW_ELLIPSE = QString("action_draw_ellipse");

/*!
  \brief String id of action draw a polygon.
 */
const QString Core::ID::Action::DRAW_POLYGON = QString("action_draw_polygon");

/*!
  \brief String id of action draw a rectangle.
 */
const QString Core::ID::Action::DRAW_RECT = QString("action_draw_rect");

/*!
  \brief String id of action draw a round corder rectanlge.
 */
const QString Core::ID::Action::DRAW_ROUNDRECT = QString("action_draw_round_rect");

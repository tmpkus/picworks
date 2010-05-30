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
  \ingroup Core
  \brief This file contains
  - class Core::ID implemtation
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2010-4-30 Created.
 */

#include <QString>

#include "constants.h"

/*!
  \class Core::ID constants.h
  \brief IDs used in PicWorks.
  It is easy to get actions or containers using these IDs
  from \a ActionManager.
  \version 0.0.1
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2009-10-13 Created.
  \date 2010-5-30 import static const fields
 */

/*!
  \brief String id of action <i>new</i>.
  \return action <i>new</i> string id
 */
const QString Core::ID::actionNew = QString("actionNew");

/*!
  \brief String id of action <i>open</i>.
  \return action <i>open</i> string id
 */
const QString Core::ID::actionOpen = QString("actionOpen");

/*!
  \brief String id of action <i>save</i>.
  \return action <i>save</i> string id
 */
const QString Core::ID::actionSave = QString("actionSave");

/*!
  \brief String id of action <i>save as</i>.
  \return action <i>save as</i> string id
 */
const QString Core::ID::actionSaveAs = QString("actionSaveAs");

/*!
  \brief String id of action <i>save all</i>.
  \return action <i>save all</i> string id
 */
const QString Core::ID::actionSaveAll = QString("actionSaveAll");

/*!
  \brief String id of action <i>print</i>.
  \return action <i>print</i> string id
 */
const QString Core::ID::actionPrint = QString("actionPrint");

/*!
  \brief String id of action <i>exit</i>.
  \return action <i>exit</i> string id
 */
const QString Core::ID::actionExit = QString("actionExit");

/*!
  \brief String id of action <i>undo</i>.
  \return action <i>undo</i> string id
 */
const QString Core::ID::actionUndo = QString("actionUndo");

/*!
  \brief String id of action <i>redo</i>.
  \return action <i>redo</i> string id
 */
const QString Core::ID::actionRedo = QString("actionRedo");

/*!
  \brief String id of action <i>cut</i>.
  \return action <i>cut</i> string id
 */
const QString Core::ID::actionCut = QString("actionCut");

/*!
  \brief String id of action <i>copy</i>.
  \return action <i>copy</i> string id
 */
const QString Core::ID::actionCopy = QString("actionCopy");

/*!
  \brief String id of action <i>paste</i>.
  \return action <i>paste</i> string id
 */
const QString Core::ID::actionPaste = QString("actionPaste");

/*!
  \brief String id of action <i>open reference dailog</i>.
  \return action <i>open reference dialog</i> string id
 */
const QString Core::ID::actionOpenReference = QString("actionOpenReference");

/*!
  \brief String id of action <i>open help document</i>.
  \return action <i>open help document</i> string id
 */
const QString Core::ID::actionOpenHelp = QString("actionOpenHelp");

/*!
  \brief String id of action <i>open about dialog</i>.
  \return action <i>open about dialog</i> string id
 */
const QString Core::ID::actionOpenAbout = QString("actionOpenAbout");

/*!
  \brief String id of action <i>select</i>.
  \return action <i>select</i> string id
 */
const QString Core::ID::actionSelect = QString("actionSelect");

/*!
  \brief String id of action <i>move</i>.
  \return action <i>move</i> string id
 */
const QString Core::ID::actionMove = QString("actionMove");

/*!
  \brief String id of action <i>brush</i>.
  \return action <i>brush</i> string id
 */
const QString Core::ID::actionBrush = QString("actionBrush");

/*!
  \brief String id of action <i>eraser</i>.
  \return action <i>eraser</i> string id
 */
const QString Core::ID::actionEraser = QString("actionEraser");

/*!
  \brief String id of action <i>paint can</i>.
  \return action <i>paint can</i> string id
 */
const QString Core::ID::actionPaintCan = QString("actionPaintCan");

/*!
  \brief String id of action <i>draw text</i>.
  \return action <i>draw text</i> string id
 */
const QString Core::ID::actionDrawText = QString("actionDrawText");

/*!
  \brief String id of action <i>draw line</i>.
  \return action <i>draw line</i> string id
 */
const QString Core::ID::actionDrawLine = QString("actionDrawLine");

/*!
  \brief String id of action <i>draw curve</i>.
  \return action <i>draw curve</i> string id
 */
const QString Core::ID::actionDrawCurve = QString("actionDrawCurve");

/*!
  \brief String id of action <i>draw ellipse</i>.
  \return action <i>draw ellipse</i> string id
 */
const QString Core::ID::actionDrawEllipse = QString("actionDrawEllipse");

/*!
  \brief String id of action <i>draw rectangle</i>.
  \return action <i>draw rectangle</i> string id
 */
const QString Core::ID::actionDrawRect = QString("actionDrawRect");

/*!
  \brief String id of action <i>draw cornor rectangle</i>.
  \return action <i>draw cornor rectangle</i> string id
 */
const QString Core::ID::actionDrawRoundRect = QString("actionDrawRoundRect");

/*!
  \brief String id of action <i>draw polygon</i>.
  \return action <i>draw polygon</i> string id
 */
const QString Core::ID::actionDrawPolygon = QString("actionDrawPolygon");

/*!
  \brief String id of menu <i>File</i>.
  \return menu <i>File</i> string id
 */
const QString Core::ID::menuFile = QString("menuFile");

/*!
  \brief String id of menu <i>Edit</i>.
  \return menu <i>Edit</i> string id
 */
const QString Core::ID::menuEdit = QString("menuEdit");

/*!
  \brief String id of menu <i>Tool</i>.
  \return menu <i>Tool</i> string id
 */
const QString Core::ID::menuTool = QString("menuTool");

/*!
  \brief String id of menu <i>Languages</i>.
  \return menu <i>Languages</i> string id
 */
const QString Core::ID::menuLang = QString("menuLang");

/*!
  \brief String id of menu <i>Help</i>.
  \return menu <i>Help</i> string id
 */
const QString Core::ID::menuHelp = QString("menuHelp");

/*!
  \brief String id of menu bar.
  \return menu bar string id
 */
const QString Core::ID::menubar = QString("mb");

/*!
  \brief String id of tool bar.
  \return tool bar string id
 */
const QString Core::ID::toolbar = QString("tb");

/*!
  \brief String id of tool box.
  \return tool box string id
 */
const QString Core::ID::toolbox = QString("tbx");

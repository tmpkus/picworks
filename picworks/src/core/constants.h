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

#define ID (Core::Singleton<Core::ConstId>::instance())

#include <QString>

#include "util_global.h"

namespace Core {

class CORESHARED_EXPORT ConstId {
public:
    ConstId();

    /*!
      \brief String id of action <i>new</i>.
      \return action <i>new</i> string id
     */
    QString actionNew() const { return actNew; }

    /*!
      \brief String id of action <i>open</i>.
      \return action <i>open</i> string id
     */
    QString actionOpen() const { return actOpen; }

    /*!
      \brief String id of action <i>save</i>.
      \return action <i>save</i> string id
     */
    QString actionSave() const { return actSave; }

    /*!
      \brief String id of action <i>save as</i>.
      \return action <i>save as</i> string id
     */
    QString actionSaveAs() const { return actSaveAs; }

    /*!
      \brief String id of action <i>save all</i>.
      \return action <i>save all</i> string id
     */
    QString actionSaveAll() const { return actSaveAll; }

    /*!
      \brief String id of action <i>print</i>.
      \return action <i>print</i> string id
     */
    QString actionPrint() const { return actPrint; }

    /*!
      \brief String id of action <i>exit</i>.
      \return action <i>exit</i> string id
     */
    QString actionExit() const { return actExit; }

    /*!
      \brief String id of action <i>undo</i>.
      \return action <i>undo</i> string id
     */
    QString actionUndo() const { return actUndo; }

    /*!
      \brief String id of action <i>redo</i>.
      \return action <i>redo</i> string id
     */
    QString actionRedo() const { return actRedo; }

    /*!
      \brief String id of action <i>cut</i>.
      \return action <i>cut</i> string id
     */
    QString actionCut() const { return actCut; }

    /*!
      \brief String id of action <i>copy</i>.
      \return action <i>copy</i> string id
     */
    QString actionCopy() const { return actCopy; }

    /*!
      \brief String id of action <i>paste</i>.
      \return action <i>paste</i> string id
     */
    QString actionPaste() const { return actPaste; }

    /*!
      \brief String id of action <i>open reference dailog</i>.
      \return action <i>open reference dialog</i> string id
     */
    QString actionOpenReference() const { return actOpenReference; }

    /*!
      \brief String id of action <i>open help document</i>.
      \return action <i>open help document</i> string id
     */
    QString actionOpenHelp() const { return actOpenHelp; }

    /*!
      \brief String id of action <i>open about dialog</i>.
      \return action <i>open about dialog</i> string id
     */
    QString actionOpenAbout() const { return actOpenAbout; }

    /*!
      \brief String id of action <i>draw line</i>.
      \return action <i>draw line</i> string id
     */
    QString actionDrawLine() const { return actDrawLine; }

    /*!
      \brief String id of action <i>draw curve</i>.
      \return action <i>draw curve</i> string id
     */
    QString actionDrawCurve() const { return actDrawCurve; }

    /*!
      \brief String id of action <i>draw ellipse</i>.
      \return action <i>draw ellipse</i> string id
     */
    QString actionDrawEllipse() const { return actDrawEllipse; }

    /*!
      \brief String id of action <i>draw rectangle</i>.
      \return action <i>draw rectangle</i> string id
     */
    QString actionDrawRect() const { return actDrawRect; }

    /*!
      \brief String id of action <i>draw cornor rectangle</i>.
      \return action <i>draw cornor rectangle</i> string id
     */
    QString actionDrawRoundRect() const { return actDrawRoundRect; }

    /*!
      \brief String id of action <i>draw polygon</i>.
      \return action <i>draw polygon</i> string id
     */
    QString actionDrawPolygon() const { return actDrawPolygon; }

    /*!
      \brief String id of menu <i>File</i>.
      \return menu <i>File</i> string id
     */
    QString menuFile() const { return mnFile; }

    /*!
      \brief String id of menu <i>Edit</i>.
      \return menu <i>Edit</i> string id
     */
    QString menuEdit() const { return mnEdit; }

    /*!
      \brief String id of menu <i>Tool</i>.
      \return menu <i>Tool</i> string id
     */
    QString menuTool() const { return mnTool; }

    /*!
      \brief String id of menu <i>Help</i>.
      \return menu <i>Help</i> string id
     */
    QString menuHelp() const { return mnHelp; }

    /*!
      \brief String id of menu bar.
      \return menu bar string id
     */
    QString compMenuBar() const { return mb; }

    /*!
      \brief String id of tool bar.
      \return tool bar string id
     */
    QString compToolBar() const { return tb; }

private:
    QString actNew;
    QString actOpen;
    QString actSave;
    QString actSaveAs;
    QString actSaveAll;
    QString actPrint;
    QString actExit;
    QString actUndo;
    QString actRedo;
    QString actCut;
    QString actCopy;
    QString actPaste;
    QString actOpenReference;
    QString actOpenHelp;
    QString actOpenAbout;
    QString actDrawLine;
    QString actDrawCurve;
    QString actDrawEllipse;
    QString actDrawRect;
    QString actDrawRoundRect;
    QString actDrawPolygon;
    QString mnFile;
    QString mnEdit;
    QString mnTool;
    QString mnHelp;
    QString mb;
    QString tb;
};

};

#endif // CONSTANTS_H

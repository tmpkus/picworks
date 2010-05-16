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
  - class Core::ConstId implemtation
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2010-4-30 Created.
 */

#include "constants.h"

/*!
  \class Core::ConstId constants.h
  \brief IDs used in PicWorks.
  It is easy to get actions or containers using these IDs
  from \a ActionManager.
  \version 0.0.1
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2009-10-13 Created.
 */

Core::ConstId::ConstId()
    : actNew("actNew"),
      actOpen("actOpen"),
      actSave("actSave"),
      actSaveAs("actSaveAs"),
      actSaveAll("actSaveAll"),
      actPrint("actPrint"),
      actExit("actExit"),
      actUndo("actUndo"),
      actRedo("actRedo"),
      actCut("actCut"),
      actCopy("actCopy"),
      actPaste("actPaste"),
      actOpenReference("actOpenReference"),
      actOpenHelp("actOpenHelp"),
      actOpenAbout("actOpenAbout"),
      actDrawLine("actDrawLine"),
      actDrawCurve("actDrawCurve"),
      actDrawEllipse("actDrawEllipse"),
      actDrawRect("actDrawRect"),
      actDrawRoundRect("actDrawRoundRect"),
      actDrawPolygon("actDrawPolygon"),
      mnFile("mnFile"),
      mnEdit("mnEdit"),
      mnTool("mnTool"),
      mnLang("mnLang"),
      mnHelp("mnHelp"),
      mb("mb"),
      tb("tb")
{
}

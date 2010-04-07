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
  \file line.h
  \ingroup Item
  \brief This file contains
  - class PicWorks::Line declaration
  \author Cheng Liang <changliang.soft@gmail.com>
  \date 2009-11-24 Created.
 */

#ifndef LINE_H
#define LINE_H

#include <QGraphicsLineItem>
#include "abstractshape.h"

class QGraphicsSceneMouseEvent;

namespace PicWorks {

class ProjectScene;

class Line : public QGraphicsLineItem, public AbstractShape
{
public:
    Line(ProjectScene *s);
    virtual ~Line();
    void startDraw(QGraphicsSceneMouseEvent * event);
    void drawing(QGraphicsSceneMouseEvent * event);
    void endDraw(QGraphicsSceneMouseEvent * event);

}; // end of class

} // end of namespace

#endif // LINE_H

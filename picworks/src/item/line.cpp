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
  \file line.cpp
  \ingroup Item
  \brief This file contains
  - class PicWorks::Line implemtation
  \author Cheng Liang <changliang.soft@gmail.com>
  \date 2009-11-24 Created.
 */

#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

#include "line.h"
#include "../view/projectscene.h"

/*!
  \class GraphicsItem::Line line.h
  \brief Line model.
  \version 0.0.1
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2009-11-24 Created.
 */

/*!
  \brief Constructor.
  Constrats a line item.
  \param s pointer of the scene in which this line is
 */
GraphicsItem::Line::Line(View::ProjectScene *s)
        : GraphicsItem::AbstractShape(s)
{
}

/*!
  \brief Destructor.
 */
GraphicsItem::Line::~Line()
{
}

void GraphicsItem::Line::startDraw(QGraphicsSceneMouseEvent * event)
{
    emit isDrawing(true);
    setLine(QLineF(event->scenePos(), event->scenePos()));
}

void GraphicsItem::Line::drawing(QGraphicsSceneMouseEvent * event)
{
    QLineF newLine(line().p1(), event->scenePos());
    setLine(newLine);
}

void GraphicsItem::Line::endDraw(QGraphicsSceneMouseEvent * event)
{
    emit isDrawing(false);
}

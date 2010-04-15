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
  \file abstractshape.cpp
  \ingroup Item
  \brief This file contains
  - class GraphicsItem::AbstractShape implemtation
  \author Cheng Liang <changliang.soft@gmail.com>
  \date 2009-11-27 Created.
 */

#include "abstractshape.h"
#include "../view/projectscene.h"

using namespace GraphicsItem;

/*!
  \class GraphicsItem::AbstractShape abstractshape.h
  \brief Abstract shape in PicWorks.
  There are several additional attributes defined in abstrace shape because
  all shapes are inherited from this abstract shape.
  \version 0.0.1
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2009-11-27 Created.
 */

/*!
  \fn virtual void GraphicsItem::AbstractShape::startDraw(QGraphicsSceneMouseEvent * event) = 0
  \brief Starts drawing this shape.
  This function usually called in \a mousePress event, you can add additional operations
  before drawing. This function is pure virtual, any subclass must override it.
  \note \a isDrawing(true) signal muse be emited if you want to update scene.
  \param event the mouse event genarated from project scene

  \fn virtual void GraphicsItem::AbstractShape::drawing(QGraphicsSceneMouseEvent * event) = 0
  \brief Drawing this shape.
  This function usually called in \a mouseMove event. It is the function defined how to drawing
  this shape. This function is pure virtual, any subclass must override it.
  \param event the mouse event genarated from project scene

  \fn virtual void GraphicsItem::AbstractShape::endDraw(QGraphicsSceneMouseEvent * event) = 0
  \brief Ends drawing this shape.
  This function usually called in \a mouseRelease event.
  This function is pure virtual, any subclass must override it.
  \note \a isDrawing(false) signal muse be emited if drawing is finished.
  \param event the mouse event genarated from project scene

  \fn void GraphicsItem::AbstractShape::isDrawing(bool d)
  \brief Signal of drawing flag.
  Usually emited \a true in \a startDraw() and \a false in \a endDraw().
  \param d whether is drawing or not, true if drawing
 */

/*!
  \brief Constractor.
  Constracts a shape item. This constructor will connect the shape to the scene.
  \param s the projet scene in which the shape is
 */
AbstractShape::AbstractShape(View::ProjectScene *s)
        : scene(s)
{
    connect(this, SIGNAL(isDrawing(bool)), scene, SLOT(setProcessing(bool)));
}

/*!
  \brief Destructor.
  Destructs this shape.
 */
AbstractShape::~AbstractShape()
{
}

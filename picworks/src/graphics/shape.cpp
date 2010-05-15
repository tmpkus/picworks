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
  \file shape.cpp
  \ingroup Graphics
  \brief This file contains
  - class Graphics::Shape implemtation
  \author Cheng Liang <changliang.soft@gmail.com>
  \date 2010-5-15 Created.
 */

#include "shape.h"

/*!
  \class Graphics::Shape shape.h
  \brief The abstract shape in PicWorks.
  There are several additional attributes defined in abstrace shape because
  all shapes are inherited from this abstract shape.
  \version 0.0.1
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2009-11-27 Created.
 */

/*!
  \fn virtual void Graphics::AbstractShape::startDraw(QGraphicsSceneMouseEvent * event) = 0
  \brief Starts drawing this shape.
  This function usually called in \a mousePress event, you can add additional operations
  before drawing. This function is pure virtual, any subclass must override it.
  \note \a isDrawing(true) signal muse be emited if you want to update scene.
  \param event the mouse event genarated from project scene

  \fn virtual void Graphics::AbstractShape::drawing(QGraphicsSceneMouseEvent * event) = 0
  \brief Drawing this shape.
  This function usually called in \a mouseMove event. It is the function defined how to drawing
  this shape. This function is pure virtual, any subclass must override it.
  \param event the mouse event genarated from project scene

  \fn virtual void Graphics::AbstractShape::endDraw(QGraphicsSceneMouseEvent * event) = 0
  \brief Ends drawing this shape.
  This function usually called in \a mouseRelease event.
  This function is pure virtual, any subclass must override it.
  \note \a isDrawing(false) signal muse be emited if drawing is finished.
  \param event the mouse event genarated from project scene

  \fn void Graphics::AbstractShape::isDrawing(bool drawing)
  \brief Signal of drawing flag.
  Usually emits \a true in \a startDraw() and \a false in \a endDraw().
  \param drawing whether is drawing or not, true if drawing
 */

/*!
  \brief Constractor.
  Constracts a shape item.
 */
Graphics::Shape::Shape()
{
}

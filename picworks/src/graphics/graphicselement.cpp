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
  \file graphicsglement.cpp
  \ingroup Graphics
  \brief This file contains
  - class Graphics::GraphicsElement implemtation
  \author Cheng Liang <changliang.soft@gmail.com>
  \date 2010-5-15 Created.
 */

#include "graphicselement.h"

/*!
  \class Graphics::GraphicsElement graphicselement.h
  \brief The abstract graphics element in PicWorks.
  Graphics elements are the element which can be added into \a ProjectScene,
  including shapes, images and texts. In order to subclass a GprahicsElement,
  you should reimplement \a startProcess(), \a processing() and \a endProcess()
  functions.
  \version 0.0.1
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2009-11-27 Created.
 */

/*!
  \fn virtual void Graphics::GraphicsElement::startProcess(QPoint * scenePos) = 0
  \brief Starts processing this element.
  This function usually called in \a mousePress event, you can add additional operations
  before drawing. This function is pure virtual, any subclass must override it.
  \note \a isDrawing(true) signal muse be emited if you want to update scene.
  \param event the mouse event genarated from project scene

  \fn virtual void Graphics::GraphicsElement::processing(QPoint * scenePos) = 0
  \brief Drawing this element.
  This function usually called in \a mouseMove event. It is the function defined how to drawing
  this shape. This function is pure virtual, any subclass must override it.
  \param event the mouse event genarated from project scene

  \fn virtual void Graphics::GraphicsElement::endProcess(QPoint * scenePos) = 0
  \brief Ends drawing this shape.
  This function usually called in \a mouseRelease event.
  This function is pure virtual, any subclass must override it.
  \note \a isDrawing(false) signal muse be emited if drawing is finished.
  \param event the mouse event genarated from project scene

  \fn void Graphics::GraphicsElement::isProcessing(bool processing)
  \brief Signal of processing flag.
  Processing maybe drawing something or do some transform, like resize.
  This signal may be emitted true when mouse button pressed and false when button released.
  \param processing \a true if processing
 */

/*!
  \brief Constractor.
  Constracts a graphics element.
 */
Graphics::GraphicsElement::GraphicsElement()
{
}

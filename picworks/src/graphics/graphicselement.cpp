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
  \file lineelement.cpp
  \ingroup Graphics
  \brief This file contains
  - class Graphics::LineElement implemtation
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2010-7-19 Created.
 */

#include "appcontext.h"
#include "graphicselement.h"

/*!
  \class Graphics::GraphicsElement graphicselement.h
  \brief Base class of all graphics elements.
  \version 0.0.1
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2010-7-19 Created.

  \fn virtual void Graphics::GraphicsElement::editStart(const QPointF &point)
  \brief Starts editing element always when mouse pressed.
  \param point mouse point in scene when mouse pressed

  \fn virtual void Graphics::GraphicsElement::editing(const QPointF &point)
  \brief Editing element always while mouse pressed.
  \param point mouse point in scene, this point maybe change while mouse moving

  \fn virtual void Graphics::GraphicsElement::editEnd(const QPointF &point)
  \brief End edit when mouse released.
  \param point mouse point in scene when mouse released

  \var QGraphicsScene *scene
  \brief scene pointer the element in
 */

Graphics::GraphicsElement::GraphicsElement(QGraphicsItem *parent /* = 0 */,
                                           QGraphicsScene *s /* = 0 */)
    : QGraphicsObject(parent),
      scene(s)
{
}

/*!
  \class Graphics::LineElement lineelement.h
  \brief Line element for drawing.
  \version 0.0.1
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2010-7-19 Created.
 */

Graphics::LineElement::LineElement(QGraphicsItem *parent /* = 0 */,
                                   QGraphicsScene *scene /* = 0 */)
    : GraphicsElement(parent, scene)
{
    lineItem = new QGraphicsLineItem(parent, scene);
    lineItem->setPen(QPen(QBrush(appCtx->penColor(), Qt::SolidPattern), appCtx->penWidth()));
}

Graphics::LineElement::~LineElement()
{
}

/*!
  \reimp
 */
void Graphics::LineElement::editStart(const QPointF &point)
{
    lineItem->setLine(QLineF(point, point));
}

/*!
  \reimp
 */
void Graphics::LineElement::editing(const QPointF &point)
{
    lineItem->setLine(QLineF(lineItem->line().p1(), point));
}

/*!
  \reimp
 */
void Graphics::LineElement::editEnd(const QPointF &point)
{
    lineItem->setLine(QLineF(lineItem->line().p1(), point));
}

/*!
  \reimp
 */
QRectF Graphics::LineElement::boundingRect() const
{
    return lineItem->boundingRect();
}

/*!
  \reimp
 */
void Graphics::LineElement::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    lineItem->paint(painter, option, widget);
}

/*!
  \reimp
 */
bool Graphics::LineElement::contains(const QPointF & point) const
{
    return lineItem->contains(point);
}

/*!
  \reimp
 */
bool Graphics::LineElement::isObscuredBy(const QGraphicsItem * item) const
{
    return lineItem->isObscuredBy(item);
}

/*!
  \reimp
 */
QPainterPath Graphics::LineElement::opaqueArea() const
{
    return lineItem->opaqueArea();
}

/*!
  \reimp
 */
QPainterPath Graphics::LineElement::shape() const
{
    return lineItem->shape();
}

/*!
  \reimp
 */
int Graphics::LineElement::type() const
{
    return lineItem->type();
}

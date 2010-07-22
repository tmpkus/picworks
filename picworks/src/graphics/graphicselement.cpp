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

/*!
  \class Graphics::LineElement lineelement.h
  \brief Line element for drawing.
  \version 0.0.1
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2010-7-19 Created.
 */

#include <QGraphicsSceneMouseEvent>

#include "appcontext.h"
#include "graphicselement.h"

Graphics::GraphicsElement::GraphicsElement(QGraphicsItem *parent /* = 0 */,
                                           QGraphicsScene *s /* = 0 */)
    : QGraphicsObject(parent),
      scene(s)
{
}

Graphics::LineElement::LineElement(QGraphicsItem *parent /* = 0 */,
                                   QGraphicsScene *scene /* = 0 */)
    : GraphicsElement(parent, scene)
{
    lineItem = new QGraphicsLineItem();
    lineItem->setPen(QPen(QBrush(appCtx->penColor(), Qt::SolidPattern), appCtx->penWidth()));
}

Graphics::LineElement::~LineElement()
{
    delete lineItem;
}

void Graphics::LineElement::editStart(const QPointF &point)
{
    QLineF line;
    line.setP1(point);
    line.setP2(point);
    lineItem->setLine(line);
}

void Graphics::LineElement::editing(const QPointF &point)
{
    lineItem->line().setP2(point);
}

void Graphics::LineElement::editEnd(const QPointF &point)
{
    lineItem->line().setP2(point);
}

QRectF Graphics::LineElement::boundingRect() const
{
    return lineItem->boundingRect();
}

void Graphics::LineElement::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    lineItem->paint(painter, option, widget);
}

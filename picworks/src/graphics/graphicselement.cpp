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

Graphics::LineElement::LineElement(QGraphicsItem *parent /* = 0 */,
                                   QGraphicsScene *scene /* = 0 */)
    : QGraphicsLineItem(parent, scene)
{
    setPen(QPen(QBrush(appCtx->penColor(), Qt::SolidPattern), appCtx->penWidth()));
}

void Graphics::LineElement::mouseMove(QGraphicsSceneMouseEvent *event)
{
//    this->line().setP2(event->scenePos());
    qDebug() << "mouse move";
}

void Graphics::LineElement::mousePress(QGraphicsSceneMouseEvent *event)
{
//    QLineF line;
//    line.setP1(event->scenePos());
//    line.setP2(event->scenePos());
//    this->setLine(line);
    qDebug() << "mouse pressed";
}

void Graphics::LineElement::mouseRelease(QGraphicsSceneMouseEvent *event)
{
//    this->line().setP2(event->scenePos());
//    emit finished();
    qDebug() << "mouse released";
}

void Graphics::LineElement::setZIndex(qreal z)
{
    this->setZValue(z);
}

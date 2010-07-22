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
  \file lineelement.h
  \ingroup Graphics
  \brief This file contains
  - class Graphics::GraphicsElement declaration
  - class Graphics::LineElement declaration
  \author Cheng Liang <changliang.soft@gmail.com>
  \date 2010-7-19 Created.
 */

#ifndef LINEELEMENT_H
#define LINEELEMENT_H

#include <QGraphicsObject>

class QGraphicsLineItem;

namespace Graphics {

class GraphicsElement : public QGraphicsObject
{
    Q_OBJECT
public:
    GraphicsElement(QGraphicsItem *parent = 0, QGraphicsScene *s = 0);

    virtual void editStart(const QPointF &point) = 0;
    virtual void editing(const QPointF &point) = 0;
    virtual void editEnd(const QPointF &point) = 0;

protected:
    QGraphicsScene *scene;

}; // end of class

class LineElement : public GraphicsElement
{
public:
    LineElement(QGraphicsItem *parent = 0, QGraphicsScene *scene = 0);
    ~LineElement();

    void editStart(const QPointF &point);
    void editing(const QPointF &point);
    void editEnd(const QPointF &point);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    bool contains(const QPointF & point) const;
    bool isObscuredBy(const QGraphicsItem * item) const;
    QPainterPath opaqueArea() const;
    QPainterPath shape() const;
    int type() const;

private:
    QGraphicsLineItem *lineItem;

}; // end of class

} // end of namespace

#endif // LINEELEMENT_H

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
  \file mouseactor.h
  \ingroup Graphics
  \brief This file contains
  - class Graphics::MouseActor declaration
  \author Cheng Liang <changliang.soft@gmail.com>
  \date 2010-7-19 Created.
 */

#ifndef MOUSEACTOR_H
#define MOUSEACTOR_H

class QGraphicsSceneMouseEvent;

namespace Graphics {

class Actor
{
public:
    virtual void mousePress(QGraphicsSceneMouseEvent * event) = 0;
    virtual void mouseMove(QGraphicsSceneMouseEvent * event) = 0;
    virtual void mouseRelease(QGraphicsSceneMouseEvent * event) = 0;
}; // end of class

} // end of namespace

#endif // MOUSEACTOR_H

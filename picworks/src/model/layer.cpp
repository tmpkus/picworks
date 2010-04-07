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
  \file layer.cpp
  \ingroup Model
  \brief This file contains
  - class PicWorks::Layer implemtation
  \author Cheng Liang <changliang.soft@gmail.com>
  \date 2009-10-17 Created.
 */

#include "layer.h"

using namespace PicWorks;

/*!
  \class PicWorks::Layer layer.h
  \brief Layer data of project in PicWorks.
  PicWorks's projects support mutil-layers. Each layer is
  an instance of this class. It is a data model of layers used
  in PicWorks.
  \version 0.0.1
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2009-10-17 Created.
*/

/*!
  \fn const QString& PicWorks::Layer::name() const
  Gets the name of this layer.
  \return name of this layer

  \fn void PicWorks::Layer::setName(const QString &name)
  Sets the name of this layer. This function will emit \a layerNameChanged
  signal if the new name id different from the old one.
  \param name new name of this layer

  \fn int PicWorks::Layer::id() const
  Gets the ID of this layer.
  ID is the identity flag of this layer. This field is read-only.
  Once a layer created, PicWorks will assign an ID to it. Developers
  needn't care about its value, just use it to identify this layer.
  \return ID of this layer

  \fn void PicWorks::Layer::layerNameChanged(const QString &newName, const QString &oldName)
  Emits when layer name has been changed.
  \param newName new layer name
  \param oldName old layer name

  \fn bool PicWorks::Layer::isBackground() const
  Checks if this layer is the backgound layer.
  \return \a true if is background

  \fn void PicWorks::Layer::setBackground(bool b)
  Sets if this layer is background.
  \param b \a true if is background
 */

/*!
  \brief Constructor.
  Creates a new layer.
 */
Layer::Layer()
{
}

/*!
  \brief Destructor.
  Destructs a layer.
 */
Layer::~Layer()
{
}

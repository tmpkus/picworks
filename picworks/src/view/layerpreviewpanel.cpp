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
  \file layerpreviewpanel.cpp
  \ingroup View
  \brief This file contains
  - class PicWorks::LayerPreviewPanel implemtation
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2009-12-4 Created.
 */

#include "layerpreviewpanel.h"

/*!
  \class PicWorks::LayerPreviewPanel layerpreviewpanel.h
  \brief A panel that can preview project layers.
  A project may has several layers. Each layer is an instance of \a Layer.
  This panel can preview layers. Usually this panel adds on the dock panels
  on the right of main window.
  \version 0.0.1
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2009-12-4 Created.
 */

/*!
  \brief Constructs the panel that can preview layers.
  \param parent the parent widget pointer
 */
PicWorks::LayerPreviewPanel::LayerPreviewPanel(QWidget *parent /* = 0 */)
    : QWidget(parent)
{
}

/*!
  \brief Destructor.
 */
PicWorks::LayerPreviewPanel::~LayerPreviewPanel()
{
}

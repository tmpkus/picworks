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
  \file projectscene.cpp
  \ingroup Ui
  \brief This file contains
  - class Ui::ProjectScene implemtation
  \author Cheng Liang <changliang.soft@gmail.com>
  \date 2009-10-12 Created.
 */

#include <QBrush>
#include <QPen>
#include <QLineF>
#include <QGraphicsSceneMouseEvent>

#include "project.h"
#include "appresource.h"
#include "appcontext.h"
#include "projectscene.h"
#include "shape.h"

/*!
  \class Ui::ProjectScene projectscene.h
  \brief Project scene in subwindow of PicWorks.
  Project scene is used for processing project data in PicWorks. This is
  the main graphics scene. The project's data should be processed
  first in this scene and then to be viewed by project view.
  That is to say the project view is the default view port of this scene.
  \sa Ui::ProjectView
  \version 0.0.1
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2009-10-12 Created.
 */

/*!
  \brief Constructor.
  Creates a new ProjectScene instance.
  \param pro the project pointer, not null.
  \param parent parent widget of this dialog, default value is 0.
 */
Ui::ProjectScene::ProjectScene(Core::Project *pro, QObject *parent /* = 0 */)
        : QGraphicsScene(parent),
          project(pro),
          layerIndex(1)
{
    // entry conditions
    Q_CHECK_PTR(pro);

    setBackgroundBrush(QBrush(appRes->grayGridImage()));
    addRect(0, 0, project->width(), project->height(),
            QPen(Qt::NoPen), QBrush(project->backgroundColor()));
}

/*!
  \brief Destructor.
  Destructs this scene.
 */
Ui::ProjectScene::~ProjectScene()
{
    if(project) {
        delete project;
    }
    if(drawingShape) {
        delete drawingShape;
    }
}

/*!
  \internal
 */
void Ui::ProjectScene::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    if(event->button() == Qt::LeftButton) {
//        switch(appCtx->currentAction()) {
//        case Core::AppResource::DrawLineAction:
//            {
//                GraphicsItem::Line *drawingLine = new GraphicsItem::Line(this);
//                drawingLine->setPen(QPen(QBrush(appCtx->penColor(), Qt::SolidPattern), appCtx->penWidth()));
//                drawingLine->setZValue(layerIndex);
//                addItem(drawingLine);
//                drawingShape = drawingLine;
//                break;
//            }
//        case Core::AppResource::DrawCurveAction:
//            {
//                break;
//            }
//        case Core::AppResource::DrawRectAction:
//            {
//                break;
//            }
//        case Core::AppResource::DrawRoundRectAction:
//            {
//                break;
//            }
//        case Core::AppResource::DrawEllipseAction:
//            {
//                break;
//            }
//        case Core::AppResource::DrawPolygonAction:
//            {
//                break;
//            }
//        default:
//            {
//                // not a drawable item, do nothing
//                break;
//            }
//        }

//        if(drawingShape) {
//            drawingShape->startDraw(event);
//        }
    }
    QGraphicsScene::mousePressEvent(event);
}

/*!
  \internal
 */
void Ui::ProjectScene::mouseMoveEvent(QGraphicsSceneMouseEvent * event)
{
    if(processing && drawingShape) {
        drawingShape->drawing(event);
    }
    QGraphicsScene::mouseMoveEvent(event);
}

/*!
  \internal
 */
void Ui::ProjectScene::mouseReleaseEvent(QGraphicsSceneMouseEvent * event)
{
    if(drawingShape) {
        drawingShape->endDraw(event);
    }
    QGraphicsScene::mouseReleaseEvent(event);
}
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
  \ingroup View
  \brief This file contains
  - class PicWorks::ProjectScene implemtation
  \author Cheng Liang <changliang.soft@gmail.com>
  \date 2009-10-12 Created.
 */

#include <QDebug>
#include <QBrush>
#include <QPen>
#include <QLineF>
#include <QGraphicsSceneMouseEvent>

#include "../model/project.h"
#include "../util/appresource.h"
#include "../util/appcontext.h"
#include "projectscene.h"
#include "../item/line.h"
#include "../item/abstractshape.h"

using namespace PicWorks;

/*!
  \class PicWorks::ProjectScene projectscene.h
  \brief Project scene in PicWorks.
  Project scene is used for processing project data in PicWorks. This is
  the main graphics scene. The project's data should be processed
  first in this scene and then to be shown by project view.
  That is to say the project view is the default view port of this scene.
  \sa PicWorks::ProjectView
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
ProjectScene::ProjectScene(Project *pro, QObject *parent /* = 0 */)
        : QGraphicsScene(parent), project(pro), layerIndex(1)
{
    // entry conditions
    Q_CHECK_PTR(pro);

    setBackgroundBrush(QBrush(AppRes.grayGridImage()));
    addRect(0, 0, project->width(), project->height(),
            QPen(Qt::NoPen), QBrush(project->backgroundColor()));
}

/*!
  \brief Destructor.
  Destructs this scene.
 */
ProjectScene::~ProjectScene()
{
}

/*!
  \internal
  \brief Override mouse press event.
  \param event the mouse event
 */
void ProjectScene::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    if(event->button() == Qt::LeftButton) {
        switch(AppCtx.currentAction()) {
        case AppResource::DrawLineAction:
            {
                Line *drawingLine = new Line(this);
                drawingLine->setPen(QPen(QBrush(AppCtx.penColor(), Qt::SolidPattern), AppCtx.penWidth()));
                drawingLine->setZValue(layerIndex);
                addItem(drawingLine);
                drawingShape = drawingLine;
                break;
            }
        case AppResource::DrawCurveAction:
            {
                break;
            }
        case AppResource::DrawRectAction:
            {
                break;
            }
        case AppResource::DrawRoundRectAction:
            {
                break;
            }
        case AppResource::DrawEllipseAction:
            {
                break;
            }
        case AppResource::DrawPolygonAction:
            {
                break;
            }
        default:
            {
                // not a drawable item, do nothing
                break;
            }
        }
        if(drawingShape) {
            drawingShape->startDraw(event);
        }
    }
    QGraphicsScene::mousePressEvent(event);
}

/*!
  \internal
  \brief Override mouse move event.
  \param event the mouse event
 */
void ProjectScene::mouseMoveEvent(QGraphicsSceneMouseEvent * event)
{
    if(processing && drawingShape) {
        drawingShape->drawing(event);
    }
    QGraphicsScene::mouseMoveEvent(event);
}

/*!
  \internal
  \brief Override mouse release event.
  \param event the mouse event
 */
void ProjectScene::mouseReleaseEvent(QGraphicsSceneMouseEvent * event)
{
    if(drawingShape) {
        drawingShape->endDraw(event);
    }
    QGraphicsScene::mouseReleaseEvent(event);
}

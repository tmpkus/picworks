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
#include <QPixmap>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

#include "project.h"
#include "constants.h"
#include "appcontext.h"
#include "projectscene.h"
#include "graphicselement.h"

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
          showGrid(false),
          layerIndex(1)
{
    // entry conditions
    Q_CHECK_PTR(pro);

    setBackgroundBrush(QBrush(appRes->grayGridImage()));
    if(project->backgroundImage().isNull()) { // from new
        addRect(0, 0, project->width(), project->height(),
                QPen(Qt::NoPen), QBrush(project->backgroundColor()));
    } else { // from open
        addPixmap(project->backgroundImage());
    }
    setSceneRect(0, 0, project->width(), project->height());

    connect(appCtx, SIGNAL(currentActionChange(const QString &, const QString &)), this, SLOT(setCurrentActor(const QString &)));
}

/*!
  \internal
 */
void Ui::ProjectScene::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    if(event->button() == Qt::LeftButton) {
        if(currActor) {
            currActor->mousePress(event);
        }
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
//    if(processing && drawingShape) {
//        drawingShape->drawing(event);
//    }
    QGraphicsScene::mouseMoveEvent(event);
}

/*!
  \internal
 */
void Ui::ProjectScene::mouseReleaseEvent(QGraphicsSceneMouseEvent * event)
{
//    if(drawingShape) {
//        drawingShape->endDraw(event);
//    }
    QGraphicsScene::mouseReleaseEvent(event);
}

/*!
  \internal Sets this window to show grid lines.
  \param show true if grid lines should be shown
 */
void Ui::ProjectScene::setGrid()
{
    showGrid = !showGrid;
    if(showGrid) {
        int dpi = project->dpi();
        QPixmap grid(dpi, dpi);
        grid.fill(Qt::transparent);
        QPainter painter(&grid);
        QPen gridPen(QColor(204, 204, 204));
        painter.setPen(gridPen);
        int bor = dpi - 1;
        painter.drawLine(0, bor, bor, bor);
        painter.drawLine(bor, 0, bor, bor);
        gridPen.setStyle(Qt::DotLine);
        painter.setPen(gridPen);
        int dpip5 = dpi / 5;
        // FIXME if dpi is too low, grid lines should be changed as PS
        int borp5 = dpip5 - 1;
        painter.drawLine(0, borp5, bor, borp5);
        painter.drawLine(borp5, 0, borp5, bor);
        int bor2p5 = dpip5 * 2 - 1;
        painter.drawLine(0, bor2p5, bor, bor2p5);
        painter.drawLine(bor2p5, 0, bor2p5, bor);
        int bor3p5 = dpip5 * 3 - 1;
        painter.drawLine(0, bor3p5, bor, bor3p5);
        painter.drawLine(bor3p5, 0, bor3p5, bor);
        int bor4p5 = dpip5 * 4 - 1;
        painter.drawLine(0, bor4p5, bor, bor4p5);
        painter.drawLine(bor4p5, 0, bor4p5, bor);
        this->setForegroundBrush(QBrush(grid));
    } else {
        this->setForegroundBrush(Qt::NoBrush);
    }
}

/*!
  \brief Sets current actor instance by action id in application context.
  \param actId new action id
 */
void Ui::ProjectScene::setCurrentActor(const QString & actId)
{
    if(actId == Core::ID::ACTION_DRAW_TEXT) {

    } else if(actId == Core::ID::ACTION_DRAW_CURVE) {

    } else if(actId == Core::ID::ACTION_DRAW_ELLIPSE) {

    } else if(actId == Core::ID::ACTION_DRAW_LINE) {
        currActor = new Graphics::LineElement();
    } else if(actId == Core::ID::ACTION_DRAW_POLYGON) {

    } else if(actId == Core::ID::ACTION_DRAW_RECT) {

    } else if(actId == Core::ID::ACTION_DRAW_ROUND_RECT) {

    } else {
        // no such action id, do nothing...
    }
}

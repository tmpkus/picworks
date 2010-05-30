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
  \file projectscene.h
  \ingroup Ui
  \brief This file contains
  - class Ui::ProjectScene declaration
  \author Cheng Liang <changliang.soft@gmail.com>
  \date 2009-10-12 Created.
 */

#ifndef PROJECTSCENE_H
#define PROJECTSCENE_H

#include <QGraphicsScene>

class QGraphicsSceneMouseEvent;

namespace Core {
    class Project;
};

namespace Graphics {
    class GraphicsElement;
};

namespace Ui {

class ProjectScene : public QGraphicsScene
{
    Q_OBJECT

public:
    ProjectScene(Core::Project *pro, QObject *parent = 0);
    ~ProjectScene() {}

public slots:
    void setProcessing(bool p) { processing = p; }

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent * event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);

private:
    Core::Project *project;
    Graphics::GraphicsElement *currentElement;
    bool processing;
    int layerIndex;

}; // end of class

} // end of namespace

#endif // PROJECTSCENE_H

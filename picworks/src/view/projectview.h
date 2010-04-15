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
  \file projectview.h
  \ingroup View
  \brief This file contains
  - class View::ProjectView declaration
  \version 0.0.1
  \author Cheng Liang <changliang.soft@gmail.com>
  \date 2009-9-19 Created.
 */

#ifndef PROJECTVIEW_H
#define PROJECTVIEW_H

#include <QGraphicsView>

class QSize;

namespace Data {
    class Project;
};

namespace View {

class ProjectScene;

class ProjectView : public QGraphicsView
{
public:
    ProjectView(Data::Project *pro, QWidget *parent = 0);
    virtual ~ProjectView();
    QSize sizeHint() const;

private:
    Data::Project *project;
    ProjectScene *projectScene;

}; // end of class

} // end of namespace

#endif // PROJECTVIEW_H

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
  \file layer.h
  \ingroup Model
  \brief This file contains
  - class PicWorks::Layer declaration
  \author Cheng Liang <changliang.soft@gmail.com>
  \date 2009-10-17 Created.
 */

#ifndef LAYER_H
#define LAYER_H

#include <QObject>
#include <QString>

namespace PicWorks {

class Layer : public QObject
{
    Q_OBJECT

public:
    Layer();
    virtual ~Layer();

    inline void setName(const QString &name)
    {
        if(name != layerName) {
            emit layerNameChanged(name, layerName);
            layerName = name;
        }
    }

    inline const QString& name() const { return layerName; }

    inline int id() const { return layerId; }

    inline bool isBackground() const { return _isBackground; }

    inline void setBackground(bool b) { _isBackground = b; }

signals:
    void layerNameChanged(const QString &newName, const QString &oldName);

private:
    int layerId;
    bool _isBackground;
    QString layerName;

}; // end of class

} // end of namespace

#endif // LAYER_H

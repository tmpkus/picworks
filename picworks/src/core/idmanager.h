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
  \file idmanager.h
  \ingroup Core
  \brief This file contains
  - class Core::IdManager declaration
  \author Cheng Liang <changliang.soft@gmail.com>
  \date 2010-4-20 Created.
 */

#ifndef IDMANAGER_H
#define IDMANAGER_H

#include <QHash>
#include <QString>

#include "singleton.h"
#include "core_global.h"

#define idManager (Core::Singleton<Core::IdManager>::instance())

namespace Core {

class CORESHARED_EXPORT IdManager
{
public:
    IdManager() {}
    ~IdManager() {}

    int uid(const QString &sid);
    QString stringId(int uid);
    bool containsStringId(const QString &sid);

private:
    QHash<QString, int> idMap;
}; // end of class

} // end of namespace

#endif // IDMANAGER_H

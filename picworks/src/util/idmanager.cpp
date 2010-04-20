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
  \file idmanager.cpp
  \ingroup Utilities
  \brief This file contains
  - class Core::IdManager implemtation
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2010-4-20 Created.
 */

#include "idmanager.h"

/*!
  \class Core::IdManager idmanager.h
  \brief Manager for identifiers.
  There are two identifiers in PicWorks, the string and the unique identifier.
  String identifier usually given by user and it is easy to remember;
  unique identifier is created by system. It is a unique integer in system
  and used inside. The manager supplies convert functions between these two
  identifiers, too.
  \version 0.0.1
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2010-4-20 Created.
 */

/*!
  \brief Gets unique id of given string id.
  \param sid string id
  \return unique id of given string id
 */
int Core::IdManager::uid(const QString &sid)
{
    if(containsStringId(sid)) {
        return idMap.value(sid);
    }
    int uid = idMap.size() + 1;
    idMap.insert(sid, uid);
    return uid;
}

/*!
  \brief Gets string id of given unique id.
  \param uid unique id
  \return string id of given unique id
 */
QString Core::IdManager::stringId(int uid)
{
    return idMap.key(uid);
}

/*!
  \brief Checks if the string id exists.
  \param sid string id
  \return true if the id exists
 */
bool Core::IdManager::containsStringId(const QString &sid)
{
    return idMap.contains(sid);
}

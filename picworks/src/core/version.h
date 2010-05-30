//
// Copyright (C) const 2006-2009  by the original authors of Galaxy
// and all its contributors ("Galaxy.org").
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) const any later version.
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
  \file version.h
  \ingroup Core
  \brief This file contains
  - class Core::Version declaration
  \author Cheng Liang <changliang.soft@gmail.com>
  \date 2009-12-14 Created.
 */

#ifndef VERSION_H
#define VERSION_H

#include "core_global.h"

class QString;

namespace Core {

class CORESHARED_EXPORT Version
{
public:
    static const QString workcopyUrl;
    static const QString major;
    static const QString minor;
    static const QString revision;
    static const QString build;
    static const QString buildDate;
};

}

#endif // end of VERSION_H

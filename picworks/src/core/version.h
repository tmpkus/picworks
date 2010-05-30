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
  - class Core::VersionInfo declaration
  \author Cheng Liang <changliang.soft@gmail.com>
  \date 2009-12-14 Created.
 */

#ifndef VERSION_H
#define VERSION_H

#define Version (Core::Singleton<Core::VersionInfo>::instance())

#include <QString>

#include "core_global.h"

namespace Core {

class CORESHARED_EXPORT VersionInfo
{
public:
    VersionInfo();

    QString url() const { return wcURL; }

    QString major() const { return ma; }

    QString minor() const { return mi; }

    QString revision() const { return rivi; }

    QString build() const { return bu; }

    QString buildDate() const { return bDate; }

private:
    QString wcURL;
    QString bDate;
    QString rivi;
    QString ma;
    QString mi;
    QString bu;
};

}

#endif // end of VERSION_H

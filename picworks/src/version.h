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
  \file version.h
  \brief This file contains
  - class PicWorks::VersionInfo declaration
  \author Cheng Liang <changliang.soft@gmail.com>
  \date 2009-12-14 Created.
 */

#ifndef VERSION_H
#define VERSION_H

#include <QString>

namespace PicWorks {

class VersionInfo
{
public:
    static QString url() { return wcURL; }

    static QString major() { return ma; }

    static QString minor() { return mi; }

    static QString revision() { return rivi; }

    static QString build() { return bu; }

    static QString buildDate() { return bDate; }

private:
    static QString wcURL;

    static QString bDate;

    static QString rivi;

    static QString ma;

    static QString mi;

    static QString bu;

};

}

#endif // end of VERSION_H

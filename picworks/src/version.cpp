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
  \file version.cpp
  \brief This file contains
  - class PicWorks::VersionInfo implemtation
  <strike>This file is generated by SubWCRev.</strike>
  \version 0.0.1
  \author Cheng Liang <changliang.soft@gmail.com>
  \date 2009-12-14 Created.
 */

#include "version.h"

/*!
  \class PicWorks::VersionInfo version.h
  \brief Version information of PicWorks.
  \version 0.0.1 SVN
  \version 0.0.2 2010-3-3 SCM changed to non-SCM-related.
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2009-12-14 Created.
 */

/*!
  \fn static QString PicWorks::VersionInfo::buildDate()
  \brief Build date in short format as YYYY-MM-DD.
  \return workcopy build date

  \fn static QString PicWorks::VersionInfo::url()
  \brief PicWorks version control system URL.
  \return URL of version control system

  \fn static QString PicWorks::VersionInfo::major()
  \brief Major version number.
  \return major version number

  \fn static QString PicWorks::VersionInfo::minor()
  \brief Minor version number.
  \return minor version number

  \fn static QString PicWorks::VersionInfo::revision()
  \brief Revision number.
  \return the rivision number

  \fn static QString PicWorks::VersionInfo::build()
  \brief Build version number.
  \return build version number
 */

/*!
  \internal
  \brief PicWorks version control system URL.
 */
QString PicWorks::VersionInfo::wcURL = QString("git://picworks.git.sourceforge.net/gitroot/picworks/picworks");

/*!
  \internal
  \brief Major version number.
 */
QString PicWorks::VersionInfo::ma = QString("0");

/*!
  \internal
  \brief Minor version number.
 */
QString PicWorks::VersionInfo::mi = QString("0");

/*!
  \internal
  \brief Revision version number.
 */
QString PicWorks::VersionInfo::rivi = QString("0");

/*!
  \internal
  \brief Build version number.
 */
QString PicWorks::VersionInfo::bu = QString("6");

/*!
  \internal
  \brief Build date.
 */
QString PicWorks::VersionInfo::bDate = QString("2010-4-20");

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
  \file appcontext.cpp
  \ingroup Utilities
  \brief This file contains
  - class PicWorks::AppContext implemtation
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2009-10-14 Created.
 */

#include "appcontext.h"

using namespace PicWorks;

/*!
  \class PicWorks::AppResource appcontext.h
  \brief Application context.
  This context contains global data used in PicWorks.
  \version 0.0.1
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2009-10-14 Created.
 */

/*!
  \def AppCtx
  \brief The abbrev for getting instance function.
  This is the abbrev for getting instance. It is equivalent to
  \code
  AppContext::instance()
  \endcode
  , so the following is dot(.) not pointer(->).

  \fn void PicWorks::AppContext::setCurrentAction(AppResource::Action a)
  \brief Sets the current action code of PicWorks.
  If new action is different from the old one, \a currentActionChanged
  signal will be emited.
  \param new action code to change, its type is defined in AppResource::Action

  \fn const QString & PicWorks::AppContext::version() const
  \brief Gets version number of PicWorks.
  Version can identify this application's version. The special version
  numbering scheme is
  <pre>
    major.minor.revision.build
  </pre>
  <p>\a major is the major number, \a minor is the minor number,
  \a revision is the revision and \a build is a build number
  based on the current date.</p>
  <p>If some new features adds, not only bugs fixed, the minor number increased;
  if lots of features adds or the code has been big modified, major number increased.</p>
  \note If major version number changes, PicWorks CANNOT ensure its code
  is compatible to the older versions.
  \return version number string with format major.minor.revision.build

  \fn AppResource::Action PicWorks::AppContext::currentAction() const
  \brief Gets the current action of PicWorks.
  This action code is a type of enum Action defined in AppResource.
  \sa AppResource
  \return current action code

  \fn void PicWorks::AppContext::setPenColor(const QColor &c)
  \brief Sets the color of global pen.
  This setter will emit \a penColorChanged signal.
  \param c new color of pen

  \fn void PicWorks::AppContext::setPenWidth(int w)
  \brief Sets the width of global pen.
  This setter will emit \a penWidthChanged signal.
  \param w new width value of pen

  \fn void PicWorks::AppContext::setMaxPenWidth(int mw)
  \brief Sets the max width of global pen.
  This setter will emit \a maxPenWidthChanged signal.
  \param w new max width value of pen

  \fn const QColor & PicWorks::AppContext::penColor() const
  \brief Gets global pen color.
  \return pen color

  \fn int PicWorks::AppContext::penWidth() const
  \brief Gets global pen width.
  \return pen width

  \fn int PicWorks::AppContext::maxPenWidth() const
  \brief Gets global max pen width
  \return max pen width

  \fn void PicWorks::AppContext::currentActionChanged(const AppResource::Action & newCurrAction, const AppResource::Action & oldCurrAction)
  \brief Emits when current action changes.
  \param newCurrAction the new action code
  \param oldCurrAction the old action code

  \fn void PicWorks::AppContext::penColorChanged(const QColor & newColor, const QColor & oldColor)
  \brief Emits when pen color changes.
  \param newColor the new color
  \param oldColor the old color

  \fn void PicWorks::AppContext::penWidthChanged(int newWidth, int oldWidth)
  \brief Emits when pen width changes.
  \param newWidth the new width value
  \param oldWidth the old width value

  \fn void PicWorks::AppContext::maxPenWidthChanged(int newValue, int oldValue)
  \brief Emits when max pen width changes.
  \param newMaxWidth the new max width value
  \param oldMaxWidth the old max width value
 */

/*!
  \internal
  \brief Private constructor.
 */
AppContext::AppContext()
        : pColor(Qt::black), maxPWidth(500)
{
    appVersion = QString("%1.%2.%3.%4")
                 .arg(VersionInfo::major())
                 .arg(VersionInfo::minor())
                 .arg(VersionInfo::revision())
                 .arg(VersionInfo::build());
}

/*!
  \internal
  \brief Private destructor.
 */
AppContext::~AppContext()
{
}

/*!
  \brief Gets the single instance of AppContext.
  AppContext contains important global data using in PicWorks.
  If these variables wants to be used, this function should be called
  in order to get the only instance.
  Also, PicWorks has a macro "AppCtx" canbe used for short.
  \return singleton instance of AppContext
 */
AppContext& AppContext::instance()
{
    static AppContext ctx;
    return ctx;
}

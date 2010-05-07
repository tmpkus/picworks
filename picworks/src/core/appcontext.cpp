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
  \ingroup Core
  \brief This file contains
  - class Core::AppContext implemtation
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2009-10-14 Created.
 */

#include "appcontext.h"
#include "actionmanager.h"
#include "version.h"

/*!
  \class Core::AppContext appcontext.h
  \brief Application context.
  This context contains global data and managers used in PicWorks.
  This class is a singleton class, the macro \a AppCtx is used for getting
  the existing instance.
  \note DO NOT try to get instance using its constructor.
  \version 0.0.1
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2009-10-14 Created.
 */

/*!
  \def AppCtx
  \brief The abbrev for getting instance function.
  This is the abbrev for getting instance. It returns an instance not a pointer.

  \fn void Core::AppContext::setCurrentAction(Core::AppResource::Action a)
  \brief Sets the current action code of PicWorks.
  If new action is different from the old one, \a currentActionChanged
  signal will be emited.
  \param new action code to change, its type is defined in AppResource::Action

  \fn const QString & Core::AppContext::version() const
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

  \fn AppResource::Action Core::AppContext::currentAction() const
  \brief Gets the current action of PicWorks.
  This action code is a type of enum Action defined in AppResource.
  \sa Core::AppResource
  \return current action code

  \fn ActionManager * Core::ActionManager::actionManager() const
  \brief Action manager in PicWorks.
  \sa Core::ActionManager
  \return the action manager

  \fn MainWindow * Core::AppContext::mainWindow() const
  \brief Gets the main window of PicWorks.
  \return main window

  \fn void Core::AppContext::setMainWindow(View::MainWindow * mw)
  \brief Sets main window of PicWorks.
  \param mw main window pointer

  \fn void Core::AppContext::setPenColor(const QColor &c)
  \brief Sets the color of global pen.
  This setter will emit \a penColorChanged signal.
  \param c new color of pen

  \fn void Core::AppContext::setPenWidth(int w)
  \brief Sets the width of global pen.
  This setter will emit \a penWidthChanged signal.
  \param w new width value of pen

  \fn void Core::AppContext::setMaxPenWidth(int mw)
  \brief Sets the max width of global pen.
  This setter will emit \a maxPenWidthChanged signal.
  \param w new max width value of pen

  \fn const QColor & Core::AppContext::penColor() const
  \brief Gets global pen color.
  \return pen color

  \fn int Core::AppContext::penWidth() const
  \brief Gets global pen width.
  \return pen width

  \fn int Core::AppContext::maxPenWidth() const
  \brief Gets global max pen width
  \return max pen width

  \fn void Core::AppContext::currentActionChanged(const Core::AppResource::Action & newCurrAction, const Core::AppResource::Action & oldCurrAction)
  \brief Emits when current action changes.
  \param newCurrAction the new action code
  \param oldCurrAction the old action code

  \fn void Core::AppContext::penColorChanged(const QColor & newColor, const QColor & oldColor)
  \brief Emits when pen color changes.
  \param newColor the new color
  \param oldColor the old color

  \fn void Core::AppContext::penWidthChanged(int newWidth, int oldWidth)
  \brief Emits when pen width changes.
  \param newWidth the new width value
  \param oldWidth the old width value

  \fn void Core::AppContext::maxPenWidthChanged(int newValue, int oldValue)
  \brief Emits when max pen width changes.
  \param newMaxWidth the new max width value
  \param oldMaxWidth the old max width value
 */

/*!
  \internal
  \brief Private constructor.
 */
Core::AppContext::AppContext() : pColor(Qt::black),
                                 maxPWidth(500),
                                 actMgr(new Core::ActionManager)
{
    appVersion = QString("%1.%2.%3.%4")
                 .arg(Version->major())
                 .arg(Version->minor())
                 .arg(Version->revision())
                 .arg(Version->build());
}

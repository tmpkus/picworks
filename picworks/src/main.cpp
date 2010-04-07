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
  \file main.cpp
  \brief Main file for entry point of PicWorks.
  \version 0.0.1
  \author Cheng Liang <changliang.soft@gmail.com>
  \date 2009-9-5 Created.
 */

#include <QDebug>
#include <QTranslator>
#include <QSplashScreen>
#include <QFileInfo>
#include <QDir>
#include <QSettings>

#include "extern/qtsingleapplication/qtsingleapplication.h"
#include "util/appresource.h"
#include "util/appcontext.h"
#include "view/mainwindow.h"
#include "view/aboutdialog.h"
#include "version.h"

int main(int argc, char *argv[])
{
    using namespace PicWorks;

    QtSingleApplication app(argc, argv);
    QCoreApplication::setOrganizationName("galaxy");
    QCoreApplication::setOrganizationDomain("galaxy");
    QCoreApplication::setApplicationName("PicWorks");
    QCoreApplication::setApplicationVersion(QString("%1.%2.%3.%4").arg(VersionInfo::major(), VersionInfo::minor(), VersionInfo::revision(), VersionInfo::build()));
    if(app.isRunning())
    {
        app.activeWindow();
        return 0;
    }

    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(AppRes.splashImage());
    splash->show();
    Qt::Alignment topRight = Qt::AlignRight | Qt::AlignTop;
    splash->showMessage(QObject::tr("Loading main window...", "Loading text on splash screen."), topRight, Qt::white);

    QSettings *settings = new QSettings(app.applicationDirPath().append("/PicWorks.ini"), QSettings::IniFormat);

    // i18n
    QString locale = settings->value("i18n/locale").toString();
    if(locale.isEmpty()) {
        locale = QLocale::system().name();
        settings->setValue("i18n/locale", locale);
    }
    if(!locale.startsWith("en")) {
        // PicWorks's translation
        QTranslator *appTranslator = new QTranslator;
        appTranslator->load("./locale/pw_" + locale);
        app.installTranslator(appTranslator);
        // Qt's translation
        QTranslator *qtTranslator = new QTranslator;
        qtTranslator->load("./locale/qt_" + locale);
        app.installTranslator(qtTranslator);
    }

    MainWindow win;
    app.setActivationWindow(&win);

    //splash->showMessage(QObject::tr("Loading modules..."), topRight, Qt::white);
    //loadModules();
    //splash->showMessage(QObject::tr("Establishing connections..."), topRight, Qt::white);
    //establishConnections();
    win.showMaximized();
    splash->finish(&win);
    delete splash;

    return app.exec();
}

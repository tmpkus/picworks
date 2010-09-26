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

#include <QSplashScreen>
#include <QLocale>
#include <QTranslator>
#include <QSettings>

#include "mainwindow.h"
#include "QtSingleApplication"
#include "appcontext.h"

int main(int argc, char *argv[])
{
    QtSingleApplication app(argc, argv);
    QCoreApplication::setOrganizationName("galaxy");
    QCoreApplication::setOrganizationDomain("galaxy");
    QCoreApplication::setApplicationName("PicWorks");
    QCoreApplication::setApplicationVersion(appCtx->version());
    if(app.isRunning()) {
        app.activeWindow();
        return 0;
    }

    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/splash"));
    splash->show();
    Qt::Alignment topRight = Qt::AlignRight | Qt::AlignTop;
    splash->showMessage(QObject::tr("Loading main window...", "Loading text on splash screen."), topRight, Qt::white);

    QSettings *settings = new QSettings(app.applicationDirPath().append("/PicWorks.conf"), QSettings::IniFormat);

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

    Ui::MainWindow win;
    appCtx->setMainWindow(&win);
    win.show();

    app.setActivationWindow(&win);

    //splash->showMessage(QObject::tr("Loading modules..."), topRight, Qt::white);
    //loadModules();
    //splash->showMessage(QObject::tr("Establishing connections..."), topRight, Qt::white);
    //establishConnections();
    win.showMaximized();
    splash->finish(&win);
    delete splash;
    splash = 0;

    return app.exec();
}

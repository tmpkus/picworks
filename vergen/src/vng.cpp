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

#include <QDate>
#include <QFile>
#include <QTextStream>
#include <QStringList>

#include "vng.h"

/*!
  \brief Constructor.
  Create process to get verion information from SCM system.
 */
VersionNumberGenarator::VersionNumberGenarator(int argc, char *argv[])
{
    for(int i = 0; i < argc; i++) {
        args << QString(argv[i]);
    }
}

/*!
  \brief Genarate version number.
 */
int VersionNumberGenarator::genarate()
{
    const QDate today(QDate::currentDate());
    int buildNumber = (today.year() - 2009) * 1000 + today.dayOfYear();
    if(QFile::exists(args.at(4))) {
        QFile::remove(args.at(4));
    }
    QFile::copy(args.at(5), args.at(4));
    QFile cppFile(args.at(4));
    if(cppFile.open(QFile::WriteOnly | QFile::Append | QFile::Text)) {
        QTextStream printer(&cppFile);
        printer << endl
                << "/*!" << endl
                << "  \\internal" << endl
                << "  \\brief Major version number." << endl
                << " */" << endl
                << QString("QString VersionInfo::ma = QString(\"%1\");").arg(args.at(1)) << endl
                << endl
                << "/*!" << endl
                << "  \\internal" << endl
                << "  \\brief Minor version number." << endl
                << " */" << endl
                << QString("QString VersionInfo::mi = QString(\"%1\");").arg(args.at(2)) << endl
                << endl
                << "/*!" << endl
                << "  \\internal" << endl
                << "  \\brief Revision version number." << endl
                << " */" << endl
                << QString("QString VersionInfo::rivi = QString(\"%1\");").arg(args.at(3)) << endl
                << endl
                << "/*!" << endl
                << "  \\internal" << endl
                << "  \\brief Build version number." << endl
                << " */" << endl
                << QString("QString VersionInfo::bu = QString(\"%1\");").arg(buildNumber) << endl
                << endl
                << "/*!" << endl
                << "  \\internal" << endl
                << "  \\brief Build date." << endl
                << " */" << endl
                << QString("QString VersionInfo::bDate = QString(\"%1-%2-%3\");").arg(QString::number(today.year()), QString::number(today.month()), QString::number(today.day())) << endl
                << endl
                << "}" << endl;
    }
    cppFile.close();
    return 0;
}

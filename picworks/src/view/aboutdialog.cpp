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
  \file aboutdialog.cpp
  \ingroup View
  \brief This file contains
  - class View::AboutDialog implemtation
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2009-10-8 Created.
 */

#include <QApplication>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QPixmap>
#include <QPushButton>
#include <QTextEdit>

#include "../util/appresource.h"
#include "../util/appcontext.h"
#include "aboutdialog.h"
#include "licensedialog.h"

using namespace View;

/*!
  \class View::AboutDialog aboutdialog.h
  \brief The about dialog of PicWorks.
  This is the about dialog of PicWorks. There are some important message
  of PicWorks to be shown on this dialog such as copyright and licences.
  \note There should be only one application window running at the same time.
  \version 0.0.1
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2009-9-5 Created.
 */

/*!
  \brief Constructor.
  Creates a new about dialog instance.
  \param parent parent widget of this window, default value is 0
 */
AboutDialog::AboutDialog(QWidget *parent /* = 0 */)
        : QDialog(parent)
{
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowTitle(tr("About PicWorks", "About dialog title."));
    setAttribute(Qt::WA_DeleteOnClose);

    backgroundImage = AppRes.splashImage();
    resize(backgroundImage.width(), backgroundImage.height());

    int buttonY = backgroundImage.height() - 45;

    QTextEdit *desc = new QTextEdit(this);
    desc->setReadOnly(true);
    desc->setGeometry(15, 110, 370, 90);
    desc->setText("PicWorks Dev Version " + AppCtx.version());
    desc->append(tr("Copyright (C) Galaxy.org\n"
                    "PicWorks is developed on Qt Framework under the terms of GPLv3."
                    ,"Other description text in About Dialog."));

    // detail buttons
    QPushButton *licenseButton = new QPushButton(tr("License...", "License button text on About dialog."), this);
    licenseButton->setGeometry(185, buttonY, 120, 25);
    QPushButton *aboutQtButton = new QPushButton(tr("About Qt...", "About Qt button text on About dialog."), this);
    aboutQtButton->setGeometry(310, buttonY, 80, 25);

    // establish connections
    connect(aboutQtButton, SIGNAL(clicked()), this, SLOT(showAboutQtDialog()));
    connect(licenseButton, SIGNAL(clicked()), this, SLOT(showLicenseDialog()));
}

/*!
  \brief Destructor.
  Destructs the about dialog.
 */
AboutDialog::~AboutDialog()
{
}

/*!
  \internal
  \brief Adds image onto background.
 */
void AboutDialog::paintEvent(QPaintEvent* event)
{
    QPainter p(this);
    p.drawPixmap(0, 0, backgroundImage.width(), backgroundImage.height(), backgroundImage);
    QFont font("Arial", 12);
    font.setBold(true);
    p.setFont(font);
    p.setPen(Qt::blue);
    p.drawText(230, 100, "Version " + AppCtx.version());
}

/*!
  \internal
  \brief Closes the about dialog by pressing mouse on it.
 */
void AboutDialog::mousePressEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton) {
        accept();
    }
}

/*!
  \internal
  \brief Shows license dialog. This will close the about dialog first.
 */
void AboutDialog::showLicenseDialog()
{
    accept();
    LicenseDialog *ld = new LicenseDialog(this, Qt::WindowSystemMenuHint | Qt::WindowTitleHint);
    ld->exec();
}

/*!
  \internal
  \brief Shows about Qt dialog. This will close the about dialog first.
 */
void AboutDialog::showAboutQtDialog()
{
    accept();
    qApp->aboutQt();
}

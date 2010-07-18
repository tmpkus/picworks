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
  \file colorindicator.cpp
  \ingroup Ui
  \brief This file contains
  - class Ui::ColorIndicator implemtation
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2009-10-26 Created.
 */

#include <QApplication>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QPen>
#include <QColor>
#include <QColorDialog>
#include <QRect>
#include <QPoint>

#include "colorindicator.h"

/*!
  \class Ui::ColorIndicator colorindicator.h
  \brief This is the class which can select background or foreground colors.
  \version 0.0.1
  \author Cheng Liang <changliang.soft@gmail.com>
  \date 2009-10-26 Created.
  \date 2010-6-4 Reimplemented.
 */

/*!
  \brief Constructor.
  Creates a new ColorIndicator instance.
  \param parent parent widget of this window, default value is 0
 */
Ui::ColorIndicator::ColorIndicator(QWidget *parent /* = 0 */)
        : QWidget(parent),
          bgColor(Qt::white),
          fgColor(Qt::black),
          inFgSection(false),
          inBgSection(false)
{
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

/*!
  \brief Destructor.
  Destructs the ColorIndicator.
 */
Ui::ColorIndicator::~ColorIndicator()
{
}

/*!
  \brief Gets suitable size.
  \return size hint
 */
QSize Ui::ColorIndicator::sizeHint() const
{
    return QSize(45, 45).expandedTo(QApplication::globalStrut() * 1.5);
}

/*!
  \brief Gets minimum size.
  \return the minimum size hint
 */
QSize Ui::ColorIndicator::minimumSizeHint() const
{
    return QSize(20, 20).expandedTo(QApplication::globalStrut());
}

void Ui::ColorIndicator::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(QPen(QColor(204, 204, 204)));
    int cs = width() / 3;
    // background color section
    painter.setBrush(bgColor);
    painter.drawRect(0, 0, cs << 1, cs << 1);
    // foreground color section
    painter.setBrush(fgColor);
    painter.drawRect(cs, cs, cs << 1, cs << 1);
    paintResetSection(painter);
    paintSwitcherSection(painter);
}

void Ui::ColorIndicator::paintSwitcherSection(QPainter &painter) const
{
    QPen pen(Qt::black);
    painter.setPen(pen);
    painter.setBrush(Qt::black);
    painter.setRenderHint(QPainter::Antialiasing);
    int bgw = backgroundColorSection().width();
    int bgy = backgroundColorSection().y();
    const QPoint upTriangle[3] = {
        QPoint(bgw + 2, bgy + 4),
        QPoint(bgw + 6, bgy + 2),
        QPoint(bgw + 6, bgy + 6)
    };
    painter.drawPolygon(upTriangle, 3);
    int fgy = foregroundColorSection().y();
    const QPoint downTriangle[3] = {
        QPoint(width() - 6, fgy - 6),
        QPoint(width() - 2, fgy - 6),
        QPoint(width() - 4, fgy - 2)
    };
    painter.drawPolygon(downTriangle, 3);
    pen.setJoinStyle(Qt::RoundJoin);
    const QPoint line[3] = {
        QPoint(bgw + 4, bgy + 4),
        QPoint(width() - 4, bgy + 4),
        QPoint(width() - 4, fgy - 2)
    };
    painter.drawPolyline(line, 3);
}

void Ui::ColorIndicator::paintResetSection(QPainter &painter) const
{
    painter.setBrush(Qt::white);
    painter.setPen(QPen(Qt::black, 0.5, Qt::SolidLine));
    int bgx = backgroundColorSection().x();
    int bgh = backgroundColorSection().height();
    painter.drawRect(bgx + 1, bgh + 3, 8, 8);
    painter.setBrush(Qt::black);
    painter.drawRect(bgx + 4, bgh + 6, 8, 8);
}

void Ui::ColorIndicator::mousePressEvent(QMouseEvent *event)
{
    QPoint pos = event->pos();
    if(event->button() == Qt::LeftButton) {
        if(foregroundColorSection().contains(pos)) {
            inFgSection = true;
            inBgSection = false;
        } else if(backgroundColorSection().contains(pos)) {
            inBgSection = true;
            inFgSection = false;
        } else if(resetSection().contains(pos)) {
            setBackgroundColor(Qt::white);
            setForegroundColor(Qt::black);
        } else if(switcherSection().contains(pos)) {
            switchColors();
        }
    }
}

void Ui::ColorIndicator::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton) {
        if(inFgSection && foregroundColorSection().contains(event->pos())) {
            QColor c = QColorDialog::getColor(fgColor,
                                              this,
                                              tr("Choose foreground color"),
                                              QColorDialog::ShowAlphaChannel);
            if(c.isValid()) {
                setForegroundColor(c);
            }
        } else if(inBgSection && backgroundColorSection().contains(event->pos())) {
            QColor c = QColorDialog::getColor(bgColor,
                                              this,
                                              tr("Choose background color"),
                                              QColorDialog::ShowAlphaChannel);
            if (c.isValid()) {
                setBackgroundColor(c);
            }
        }
        inFgSection = inBgSection = false;
    }
}

inline QRect Ui::ColorIndicator::backgroundColorSection() const
{
    int cs2 = width() / 3 << 1;
    return QRect(0, 0, cs2, cs2);
}

inline QRect Ui::ColorIndicator::foregroundColorSection() const
{
    int cs = width() / 3;
    return QRect(cs, cs, cs << 1, cs << 1);
}

inline QRect Ui::ColorIndicator::resetSection() const
{
    return QRect(backgroundColorSection().x() + 1,
                 backgroundColorSection().height() + 3,
                 12, 12);
}

inline QRect Ui::ColorIndicator::switcherSection() const
{
    return QRect(backgroundColorSection().width() + 2,
                 backgroundColorSection().y() + 2,
                 11, 11);
}

inline void Ui::ColorIndicator::setBackgroundColor(const QColor &c)
{
    if(bgColor != c) {
        emit backgroundColorChanged(bgColor);
        bgColor = c;
        update();
    }
}

inline void Ui::ColorIndicator::setForegroundColor(const QColor &c)
{
    if(fgColor != c) {
        emit foregroundColorChanged(fgColor);
        fgColor = c;
        update();
    }
}

inline void Ui::ColorIndicator::switchColors()
{
     if (fgColor != bgColor) {
         qSwap(fgColor, bgColor);
         emit backgroundColorChanged(bgColor);
         emit foregroundColorChanged(fgColor);
         update();
     }
 }


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

/**
 * \file colorindicator.h
 * \ingroup Ui
 * \brief This file contains
 * - class Ui::ColorIndicator declaration
 * \author Cheng Liang <changliang.soft@gmail.com>
 * \date 2009-10-26 Created.
 */

#ifndef COLORINDICATOR_H
#define COLORINDICATOR_H

#include <QWidget>

class QPaintEvent;
class QMouseEvent;
class QColor;
class QRect;
class QPainter;

namespace Ui {

class ColorIndicator : public QWidget
{
    Q_OBJECT
public:
    explicit ColorIndicator(QWidget *parent = 0);
    ~ColorIndicator();

    QSize sizeHint() const;
    QSize minimumSizeHint() const;

public slots:
    void setBackgroundColor(const QColor &c);
    void setForegroundColor(const QColor &c);

signals:
    void backgroundColorChanged(const QColor &oldColor);
    void foregroundColorChanged(const QColor &newColor);

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    QRect backgroundColorSection() const;
    QRect foregroundColorSection() const;
    QRect resetSection() const;
    QRect switcherSection() const;
    void paintSwitcherSection(QPainter &painter) const;
    void paintResetSection(QPainter &painter) const;
    void switchColors();

    QColor bgColor;
    QColor fgColor;
    bool inFgSection;
    bool inBgSection;

}; // end of class ColorIndicator

} // end of namespace

#endif // COLORINDICATOR_H

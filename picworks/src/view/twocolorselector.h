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
 * @file twocolorselector.h
 * @ingroup View
 * @brief This file contains
 * - class View::TwoColorSelector declaration
 * @author Cheng Liang <changliang.soft@gmail.com>
 * @date 2009-10-26 Created.
 */

#ifndef TWOCOLORSELECTOR_H
#define TWOCOLORSELECTOR_H

#include <QWidget>
#include <QColor>
#include <QPoint>
#include <QRect>
#include <QDrag>

class QSize;
class QMouseEvent;
class QDragEnterEvent;
class QDragMoveEvent;
class QDropEvent;

namespace View {

class TwoColorSelector : public QWidget
{
    Q_OBJECT
public:
    explicit TwoColorSelector(QWidget *parent = 0);
    ~TwoColorSelector();
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    inline const QPoint & pressPosition() const { return pressPos; }

    inline bool isActive() const { return active; }

    inline const QColor & backgroundColor() const { return bgColor; }

    inline const QColor & foregroundColor() const { return fgColor; }

    inline bool dragEnabled() const { return dragable; }

    inline QRect backgroundColorRect() const
    {
        return QRect(0, 0,
                     (this->width() / 3) << 1, (this->height() / 3) << 1);
    }

    inline QRect foregroundColorRect() const
    {
        return QRect(this->width() / 3, this->height() / 3,
                     (this->width() / 3) << 1, (this->height() / 3) << 1);
    }

    inline QRect resetColorsRect() const
    {
        return QRect(backgroundColorRect().x() + 2,
                     backgroundColorRect().height() + 1,
                     12, 12);
    }

    inline QRect switchColorsRect() const
    {
        return QRect(backgroundColorRect().width() + 2,
                     backgroundColorRect().y() + 2,
                     11, 11);
    }

public slots:
    void switchColors();

    inline void setActive(bool a) { active = a; }

    inline void setBackgroundColor(const QColor & bc)
    {
        if (bc == bgColor) {
            return;
        }
        bgColor = bc;
        emit backgroundColorChanged(bc);
        update();
    }

    inline void setForegroundColor(const QColor & fc)
    {
        if (fc == fgColor) {
            return;
        }
        fgColor = fc;
        emit foregroundColorChanged(fc);
        update();
    }

    inline void setDragEnabled(bool enabled) { dragable = enabled; }

signals:
    void foregroundColorChanged(const QColor & newColor);
    void backgroundColorChanged(const QColor & newColor);

protected:
    void paintEvent(QPaintEvent * event);
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent * event);
    void dragEnterEvent(QDragEnterEvent * event);
    void dragMoveEvent(QDragMoveEvent * event);
    void dropEvent(QDropEvent * event);

private:
    QColor fgColor; // foreground color
    QColor bgColor; // background color
    QPoint pressPos; // pressed position
    bool inFgPoint; // whether in foreground color section
    bool inBgPoint; // whether in background color section
    bool active;
    bool dragable;

    void paintSection(QPainter * painter, const QRect & rect, const QColor & color);
    void paintSwitchSection(QPainter * painter);
    void paintResetSection(QPainter * painter);

}; // end of class

class ColorDrag : public QDrag {

public:

    ColorDrag(QWidget *source, const QColor &color, const QString &name);

}; // end of class ColorDrag

} // end of namespace

#endif // TWOCOLORSELECTOR_H

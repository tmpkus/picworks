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
  \file twocolorselector.cpp
  \ingroup View
  \brief This file contains
  - class PicWorks::TwoColorSelector implemtation
  \author Cheng Liang <chengliang.soft@gmail.com>
  \date 2009-10-26 Created.
 */

#include <QPaintEvent>
#include <QSizePolicy>
#include <QStyleOptionButton>
#include <QStyle>
#include <QCursor>
#include <QPalette>
#include <QSize>
#include <QMouseEvent>
#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QPixmap>
#include <QPen>
#include <QMimeData>
#include <QColorDialog>
#include <QPainter>
#include <QApplication>

#include "twocolorselector.h"

using namespace View;

/*!
  \class PicWorks::TwoColorSelector twocolorselector.h
  \brief This is the class which can select background or foreground colors.
  \version 0.0.1
  \author Cheng Liang <changliang.soft@gmail.com>
  \date 2009-10-26 Created.
 */

/*!
  \fn const QPoint & PicWorks::TwoColorSelector::pressPosition() const
  \brief Gets the mouse pressed position on this selector.
  \return position the mouse pressed

  \fn bool PicWorks::TwoColorSelector::isActive() const
  \brief Gets whether the selector is active or not.
  \return true, if this selector is active

  \fn const QColor & PicWorks::TwoColorSelector::backgroundColor() const
  \brief Gets selected background color.
  \return selected background color

  \fn const QColor & PicWorks::TwoColorSelector::foregroundColor() const
  \brief Gets selected foreground color.
  \return selected foreground color

  \fn bool PicWorks::TwoColorSelector::dragEnabled() const
  \brief Gets whether the selector is drag enabled or not.
  \return whether the selector is drag enabled or not

  \fn QRect PicWorks::TwoColorSelector::backgroundColorRect() const
  \brief Gets the background color area on the selector.
  \return the background color area on the selector

  \fn QRect PicWorks::TwoColorSelector::foregroundColorRect() const
  \brief Gets the foreground color area on the selector.
  \return the foreground color area on the selector

  \fn QRect PicWorks::TwoColorSelector::resetColorsRect() const
  \brief Gets the color reset rectangle on this selector.
  \return the reset button bound

  \fn QRect PicWorks::TwoColorSelector::switchColorsRect() const
  \brief Gets the color switch rectangle on this selector.
  \return the switch button bound

  \fn void PicWorks::TwoColorSelector::setActive(bool a)
  \brief Sets whether the selector is active.
  \param a true, if this selector is active

  \fn void PicWorks::TwoColorSelector::setBackgroundColor(const QColor & bc)
  \brief Sets background color.
  If the new color is different from the old one, a
  \a backgroundColorChanged(const QColor &) single will be emitted.
  \param bc new background color

  \fn void PicWorks::TwoColorSelector::setForegroundColor(const QColor & fc)
  \brief Sets foreground color.
  If the new color is different from the old one, a
  \a foregroundColorChanged(const QColor &) single will be emitted.
  \param fc new foreground color

  \fn void PicWorks::TwoColorSelector::setDragEnabled(bool enabled)
  \brief Sets drag enabled.
  \param enabled whether drag operation is enabled or not

  \fn void PicWorks::TwoColorSelector::foregroundColorChanged(const QColor & newColor)
  \brief Emits if foreground color changes.
  \param newColor the new foreground color selected

  \fn void PicWorks::TwoColorSelector::backgroundColorChanged(const QColor & newColor)
  \brief Emits if background color changes.
  \param newColor the new background color selected
 */

/*!
  \class PicWorks::ColorDrag twocolorselector.h
  \brief The drag event class of dragging a color.
  \version 0.0.1
  \author Cheng Liang <changliang.soft@gmail.com>
  \date 2009-10-28 Created.
 */

/*!
  \brief Constructor.
  Creates a new TwoColorSelector instance.
  \param parent parent widget of this window, default value is 0
 */
TwoColorSelector::TwoColorSelector(QWidget *parent /* = 0 */)
        : QWidget(parent), fgColor(Qt::black), bgColor(Qt::white)
{
    inFgPoint = false;
    inBgPoint = false;
    active = true;
    dragable = true;

    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    setAttribute(Qt::WA_Hover);
    setAcceptDrops(true);
    setMouseTracking(true);
}

/*!
  \brief Destructor.
  Destructs the TwoColorSelector dialog.
 */
TwoColorSelector::~TwoColorSelector()
{
}

/*!
  \internal
 */
void TwoColorSelector::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    paintSection(&painter, backgroundColorRect(), bgColor);
    paintSection(&painter, foregroundColorRect(), fgColor);
    paintResetSection(&painter);
    paintSwitchSection(&painter);
}

/*!
  \internal
 */
void TwoColorSelector::paintSection(QPainter * painter, const QRect & rect, const QColor & color)
{
    QStyleOptionButton opt;
    opt.initFrom(this);
    opt.rect = rect;
    if ((rect.contains(QPoint(3, 3)) && inFgPoint)
        || (rect.contains(QPoint(width() - 4, height() - 4)) && inBgPoint)) {
        opt.state |= QStyle::State_Sunken;
    } else {
        opt.state |= QStyle::State_Raised;
    }
    if (rect == foregroundColorRect()
        && rect.contains(mapFromGlobal(QCursor::pos()))) {
        opt.state |= QStyle::State_MouseOver;
    } else if (rect == backgroundColorRect()
                && rect.contains(mapFromGlobal(QCursor::pos()))
                && !foregroundColorRect().contains(mapFromGlobal(QCursor::pos()))) {
        opt.state |= QStyle::State_MouseOver;
    } else {
        opt.state &= ~(QStyle::State_MouseOver);
    }
    style()->drawControl(QStyle::CE_PushButtonBevel, &opt, painter, this);
    QRect fillRect = style()->subElementRect(QStyle::SE_PushButtonContents, &opt, this);
    int offset = (opt.rect.height() - fillRect.height()) >> 1;
    fillRect = opt.rect.adjusted(offset, offset, -offset, -offset);
    if (opt.state & QStyle::State_Sunken) {
        fillRect.translate(style()->pixelMetric(QStyle::PM_ButtonShiftHorizontal),
                           style()->pixelMetric(QStyle::PM_ButtonShiftVertical));
    }
    painter->setPen(Qt::NoPen);
    painter->setBrush(opt.state & QStyle::State_Enabled
                        ? color
                        : palette().color(QPalette::Disabled, QPalette::Window ));
    // check if (0,0) hits the button - if yes -> drawRect, otherwise drawRoundedRect
    painter->setRenderHint(QPainter::Antialiasing);
    painter->drawRoundedRect(fillRect, 3, 3);
}

/*!
  \internal
 */
void TwoColorSelector::paintResetSection(QPainter * painter)
{
    painter->setRenderHint(QPainter::Antialiasing, false);
    painter->setBrush(Qt::white);
    painter->setPen(QPen(Qt::black, 0.5, Qt::SolidLine));
    painter->drawRect(backgroundColorRect().x() + 2, backgroundColorRect().height() + 1, 8, 8);
    painter->setBrush(Qt::black);
    painter->drawRect(backgroundColorRect().x() + 5, backgroundColorRect().height() + 4, 8, 8);
}

/*!
  \internal
 */
void TwoColorSelector::paintSwitchSection(QPainter * painter)
{
    painter->setRenderHint(QPainter::Antialiasing);
    QPen pen(Qt::black);
    painter->setPen(pen);
    const QPoint upTriangle[3] = {
        QPoint(backgroundColorRect().width() + 2, backgroundColorRect().y() + 4),
        QPoint(backgroundColorRect().width() + 6, backgroundColorRect().y() + 2),
        QPoint(backgroundColorRect().width() + 6, backgroundColorRect().y() + 6)
    };
    painter->drawPolygon(upTriangle, 3);
    const QPoint downTriangle[3] = {
        QPoint(width() - 6, foregroundColorRect().y() - 6),
        QPoint(width() - 2, foregroundColorRect().y() - 6),
        QPoint(width() - 4, foregroundColorRect().y() - 2)
    };
    painter->drawPolygon(downTriangle, 3);
    pen.setJoinStyle(Qt::RoundJoin);
    const QPoint line[3] = {
        QPoint(backgroundColorRect().width() + 2, backgroundColorRect().y() + 4),
        QPoint(width() - 4, backgroundColorRect().y() + 4),
        QPoint(width() - 4, foregroundColorRect().y() - 2)
    };
    painter->drawPolyline(line, 3);
}

/*!
  \brief Gets suitable size.
  \return size hint
 */
QSize TwoColorSelector::sizeHint() const
{
    return QSize(45, 45).expandedTo(QApplication::globalStrut() * 1.5);
}

/*!
  \brief Gets minimum size.
  \return the minimum size hint
 */
QSize TwoColorSelector::minimumSizeHint() const
{
    return QSize(20, 20).expandedTo(QApplication::globalStrut());
}

/*!
  \brief Swaps foreground and background colors.
 */
void TwoColorSelector::switchColors() {
    if (fgColor == bgColor) {
        return;
    }
    qSwap(fgColor, bgColor);
    emit backgroundColorChanged(bgColor);
    emit foregroundColorChanged(fgColor);
    update();
}

/*!
  \internal
 */
void TwoColorSelector::mousePressEvent(QMouseEvent * event) {
    pressPos = event->pos();
    if (event->button() == Qt::LeftButton) {
        if (foregroundColorRect().contains(event->pos())) {
            inFgPoint = true;
            inBgPoint = false;
            // emit foregroundColorRectPressed();
            update();
        } else if (backgroundColorRect().contains(event->pos())) {
            inBgPoint = true;
            inFgPoint = false;
            // emit backgroundColorRectPressed();
            update();
        } else if (resetColorsRect().contains(event->pos())) {
            setBackgroundColor(Qt::white);
            setForegroundColor(Qt::black);
            update();
        } else if (switchColorsRect().contains(event->pos())) {
            switchColors();
        }
    }
}

/*!
  \internal
 */
void TwoColorSelector::mouseMoveEvent(QMouseEvent *event)
{
    if (inFgPoint || inBgPoint) {
        if (dragEnabled() && (event->pos() - pressPos).manhattanLength()
                >= QApplication::startDragDistance()) {
            QColor col = inFgPoint ? foregroundColor() : backgroundColor();
            ColorDrag *drag = new ColorDrag(this, col, col.name());
            drag->exec();
            inFgPoint = inBgPoint = false;
            update();
        }
    } else if (testAttribute(Qt::WA_Hover)) {
        update();
    }
    QWidget::mouseMoveEvent(event);
}

/*!
  \internal
 */
void TwoColorSelector::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        if (inFgPoint && foregroundColorRect().contains(event->pos())) {
            // emit foregroundColorRectClicked();
            if (active) {
                QColor c = QColorDialog::getColor(fgColor,
                                                  this,
                                                  tr("Choose foreground color"),
                                                  QColorDialog::ShowAlphaChannel);
                if (c.isValid()) {
                    setForegroundColor(c);
                }
            }
        } else if (inBgPoint && backgroundColorRect().contains(event->pos())) {
            // emit baclgroundColorRectClicked();
            if (active) {
                QColor c = QColorDialog::getColor(bgColor,
                                                  this,
                                                  tr("Choose background color"),
                                                  QColorDialog::ShowAlphaChannel);
                if (c.isValid()) {
                    setBackgroundColor(c);
                }
            }
        }
        inFgPoint = inBgPoint = false;
        update();
    }
}

/*!
  \internal
 */
void TwoColorSelector::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasColor()) {
        QColor col(qvariant_cast<QColor>(event->mimeData()->colorData()));
        if (col.isValid()) {
            event->acceptProposedAction();
        }
    } else if (event->mimeData()->hasFormat("text/plain")) {
        QColor col;
        col.setNamedColor(event->mimeData()->text());
        if (col.isValid()) {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

/*!
  \internal
 */
void TwoColorSelector::dragMoveEvent(QDragMoveEvent *event)
{
    bool acc = false;
    if (event->mimeData()->hasColor()) {
        QColor col(qvariant_cast<QColor>(event->mimeData()->colorData()));
        if (col.isValid()) {
            acc = true;
        }
    } else if (event->mimeData()->hasFormat("text/plain")) {
        QColor col;
        col.setNamedColor(event->mimeData()->text());
        if (col.isValid()) {
            acc = true;
        }
    } else {
        event->ignore();
    }
    if (foregroundColorRect().intersects(event->answerRect())) {
        event->acceptProposedAction();
        event->accept(foregroundColorRect());
    } else if (backgroundColorRect().intersects(event->answerRect())) {
        event->acceptProposedAction();
    } else {
        event->ignore();
    }
}

/*!
  \internal
 */
void TwoColorSelector::dropEvent(QDropEvent *event)
{
    QColor col;
    if (event->mimeData()->hasColor()) {
        col = qvariant_cast<QColor>(event->mimeData()->colorData());
    } else {
        col.setNamedColor(event->mimeData()->text());
    }
    if (foregroundColorRect().contains(event->pos())) {
        setForegroundColor(col);
    } else if (backgroundColorRect().contains(event->pos())) {
        setBackgroundColor(col);
    }
    event->setDropAction(Qt::CopyAction);
}

/*!
  \brief Constructs a ColorDrag instance.
  \param source source widget starting to drag
  \param color source color
  \param name drag name
 */
ColorDrag::ColorDrag(QWidget *source, const QColor &color, const QString &name)
        : QDrag(source)
{
        int siz = source->style()->pixelMetric(QStyle::PM_ButtonIconSize, 0, source);
        QPixmap px = QPixmap(QSize(siz,siz));
        px.fill(color);
        setPixmap(px);
        QMimeData *mimeData = new QMimeData;
        mimeData->setColorData(color);
        mimeData->setText(name);
        mimeData->setImageData(px.toImage());
        setMimeData(mimeData);
}

/****************************************************************************************
 * Copyright (c) 2006 Peter Penz <peter.penz@gmx.at>                                    *
 * Copyright (c) 2006 Aaron Seigo <aseigo@kde.org>                                      *
 * Copyright (c) 2009 Seb Ruiz <ruiz@kde.org>                                           *
 *                                                                                      *
 * This program is free software; you can redistribute it and/or modify it under        *
 * the terms of the GNU General Public License as published by the Free Software        *
 * Foundation; either version 2 of the License, or (at your option) any later           *
 * version.                                                                             *
 *                                                                                      *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY      *
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A      *
 * PARTICULAR PURPOSE. See the GNU General Public License for more details.             *
 *                                                                                      *
 * You should have received a copy of the GNU General Public License along with         *
 * this program.  If not, see <http://www.gnu.org/licenses/>.                           *
 ****************************************************************************************/

#ifndef BREADCRUMBITEMBUTTON_P_H
#define BREADCRUMBITEMBUTTON_P_H

#include <QColor>

#include "ElidingButton.h"

class QEvent;

/**
 * @brief Base class for buttons of the URL navigator.
 *
 * Each button of the URL navigator contains an URL, which
 * is set as soon as the button has been clicked.
 */
class BreadcrumbItemButton : public ElidingButton
{
    Q_OBJECT

    public:
        BreadcrumbItemButton( QWidget* parent );
        BreadcrumbItemButton( const QIcon &icon, const QString &text, QWidget *parent );
        virtual ~BreadcrumbItemButton();

        void setActive( const bool active );

        virtual QSize sizeHint() const;

    protected:
        enum DisplayHint
        {
            ActiveHint = 1,
            HoverHint = 2
        };

        void setDisplayHintEnabled(DisplayHint hint, bool enable);
        bool isDisplayHintEnabled(DisplayHint hint) const;

        virtual void enterEvent(QEvent* event);
        virtual void leaveEvent(QEvent* event);

        virtual void paintEvent(QPaintEvent* event);
        virtual void drawHoverBackground(QPainter* painter);

        /** Returns the foreground color by respecting the current display hint. */
        QColor foregroundColor() const;

    private:
        void init();
        int m_displayHint;
};

#endif

#include "UpdateDelegate.h"

// Qt
#include <QApplication>
#include <QtGui/QMouseEvent>
#include <QtGui/QPainter>

// KDE includes
#include <KDebug>
#include <KIcon>
#include <KIconLoader>

#define SPACING 4
#define ICON_SIZE KIconLoader::SizeSmallMedium

UpdateDelegate::UpdateDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{
}

QSize UpdateDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(index);

    QSize size;
    QFontMetrics metric = QFontMetrics(option.font);

    size.setWidth(metric.width(index.data(Qt::DisplayRole).toString()));
    size.setHeight(ICON_SIZE + SPACING);

    if (index.column() == 0) {
        const QStyle *style = QApplication::style();
        QRect rect = style->subElementRect(QStyle::SE_CheckBoxIndicator, &option);
        // Adds the icon size AND the checkbox size
        // [ x ] (icon) Text
        size.rwidth() += 4 * SPACING + ICON_SIZE + rect.width();
    }

    return size;
}

bool UpdateDelegate::editorEvent(QEvent *event,
                                 QAbstractItemModel *model,
                                 const QStyleOptionViewItem &option,
                                 const QModelIndex &index)
{
    bool setData = false;
    if (index.column() == 0 &&
        event->type() == QEvent::MouseButtonRelease) {
    }

    const QWidget *widget = 0;
    if (const QStyleOptionViewItemV4 *v4 = qstyleoption_cast<const QStyleOptionViewItemV4 *>(&option)) {
        widget = v4->widget;
    }

    QStyle *style = widget ? widget->style() : QApplication::style();

    // make sure that we have the right event type
    if ((event->type() == QEvent::MouseButtonRelease)
        || (event->type() == QEvent::MouseButtonDblClick)) {
        setData = true;
        QStyleOptionViewItemV4 viewOpt(option);
        initStyleOption(&viewOpt, index);
        QRect checkRect = style->subElementRect(QStyle::SE_ItemViewItemCheckIndicator, &viewOpt, widget);
        QMouseEvent *me = static_cast<QMouseEvent*>(event);
        if (me->button() != Qt::LeftButton || !checkRect.contains(me->pos()))
            return false;

        // eat the double click events inside the check rect
        if (event->type() == QEvent::MouseButtonDblClick)
            return true;

        setData = true;
    } else if (event->type() == QEvent::KeyPress) {
        if (static_cast<QKeyEvent*>(event)->key() == Qt::Key_Space
         || static_cast<QKeyEvent*>(event)->key() == Qt::Key_Select) {
            setData = true;
        }
    }

    if (setData) {
        return model->setData(index,
                       !index.data(Qt::CheckStateRole).toBool(),
                       Qt::CheckStateRole);
    }
    return false;
}

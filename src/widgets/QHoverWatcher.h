#ifndef QHOVERWATCHER_H
#define QHOVERWATCHER_H

#include <QWidget>
#include <QEvent>
#include <QStyleOption>
#include <QPainter>

class QHoverWatcher: public QWidget{
    Q_OBJECT

public:
    explicit QHoverWatcher(QWidget *parent = nullptr) : QWidget(parent) { this->installEventFilter(this); }

protected:
    bool eventFilter(QObject *, QEvent *event) override {
        switch (event->type()) {
            case QEvent::Enter:
            case QEvent::HoverEnter:
                emit entered();
                break;
        default: break;
        }
        return false;
    }

    void paintEvent(QPaintEvent *event) override {
        QStyleOption opt;
        opt.initFrom(this);
        QPainter p(this);
        style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
        QWidget::paintEvent(event);
    }

signals:
    void entered();
};

#endif // QHOVERWATCHER_H

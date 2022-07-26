#ifndef HISTORYWIDGET_H
#define HISTORYWIDGET_H

#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QSpacerItem>
#include <widgets/panels/abstractpanel.h>
#include <QGraphicsDropShadowEffect>

class HistoryWidget : public AbstractPanel
{
    Q_OBJECT
public:
    explicit HistoryWidget(QWidget *parent = nullptr);

signals:
    void closed();
};

#endif // HISTORYWIDGET_H

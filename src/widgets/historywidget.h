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

class HistoryWidget : public QWidget
{
    Q_OBJECT

    QVBoxLayout* mainLayout;

    QWidget* titleBarWidget;
    QHBoxLayout* titleBarLayout;

    QLabel* titleName;
    QSpacerItem* titleBarSpacer;
    QPushButton* viewButton;
    QPushButton* closeButton;

    QWidget* mainWidget;


public:
    explicit HistoryWidget(QWidget *parent = nullptr);

signals:

};

#endif // HISTORYWIDGET_H

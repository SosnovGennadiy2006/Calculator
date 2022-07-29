#ifndef HISTORYWIDGET_H
#define HISTORYWIDGET_H

#include <QObject>
#include <QWidget>
#include "../../widgets/panelWidgets/abstractPanelWidget.h"

class HistoryWidget : public AbstractPanelWidget
{
    Q_OBJECT
public:
    explicit HistoryWidget(QWidget *parent = nullptr);

    void setupUI() override;
    void setupConections() override;

signals:

};

#endif // HISTORYWIDGET_H

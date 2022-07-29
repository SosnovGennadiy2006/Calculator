#ifndef HISTORYWINDOW_H
#define HISTORYWINDOW_H

#include "abstractPanelWindow.h"
#include <QObject>
#include <QWidget>
#include "../../../widgets/panelWidgets/historyWidget.h"

class HistoryWindow : public AbstractPanelWindow
{
    Q_OBJECT
public:
    explicit HistoryWindow(QWidget* parent = nullptr);

    void setupUI() override;
};

#endif // HISTORYWINDOW_H

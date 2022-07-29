#ifndef HISTORYPANELSECTION_H
#define HISTORYPANELSECTION_H

#include "abstractPanelSection.h"
#include <QObject>
#include <QWidget>
#include "../../widgets/panelWidgets/historyWidget.h"
#include "../../widgets/windows/panelWindows/historyWindow.h"

class HistoryPanelSection : public AbstractPanelSection
{
    Q_OBJECT

    HistoryWindow* window;

public:
    explicit HistoryPanelSection(QWidget* parent = nullptr);

protected slots:
    void viewWindow() override;
    void closeWindow() override;
    void hideWindow() override;
};

#endif // HISTORYPANELSECTION_H

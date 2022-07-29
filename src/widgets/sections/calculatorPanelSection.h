#ifndef CALCULATORPANELSECTION_H
#define CALCULATORPANELSECTION_H

#include "abstractPanelSection.h"
#include <QObject>
#include <QWidget>
#include "../../widgets/panelWidgets/calculatorWidget.h"
#include "../../widgets/panelWidgets/abstractPanelWidget.h"
#include "../../widgets/windows/panelWindows/calculatorWindow.h"

class CalculatorPanelSection : public AbstractPanelSection
{
    Q_OBJECT

    CalculatorWindow* window;

public:
    explicit CalculatorPanelSection(QWidget *parent = nullptr);

protected slots:
    void viewWindow() override;
    void closeWindow() override;
    void hideWindow() override;
};

#endif // CALCULATORPANELSECTION_H

#ifndef CALCULATORPANELSECTION_H
#define CALCULATORPANELSECTION_H

#include "abstractSection.h"
#include <QObject>
#include <QWidget>
#include "../../widgets/panelWidgets/calculatorWidget.h"
#include "../../widgets/panelWidgets/abstractPanelWidget.h"
#include "../../widgets/windows/panelWindows/calculatorWindow.h"

class CalculatorSection : public AbstractSection
{
    Q_OBJECT

    CalculatorWindow* window;
    CalculatorWidget* panelWidget;

public:
    explicit CalculatorSection(QWidget *parent = nullptr);

    void restoreMemory(const QString& text);

signals:
    void memoryClearBtnClicked();
    void memoryStoreBtnClicked(const QString& number);
    void memoryRestoreBtnClicked();
    void memoryPlusBtnClicked(double number);
    void memoryMinusBtnClicked(double number);

protected slots:
    void viewWindow() override;
    void closeWindow() override;
    void hideWindow() override;
};

#endif // CALCULATORPANELSECTION_H

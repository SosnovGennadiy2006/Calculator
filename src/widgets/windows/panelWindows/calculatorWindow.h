#ifndef CALCULATORWINDOW_H
#define CALCULATORWINDOW_H

#include "abstractPanelWindow.h"
#include <QObject>
#include <QWidget>
#include "../../../widgets/panelWidgets/calculatorWidget.h"

class CalculatorWindow : public AbstractPanelWindow
{
    Q_OBJECT

public:
    explicit CalculatorWindow(QWidget* parent = nullptr);

    void setupUI() override;
};

#endif // CALCULATORWINDOW_H

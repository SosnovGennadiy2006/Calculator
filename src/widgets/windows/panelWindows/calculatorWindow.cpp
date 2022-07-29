#include "calculatorWindow.h"

CalculatorWindow::CalculatorWindow(QWidget* parent) :
    AbstractPanelWindow{parent} {
    setupUI();
}


void CalculatorWindow::setupUI()
{
    tb->setWindowIcon(QIcon(":/icons/calculator.png"));
    tb->setWindowTitle("Engineering calculator");

    setPanelWidget(new CalculatorWidget(this));
}

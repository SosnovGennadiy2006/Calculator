#include "calculatorPanelSection.h"

CalculatorPanelSection::CalculatorPanelSection(QWidget *parent) :
    AbstractPanelSection{new CalculatorWidget(), parent}
{
    tb->setWindowIcon(QIcon(":/icons/calculator.png"));
    tb->setWindowTitle("Engineering calculator");
}

void CalculatorPanelSection::viewWindow()
{
    hide();

    window = new CalculatorWindow();

    window->setGeometry(mapToGlobal(QPointF(0, 0)).rx(),
                        mapToGlobal(QPointF(0, 0)).ry(),
                        width(), height());

    window->show();

    connect(window, &CalculatorWindow::closed, this, &CalculatorPanelSection::closeWindow);
    connect(window, &CalculatorWindow::hided, this, &CalculatorPanelSection::hideWindow);

    emit CalculatorPanelSection::viewed();
}

void CalculatorPanelSection::closeWindow()
{
    emit windowClosed();
}

void CalculatorPanelSection::hideWindow()
{
    show();
    window->close();

    emit windowHided();
}

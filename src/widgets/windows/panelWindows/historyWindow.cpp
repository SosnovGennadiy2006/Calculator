#include "historyWindow.h"

HistoryWindow::HistoryWindow(QWidget* parent) : AbstractPanelWindow{parent}
{
    setupUI();
}

void HistoryWindow::setupUI()
{
    tb->setWindowIcon(QIcon(":/icons/history.png"));
    tb->setWindowTitle("History");

    panelWidget = new HistoryWidget();

    setPanelWidget(panelWidget);
}

double HistoryWindow::getValue() const
{
    return panelWidget->getValue();
}

void HistoryWindow::setNumbers(const QVector<double>& _items)
{
    panelWidget->setNumbers(_items);
}

QVector<double> HistoryWindow::getNumbers() const
{
    return panelWidget->getNumbers();
}

void HistoryWindow::clearMemory()
{
    panelWidget->clear();
}

void HistoryWindow::memoryPlus(double number)
{
    panelWidget->memoryPlus(number);
}

void HistoryWindow::memoryMinus(double number)
{
    panelWidget->memoryMinus(number);
}

void HistoryWindow::addNumber(double number)
{
    panelWidget->addNumber(number);
}
#include "historySection.h"

HistorySection::HistorySection(QWidget* parent) :
    AbstractSection{parent}
{
    tb->setWindowIcon(QIcon(":/icons/history.png"));
    tb->setWindowTitle("History");

    panelWidget = new HistoryWidget();

    setPanelWidget(panelWidget);

    window = nullptr;
}

void HistorySection::viewWindow()
{
    hide();

    window = new HistoryWindow();

    window->setGeometry(mapToGlobal(QPointF(0, 0)).rx(),
                        mapToGlobal(QPointF(0, 0)).ry(),
                        width(), height());
    window->setMinimumSize(500, 500);

    window->setNumbers(panelWidget->getNumbers());

    window->show();

    connect(window, &HistoryWindow::closed, this, &HistorySection::closeWindow);
    connect(window, &HistoryWindow::hided, this, &HistorySection::hideWindow);

    emit viewed();
}

void HistorySection::closeWindow()
{
    emit windowClosed();
}

void HistorySection::hideWindow()
{
    show();
    window->close();

    emit windowHided();
}

double HistorySection::getValue() const
{
    return panelWidget->getValue();
}

void HistorySection::clearMemory()
{
    panelWidget->clear();
    if (window != nullptr) {
        window->clearMemory();
    }
}

void HistorySection::memoryPlus(double number)
{
    panelWidget->memoryPlus(number);
    if (window != nullptr) {
        window->memoryPlus(number);
    }
}

void HistorySection::memoryMinus(double number)
{
    panelWidget->memoryMinus(number);
    if (window != nullptr) {
        window->memoryMinus(number);
    }
}

void HistorySection::addNumber(const QString& number)
{
    panelWidget->addNumber(number.toDouble());
    if (window != nullptr)
    {
        window->addNumber(number.toDouble());
    }
}
#include "calculatorSection.h"

CalculatorSection::CalculatorSection(QWidget *parent) :
    AbstractSection{ parent}
{
    panelWidget = new CalculatorWidget();

    window = nullptr;

    setPanelWidget(panelWidget);

    tb->setWindowIcon(QIcon(":/icons/calculator.png"));
    tb->setWindowTitle("Engineering calculator");

    connect(panelWidget, &CalculatorWidget::memoryClearBtnClicked, this, [this](){
        emit memoryClearBtnClicked();
    });
    connect(panelWidget, &CalculatorWidget::memoryStoreBtnClicked, this, [this](){
        emit memoryStoreBtnClicked(panelWidget->count(panelWidget->getLineEditText()));
    });
    connect(panelWidget, &CalculatorWidget::memoryRestoreBtnClicked, this, [this](){
        emit memoryRestoreBtnClicked();
    });
    connect(panelWidget, &CalculatorWidget::memoryPlusBtnClicked, this, [this](){
        emit memoryPlusBtnClicked(panelWidget->count(panelWidget->getLineEditText()).toDouble());
    });
    connect(panelWidget, &CalculatorWidget::memoryMinusBtnClicked, this, [this](){
        emit memoryMinusBtnClicked(panelWidget->count(panelWidget->getLineEditText()).toDouble());
    });
}

void CalculatorSection::viewWindow()
{
    hide();

    window = new CalculatorWindow();

    window->setGeometry(mapToGlobal(QPointF(0, 0)).rx(),
                        mapToGlobal(QPointF(0, 0)).ry(),
                        width(), height());

    window->show();

    window->setLineEditText(panelWidget->getLineEditText());

    connect(window, &CalculatorWindow::closed, this, &CalculatorSection::closeWindow);
    connect(window, &CalculatorWindow::hided, this, &CalculatorSection::hideWindow);

    connect(window, &CalculatorWindow::memoryClearBtnClicked, this, [this](){
        emit memoryClearBtnClicked();
    });
    connect(window, &CalculatorWindow::memoryStoreBtnClicked, this, [this](){
        emit memoryStoreBtnClicked(panelWidget->count(window->getLineEditText()));
    });
    connect(window, &CalculatorWindow::memoryRestoreBtnClicked, this, [this](){
        emit memoryRestoreBtnClicked();
    });
    connect(window, &CalculatorWindow::memoryPlusBtnClicked, this, [this](){
        emit memoryPlusBtnClicked(panelWidget->count(window->getLineEditText()).toDouble());
    });
    connect(window, &CalculatorWindow::memoryMinusBtnClicked, this, [this](){
        emit memoryMinusBtnClicked(panelWidget->count(window->getLineEditText()).toDouble());
    });

    emit viewed();
}

void CalculatorSection::closeWindow()
{
    emit windowClosed();
}

void CalculatorSection::hideWindow()
{
    panelWidget->setLineEditText(window->getLineEditText());

    show();
    window->close();

    emit windowHided();
}

void CalculatorSection::restoreMemory(const QString& text)
{
    if (window != nullptr)
    {
        window->memoryRestore(text);
    }
    panelWidget->memoryRestore(text);
}

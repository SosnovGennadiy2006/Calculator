#include "calculatorWindow.h"

CalculatorWindow::CalculatorWindow(QWidget* parent) :
    AbstractPanelWindow{parent} {
    setupUI();
    setupConnections();
}


void CalculatorWindow::setupUI()
{
    tb->setWindowIcon(QIcon(":/icons/calculator.png"));
    tb->setWindowTitle("Engineering calculator");

    panelWidget = new CalculatorWidget();

    setPanelWidget(panelWidget);
}

void CalculatorWindow::setupConnections()
{
    connect(panelWidget, &CalculatorWidget::memoryClearBtnClicked, this, [this](){
        emit memoryClearBtnClicked();
    });
    connect(panelWidget, &CalculatorWidget::memoryStoreBtnClicked, this, [this](){
        emit memoryStoreBtnClicked();
    });
    connect(panelWidget, &CalculatorWidget::memoryRestoreBtnClicked, this, [this](){
        emit memoryRestoreBtnClicked();
    });
    connect(panelWidget, &CalculatorWidget::memoryPlusBtnClicked, this, [this](){
        emit memoryPlusBtnClicked();
    });
    connect(panelWidget, &CalculatorWidget::memoryMinusBtnClicked, this, [this](){
        emit memoryMinusBtnClicked();
    });
}

void CalculatorWindow::setLineEditText(const QString &newText) {
    panelWidget->setLineEditText(newText);
}

QString CalculatorWindow::getLineEditText() const
{
    return panelWidget->getLineEditText();
}

void CalculatorWindow::showExtraButtons()
{
    panelWidget->showExtraButtons();
}

void CalculatorWindow::hideExtraButtons()
{
    panelWidget->closeExtraButtons();
}

void CalculatorWindow::memoryRestore(const QString& text)
{
    panelWidget->memoryRestore(text);
}


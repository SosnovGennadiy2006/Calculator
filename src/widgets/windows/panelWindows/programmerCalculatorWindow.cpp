//
// Created by genas on 29.07.2022.
//

#include "programmerCalculatorWindow.h"

ProgrammerCalculatorWindow::ProgrammerCalculatorWindow(QWidget *parent) : AbstractPanelWindow{parent} {
    setupUI();
}

void ProgrammerCalculatorWindow::setupUI() {
    tb->setWindowIcon(QIcon(":/icons/programmerCalculator.png"));
    tb->setWindowTitle("Programmer calculator");

    panelWidget = new ProgrammerCalculatorWidget();
    setPanelWidget(panelWidget);
}

void ProgrammerCalculatorWindow::setupConnections() {
    connect(panelWidget, &ProgrammerCalculatorWidget::memoryRestoreBtnClicked, this,
            [this]() { emit memoryRestoreBtnClicked(); });
    connect(panelWidget, &ProgrammerCalculatorWidget::memoryStoreBtnClicked, this,
            [this]() { emit memoryStoreBtnClicked(); });
}

void ProgrammerCalculatorWindow::selectLineEdit(const unsigned short int &number) {
    panelWidget->selectLineEdit(number);
}

void ProgrammerCalculatorWindow::setLineEditFromText(const QString &text) {
    panelWidget->setLineEditFromText(text);
}

void ProgrammerCalculatorWindow::setLineEditToText(const QString &text) {
    panelWidget->setLineEditToText(text);
}

void ProgrammerCalculatorWindow::setComboBoxFromIndex(const int &index) {
    panelWidget->setComboBoxFromIndex(index);
}

void ProgrammerCalculatorWindow::setComboBoxToIndex(const int &index) {
    panelWidget->setComboBoxToIndex(index);
}

void ProgrammerCalculatorWindow::makeConversion() {
    panelWidget->makeConversion();
}

unsigned short int ProgrammerCalculatorWindow::getSelectedLineEditNumber() const {
    return panelWidget->getSelectedLineEditNumber();
}

QString ProgrammerCalculatorWindow::getLineEditFromText() const {
    return panelWidget->getLineEditFromText();
}

QString ProgrammerCalculatorWindow::getLineEditToText() const {
    return panelWidget->getLineEditToText();
}

QString ProgrammerCalculatorWindow::getSelectedLineEditText() const
{
    return panelWidget->getSelectedLineEditText();
}

int ProgrammerCalculatorWindow::getComboBoxFromIndex() const {
    return panelWidget->getComboBoxFromIndex();
}

int ProgrammerCalculatorWindow::getComboBoxToIndex() const {
    return panelWidget->getComboBoxToIndex();
}

void ProgrammerCalculatorWindow::memoryRestore(const QString& text)
{
    panelWidget->memoryRestore(text);
}

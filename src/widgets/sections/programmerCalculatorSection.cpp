//
// Created by genas on 29.07.2022.
//

#include "programmerCalculatorSection.h"

ProgrammerCalculatorSection::ProgrammerCalculatorSection(QWidget *parent) :
        AbstractSection{parent}
{
    panelWidget = new ProgrammerCalculatorWidget();

    setPanelWidget(panelWidget);

    tb->setWindowIcon(QIcon(":/icons/programmerCalculator.png"));
    tb->setWindowTitle("Programmer calculator");
}

void ProgrammerCalculatorSection::viewWindow()
{
    hide();

    window = new ProgrammerCalculatorWindow();

    window->setGeometry(mapToGlobal(QPointF(0, 0)).rx(),
                        mapToGlobal(QPointF(0, 0)).ry(),
                        width(), height());

    window->show();

    window->selectLineEdit(panelWidget->getSelectedLineEditNumber());
    window->setComboBoxFromIndex(panelWidget->getComboBoxFromIndex());
    window->setComboBoxToIndex(panelWidget->getComboBoxToIndex());
    window->setLineEditFromText(panelWidget->getLineEditFromText());
    window->setLineEditToText(panelWidget->getLineEditToText());
    window->makeConversion();

    connect(window, &ProgrammerCalculatorWindow::closed, this, &ProgrammerCalculatorSection::closeWindow);
    connect(window, &ProgrammerCalculatorWindow::hided, this, &ProgrammerCalculatorSection::hideWindow);

    emit viewed();
}

void ProgrammerCalculatorSection::closeWindow()
{
    emit windowClosed();
}

void ProgrammerCalculatorSection::hideWindow()
{
    panelWidget->selectLineEdit(window->getSelectedLineEditNumber());
    panelWidget->setComboBoxFromIndex(window->getComboBoxFromIndex());
    panelWidget->setComboBoxToIndex(window->getComboBoxToIndex());
    panelWidget->setLineEditFromText(window->getLineEditFromText());
    panelWidget->setLineEditToText(window->getLineEditToText());

    show();
    window->close();

    emit windowHided();
}
//
// Created by genas on 29.07.2022.
//

#ifndef SRC_PROGRAMMERCALCULATORSECTION_H
#define SRC_PROGRAMMERCALCULATORSECTION_H

#include "abstractSection.h"
#include <QObject>
#include <QWidget>
#include "../../widgets/panelWidgets/programmerCalculatorWidget.h"
#include "../../widgets/panelWidgets/abstractPanelWidget.h"
#include "../../widgets/windows/panelWindows/programmerCalculatorWindow.h"

class ProgrammerCalculatorSection : public AbstractSection {
    Q_OBJECT

    ProgrammerCalculatorWindow* window;
    ProgrammerCalculatorWidget* panelWidget;

public:
    explicit ProgrammerCalculatorSection(QWidget *parent = nullptr);

    void restoreMemory(const QString& text);

signals:
    void memoryStoreBtnClicked(const QString& number);
    void memoryRestoreBtnClicked();

protected slots:
    void viewWindow() override;
    void closeWindow() override;
    void hideWindow() override;
};


#endif //SRC_PROGRAMMERCALCULATORSECTION_H

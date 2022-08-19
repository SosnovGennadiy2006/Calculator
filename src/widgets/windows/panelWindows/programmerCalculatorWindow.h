//
// Created by genas on 29.07.2022.
//

#ifndef SRC_PROGRAMMERCALCULATORWINDOW_H
#define SRC_PROGRAMMERCALCULATORWINDOW_H

#include "abstractPanelWindow.h"
#include <QObject>
#include <QWidget>
#include "../../../widgets/panelWidgets/programmerCalculatorWidget.h"

class ProgrammerCalculatorWindow : public AbstractPanelWindow {
    Q_OBJECT

    ProgrammerCalculatorWidget* panelWidget;

public:
    explicit ProgrammerCalculatorWindow(QWidget* parent = nullptr);

    void setupUI() override;
    void setupConnections();

    void selectLineEdit(const unsigned short int& number);
    void setLineEditFromText(const QString& text);
    void setLineEditToText(const QString& text);
    void setComboBoxFromIndex(const int& index);
    void setComboBoxToIndex(const int& index);
    void makeConversion();

    [[nodiscard]] unsigned short int getSelectedLineEditNumber() const;
    [[nodiscard]] QString getLineEditFromText() const;
    [[nodiscard]] QString getLineEditToText() const;
    [[nodiscard]] QString getSelectedLineEditText() const;
    [[nodiscard]] int getComboBoxFromIndex() const;
    [[nodiscard]] int getComboBoxToIndex() const;

    void memoryRestore(const QString& text);

signals:
    void memoryRestoreBtnClicked();
    void memoryStoreBtnClicked();
};


#endif //SRC_PROGRAMMERCALCULATORWINDOW_H

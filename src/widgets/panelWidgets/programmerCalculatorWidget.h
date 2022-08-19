//
// Created by genas on 29.07.2022.
//

#ifndef SRC_PROGRAMMERCALCULATORWIDGET_H
#define SRC_PROGRAMMERCALCULATORWIDGET_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QGridLayout>
#include "../../widgets/comboBoxes/customComboBox.h"
#include "../../widgets/buttons/customButton.h"
#include "../../widgets/lineEdits/selectedLineEdit.h"
#include "../../widgets/panelWidgets/abstractPanelWidget.h"

enum calculusSystems
{
    BIN,
    OCT,
    DEC,
    HEX
};

class ProgrammerCalculatorWidget : public AbstractPanelWidget {
    Q_OBJECT

    QVBoxLayout* mainLayout;

    QWidget* widgetFrom;

    QVBoxLayout* calculusSystemFromLayout;

    QWidget* systemFromWidget;
    QHBoxLayout* fromLayout;
    QLabel* labelFrom;
    CustomComboBox* comboBoxFrom;

    SelectedLineEdit* lineEditFrom;

    QWidget* widgetTo;

    QVBoxLayout* calculusSystemToLayout;

    QWidget* systemToWidget;
    QHBoxLayout* toLayout;
    QLabel* labelTo;
    CustomComboBox* comboBoxTo;

    SelectedLineEdit* lineEditTo;

    QSpacerItem* spacer1;
    QSpacerItem* spacer2;

    QWidget* keyboardWidget;

    QGridLayout* keyboardGrid;

    CustomButton* button_AC;
    CustomButton* button_backspace;
    CustomButton* button_A;
    CustomButton* button_B;
    CustomButton* button_C;
    CustomButton* button_D;
    CustomButton* button_E;
    CustomButton* button_F;
    CustomButton* button_0;
    CustomButton* button_1;
    CustomButton* button_2;
    CustomButton* button_3;
    CustomButton* button_4;
    CustomButton* button_5;
    CustomButton* button_6;
    CustomButton* button_7;
    CustomButton* button_8;
    CustomButton* button_9;
    CustomButton* button_MR;
    CustomButton* button_MS;

    SelectedLineEdit* selectedLineEdit;
    CustomComboBox* selectedComboBox;

public:
    explicit ProgrammerCalculatorWidget(QWidget *parent = nullptr);

    void setupUI() override;
    void setupConnections() override;

    void hideKeyboard();
    void showKeyboard();
    void disableKeyboard(unsigned short int opt);

    void makeConversion();

    void selectLineEdit(const unsigned short int& number);
    void setLineEditFromText(const QString& text);
    void setLineEditToText(const QString& text);
    void setComboBoxFromIndex(const int& index);
    void setComboBoxToIndex(const int& index);

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

private slots:
    void addZero();
    void addNumber();

    void textChanged(const QString& newText);

    void comboBoxIndexChanged();

};


#endif //SRC_PROGRAMMERCALCULATORWIDGET_H

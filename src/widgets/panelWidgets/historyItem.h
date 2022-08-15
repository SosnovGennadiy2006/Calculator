//
// Created by genas on 02.08.2022.
//

#ifndef SRC_HISTORYITEM_H
#define SRC_HISTORYITEM_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QSpacerItem>
#include "../../widgets/buttons/customButton.h"
#include "../../widgets/customSpinBoxes/CustomDoubleSpinBox.h"

class HistoryItem : public QWidget {
    Q_OBJECT

    QHBoxLayout* mainLayout;
    QLabel* memoryValue;
    CustomDoubleSpinBox* spinBox;
    CustomButton* buttonClear;
    CustomButton* buttonCorrect;

    QSpacerItem* spacer;

public:
    explicit HistoryItem(QWidget* parent = nullptr);

    void setValue(double newVal);

    [[nodiscard]] double getValue() const;
    void plus(double val);
    void minus(double val);

private:
    void correct();

signals:
    void deleted();
};


#endif //SRC_HISTORYITEM_H

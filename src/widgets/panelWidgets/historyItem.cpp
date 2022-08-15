//
// Created by genas on 02.08.2022.
//

#include "historyItem.h"

HistoryItem::HistoryItem(QWidget* parent) : QWidget{parent}
{
    setMaximumHeight(60);

    QFont basicFont;
    basicFont.setPixelSize(24);
    basicFont.setFamily("Bahnschrift SemiLight SemiConde");

    mainLayout = new QHBoxLayout(this);

    memoryValue = new QLabel(this);
    memoryValue->setFont(basicFont);
    memoryValue->setFixedWidth(80);
    spinBox = new CustomDoubleSpinBox(this);
    spinBox->setFixedWidth(80);
    spinBox->hide();
    spinBox->setMinimum(-10e15);
    spinBox->setMaximum(10e15);
    buttonClear = new CustomButton(this);
    buttonClear->setText("MC");
    buttonCorrect = new CustomButton(this);
    buttonCorrect->setIcon(QIcon(":/icons/edit.png"));

    spacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

    mainLayout->addWidget(memoryValue);
    mainLayout->addWidget(spinBox);
    mainLayout->addItem(spacer);
    mainLayout->addWidget(buttonCorrect);
    mainLayout->addWidget(buttonClear);

    connect(buttonClear, &CustomButton::clicked, this, [this](){ emit deleted(); });
    connect(buttonCorrect, &CustomButton::clicked, this, &HistoryItem::correct);
    connect(spinBox, &CustomDoubleSpinBox::editingFinished, this, &HistoryItem::correct);
}

void HistoryItem::setValue(double newVal)
{
    spinBox->setValue(newVal);
    memoryValue->setText(QString::number(newVal));
    buttonCorrect->setIcon(QIcon(":/icons/edit.png"));
    memoryValue->show();
    spinBox->hide();
}

double HistoryItem::getValue() const
{
    return spinBox->value();
}

void HistoryItem::plus(double val)
{
    setValue(getValue() + val);
}

void HistoryItem::minus(double val)
{
    setValue(getValue() - val);
}

void HistoryItem::correct()
{
    if (memoryValue->isHidden())
    {
        memoryValue->setText(QString::number(spinBox->value()));
        buttonCorrect->setIcon(QIcon(":/icons/edit.png"));
        memoryValue->show();
        spinBox->hide();
    }else
    {
        buttonCorrect->setIcon(QIcon(":/icons/save.png"));
        memoryValue->hide();
        spinBox->show();
        spinBox->setValue(memoryValue->text().toDouble());
    }
}
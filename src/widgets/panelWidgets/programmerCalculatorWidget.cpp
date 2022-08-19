//
// Created by genas on 29.07.2022.
//

#include "programmerCalculatorWidget.h"

ProgrammerCalculatorWidget::ProgrammerCalculatorWidget(QWidget *parent)
        : AbstractPanelWidget{parent}
{
    setupUI();
    setupConnections();

    lineEditFrom->setSelected(true);
    lineEditTo->setSelected(false);
    selectedLineEdit = lineEditFrom;
    selectedComboBox = comboBoxFrom;
}

void ProgrammerCalculatorWidget::setupUI()
{
    setMinimumHeight(400);
    setMaximumSize(600, 700);

    QFont basicFont;
    basicFont.setPixelSize(24);
    basicFont.setFamily("Bahnschrift SemiLight SemiConde");

    mainLayout = new QVBoxLayout(this);

    widgetFrom = new QWidget(this);

    calculusSystemFromLayout = new QVBoxLayout(widgetFrom);

    systemFromWidget = new QWidget(widgetFrom);
    fromLayout = new QHBoxLayout(systemFromWidget);
    labelFrom = new QLabel(widgetFrom);
    labelFrom->setText("From:");
    labelFrom->setFont(basicFont);
    spacer1 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
    comboBoxFrom = new CustomComboBox(widgetFrom);
    comboBoxFrom->addItem("BIN", QVariant(".01"));
    comboBoxFrom->addItem("OCT", QVariant(".01234567"));
    comboBoxFrom->addItem("DEC", QVariant(".0123456789"));
    comboBoxFrom->addItem("HEX", QVariant(".0123456789ABCDEF"));
    comboBoxFrom->setCurrentIndex(2);

    fromLayout->addWidget(labelFrom);
    fromLayout->addItem(spacer1);
    fromLayout->addWidget(comboBoxFrom);

    lineEditFrom = new SelectedLineEdit(widgetFrom);

    calculusSystemFromLayout->addWidget(systemFromWidget);
    calculusSystemFromLayout->addWidget(lineEditFrom);

    widgetTo = new QWidget(this);

    calculusSystemToLayout = new QVBoxLayout(widgetTo);

    systemToWidget = new QWidget(widgetTo);
    toLayout = new QHBoxLayout(systemToWidget);
    labelTo = new QLabel(widgetTo);
    labelTo->setText("To:");
    labelTo->setFont(basicFont);
    spacer2 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
    comboBoxTo = new CustomComboBox(widgetTo);
    comboBoxTo->addItem("BIN", QVariant(".01"));
    comboBoxTo->addItem("OCT", QVariant(".01234567"));
    comboBoxTo->addItem("DEC", QVariant(".0123456789"));
    comboBoxTo->addItem("HEX", QVariant(".0123456789ABCDEF"));
    comboBoxTo->setCurrentIndex(2);

    toLayout->addWidget(labelTo);
    toLayout->addItem(spacer2);
    toLayout->addWidget(comboBoxTo);

    lineEditTo = new SelectedLineEdit(widgetTo);

    calculusSystemToLayout->addWidget(systemToWidget);
    calculusSystemToLayout->addWidget(lineEditTo);

    mainLayout->addWidget(widgetFrom);
    mainLayout->addWidget(widgetTo);

    keyboardWidget = new QWidget(this);

    keyboardGrid = new QGridLayout(keyboardWidget);

    button_AC = new CustomButton(keyboardWidget);
    button_AC->setText("AC");
    button_backspace = new CustomButton(keyboardWidget);
    button_backspace->setIcon(QIcon(":/icons/backspace.png"));
    button_A = new CustomButton(keyboardWidget);
    button_A->setText("A");
    button_B = new CustomButton(keyboardWidget);
    button_B->setText("B");
    button_C = new CustomButton(keyboardWidget);
    button_C->setText("C");
    button_D = new CustomButton(keyboardWidget);
    button_D->setText("D");
    button_E = new CustomButton(keyboardWidget);
    button_E->setText("E");
    button_F = new CustomButton(keyboardWidget);
    button_F->setText("F");
    button_0 = new CustomButton(keyboardWidget);
    button_0->setText("0");
    button_1 = new CustomButton(keyboardWidget);
    button_1->setText("1");
    button_2 = new CustomButton(keyboardWidget);
    button_2->setText("2");
    button_3 = new CustomButton(keyboardWidget);
    button_3->setText("3");
    button_4 = new CustomButton(keyboardWidget);
    button_4->setText("4");
    button_5 = new CustomButton(keyboardWidget);
    button_5->setText("5");
    button_6 = new CustomButton(keyboardWidget);
    button_6->setText("6");
    button_7 = new CustomButton(keyboardWidget);
    button_7->setText("7");
    button_8 = new CustomButton(keyboardWidget);
    button_8->setText("8");
    button_9 = new CustomButton(keyboardWidget);
    button_9->setText("9");
    button_MR = new CustomButton(keyboardWidget);
    button_MR->setText("MR");
    button_MR->setWhatsThis("save to memory");
    button_MS = new CustomButton(keyboardWidget);
    button_MS->setText("MS");
    button_MS->setWhatsThis("calling from memory");

    keyboardGrid->addWidget(button_AC, 0, 0);
    keyboardGrid->addWidget(button_backspace, 0, 1);
    keyboardGrid->addWidget(button_F, 0, 2);
    keyboardGrid->addWidget(button_E, 0, 3);
    keyboardGrid->addWidget(button_7, 1, 0);
    keyboardGrid->addWidget(button_8, 1, 1);
    keyboardGrid->addWidget(button_9, 1, 2);
    keyboardGrid->addWidget(button_D, 1, 3);
    keyboardGrid->addWidget(button_4, 2, 0);
    keyboardGrid->addWidget(button_5, 2, 1);
    keyboardGrid->addWidget(button_6, 2, 2);
    keyboardGrid->addWidget(button_C, 2, 3);
    keyboardGrid->addWidget(button_1, 3, 0);
    keyboardGrid->addWidget(button_2, 3, 1);
    keyboardGrid->addWidget(button_3, 3, 2);
    keyboardGrid->addWidget(button_B, 3, 3);
    keyboardGrid->addWidget(button_0, 4, 0);
    keyboardGrid->addWidget(button_MR, 4, 1);
    keyboardGrid->addWidget(button_MS, 4, 2);
    keyboardGrid->addWidget(button_A, 4, 3);

    mainLayout->addWidget(keyboardWidget);

    selectedLineEdit = lineEditFrom;
    selectedComboBox = comboBoxFrom;

    disableKeyboard(2);
}

void ProgrammerCalculatorWidget::setupConnections()
{
    connect(lineEditFrom, &SelectedLineEdit::selected, this, [this](){
        lineEditTo->setSelected(false);
        lineEditFrom->setSelected(true);
        selectedLineEdit = lineEditFrom;
        selectedComboBox = comboBoxFrom;
        disableKeyboard(selectedComboBox->currentIndex());
    });
    connect(lineEditTo, &SelectedLineEdit::selected, this, [this](){
        lineEditTo->setSelected(true);
        lineEditFrom->setSelected(false);
        selectedLineEdit = lineEditTo;
        selectedComboBox = comboBoxTo;
        disableKeyboard(selectedComboBox->currentIndex());
    });

    connect(lineEditFrom, &SelectedLineEdit::textEdited, this, &ProgrammerCalculatorWidget::textChanged);
    connect(lineEditTo, &SelectedLineEdit::textEdited, this, &ProgrammerCalculatorWidget::textChanged);

    connect(comboBoxFrom, &CustomComboBox::currentIndexChanged, this, &ProgrammerCalculatorWidget::comboBoxIndexChanged);
    connect(comboBoxTo, &CustomComboBox::currentIndexChanged, this, &ProgrammerCalculatorWidget::comboBoxIndexChanged);

    connect(button_0, &CustomButton::clicked, this, &ProgrammerCalculatorWidget::addZero);
    connect(button_1, &CustomButton::clicked, this, &ProgrammerCalculatorWidget::addNumber);
    connect(button_2, &CustomButton::clicked, this, &ProgrammerCalculatorWidget::addNumber);
    connect(button_3, &CustomButton::clicked, this, &ProgrammerCalculatorWidget::addNumber);
    connect(button_4, &CustomButton::clicked, this, &ProgrammerCalculatorWidget::addNumber);
    connect(button_5, &CustomButton::clicked, this, &ProgrammerCalculatorWidget::addNumber);
    connect(button_6, &CustomButton::clicked, this, &ProgrammerCalculatorWidget::addNumber);
    connect(button_7, &CustomButton::clicked, this, &ProgrammerCalculatorWidget::addNumber);
    connect(button_8, &CustomButton::clicked, this, &ProgrammerCalculatorWidget::addNumber);
    connect(button_9, &CustomButton::clicked, this, &ProgrammerCalculatorWidget::addNumber);
    connect(button_A, &CustomButton::clicked, this, &ProgrammerCalculatorWidget::addNumber);
    connect(button_B, &CustomButton::clicked, this, &ProgrammerCalculatorWidget::addNumber);
    connect(button_C, &CustomButton::clicked, this, &ProgrammerCalculatorWidget::addNumber);
    connect(button_D, &CustomButton::clicked, this, &ProgrammerCalculatorWidget::addNumber);
    connect(button_E, &CustomButton::clicked, this, &ProgrammerCalculatorWidget::addNumber);
    connect(button_F, &CustomButton::clicked, this, &ProgrammerCalculatorWidget::addNumber);

    connect(button_backspace, &CustomButton::clicked, this, [this](){
        QString t = selectedLineEdit->text();
        t.chop(1);
        selectedLineEdit->setText(t);
    });

    connect(button_AC, &CustomButton::clicked, this, [this](){selectedLineEdit->setText("0");});

    connect(button_MR, &CustomButton::clicked, this, [this](){emit memoryRestoreBtnClicked();});
    connect(button_MS, &CustomButton::clicked, this, [this](){emit memoryStoreBtnClicked();});
}

void ProgrammerCalculatorWidget::hideKeyboard()
{
    keyboardWidget->hide();
}

void ProgrammerCalculatorWidget::showKeyboard()
{
    keyboardWidget->show();
}

void ProgrammerCalculatorWidget::disableKeyboard(unsigned short int opt)
{
    button_0->setDisabled(false);
    button_1->setDisabled(false);
    button_2->setDisabled(false);
    button_3->setDisabled(false);
    button_4->setDisabled(false);
    button_5->setDisabled(false);
    button_6->setDisabled(false);
    button_7->setDisabled(false);
    button_8->setDisabled(false);
    button_9->setDisabled(false);
    button_A->setDisabled(false);
    button_B->setDisabled(false);
    button_C->setDisabled(false);
    button_D->setDisabled(false);
    button_E->setDisabled(false);
    button_F->setDisabled(false);

    if (opt < 3)
    {
        button_A->setDisabled(true);
        button_B->setDisabled(true);
        button_C->setDisabled(true);
        button_D->setDisabled(true);
        button_E->setDisabled(true);
        button_F->setDisabled(true);
    }

    if (opt < 2)
    {
        button_8->setDisabled(true);
        button_9->setDisabled(true);
    }

    if (opt < 1)
    {
        button_2->setDisabled(true);
        button_3->setDisabled(true);
        button_4->setDisabled(true);
        button_5->setDisabled(true);
        button_6->setDisabled(true);
        button_7->setDisabled(true);
    }
}

void ProgrammerCalculatorWidget::addZero()
{
    if (selectedLineEdit->text() != "0")
    {
        selectedLineEdit->setText(selectedLineEdit->text() + "0");
    }
    makeConversion();
}

void ProgrammerCalculatorWidget::addNumber()
{
    if (selectedLineEdit->text() != "0")
    {
        selectedLineEdit->setText(selectedLineEdit->text() +
                                          qobject_cast<QPushButton*>(sender())->text());
    }else
    {
        selectedLineEdit->setText(qobject_cast<QPushButton*>(sender())->text());
    }
    makeConversion();
}

void ProgrammerCalculatorWidget::makeConversion()
{
    unsigned short int calculusSystemFrom = 0, calculusSystemTo = 0;

    switch(comboBoxFrom->currentIndex())
    {
        case 0:
        {
            calculusSystemFrom = 2;
            break;
        }
        case 1:
        {
            calculusSystemFrom = 8;
            break;
        }
        case 2:
        {
            calculusSystemFrom = 10;
            break;
        }
        case 3:
        {
            calculusSystemFrom = 16;
            break;
        }
    }

    switch(comboBoxTo->currentIndex())
    {
        case 0:
        {
            calculusSystemTo = 2;
            break;
        }
        case 1:
        {
            calculusSystemTo = 8;
            break;
        }
        case 2:
        {
            calculusSystemTo = 10;
            break;
        }
        case 3:
        {
            calculusSystemTo = 16;
            break;
        }
    }

    bool ok;

    if (selectedLineEdit == lineEditFrom)
    {
        lineEditTo->setText(QString::number(lineEditFrom->text().toInt(&ok, calculusSystemFrom), calculusSystemTo));
    }else
    {
        lineEditFrom->setText(QString::number(lineEditTo->text().toInt(&ok, calculusSystemTo), calculusSystemFrom));
    }
}

void ProgrammerCalculatorWidget::selectLineEdit(const unsigned short int& number)
{
    if (number == 0)
    {
        lineEditFrom->setSelected(true);
        lineEditTo->setSelected(false);
        selectedLineEdit = lineEditFrom;
        selectedComboBox = comboBoxFrom;
        disableKeyboard(selectedComboBox->currentIndex());
    }else
    {
        lineEditFrom->setSelected(false);
        lineEditTo->setSelected(true);
        selectedLineEdit = lineEditTo;
        selectedComboBox = comboBoxTo;
        disableKeyboard(selectedComboBox->currentIndex());
    }
}

void ProgrammerCalculatorWidget::setLineEditFromText(const QString& text)
{
    lineEditFrom->setText(text);
}

void ProgrammerCalculatorWidget::setLineEditToText(const QString& text)
{
    lineEditTo->setText(text);
}

void ProgrammerCalculatorWidget::setComboBoxFromIndex(const int& index)
{
    comboBoxFrom->setCurrentIndex(index);
}

void ProgrammerCalculatorWidget::setComboBoxToIndex(const int& index)
{
    comboBoxTo->setCurrentIndex(index);
}

unsigned short int ProgrammerCalculatorWidget::getSelectedLineEditNumber() const
{
    if (selectedLineEdit == lineEditFrom)
    {
        return 0;
    }
    return 1;
}

QString ProgrammerCalculatorWidget::getLineEditFromText() const
{
    return lineEditFrom->text();
}

QString ProgrammerCalculatorWidget::getLineEditToText() const
{
    return lineEditTo->text();
}

QString ProgrammerCalculatorWidget::getSelectedLineEditText() const
{
    unsigned short int calculusSystemFrom = 0, calculusSystemTo = 0;

    switch(comboBoxFrom->currentIndex())
    {
        case 0:
        {
            calculusSystemFrom = 2;
            break;
        }
        case 1:
        {
            calculusSystemFrom = 8;
            break;
        }
        case 2:
        {
            calculusSystemFrom = 10;
            break;
        }
        case 3:
        {
            calculusSystemFrom = 16;
            break;
        }
    }

    switch(comboBoxTo->currentIndex())
    {
        case 0:
        {
            calculusSystemTo = 2;
            break;
        }
        case 1:
        {
            calculusSystemTo = 8;
            break;
        }
        case 2:
        {
            calculusSystemTo = 10;
            break;
        }
        case 3:
        {
            calculusSystemTo = 16;
            break;
        }
    }

    bool ok;

    if (selectedLineEdit == lineEditFrom)
    {
        return QString::number(lineEditFrom->text().toInt(&ok, calculusSystemFrom), 10);
    }else
    {
        return QString::number(lineEditTo->text().toInt(&ok, calculusSystemTo), 10);
    }
}

int ProgrammerCalculatorWidget::getComboBoxFromIndex() const
{
    return comboBoxFrom->currentIndex();
}

int ProgrammerCalculatorWidget::getComboBoxToIndex() const
{
    return comboBoxTo->currentIndex();
}

void ProgrammerCalculatorWidget::memoryRestore(const QString& text)
{
    unsigned short int calculusSystemFrom = 0, calculusSystemTo = 0;

    switch(comboBoxFrom->currentIndex())
    {
        case 0:
        {
            calculusSystemFrom = 2;
            break;
        }
        case 1:
        {
            calculusSystemFrom = 8;
            break;
        }
        case 2:
        {
            calculusSystemFrom = 10;
            break;
        }
        case 3:
        {
            calculusSystemFrom = 16;
            break;
        }
    }

    switch(comboBoxTo->currentIndex())
    {
        case 0:
        {
            calculusSystemTo = 2;
            break;
        }
        case 1:
        {
            calculusSystemTo = 8;
            break;
        }
        case 2:
        {
            calculusSystemTo = 10;
            break;
        }
        case 3:
        {
            calculusSystemTo = 16;
            break;
        }
    }

    if (selectedLineEdit == lineEditFrom)
    {
        lineEditFrom->setText(QString::number(text.toInt(), calculusSystemFrom));
    }else
    {
        lineEditTo->setText(QString::number(text.toInt(), calculusSystemTo));
    }

    makeConversion();
}

void ProgrammerCalculatorWidget::textChanged(const QString& newText)
{
    if (newText == "")
    {
        selectedLineEdit->setText("0");
    }else
    {
        QString t;
        qsizetype i = 0;
        if (newText == "0" || (newText[0] == '0' && newText[1] != '.'))
            i = 1;

        for (; i < newText.size(); i++)
        {
            if (selectedComboBox->currentData().toString().contains(newText[i]))
            {
                t += newText[i];
            }
        }

        if (t != "")
        {
            selectedLineEdit->setText(t);
        }else
        {
            selectedLineEdit->setText("0");
        }
    }

    makeConversion();
}

void ProgrammerCalculatorWidget::comboBoxIndexChanged()
{
    if (sender()->objectName() == selectedComboBox->objectName())
    {
        lineEditFrom->setText("0");
        lineEditTo->setText("0");

        disableKeyboard(selectedComboBox->currentIndex());
    }else
    {
        makeConversion();
    }
}
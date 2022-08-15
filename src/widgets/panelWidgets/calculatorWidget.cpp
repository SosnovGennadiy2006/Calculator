#include "calculatorWidget.h"

CalculatorWidget::CalculatorWidget(QWidget* parent) :
    AbstractPanelWidget{parent}
{
    setupUI();
    setupConnections();
}

void CalculatorWidget::setupUI()
{
    setMaximumSize(1000, 700);

    mainGrid = new QGridLayout(this);
    mainGrid->setSpacing(5);

    mainEdit = new CustomLineEdit(this);
    QStringList wordList;
    wordList << "sqrt(" << "exp(" << "abs(" << "asin(" << "sin(" << "sinh(" \
        << "asinh(" << "acos(" << "cos(" << "cosh(" << "acosh(" << "atan(" \
        << "tan(" << "tanh(" << "atanh(" << "sec(" << "csc(" << "log(" << "log10(";

    QCompleter* completer = new QCompleter(wordList, this);
    completer->setCaseSensitivity(Qt::CaseSensitive);
    completer->setCompletionMode(QCompleter::InlineCompletion);

    mainEdit->setCompleter(completer);

    button_power = new CustomButton(this);
    button_power->setText("^");
    button_sqrt = new CustomButton(this);
    button_sqrt->setText("sqrt");
    button_exp = new CustomButton(this);
    button_exp->setText("exp");
    button_abs = new CustomButton(this);
    button_abs->setText("abs");
    button_asin = new CustomButton(this);
    button_asin->setText("asin");
    button_sin = new CustomButton(this);
    button_sin->setText("sin");
    button_sinh = new CustomButton(this);
    button_sinh->setText("sinh");
    button_asinh = new CustomButton(this);
    button_asinh->setText("asinh");
    button_acos = new CustomButton(this);
    button_acos->setText("acos");
    button_cos = new CustomButton(this);
    button_cos->setText("cos");
    button_cosh = new CustomButton(this);
    button_cosh->setText("cosh");
    button_acosh = new CustomButton(this);
    button_acosh->setText("acosh");
    button_atan = new CustomButton(this);
    button_atan->setText("atan");
    button_tan = new CustomButton(this);
    button_tan->setText("tan");
    button_tanh = new CustomButton(this);
    button_tanh->setText("tanh");
    button_atanh = new CustomButton(this);
    button_atanh->setText("atanh");
    button_sec = new CustomButton(this);
    button_sec->setText("sec");
    button_csc = new CustomButton(this);
    button_csc->setText("csc");
    button_log = new CustomButton(this);
    button_log->setText("log");
    button_ln = new CustomButton(this);
    button_ln->setText("ln");
    button_C = new CustomButton(this);
    button_C->setText("C");
    button_backspace = new CustomButton(this);
    button_backspace->setIcon(QIcon(":/icons/backspace.png"));
    button_MC = new CustomButton(this);
    button_MC->setText("MC");
    button_MC->setWhatsThis("Memory clear");
    button_MR = new CustomButton(this);
    button_MR->setText("MR");
    button_MR->setWhatsThis("Memory restore");
    button_MS = new CustomButton(this);
    button_MS->setText("MS");
    button_MS->setWhatsThis("Memory store");
    button_M_minus = new CustomButton(this);
    button_M_minus->setText("M-");
    button_M_minus->setWhatsThis("Memory minus");
    button_M_plus = new CustomButton(this);
    button_M_plus->setText("M+");
    button_M_plus->setWhatsThis("Memory plus");
    button_brackets = new CustomButton(this);
    button_brackets->setText("()");
    button_divide = new CustomButton(this);
    button_divide->setText("/");
    button_7 = new CustomButton(this);
    button_7->setText("7");
    button_8 = new CustomButton(this);
    button_8->setText("8");
    button_9 = new CustomButton(this);
    button_9->setText("9");
    button_multiply = new CustomButton(this);
    button_multiply->setText("*");
    button_4 = new CustomButton(this);
    button_4->setText("4");
    button_5 = new CustomButton(this);
    button_5->setText("5");
    button_6 = new CustomButton(this);
    button_6->setText("6");
    button_minus = new CustomButton(this);
    button_minus->setText("-");
    button_1 = new CustomButton(this);
    button_1->setText("1");
    button_2 = new CustomButton(this);
    button_2->setText("2");
    button_3 = new CustomButton(this);
    button_3->setText("3");
    button_plus = new CustomButton(this);
    button_plus->setText("+");
    button_0 = new CustomButton(this);
    button_0->setText("0");
    button_comma = new CustomButton(this);
    button_comma->setText(".");
    button_equal = new CustomButton(this);
    button_equal->setText("=");

    mainGrid->addWidget(mainEdit, 0, 0, 1, 9);
    mainGrid->addWidget(button_power, 1, 0);
    mainGrid->addWidget(button_sqrt, 1, 1);
    mainGrid->addWidget(button_exp, 1, 2);
    mainGrid->addWidget(button_abs, 1, 3);
    mainGrid->addWidget(button_MC, 1, 4);
    mainGrid->addWidget(button_backspace, 1, 5);
    mainGrid->addWidget(button_C, 1, 6);
    mainGrid->addWidget(button_brackets, 1, 7);
    mainGrid->addWidget(button_divide, 1, 8);
    mainGrid->addWidget(button_asin, 2, 0);
    mainGrid->addWidget(button_sin, 2, 1);
    mainGrid->addWidget(button_sinh, 2, 2);
    mainGrid->addWidget(button_asinh, 2, 3);
    mainGrid->addWidget(button_MS, 2, 4);
    mainGrid->addWidget(button_7, 2, 5);
    mainGrid->addWidget(button_8, 2, 6);
    mainGrid->addWidget(button_9, 2, 7);
    mainGrid->addWidget(button_multiply, 2, 8);
    mainGrid->addWidget(button_acos, 3, 0);
    mainGrid->addWidget(button_cos, 3, 1);
    mainGrid->addWidget(button_cosh, 3, 2);
    mainGrid->addWidget(button_acosh, 3, 3);
    mainGrid->addWidget(button_MR, 3, 4);
    mainGrid->addWidget(button_4, 3, 5);
    mainGrid->addWidget(button_5, 3, 6);
    mainGrid->addWidget(button_6, 3, 7);
    mainGrid->addWidget(button_minus, 3, 8);
    mainGrid->addWidget(button_atan, 4, 0);
    mainGrid->addWidget(button_tan, 4, 1);
    mainGrid->addWidget(button_tanh, 4, 2);
    mainGrid->addWidget(button_atanh, 4, 3);
    mainGrid->addWidget(button_M_plus, 4, 4);
    mainGrid->addWidget(button_1, 4, 5);
    mainGrid->addWidget(button_2, 4, 6);
    mainGrid->addWidget(button_3, 4, 7);
    mainGrid->addWidget(button_plus, 4, 8);
    mainGrid->addWidget(button_sec, 5, 0);
    mainGrid->addWidget(button_csc, 5, 1);
    mainGrid->addWidget(button_log, 5, 2);
    mainGrid->addWidget(button_ln, 5, 3);
    mainGrid->addWidget(button_M_minus, 5, 4);
    mainGrid->addWidget(button_0, 5, 5, 1, 2);
    mainGrid->addWidget(button_comma, 5, 7);
    mainGrid->addWidget(button_equal, 5, 8);
}

void CalculatorWidget::setupConnections()
{
    connect(button_power, &QPushButton::clicked, this, &CalculatorWidget::addOperation);
    connect(button_divide, &QPushButton::clicked, this, &CalculatorWidget::addOperation);
    connect(button_multiply, &QPushButton::clicked, this, &CalculatorWidget::addOperation);
    connect(button_minus, &QPushButton::clicked, this, &CalculatorWidget::addOperation);
    connect(button_plus, &QPushButton::clicked, this, &CalculatorWidget::addOperation);
    connect(button_comma, &QPushButton::clicked, this, &CalculatorWidget::addOperation);

    connect(button_brackets, &QPushButton::clicked, this, &CalculatorWidget::addBracket);

    connect(button_0, &QPushButton::clicked, this, &CalculatorWidget::addNumber);
    connect(button_1, &QPushButton::clicked, this, &CalculatorWidget::addNumber);
    connect(button_2, &QPushButton::clicked, this, &CalculatorWidget::addNumber);
    connect(button_3, &QPushButton::clicked, this, &CalculatorWidget::addNumber);
    connect(button_4, &QPushButton::clicked, this, &CalculatorWidget::addNumber);
    connect(button_5, &QPushButton::clicked, this, &CalculatorWidget::addNumber);
    connect(button_6, &QPushButton::clicked, this, &CalculatorWidget::addNumber);
    connect(button_7, &QPushButton::clicked, this, &CalculatorWidget::addNumber);
    connect(button_8, &QPushButton::clicked, this, &CalculatorWidget::addNumber);
    connect(button_9, &QPushButton::clicked, this, &CalculatorWidget::addNumber);

    connect(button_sqrt, &QPushButton::clicked, this, &CalculatorWidget::addFunction);
    connect(button_exp, &QPushButton::clicked, this, &CalculatorWidget::addFunction);
    connect(button_abs, &QPushButton::clicked, this, &CalculatorWidget::addFunction);
    connect(button_asin, &QPushButton::clicked, this, &CalculatorWidget::addFunction);
    connect(button_sin, &QPushButton::clicked, this, &CalculatorWidget::addFunction);
    connect(button_sinh, &QPushButton::clicked, this, &CalculatorWidget::addFunction);
    connect(button_asinh, &QPushButton::clicked, this, &CalculatorWidget::addFunction);
    connect(button_cos, &QPushButton::clicked, this, &CalculatorWidget::addFunction);
    connect(button_cosh, &QPushButton::clicked, this, &CalculatorWidget::addFunction);
    connect(button_acosh, &QPushButton::clicked, this, &CalculatorWidget::addFunction);
    connect(button_acos, &QPushButton::clicked, this, &CalculatorWidget::addFunction);
    connect(button_atan, &QPushButton::clicked, this, &CalculatorWidget::addFunction);
    connect(button_tan, &QPushButton::clicked, this, &CalculatorWidget::addFunction);
    connect(button_tanh, &QPushButton::clicked, this, &CalculatorWidget::addFunction);
    connect(button_atanh, &QPushButton::clicked, this, &CalculatorWidget::addFunction);
    connect(button_sec, &QPushButton::clicked, this, &CalculatorWidget::addFunction);
    connect(button_csc, &QPushButton::clicked, this, &CalculatorWidget::addFunction);
    connect(button_log, &QPushButton::clicked, this, &CalculatorWidget::addFunction);
    connect(button_ln, &QPushButton::clicked, this, &CalculatorWidget::addFunction);

    connect(button_equal, &QPushButton::clicked, this, &CalculatorWidget::solve);

    connect(button_C, &QPushButton::clicked, this, [this](){
        mainEdit->setText("");
    });

    connect(button_backspace, &QPushButton::clicked, this, [this](){
        if (mainEdit->text().isEmpty())
            mainEdit->setText(mainEdit->text().chopped(1));
    });

    connect(button_MC, &QPushButton::clicked, this, [this](){
        emit memoryClearBtnClicked();
    });
    connect(button_MS, &QPushButton::clicked, this, [this](){
        emit memoryStoreBtnClicked();
    });
    connect(button_MR, &QPushButton::clicked, this, [this](){
        emit memoryRestoreBtnClicked();
    });
    connect(button_M_plus, &QPushButton::clicked, this, [this](){
        emit memoryPlusBtnClicked();
    });
    connect(button_M_minus, &QPushButton::clicked, this, [this](){
        emit memoryMinusBtnClicked();
    });
}

QString CalculatorWidget::getLineEditText() const
{
    return mainEdit->text();
}

void CalculatorWidget::setLineEditText(const QString& newText)
{
    mainEdit->setText(newText);
}

QString CalculatorWidget::count(const QString& text)
{
    try
    {
        p.SetExpr(text.toStdWString());
        mu::value_type result = p.Eval();
        return QString::number(result);
    }
    catch(mu::Parser::exception_type &e)
    {
        return "ERROR!";
    }
}

void CalculatorWidget::addNumber()
{
    if (mainEdit->text().isEmpty() || mainEdit->text().back() != ')')
        mainEdit->setText(mainEdit->text() + (qobject_cast<QPushButton*>(sender()))->text());
}

void CalculatorWidget::addOperation()
{
    if (mainEdit->text().isEmpty())
        return;
    if (mainEdit->text().back().isDigit() || mainEdit->text().back() == ')')
        mainEdit->setText(mainEdit->text() + (qobject_cast<QPushButton*>(sender()))->text()[0]);
}

void CalculatorWidget::addFunction()
{
    if (mainEdit->text().isEmpty() || !mainEdit->text().back().isDigit() || mainEdit->text().back() != ')')
    {
        mainEdit->setText(mainEdit->text() + (qobject_cast<QPushButton*>(sender()))->text() + "(");
        cnt++;
    }
}

void CalculatorWidget::addBracket()
{
    if (cnt > 0)
    {
        mainEdit->setText(mainEdit->text() + ")");
        cnt--;
        return;
    }
    if (!mainEdit->text().back().isDigit()) {
        mainEdit->setText(mainEdit->text() + "(");
        cnt++;
    }
}

void CalculatorWidget::solve()
{
    mainEdit->setText(count(mainEdit->text()));
}

void CalculatorWidget::showExtraButtons()
{
    button_power->show();
    button_sqrt->show();
    button_exp->show();
    button_abs->show();
    button_asin->show();
    button_sin->show();
    button_sinh->show();
    button_asinh->show();
    button_acos->show();
    button_cos->show();
    button_cosh->show();
    button_acosh->show();
    button_atan->show();
    button_tan->show();
    button_tanh->show();
    button_atanh->show();
    button_sec->show();
    button_csc->show();
    button_log->show();
    button_ln->show();
}

void CalculatorWidget::closeExtraButtons()
{
    button_power->hide();
    button_sqrt->hide();
    button_exp->hide();
    button_abs->hide();
    button_asin->hide();
    button_sin->hide();
    button_sinh->hide();
    button_asinh->hide();
    button_acos->hide();
    button_cos->hide();
    button_cosh->hide();
    button_acosh->hide();
    button_atan->hide();
    button_tan->hide();
    button_tanh->hide();
    button_atanh->hide();
    button_sec->hide();
    button_csc->hide();
    button_log->hide();
    button_ln->hide();
}

void CalculatorWidget::memoryRestore(const QString& text)
{
    mainEdit->setText(mainEdit->text() + text);
}
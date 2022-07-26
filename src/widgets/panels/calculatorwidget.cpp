#include "calculatorwidget.h"

CalculatorWidget::CalculatorWidget(QWidget *parent)
    : AbstractPanel{parent}
{
    tb->setWindowIcon(QIcon(":/icons/calculator.png"));
    tb->setWindowTitle("Engineering calculator");

    QFont basicFont;
    basicFont.setPixelSize(42);
    basicFont.setFamily("Bahnschrift SemiLight SemiConde");

    gridWidget = new QWidget(mainWidget);
    widgetLayout->addWidget(gridWidget);

    mainGrid = new QGridLayout(gridWidget);
    mainGrid->setSpacing(5);

    mainEdit = new QLineEdit(this);
    mainEdit->setFont(basicFont);
    mainEdit->setAlignment(Qt::AlignmentFlag::AlignRight);
    mainEdit->setPlaceholderText("0");
    mainEdit->setStyleSheet("QLineEdit{"
                            "   border: 1px solid #555;"
                            "   border-radius: 5px;"
                            "   padding: 0px 0px -11px 0px;"
                            "}"
                            "QLineEdit:focus{"
                            "   border: 1px solid #2154B9;"
                            "}");

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
    button_log10 = new CustomButton(this);
    button_log10->setText("log10");
    button_C = new CustomButton(this);
    button_C->setText("C");
    button_AC = new CustomButton(this);
    button_AC->setText("AC");
    button_brackets = new CustomButton(this);
    button_brackets->setText("()");
    button_divide = new CustomButton(this);
    button_divide->setText("/");;
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

    mainGrid->addWidget(mainEdit, 0, 0, 1, 8);
    mainGrid->addWidget(button_power, 1, 0);
    mainGrid->addWidget(button_sqrt, 1, 1);
    mainGrid->addWidget(button_exp, 1, 2);
    mainGrid->addWidget(button_abs, 1, 3);
    mainGrid->addWidget(button_C, 1, 4);
    mainGrid->addWidget(button_AC, 1, 5);
    mainGrid->addWidget(button_brackets, 1, 6);
    mainGrid->addWidget(button_divide, 1, 7);
    mainGrid->addWidget(button_asin, 2, 0);
    mainGrid->addWidget(button_sin, 2, 1);
    mainGrid->addWidget(button_sinh, 2, 2);
    mainGrid->addWidget(button_asinh, 2, 3);
    mainGrid->addWidget(button_7, 2, 4);
    mainGrid->addWidget(button_8, 2, 5);
    mainGrid->addWidget(button_9, 2, 6);
    mainGrid->addWidget(button_multiply, 2, 7);
    mainGrid->addWidget(button_acos, 3, 0);
    mainGrid->addWidget(button_cos, 3, 1);
    mainGrid->addWidget(button_cosh, 3, 2);
    mainGrid->addWidget(button_acosh, 3, 3);
    mainGrid->addWidget(button_4, 3, 4);
    mainGrid->addWidget(button_5, 3, 5);
    mainGrid->addWidget(button_6, 3, 6);
    mainGrid->addWidget(button_minus, 3, 7);
    mainGrid->addWidget(button_atan, 4, 0);
    mainGrid->addWidget(button_tan, 4, 1);
    mainGrid->addWidget(button_tanh, 4, 2);
    mainGrid->addWidget(button_atanh, 4, 3);
    mainGrid->addWidget(button_1, 4, 4);
    mainGrid->addWidget(button_2, 4, 5);
    mainGrid->addWidget(button_3, 4, 6);
    mainGrid->addWidget(button_plus, 4, 7);
    mainGrid->addWidget(button_sec, 5, 0);
    mainGrid->addWidget(button_csc, 5, 1);
    mainGrid->addWidget(button_log, 5, 2);
    mainGrid->addWidget(button_log10, 5, 3);
    mainGrid->addWidget(button_0, 5, 4, 1, 2);
    mainGrid->addWidget(button_comma, 5, 6);
    mainGrid->addWidget(button_equal, 5, 7);

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
    connect(button_log10, &QPushButton::clicked, this, &CalculatorWidget::addFunction);

    connect(button_equal, &QPushButton::clicked, this, &CalculatorWidget::solve);

    connect(button_C, &QPushButton::clicked, this, [this](){
        mainEdit->setText("");
    });

    connect(tb, &ViewTitleBar::closeRequest, this, [this](){ emit closed(); });
}

void CalculatorWidget::addNumber()
{
    mainEdit->setText(mainEdit->text() + (qobject_cast<QPushButton*>(sender()))->text());
}

void CalculatorWidget::addOperation()
{
    mainEdit->setText(mainEdit->text() + (qobject_cast<QPushButton*>(sender()))->text()[0]);
}

void CalculatorWidget::addFunction()
{
    mainEdit->setText(mainEdit->text() + (qobject_cast<QPushButton*>(sender()))->text() + "(");
    cnt++;
}

void CalculatorWidget::addBracket()
{
    if (cnt > 0)
    {
        mainEdit->setText(mainEdit->text() + ")");
        cnt--;
        return;
    }
    mainEdit->setText(mainEdit->text() + "(");
    cnt++;
}

void CalculatorWidget::solve()
{
    try
    {
        p.SetExpr(mainEdit->text().toStdWString());
        mu::value_type result = p.Eval();
        mainEdit->setText(QString::number(result));
    }
    catch(mu::Parser::exception_type &e)
    {
        mainEdit->setText("ERROR!");
    }
}

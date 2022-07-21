#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    setFixedSize(1100, 400);

    centralWidget = new QWidget(this);

    QFont basicFont;
    basicFont.setPixelSize(32);
    basicFont.setFamily("Bahnschrift SemiLight SemiConde");

    mainLayout = new QHBoxLayout(centralWidget);

    gridWidget = new QWidget(centralWidget);
    mainGrid = new QGridLayout(gridWidget);
    mainGrid->setSpacing(0);

    mainEdit = new QLineEdit(gridWidget);
    mainEdit->setFont(basicFont);
    mainEdit->setAlignment(Qt::AlignmentFlag::AlignRight | Qt::AlignmentFlag::AlignVCenter);
    mainEdit->setPlaceholderText("0");

    button_power = new CustomButton(gridWidget);
    button_power->setText("^");
    button_sqrt = new CustomButton(gridWidget);
    button_sqrt->setText("sqrt");
    button_exp = new CustomButton(gridWidget);
    button_exp->setText("exp");
    button_abs = new CustomButton(gridWidget);
    button_abs->setText("abs");
    button_asin = new CustomButton(gridWidget);
    button_asin->setText("asin");
    button_sin = new CustomButton(gridWidget);
    button_sin->setText("sin");
    button_sinh = new CustomButton(gridWidget);
    button_sinh->setText("sinh");
    button_asinh = new CustomButton(gridWidget);
    button_asinh->setText("asinh");
    button_acos = new CustomButton(gridWidget);
    button_acos->setText("acos");
    button_cos = new CustomButton(gridWidget);
    button_cos->setText("cos");
    button_cosh = new CustomButton(gridWidget);
    button_cosh->setText("cosh");
    button_acosh = new CustomButton(gridWidget);
    button_acosh->setText("acosh");
    button_atan = new CustomButton(gridWidget);
    button_atan->setText("atan");
    button_tan = new CustomButton(gridWidget);
    button_tan->setText("tan");
    button_tanh = new CustomButton(gridWidget);
    button_tanh->setText("tanh");
    button_atanh = new CustomButton(gridWidget);
    button_atanh->setText("atanh");
    button_sec = new CustomButton(gridWidget);
    button_sec->setText("sec");
    button_csc = new CustomButton(gridWidget);
    button_csc->setText("csc");
    button_log = new CustomButton(gridWidget);
    button_log->setText("log");
    button_log10 = new CustomButton(gridWidget);
    button_log10->setText("log10");
    button_C = new CustomButton(gridWidget);
    button_C->setText("C");
    button_AC = new CustomButton(gridWidget);
    button_AC->setText("AC");
    button_brackets = new CustomButton(gridWidget);
    button_brackets->setText("()");
    button_divide = new CustomButton(gridWidget);
    button_divide->setText("/");;
    button_7 = new CustomButton(gridWidget);
    button_7->setText("7");
    button_8 = new CustomButton(gridWidget);
    button_8->setText("8");
    button_9 = new CustomButton(gridWidget);
    button_9->setText("9");
    button_multiply = new CustomButton(gridWidget);
    button_multiply->setText("*");
    button_4 = new CustomButton(gridWidget);
    button_4->setText("4");
    button_5 = new CustomButton(gridWidget);
    button_5->setText("5");
    button_6 = new CustomButton(gridWidget);
    button_6->setText("6");
    button_minus = new CustomButton(gridWidget);
    button_minus->setText("-");
    button_1 = new CustomButton(gridWidget);
    button_1->setText("1");
    button_2 = new CustomButton(gridWidget);
    button_2->setText("2");
    button_3 = new CustomButton(gridWidget);
    button_3->setText("3");
    button_plus = new CustomButton(gridWidget);
    button_plus->setText("+");
    button_0 = new CustomButton(gridWidget);
    button_0->setText("0");
    button_comma = new CustomButton(gridWidget);
    button_comma->setText(".");
    button_equal = new CustomButton(gridWidget);
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

    historyWidgetWrapper = new QWidget(centralWidget);
    historyLayout = new QVBoxLayout(historyWidgetWrapper);
    historyWidget = new HistoryWidget(historyWidgetWrapper);

    historyLayout->addWidget(historyWidget);

    mainLayout->addWidget(gridWidget);
    mainLayout->addWidget(historyWidgetWrapper);

    this->setCentralWidget(centralWidget);

    connect(button_power, &QPushButton::clicked, this, &MainWindow::addOperation);
    connect(button_divide, &QPushButton::clicked, this, &MainWindow::addOperation);
    connect(button_multiply, &QPushButton::clicked, this, &MainWindow::addOperation);
    connect(button_minus, &QPushButton::clicked, this, &MainWindow::addOperation);
    connect(button_plus, &QPushButton::clicked, this, &MainWindow::addOperation);
    connect(button_comma, &QPushButton::clicked, this, &MainWindow::addOperation);

    connect(button_brackets, &QPushButton::clicked, this, &MainWindow::addBracket);

    connect(button_0, &QPushButton::clicked, this, &MainWindow::addNumber);
    connect(button_1, &QPushButton::clicked, this, &MainWindow::addNumber);
    connect(button_2, &QPushButton::clicked, this, &MainWindow::addNumber);
    connect(button_3, &QPushButton::clicked, this, &MainWindow::addNumber);
    connect(button_4, &QPushButton::clicked, this, &MainWindow::addNumber);
    connect(button_5, &QPushButton::clicked, this, &MainWindow::addNumber);
    connect(button_6, &QPushButton::clicked, this, &MainWindow::addNumber);
    connect(button_7, &QPushButton::clicked, this, &MainWindow::addNumber);
    connect(button_8, &QPushButton::clicked, this, &MainWindow::addNumber);
    connect(button_9, &QPushButton::clicked, this, &MainWindow::addNumber);

    connect(button_sqrt, &QPushButton::clicked, this, &MainWindow::addFunction);
    connect(button_exp, &QPushButton::clicked, this, &MainWindow::addFunction);
    connect(button_abs, &QPushButton::clicked, this, &MainWindow::addFunction);
    connect(button_asin, &QPushButton::clicked, this, &MainWindow::addFunction);
    connect(button_sin, &QPushButton::clicked, this, &MainWindow::addFunction);
    connect(button_sinh, &QPushButton::clicked, this, &MainWindow::addFunction);
    connect(button_asinh, &QPushButton::clicked, this, &MainWindow::addFunction);
    connect(button_cos, &QPushButton::clicked, this, &MainWindow::addFunction);
    connect(button_cosh, &QPushButton::clicked, this, &MainWindow::addFunction);
    connect(button_acosh, &QPushButton::clicked, this, &MainWindow::addFunction);
    connect(button_acos, &QPushButton::clicked, this, &MainWindow::addFunction);
    connect(button_atan, &QPushButton::clicked, this, &MainWindow::addFunction);
    connect(button_tan, &QPushButton::clicked, this, &MainWindow::addFunction);
    connect(button_tanh, &QPushButton::clicked, this, &MainWindow::addFunction);
    connect(button_atanh, &QPushButton::clicked, this, &MainWindow::addFunction);
    connect(button_sec, &QPushButton::clicked, this, &MainWindow::addFunction);
    connect(button_csc, &QPushButton::clicked, this, &MainWindow::addFunction);
    connect(button_log, &QPushButton::clicked, this, &MainWindow::addFunction);
    connect(button_log10, &QPushButton::clicked, this, &MainWindow::addFunction);

    connect(button_equal, &QPushButton::clicked, this, &MainWindow::solve);

    connect(button_C, &QPushButton::clicked, this, [this](){
        mainEdit->setText("");
    });
}

MainWindow::~MainWindow()
{
}

void MainWindow::addNumber()
{
    mainEdit->setText(mainEdit->text() + (qobject_cast<QPushButton*>(sender()))->text());
}

void MainWindow::addOperation()
{
    mainEdit->setText(mainEdit->text() + (qobject_cast<QPushButton*>(sender()))->text()[0]);
}

void MainWindow::addFunction()
{
    mainEdit->setText(mainEdit->text() + (qobject_cast<QPushButton*>(sender()))->text() + "(");
    cnt++;
}

void MainWindow::addBracket()
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

void MainWindow::solve()
{
    expression = mainEdit->text();
    try
    {
        p.SetExpr(expression.toStdWString());
        mu::value_type result = p.Eval();
        mainEdit->setText(QString::number(result));
    }
    catch(mu::Parser::exception_type &e)
    {
        mainEdit->setText("ERROR!");
    }
}

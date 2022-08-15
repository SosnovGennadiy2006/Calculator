#include "mainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : CustomWindow(parent)
{
    cnt = 1;
    isHistoryShowed = false;
    isCalculatorShowed = true;
    isProgrammerCalculatorShowed = false;

    tb->setWindowIcon(QPixmap(":/icons/favicon.png"));
    tb->setWindowTitle("Calculator");
    initMenu();

    setupUI();
    setupConnections();
}

MainWindow::~MainWindow()
{
}

void MainWindow::setupUI()
{
    setMinimumSize(1075, 875);
    resize(1075, 875);

    QFont basicFont;
    basicFont.setPixelSize(16);
    basicFont.setFamily("Bahnschrift SemiLight SemiConde");
    QFont biggerFont;
    biggerFont.setPixelSize(24);
    biggerFont.setFamily("Bahnschrift SemiLight SemiConde");

    mainLayout = new QVBoxLayout(privWidget);

    panelsWidget = new QWidget(privWidget);
    panelsLayout = new QHBoxLayout(panelsWidget);

    layout1 = new QVBoxLayout();
    layout2 = new QVBoxLayout();

    panelsLayout->addLayout(layout1);
    panelsLayout->addLayout(layout2);

    ifWindowIsEmptyLabel = new QLabel(panelsWidget);
    ifWindowIsEmptyLabel->setAlignment(Qt::AlignCenter);
    ifWindowIsEmptyLabel->setText("The window is empty, nothing to show!\nYou can add panels in the menu");
    ifWindowIsEmptyLabel->setFont(biggerFont);
    ifWindowIsEmptyLabel->setStyleSheet("color: #DF1A2E;");
    ifWindowIsEmptyLabel->hide();

    initPanels();

    layout1->addWidget(calculator);
    layout1->addWidget(programmerCalculator);
    layout1->addWidget(ifWindowIsEmptyLabel);

    layout2->addWidget(history);

    copyrightLabel = new QLabel(privWidget);
    copyrightLabel->setFont(basicFont);
    copyrightLabel->setAlignment(Qt::AlignCenter);
    copyrightLabel->setText("©Sosnov Gennadiy, 2022");

    mainLayout->addWidget(panelsWidget, 1);
    mainLayout->addWidget(copyrightLabel);
}

void MainWindow::setupConnections()
{
    connect(calculator, &CalculatorSection::closed, this, [this](){
        calculator->close();
        isCalculatorShowed = false;
        cnt--;
        isWindowIsEmpty();
    });
    connect(history, &HistorySection::closed, this, [this](){
        history->close();
        isHistoryShowed = false;
        cnt--;
        isWindowIsEmpty();
    });
    connect(programmerCalculator, &ProgrammerCalculatorSection::closed, this, [this](){
        programmerCalculator->close();
        isProgrammerCalculatorShowed = false;
        cnt--;
        isWindowIsEmpty();
    });

    connect(calculator, &CalculatorSection::viewed, this, [this](){
        cnt--;
        isWindowIsEmpty();
    });
    connect(history, &HistorySection::viewed, this, [this](){
        cnt--;
        isWindowIsEmpty();
    });
    connect(programmerCalculator, &ProgrammerCalculatorSection::viewed, this, [this](){
        cnt--;
        isWindowIsEmpty();
    });

    connect(calculator, &CalculatorSection::windowHided, this, [this](){
        cnt++;
        isWindowIsEmpty();
    });
    connect(history, &HistorySection::windowHided, this, [this](){
        cnt++;
        isWindowIsEmpty();
    });
    connect(programmerCalculator, &ProgrammerCalculatorSection::windowHided, this, [this](){
        cnt++;
        isWindowIsEmpty();
    });

    connect(calculator, &CalculatorSection::memoryClearBtnClicked, history, &HistorySection::clearMemory);
    connect(calculator, &CalculatorSection::memoryPlusBtnClicked, history, &HistorySection::memoryPlus);
    connect(calculator, &CalculatorSection::memoryMinusBtnClicked, history, &HistorySection::memoryMinus);
    connect(calculator, &CalculatorSection::memoryStoreBtnClicked, history, &HistorySection::addNumber);
    connect(calculator, &CalculatorSection::memoryRestoreBtnClicked, this, [this](){
        calculator->restoreMemory(QString::number(history->getValue()));
    });
}

void MainWindow::initMenu()
{
    QAction* historyAction = new QAction(QIcon(":/icons/history.png"), "Calculator history", this);
    historyAction->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_H));
    QShortcut *historyShortcut = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_H), this);

    QAction* engineeringCalculatorAction = new QAction(QIcon(":/icons/calculator.png"),
                                                      "Engineering calculator", this);

    QAction* programmerCalculatorAction = new QAction(QIcon(":/icons/programmerCalculator.png"),
                                                      "Programmer calculator", this);

    QAction* closeAction = new QAction(QIcon(":/icons/exit.png"), "Close", this);
    closeAction->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Q));
    QShortcut *closeShortcut = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_Q), this);

    QObject::connect(closeShortcut, &QShortcut::activated,
                     this, &MainWindow::close);
    QObject::connect(historyShortcut, &QShortcut::activated,
                     this, &MainWindow::showHistory);

    calculatorBtn = new MenuButton(this);
    calculatorBtn->setText("Calculator");
    calculatorBtn->addAction(historyAction);
    calculatorBtn->addSeparator();
    calculatorBtn->addAction(engineeringCalculatorAction);
    calculatorBtn->addAction(programmerCalculatorAction);
    calculatorBtn->addSeparator();
    calculatorBtn->addAction(closeAction);

    helpBtn = new MenuButton(this);
    helpBtn->setText("Help");
    helpBtn->addAction(new QAction(QIcon(":/icons/help.png"), "Help", this));
    helpBtn->addSeparator();
    helpBtn->addAction(new QAction(QIcon(":/icons/about.png"), "About", this));

    connect(closeAction, &QAction::triggered, this, &MainWindow::close);
    connect(historyAction, &QAction::triggered, this, &MainWindow::showHistory);
    connect(engineeringCalculatorAction, &QAction::triggered, this, &MainWindow::showCalculator);
    connect(programmerCalculatorAction, &QAction::triggered, this, &MainWindow::showProgrammerCalculator);

    tb->addMenuButton(calculatorBtn);
    tb->addMenuButton(helpBtn);
}

void MainWindow::initPanels()
{
    calculator = new CalculatorSection(panelsWidget);
    history = new HistorySection(panelsWidget);
    history->hide();
    programmerCalculator = new ProgrammerCalculatorSection(panelsWidget);
    programmerCalculator->hide();
}

void MainWindow::showHistory()
{
    if (!isHistoryShowed)
    {
        history->show();
        cnt++;
    }
    isHistoryShowed = true;
    isWindowIsEmpty();
}

void MainWindow::showCalculator()
{
    if (!isCalculatorShowed)
    {
        calculator->show();
        cnt++;
    }
    isCalculatorShowed = true;
    isWindowIsEmpty();
}

void MainWindow::showProgrammerCalculator()
{
    if (!isProgrammerCalculatorShowed)
    {
        programmerCalculator->show();
        cnt++;
    }
    isProgrammerCalculatorShowed = true;
    isWindowIsEmpty();
}

void MainWindow::isWindowIsEmpty()
{
    if (cnt == 0)
    {
        ifWindowIsEmptyLabel->show();
    }else
    {
        ifWindowIsEmptyLabel->hide();
    }
}

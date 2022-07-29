#include "mainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : CustomWindow(parent)
{
    cnt = 1;
    isHistoryPanelShowed = false;
    isCalculatorPanelShowed = false;

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
    setMinimumSize(700, 600);
    resize(700, 600);

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
    connect(calculator, &CalculatorPanelSection::closed, this, [this](){
        calculator->close();
        isCalculatorPanelShowed = false;
        cnt--;
        isWindowIsEmpty();
    });
    connect(history, &HistoryPanelSection::closed, this, [this](){
        history->close();
        isHistoryPanelShowed = false;
        cnt--;
        isWindowIsEmpty();
    });

    connect(calculator, &CalculatorPanelSection::viewed, this, [this](){
        cnt--;
        isWindowIsEmpty();
    });
    connect(history, &HistoryPanelSection::viewed, this, [this](){
        cnt--;
        isWindowIsEmpty();
    });

    connect(calculator, &CalculatorPanelSection::windowHided, this, [this](){
        cnt++;
        isWindowIsEmpty();
    });
    connect(history, &HistoryPanelSection::windowHided, this, [this](){
        cnt++;
        isWindowIsEmpty();
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

    QMenu* convertersMenu = new QMenu(this);
    convertersMenu->setTitle("Converters");

    QAction* currencyAction = new QAction(QIcon(":/icons/converterIcons/currency.png"), "Currency", this);
    QAction* volumeAction = new QAction(QIcon(":/icons/converterIcons/volume.png"), "Volume", this);
    QAction* lengthAction = new QAction(QIcon(":/icons/converterIcons/length.png"), "Length", this);
    QAction* weightAction = new QAction(QIcon(":/icons/converterIcons/weight.png"), "Weight", this);
    QAction* temperatureAction = new QAction(QIcon(":/icons/converterIcons/temperature.png"), "Temperature", this);
    QAction* energyAction = new QAction(QIcon(":/icons/converterIcons/energy.png"), "Energy", this);
    QAction* areaAction = new QAction(QIcon(":/icons/converterIcons/area.png"), "Area", this);
    QAction* speedAction = new QAction(QIcon(":/icons/converterIcons/speed.png"), "Speed", this);
    QAction* timeAction = new QAction(QIcon(":/icons/converterIcons/time.png"), "Time", this);
    QAction* powerAction = new QAction(QIcon(":/icons/converterIcons/power.png"), "Power", this);
    QAction* dataAction = new QAction(QIcon(":/icons/converterIcons/data.png"), "Data", this);
    QAction* pressureAction = new QAction(QIcon(":/icons/converterIcons/pressure.png"), "Pressure", this);
    QAction* angleAction = new QAction(QIcon(":/icons/converterIcons/angle.png"), "Angle", this);

    convertersMenu->addAction(currencyAction);
    convertersMenu->addAction(volumeAction);
    convertersMenu->addAction(lengthAction);
    convertersMenu->addAction(weightAction);
    convertersMenu->addAction(temperatureAction);
    convertersMenu->addAction(energyAction);
    convertersMenu->addAction(areaAction);
    convertersMenu->addAction(speedAction);
    convertersMenu->addAction(timeAction);
    convertersMenu->addAction(powerAction);
    convertersMenu->addAction(dataAction);
    convertersMenu->addAction(pressureAction);
    convertersMenu->addAction(angleAction);

    QObject::connect(closeShortcut, &QShortcut::activated,
                     this, &MainWindow::close);
    QObject::connect(historyShortcut, &QShortcut::activated,
                     this, &MainWindow::showHistoryPanel);

    calculatorBtn = new MenuButton(this);
    calculatorBtn->setText("Calculator");
    calculatorBtn->addAction(historyAction);
    calculatorBtn->addSeparator();
    calculatorBtn->addAction(engineeringCalculatorAction);
    calculatorBtn->addAction(programmerCalculatorAction);
    calculatorBtn->addMenu(convertersMenu);
    calculatorBtn->addSeparator();
    calculatorBtn->addAction(closeAction);

    helpBtn = new MenuButton(this);
    helpBtn->setText("Help");
    helpBtn->addAction(new QAction(QIcon(":/icons/help.png"), "Help", this));
    helpBtn->addSeparator();
    helpBtn->addAction(new QAction(QIcon(":/icons/about.png"), "About", this));

    connect(closeAction, &QAction::triggered, this, &MainWindow::close);
    connect(historyAction, &QAction::triggered, this, &MainWindow::showHistoryPanel);
    connect(engineeringCalculatorAction, &QAction::triggered, this, &MainWindow::showCalculator);

    tb->addMenuButton(calculatorBtn);
    tb->addMenuButton(helpBtn);
}

void MainWindow::initPanels()
{
    calculator = new CalculatorPanelSection(panelsWidget);
    history = new HistoryPanelSection(panelsWidget);
    history->hide();
}

void MainWindow::showHistoryPanel()
{
    if (!isHistoryPanelShowed)
    {
        history->show();
        cnt++;
    }
    isHistoryPanelShowed = true;
    isWindowIsEmpty();
}

void MainWindow::showCalculator()
{
    if (!isCalculatorPanelShowed)
    {
        calculator->show();
        cnt++;
    }
    isCalculatorPanelShowed = true;
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

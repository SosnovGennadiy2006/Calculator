#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QFrame>
#include <QSpacerItem>
#include <QMessageBox>
#include <QEvent>
#include <QShortcut>
#include "widgets/windows/customWindow.h"
#include "widgets/buttons/menuButton.h"
#include "widgets/sections/calculatorSection.h"
#include "widgets/sections/historySection.h"
#include "widgets/sections/programmerCalculatorSection.h"
#include "libs/muParser.h"

class MainWindow : public CustomWindow
{
    Q_OBJECT

    QVBoxLayout* mainLayout;

    QWidget* panelsWidget;
    QHBoxLayout* panelsLayout;

    QVBoxLayout* layout1;
    QVBoxLayout* layout2;

    CalculatorSection* calculator;
    HistorySection* history;
    ProgrammerCalculatorSection* programmerCalculator;

    MenuButton* calculatorBtn;
    MenuButton* helpBtn;

    QLabel* ifWindowIsEmptyLabel;

    QLabel* copyrightLabel;

    bool isHistoryShowed;
    bool isCalculatorShowed;
    bool isProgrammerCalculatorShowed;

    int cnt;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setupUI();
    void setupConnections();

    void initMenu();
    void initPanels();

    void isWindowIsEmpty();

private slots:
    void showHistory();
    void showCalculator();
    void showProgrammerCalculator();

};
#endif // MAINWINDOW_H

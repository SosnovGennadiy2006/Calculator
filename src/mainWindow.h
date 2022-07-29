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
#include "widgets/sections/calculatorPanelSection.h"
#include "widgets/sections/historyPanelSection.h"
#include "libs/muParser.h"

class MainWindow : public CustomWindow
{
    Q_OBJECT

    QVBoxLayout* mainLayout;

    QWidget* panelsWidget;
    QHBoxLayout* panelsLayout;

    QVBoxLayout* layout1;
    QVBoxLayout* layout2;

    CalculatorPanelSection* calculator;
    HistoryPanelSection* history;

    MenuButton* calculatorBtn;
    MenuButton* helpBtn;

    QLabel* ifWindowIsEmptyLabel;

    QLabel* copyrightLabel;

    bool isHistoryPanelShowed;
    bool isCalculatorPanelShowed;

    int cnt;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setupUI();
    void setupConnections();

    void initMenu();
    void initPanels();

    void isWindowIsEmpty();

private slots:
    void showHistoryPanel();
    void showCalculator();

};
#endif // MAINWINDOW_H

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
#include <widgets/buttons/customButton.h>
#include <widgets/panels/historywidget.h>
#include <widgets/windows/customwindow.h>
#include <widgets/panels/calculatorwidget.h>
#include <widgets/buttons/menubutton.h>
#include <libs/muParser.h>

class MainWindow : public CustomWindow
{
    Q_OBJECT

    QVBoxLayout* mainLayout;

    QWidget* panelsWidget;
    QHBoxLayout* panelsLayout;

    QVBoxLayout* layout1;
    QVBoxLayout* layout2;

    CalculatorWidget* calculator;
    HistoryWidget* history;

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

    void initMenu();

    void isWindowIsEmpty();

private slots:
    void showHistoryPanel();
    void showCalculator();

};
#endif // MAINWINDOW_H

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
#include <widgets/customButton.h>
#include <widgets/historywidget.h>
#include <libs/muParser.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

    mu::Parser p;

    int cnt = 0;

    QString expression;

    QHBoxLayout* mainLayout;

    QWidget* centralWidget;

    QWidget* gridWidget;
    QGridLayout* mainGrid;
    QLineEdit* mainEdit;

    QWidget* historyWidgetWrapper;
    QVBoxLayout* historyLayout;
    HistoryWidget* historyWidget;

    CustomButton* button_power;
    CustomButton* button_sqrt;
    CustomButton* button_exp;
    CustomButton* button_abs;
    CustomButton* button_asin;
    CustomButton* button_sin;
    CustomButton* button_sinh;
    CustomButton* button_asinh;
    CustomButton* button_acos;
    CustomButton* button_cos;
    CustomButton* button_cosh;
    CustomButton* button_acosh;
    CustomButton* button_atan;
    CustomButton* button_tan;
    CustomButton* button_tanh;
    CustomButton* button_atanh;
    CustomButton* button_sec;
    CustomButton* button_csc;
    CustomButton* button_log;
    CustomButton* button_log10;
    CustomButton* button_C;
    CustomButton* button_AC;
    CustomButton* button_brackets;
    CustomButton* button_divide;
    CustomButton* button_7;
    CustomButton* button_8;
    CustomButton* button_9;
    CustomButton* button_multiply;
    CustomButton* button_4;
    CustomButton* button_5;
    CustomButton* button_6;
    CustomButton* button_minus;
    CustomButton* button_1;
    CustomButton* button_2;
    CustomButton* button_3;
    CustomButton* button_plus;
    CustomButton* button_0;
    CustomButton* button_comma;
    CustomButton* button_equal;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addNumber();
    void addOperation();
    void addFunction();
    void addBracket();
    void solve();
};
#endif // MAINWINDOW_H

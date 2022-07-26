#ifndef MENU_H
#define MENU_H

#include <QObject>
#include <QWidget>
#include <QHBoxLayout>
#include <widgets/buttons/menubutton.h>

class Menu : public QWidget
{
    Q_OBJECT

    QHBoxLayout* mainLayout;

public:
    explicit Menu(QWidget *parent = nullptr);

    void addMenuButton(MenuButton* btn);

signals:

};

#endif // MENU_H

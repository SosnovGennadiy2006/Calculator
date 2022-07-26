#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include <QWidget>
#include <QMenu>
#include <QMouseEvent>
#include <QPushButton>

class MenuButton : public QPushButton
{
    QMenu menu;
    QString menuStyleString;

public:
    MenuButton(QWidget* parent = nullptr);

    void addAction(QAction* action);
    void addSeparator();
    void addMenu(QMenu* menu);
};

#endif // MENUBUTTON_H

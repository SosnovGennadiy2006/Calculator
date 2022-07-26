#include "menu.h"

Menu::Menu(QWidget *parent)
    : QWidget{parent}
{
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
    mainLayout = new QHBoxLayout(this);
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);
}

void Menu::addMenuButton(MenuButton* btn)
{
    mainLayout->addWidget(btn);
}

#include "menuButton.h"

MenuButton::MenuButton(QWidget* parent) : QPushButton{parent}
{
    QFont font;
    font.setPixelSize(16);
    font.setFamily("Bahnschrift SemiLight SemiConde");

    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
    setStyleSheet(
       "QPushButton {\n"
       "   background: #1E90FF;\n"
       "   border: none;\n"
       "   color: white;\n"
       "   padding: 0px 10px;\n"
       "}\n"
       "QPushButton::hover {\n"
       "   background: #1A7EDF;\n"
       "}\n"
       "QPushButton::pressed, QPushButton::!enabled {\n"
       "   background: #166CBF;\n"
       "}\n");
    setFont(font);
    setCursor(Qt::CursorShape::PointingHandCursor);

    QMenu menu = QMenu(this);
    menuStyleString = "QMenu {"
                      "    background: #1E90FF;"
                      "    padding: 2px;"
                      "    color: #fff;"
                      "    border: 1px solid lightblue;"
                      "}"
                      "QMenu::item {"
                      "    background: #1E90FF;"
                      "    padding: 2px 25px 2px 20px;"
                      "}"
                      "QMenu::item:selected {"
                      "    background: #166CBF;"
                      "}"
                      "QMenu::icon {"
                      "    position: absolute;"
                      "    top: 1px;"
                      "    right: 2px;"
                      "    bottom: 1px;"
                      "    left: 2px;"
                      "}"
                      "QMenu::separator {"
                      "    height: 1px;"
                      "    background: lightblue;"
                      "    margin-left: 10px;"
                      "    margin-right: 5px;"
                      "}";
    menu.setStyleSheet(menuStyleString);

    connect(this, &QPushButton::clicked, this, [this](){
        this->menu.exec(QPoint(mapToGlobal(QPointF(0,0)).rx(), mapToGlobal(QPointF(0,0)).ry() + size().height()));
    });
}

void MenuButton::addAction(QAction *action)
{
    menu.addAction(action);
    menu.setStyleSheet(menuStyleString);
}

void MenuButton::addSeparator()
{
    menu.addSeparator();
    menu.setStyleSheet(menuStyleString);
}

void MenuButton::addMenu(QMenu *_menu)
{
    _menu->setStyleSheet(menuStyleString);
    menu.addMenu(_menu);
    menu.setStyleSheet(menuStyleString);
}

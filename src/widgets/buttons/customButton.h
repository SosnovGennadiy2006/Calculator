#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H

#include <QPushButton>
#include <QObject>
#include <QWidget>

class CustomButton : public QPushButton
{
    Q_OBJECT
public:
    CustomButton(QWidget* parent = nullptr);
};

#endif // CUSTOMBUTTON_H

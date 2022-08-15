//
// Created by genas on 29.07.2022.
//

#ifndef SRC_CUSTOMLINEEDIT_H
#define SRC_CUSTOMLINEEDIT_H

#include <QWidget>
#include <QLineEdit>
#include <QCompleter>

class CustomLineEdit : public QLineEdit {
    Q_OBJECT;

public:
    explicit CustomLineEdit(QWidget* parent = nullptr);
};


#endif //SRC_CUSTOMLINEEDIT_H

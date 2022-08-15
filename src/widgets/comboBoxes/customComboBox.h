//
// Created by genas on 30.07.2022.
//

#ifndef SRC_CUSTOMCOMBOBOX_H
#define SRC_CUSTOMCOMBOBOX_H

#include <QComboBox>

class CustomComboBox : public QComboBox {
    Q_OBJECT;

public:
    explicit CustomComboBox(QWidget* parent = nullptr);
};


#endif //SRC_CUSTOMCOMBOBOX_H

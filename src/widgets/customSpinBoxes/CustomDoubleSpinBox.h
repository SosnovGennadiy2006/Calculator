//
// Created by genas on 02.08.2022.
//

#ifndef SRC_CUSTOMDOUBLESPINBOX_H
#define SRC_CUSTOMDOUBLESPINBOX_H

#include <QDoubleSpinBox>

class CustomDoubleSpinBox : public QDoubleSpinBox {
    Q_OBJECT;

public:
    explicit CustomDoubleSpinBox(QWidget* parent = nullptr);

};


#endif //SRC_CUSTOMDOUBLESPINBOX_H

//
// Created by genas on 30.07.2022.
//

#ifndef SRC_SELECTEDLINEEDIT_H
#define SRC_SELECTEDLINEEDIT_H

#include <QLineEdit>

class SelectedLineEdit : public QLineEdit {
    Q_OBJECT;

    bool _isSelected;

public:
    explicit SelectedLineEdit(QWidget* parent = nullptr);

    [[nodiscard]] inline bool isSelected() const;

    void setSelected(bool _selected);

    void focusInEvent(QFocusEvent *e) override;

signals:
    void selected();
};


#endif //SRC_SELECTEDLINEEDIT_H

//
// Created by Sina KH on 9/7/23.
//

#include "my_label.h"

UIComponents::MyLabel::MyLabel(QWidget *parent, QString title)
    : QLabel(parent) {
    setText(title);
    setWordWrap(true);
}

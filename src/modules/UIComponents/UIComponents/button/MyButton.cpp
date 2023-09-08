//
// Created by Sina KH on 9/7/23.
//

#include "MyButton.h"

UIComponents::MyButton::MyButton(QWidget *parent, QString title)
        : QPushButton(parent)
{
    setText(title);
}

//
// Created by Sina KH on 9/7/23.
//

#include "MyLabel.h"

UIComponents::MyLabel::MyLabel(QWidget *parent, QString title)
        : QLabel(parent)
{
    setText(title);
    setWordWrap(true);
}

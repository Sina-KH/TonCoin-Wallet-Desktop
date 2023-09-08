//
// Created by Sina KH on 9/7/23.
//

#ifndef TONCOIN_WALLET_DESKTOP_MYBUTTON_H
#define TONCOIN_WALLET_DESKTOP_MYBUTTON_H

#include <QPushButton>

namespace UIComponents {

class MyButton : public QPushButton {
    Q_OBJECT

    enum Type {
        Primary,
        Secondary
    };

    public:
    MyButton(QWidget *parent = nullptr, QString title = "", Type buttonType = Type::Primary);

    signals:

    public slots:
    };
}

#endif //TONCOIN_WALLET_DESKTOP_MYBUTTON_H

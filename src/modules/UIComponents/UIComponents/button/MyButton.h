//
// Created by Sina KH on 9/7/23.
//

#ifndef TONCOIN_WALLET_DESKTOP_MYBUTTON_H
#define TONCOIN_WALLET_DESKTOP_MYBUTTON_H

#include <QPushButton>

namespace UIComponents {
    class MyButton : public QPushButton {
    Q_OBJECT

    public:
        MyButton(QWidget *parent = nullptr, QString title = "");

    signals:

    public slots:
    };
}

#endif //TONCOIN_WALLET_DESKTOP_MYBUTTON_H

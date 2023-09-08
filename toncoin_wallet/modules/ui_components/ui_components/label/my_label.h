//
// Created by Sina KH on 9/7/23.
//

#ifndef TONCOIN_WALLET_DESKTOP_MYLABEL_H
#define TONCOIN_WALLET_DESKTOP_MYLABEL_H

#include <QLabel>

namespace UIComponents {
    class MyLabel : public QLabel {
    Q_OBJECT

    public:
        MyLabel(QWidget *parent = nullptr, QString title = "");

    signals:

    public slots:
    };
}

#endif //TONCOIN_WALLET_DESKTOP_MYLABEL_H

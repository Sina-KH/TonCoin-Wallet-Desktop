//
// Created by Sina KH on 9/7/23.
//

#include "IntroScreen.h"

#include "QLabel"
#include "QVBoxLayout"
#include "../../../UIComponents/button/MyButton.h"
#include "../../../UIComponents/label/MyLabel.h"

namespace UICreateWallet {
    UICreateWallet::IntroScreen::IntroScreen(QWidget *parent)
            : QWidget(parent)
    {
        auto *title = new QLabel("TON Wallet", this);
        title->setAlignment(Qt::AlignCenter);

        auto *subTitle = new UIComponents::MyLabel(this);
        subTitle->setText("TON Wallet allows you to make fast and secure blockchain-based payments without intermediaries.");
        subTitle->setAlignment(Qt::AlignCenter);

        auto *nextButton = new UIComponents::MyButton(this);

        auto *layout = new QVBoxLayout(this);
        layout->addWidget(title);
        layout->addWidget(subTitle);
        layout->addWidget(nextButton);
        layout->addStretch(); // Add some space at the bottom

        setLayout(layout);
    }
} // UICreateWallet
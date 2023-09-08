//
// Created by Sina KH on 9/7/23.
//

#ifndef TONCOIN_WALLET_DESKTOP_INTROSCREEN_H
#define TONCOIN_WALLET_DESKTOP_INTROSCREEN_H

#include "QWidget"

#include <ui_components/theme/my_styled_widget.h>

namespace UICreateWallet {

class IntroScreen : public QWidget, public UIComponents::MyStyledWidget {
    Q_OBJECT

  public:
    IntroScreen(QWidget *parent = nullptr);
    void updateStyledTheme() override;
  private slots:
};

} // namespace UICreateWallet

#endif // TONCOIN_WALLET_DESKTOP_INTROSCREEN_H

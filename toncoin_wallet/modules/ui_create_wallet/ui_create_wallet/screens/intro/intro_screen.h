//
// Created by Sina KH on 9/7/23.
//

#ifndef TONCOIN_WALLET_DESKTOP_INTROSCREEN_H
#define TONCOIN_WALLET_DESKTOP_INTROSCREEN_H

#include "QWidget"

#include <ui_components/theme/my_styled_widget.h>

#include <ui_components/screen/my_screen.h>

namespace UICreateWallet {

class IntroScreen : public UIComponents::MyScreen,
                    public UIComponents::MyStyledWidget {
    Q_OBJECT

  public:
    IntroScreen(QWidget *parent = nullptr,
                UIComponents::MyNavigator *navigator = nullptr);
    void updateStyledTheme() override;

  private:
  private slots:
    void newWalletPressed();
};

} // namespace UICreateWallet

#endif // TONCOIN_WALLET_DESKTOP_INTROSCREEN_H

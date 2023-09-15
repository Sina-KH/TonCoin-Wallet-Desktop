//
// Created by Sina KH on 9/7/23.
//

#include "intro_screen.h"

#include "QLabel"
#include "QSpacerItem"
#include "QVBoxLayout"
#include "ui_create_wallet/screens/congratulations/congratulations_screen.h"

#include <ui_components/animation/my_animation.h>
#include <ui_components/button/my_bottom_actions.h>
#include <ui_components/button/my_button.h>
#include <ui_components/label/my_label.h>

namespace UICreateWallet {
UICreateWallet::IntroScreen::IntroScreen(QWidget *parent,
                                         UIComponents::MyNavigator *navigator)
    : UIComponents::MyScreen(parent, navigator) {
    auto animation =
        new UIComponents::MyAnimation(this, QUrl("qrc:/Start.json"));

    auto title = new UIComponents::MyLabel(this, tr("intro.title"));
    auto titleFont = QFont("Inter");
    titleFont.setWeight(QFont::Weight::DemiBold);
    titleFont.setPointSize(23);
    title->setFont(titleFont);
    title->setAlignment(Qt::AlignCenter);

    auto *subTitle = new UIComponents::MyLabel(this, tr("intro.description"));
    auto subFont = QFont("Inter");
    subFont.setWeight(QFont::Weight::Normal);
    subFont.setPointSize(15);
    subTitle->setFont(subFont);
    subTitle->setAlignment(Qt::AlignCenter);

    auto *bottomActions = new UIComponents::MyBottomActions(
        this,
        UIComponents::MyBottomActions::Action{tr("intro.createWallet"), this,
                                              SLOT(newWalletPressed())},
        UIComponents::MyBottomActions::Action{tr("intro.importWallet")});

    auto *layout = new QVBoxLayout(this);
    layout->setContentsMargins(24, 0, 24, 0);
    layout->addSpacerItem(
        new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding));
    layout->addWidget(animation);
    layout->addWidget(title);
    layout->addWidget(subTitle);
    layout->addSpacerItem(
        new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding));
    layout->addWidget(bottomActions);

    setLayout(layout);
}

void UICreateWallet::IntroScreen::newWalletPressed() {
    // TODO:: Lock screen
    // TODO:: Create wallet logic
    // onCompletion:
    UICreateWallet::CongratulationsScreen *congratulationsScreen =
        new UICreateWallet::CongratulationsScreen(
            this, navigator); // TODO:: Pass this as parent?
    navigator->pushScreen(congratulationsScreen);
}

void UICreateWallet::IntroScreen::updateStyledTheme() {
    UIComponents::MyStyledWidget::updateStyledTheme();
}

} // namespace UICreateWallet

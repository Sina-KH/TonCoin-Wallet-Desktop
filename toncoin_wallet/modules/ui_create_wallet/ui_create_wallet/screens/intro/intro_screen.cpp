//
// Created by Sina KH on 9/7/23.
//

#include "intro_screen.h"

#include "QLabel"
#include "QSpacerItem"
#include "QVBoxLayout"

#include <ui_components/button/my_bottom_actions.h>
#include <ui_components/button/my_button.h>
#include <ui_components/label/my_label.h>

namespace UICreateWallet {
UICreateWallet::IntroScreen::IntroScreen(QWidget *parent) : QWidget(parent) {
    auto *title = new UIComponents::MyLabel(this, tr("intro.title"));
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
        this, tr("intro.createWallet"), tr("intro.importWallet"));

    auto *layout = new QVBoxLayout(this);
    layout->setContentsMargins(24, 0, 24, 0);
    layout->addSpacerItem(
        new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding));
    layout->addWidget(title);
    layout->addWidget(subTitle);
    layout->addSpacerItem(
        new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding));
    layout->addWidget(bottomActions);

    setLayout(layout);
}

void UICreateWallet::IntroScreen::updateStyledTheme() {
    UIComponents::MyStyledWidget::updateStyledTheme();
}

} // namespace UICreateWallet

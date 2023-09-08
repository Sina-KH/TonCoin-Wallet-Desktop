//
// Created by Sina KH on 9/7/23.
//

#include "intro_screen.h"

#include "QLabel"
#include "QVBoxLayout"

#include <ui_components/label/my_label.h>
#include <ui_components/button/my_button.h>

namespace UICreateWallet {
UICreateWallet::IntroScreen::IntroScreen(QWidget *parent) : QWidget(parent) {
  auto *title = new UIComponents::MyLabel(this, tr("intro.title"));
  title->setAlignment(Qt::AlignCenter);

  auto *subTitle = new UIComponents::MyLabel(this, tr("intro.description"));
  subTitle->setAlignment(Qt::AlignCenter);

  auto *nextButton = new UIComponents::MyButton(this, tr("intro.hi"));

  auto *layout = new QVBoxLayout(this);
  layout->addWidget(title);
  layout->addWidget(subTitle);
  layout->addWidget(nextButton);
  layout->addStretch(); // Add some space at the bottom

  setLayout(layout);
}
} // UICreateWallet

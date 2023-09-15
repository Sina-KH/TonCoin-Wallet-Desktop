#include "congratulations_screen.h"

#include <ui_components/label/my_label.h>

#include <ui_components/animation/my_animation.h>

#include <ui_components/button/my_bottom_actions.h>

#include <QVBoxLayout>

UICreateWallet::CongratulationsScreen::CongratulationsScreen(
    QWidget *parent, UIComponents::MyNavigator *navigator)
    : UIComponents::MyScreen{parent, navigator} {
    auto animation =
        new UIComponents::MyAnimation(this, QUrl("qrc:/Congratulations.json"));

    auto title = new UIComponents::MyLabel(this, tr("congratulations.title"));
    auto titleFont = QFont("Inter");
    titleFont.setWeight(QFont::Weight::DemiBold);
    titleFont.setPointSize(23);
    title->setFont(titleFont);
    title->setAlignment(Qt::AlignCenter);

    auto *subTitle =
        new UIComponents::MyLabel(this, tr("congratulations.description"));
    auto subFont = QFont("Inter");
    subFont.setWeight(QFont::Weight::Normal);
    subFont.setPointSize(15);
    subTitle->setFont(subFont);
    subTitle->setAlignment(Qt::AlignCenter);

    auto *bottomActions = new UIComponents::MyBottomActions(
        this,
        UIComponents::MyBottomActions::Action{tr("congratulations.proceed")});

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

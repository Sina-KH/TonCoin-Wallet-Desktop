#include "my_bottom_actions.h"
#include "my_button.h"

#include <QVBoxLayout>

UIComponents::MyBottomActions::MyBottomActions(QWidget *parent,
                                               QString primaryText,
                                               QString secondaryText)
    : QWidget{parent} {
    // primary button
    auto *primaryButton = new UIComponents::MyButton(this, primaryText);
    // secondary button
    auto *secondaryButton = new UIComponents::MyButton(
        this, secondaryText, MyButton::Type::Secondary);

    auto *layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignHCenter);
    layout->addWidget(primaryButton);
    layout->addWidget(secondaryButton);
}

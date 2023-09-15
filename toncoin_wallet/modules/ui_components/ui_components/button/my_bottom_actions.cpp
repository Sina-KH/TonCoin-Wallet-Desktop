#include "my_bottom_actions.h"
#include "my_button.h"

#include <QObject>
#include <QVBoxLayout>

UIComponents::MyBottomActions::MyBottomActions(QWidget *parent,
                                               Action primaryAction,
                                               Action secondaryAction)
    : QWidget{parent} {
    // primary button
    auto *primaryButton = new UIComponents::MyButton(this, primaryAction.text);
    QObject::connect(primaryButton, SIGNAL(clicked(bool)),
                     primaryAction.pressReceiver, primaryAction.pressSlot);
    // secondary button
    auto *secondaryButton = new UIComponents::MyButton(
        this, secondaryAction.text, MyButton::Type::Secondary);

    auto *layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignHCenter);
    layout->addWidget(primaryButton);
    layout->addWidget(secondaryButton);
}

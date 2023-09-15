#include "my_navigator.h"

UIComponents::MyNavigator::MyNavigator(QObject *parent, QStackedWidget *stackedWidget)
    : QObject{parent}
{
    this->stackedWidget = stackedWidget;
}

void UIComponents::MyNavigator::pushScreen(QWidget *screen) {
    this->stackedWidget->addWidget(screen);
    this->stackedWidget->setCurrentWidget(screen);
}

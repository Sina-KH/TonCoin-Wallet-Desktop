#include "my_navigator.h"

UIComponents::MyNavigator::MyNavigator(QWidget *parent)
    : QStackedWidget{parent} {}

void UIComponents::MyNavigator::pushScreen(QWidget *screen) {
    this->addWidget(screen);
    this->setCurrentWidget(screen);
}

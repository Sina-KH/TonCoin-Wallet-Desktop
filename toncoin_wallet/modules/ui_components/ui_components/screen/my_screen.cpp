#include "my_screen.h"

UIComponents::MyScreen::MyScreen(QWidget *parent, MyNavigator *navigator)
    : QWidget{parent}
{
    this->navigator = navigator;
}

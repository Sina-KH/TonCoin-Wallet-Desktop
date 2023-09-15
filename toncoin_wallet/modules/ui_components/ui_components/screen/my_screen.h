#ifndef MYSCREEN_H
#define MYSCREEN_H

#include <QWidget>

#include <ui_components/navigator/my_navigator.h>

namespace UIComponents {
class MyScreen : public QWidget
{
    Q_OBJECT
  public:
    explicit MyScreen(QWidget *parent = nullptr, MyNavigator *navigator = nullptr);

  protected:
    UIComponents::MyNavigator *navigator;

  signals:

};
}

#endif // MYSCREEN_H

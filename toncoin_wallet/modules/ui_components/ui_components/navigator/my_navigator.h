#ifndef MYNAVIGATOR_H
#define MYNAVIGATOR_H

#include <QObject>
#include <QStackedWidget>

namespace UIComponents {
class MyNavigator : public QObject
{
    Q_OBJECT
  public:
    explicit MyNavigator(QObject *parent = nullptr, QStackedWidget *stackedWidget = nullptr);

    void pushScreen(QWidget *screen);

  private:
    QStackedWidget *stackedWidget;
  signals:

};
}

#endif // MYNAVIGATOR_H

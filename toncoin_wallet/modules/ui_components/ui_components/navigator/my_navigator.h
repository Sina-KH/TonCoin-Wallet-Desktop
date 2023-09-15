#ifndef MYNAVIGATOR_H
#define MYNAVIGATOR_H

#include <QStackedWidget>
#include <QWidget>

namespace UIComponents {
class MyNavigator : public QStackedWidget {
    Q_OBJECT
  public:
    explicit MyNavigator(QWidget *parent = nullptr);

    void pushScreen(QWidget *screen);

  private:
  signals:
};
} // namespace UIComponents

#endif // MYNAVIGATOR_H

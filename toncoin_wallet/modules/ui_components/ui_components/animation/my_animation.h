#ifndef MYANIMATION_H
#define MYANIMATION_H

#include <QWidget>

namespace UIComponents {
class MyAnimation : public QWidget {
    Q_OBJECT
  public:
    explicit MyAnimation(QWidget *parent, QUrl animationUrl);

  signals:
};
} // namespace UIComponents

#endif // MYANIMATION_H

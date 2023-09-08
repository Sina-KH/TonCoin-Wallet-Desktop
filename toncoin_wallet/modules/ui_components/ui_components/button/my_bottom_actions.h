#ifndef MYBOTTOMACTIONS_H
#define MYBOTTOMACTIONS_H

#include <QWidget>

namespace UIComponents {
class MyBottomActions : public QWidget {
    Q_OBJECT
  public:
    explicit MyBottomActions(QWidget *parent = nullptr,
                             QString primaryText = "",
                             QString secondaryText = "");

  signals:
};
} // namespace UIComponents

#endif // MYBOTTOMACTIONS_H

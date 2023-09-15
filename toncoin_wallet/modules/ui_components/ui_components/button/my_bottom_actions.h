#ifndef MYBOTTOMACTIONS_H
#define MYBOTTOMACTIONS_H

#include <QWidget>

namespace UIComponents {
class MyBottomActions : public QWidget {
    Q_OBJECT
  public:
    struct Action {
        QString text;
        QObject *pressReceiver;
        const char *pressSlot;
    };

    MyBottomActions(QWidget *parent = nullptr, Action primaryAction = {},
                    Action secondaryAction = {});

  signals:
};
} // namespace UIComponents

#endif // MYBOTTOMACTIONS_H

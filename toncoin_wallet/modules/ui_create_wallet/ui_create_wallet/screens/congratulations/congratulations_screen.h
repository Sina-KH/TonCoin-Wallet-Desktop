#ifndef CONGRATULATIONSSCREEN_H
#define CONGRATULATIONSSCREEN_H

#include <QWidget>

#include <ui_components/screen/my_screen.h>

namespace UICreateWallet {
class CongratulationsScreen : public UIComponents::MyScreen {
    Q_OBJECT
  public:
    explicit CongratulationsScreen(
        QWidget *parent = nullptr,
        UIComponents::MyNavigator *navigator = nullptr);

  signals:

  private slots:
    void proceedPressed();
};
} // namespace UICreateWallet

#endif // CONGRATULATIONSSCREEN_H

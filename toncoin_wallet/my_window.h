#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QMainWindow>
#include <ui_components/theme/my_styled_widget.h>
#include <ui_components/theme/my_theme_manager.h>

class MyWindow : public QMainWindow, UIComponents::MyStyledWidget {
    Q_OBJECT

  public:
    MyWindow(QWidget *parent = nullptr);
    ~MyWindow();

  private:
    void setTheme(UIComponents::ThemeName themeName);
};
#endif // MYWINDOW_H

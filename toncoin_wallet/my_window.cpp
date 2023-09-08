#include "my_window.h"

#include <QStackedWidget>
#include <QVBoxLayout>
#include <qapplication.h>
#include <ui_create_wallet/screens/intro/intro_screen.h>

MyWindow::MyWindow(QWidget *parent)
    : QMainWindow(parent), UIComponents::MyStyledWidget() {
    resize(360, 720);

    auto *stackedWidget = new QStackedWidget(this);

    // Intro Screen
    auto *introScreen = new UICreateWallet::IntroScreen(this);
    stackedWidget->addWidget(introScreen);

    setCentralWidget(stackedWidget);

    setTheme(UIComponents::ThemeName::light);
}

MyWindow::~MyWindow() {}

void MyWindow::setTheme(UIComponents::ThemeName themeName) {
    // Set global theme value
    UIComponents::MyThemeManager::getInstance().setCurrentTheme(themeName);

    // Update color pallete
    QPalette colorPalette;
    switch (themeName) {
    case UIComponents::ThemeName::dark:
        // Background color
        colorPalette.setColor(QPalette::Window, QColor(45, 45, 45));
        // Text color
        colorPalette.setColor(QPalette::WindowText, Qt::white);
        // Button text color
        colorPalette.setColor(QPalette::ButtonText, Qt::white);
        break;
    case UIComponents::ThemeName::light:
        // Background color
        colorPalette.setColor(QPalette::Window, Qt::white);
        // Text color
        colorPalette.setColor(QPalette::WindowText, Qt::black);
        // Button text color
        colorPalette.setColor(QPalette::ButtonText, Qt::black);
        break;
    }

    // Apply the theme palette to the entire application
    dynamic_cast<QApplication *>(QApplication::instance())
        ->setPalette(colorPalette);

    // Update all child widgets if extended from my styled widget
    updateStyledTheme();
}

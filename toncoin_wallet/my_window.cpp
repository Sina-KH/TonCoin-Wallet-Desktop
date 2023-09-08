#include "my_window.h"

#include <QStackedWidget>
#include <QVBoxLayout>
#include <ui_create_wallet/screens/intro/intro_screen.h>

MyWindow::MyWindow(QWidget *parent) : QMainWindow(parent) {
    resize(400, 600);

    auto *stackedWidget = new QStackedWidget(this);

    // Intro Screen
    auto *introScreen = new UICreateWallet::IntroScreen(this);
    stackedWidget->addWidget(introScreen);

    setCentralWidget(stackedWidget);
}

MyWindow::~MyWindow() {}

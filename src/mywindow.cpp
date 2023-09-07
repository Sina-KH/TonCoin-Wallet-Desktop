#include "mywindow.h"
#include "modules/UICreateWallet/screens/IntroScreen/IntroScreen.h"

#include <QStackedWidget>
#include <QVBoxLayout>

MyWindow::MyWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(400, 600);

    auto *stackedWidget = new QStackedWidget(this);

    // Intro Screen
    auto *introScreen = new UICreateWallet::IntroScreen(this);
    stackedWidget->addWidget(introScreen);

    setCentralWidget(stackedWidget);
}

MyWindow::~MyWindow()
{
}


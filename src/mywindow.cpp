#include "mywindow.h"

#include <QLabel>

MyWindow::MyWindow(QWidget *parent)
    : QMainWindow(parent)
{
    auto label = new QLabel(this);
    label->setText("Hi TON!");
    setCentralWidget(label);
}

MyWindow::~MyWindow()
{
}


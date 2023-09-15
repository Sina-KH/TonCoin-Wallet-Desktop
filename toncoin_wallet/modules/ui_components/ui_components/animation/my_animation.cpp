#include "my_animation.h"

#include "qtlottie/qtlottiewidget.h"

#include <QHBoxLayout>

UIComponents::MyAnimation::MyAnimation(QWidget *parent, QUrl animationUrl)
    : QWidget{parent} {
    // Load lottie animation
    const auto lottieWidget = new QtLottieWidget(this);
    lottieWidget->setMinimumSize(124, 124);
    lottieWidget->setSource(animationUrl);

    // Add animation to container layout
    const auto lottieLayout = new QHBoxLayout(this);
    lottieLayout->addWidget(lottieWidget);
    lottieLayout->setAlignment(Qt::AlignCenter);
    setLayout(lottieLayout);
}

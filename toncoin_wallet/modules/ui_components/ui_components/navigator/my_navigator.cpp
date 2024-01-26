#include "my_navigator.h"

#include <QPropertyAnimation>
#include <QParallelAnimationGroup>

UIComponents::MyNavigator::MyNavigator(QWidget *parent)
    : QStackedWidget{parent} {}

void UIComponents::MyNavigator::pushScreen(QWidget *screen, bool animated) {
    if (isAnimating)
        return;

    this->addWidget(screen);

    auto *currentWidget = this->currentWidget();
    if (animated && currentWidget) {
        isAnimating = true;

        // Initialize animations for both widgets
        auto animationCurrent = new QPropertyAnimation(currentWidget, "geometry");
        animationCurrent->setDuration(300);

        auto animationNew = new QPropertyAnimation(screen, "geometry");
        animationNew->setDuration(300);

        // Set up animations for the current widget
        animationCurrent->setStartValue(currentWidget->geometry());
        animationCurrent->setEndValue(QRect(-width(), 0, width(), height()));

        // Set up animations for the new widget
        animationNew->setStartValue(QRect(width(), 0, width(), height()));
        animationNew->setEndValue(QRect(0, 0, width(), height()));

        // Create a parallel animation group to run both animations concurrently
        auto *group = new QParallelAnimationGroup;
        group->addAnimation(animationCurrent);
        group->addAnimation(animationNew);

        // Connect the animation finished signal to handle cleanup
        screen->show();
        connect(group, &QParallelAnimationGroup::finished, this, [this, currentWidget]() {
            currentWidget->hide();
            this->setCurrentIndex(currentIndex() + 1);
            this->isAnimating = false;
        });

        // Start the parallel animation group
        group->start();
    } else {
        this->setCurrentIndex(currentIndex() + 1);
    }
}

void UIComponents::MyNavigator::popScreen(bool animated) {
    if (currentIndex() < 1 || isAnimating)
        return;

    auto *currentWidget = this->currentWidget();
    auto *prevWidget = this->widget(currentIndex() - 1);
    if (animated) {
        isAnimating = true;

        // Initialize animations for both widgets
        auto animationCurrent = new QPropertyAnimation(currentWidget, "geometry");
        animationCurrent->setDuration(300);

        auto animationNew = new QPropertyAnimation(prevWidget, "geometry");
        animationNew->setDuration(300);

        // Set up animations for the current widget
        animationCurrent->setStartValue(currentWidget->geometry());
        animationCurrent->setEndValue(QRect(width(), 0, width(), height()));

        // Set up animations for the new widget
        animationNew->setStartValue(QRect(-width(), 0, width(), height()));
        animationNew->setEndValue(QRect(0, 0, width(), height()));

        // Create a parallel animation group to run both animations concurrently
        auto *group = new QParallelAnimationGroup;
        group->addAnimation(animationCurrent);
        group->addAnimation(animationNew);

        // Connect the animation finished signal to handle cleanup
        prevWidget->show();
        connect(group, &QParallelAnimationGroup::finished, this, [this, currentWidget]() {
            this->removeWidget(currentWidget);
            this->setCurrentIndex(currentIndex() - 1);
            this->isAnimating = false;
        });

        // Start the parallel animation group
        group->start();
    } else {
        this->removeWidget(currentWidget);
        this->setCurrentIndex(currentIndex() - 1);
    }
}

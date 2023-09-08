#ifndef MYSTYLEDWIDGET_H
#define MYSTYLEDWIDGET_H

#include <QObjectList>
#include <QWidget>

namespace UIComponents {
class MyStyledWidget {
  public:
    MyStyledWidget();

    // Update widget and all children to new theme
    virtual void updateStyledTheme() {
        QWidget *thisWidget = dynamic_cast<QWidget *>(this);
        if (thisWidget == nullptr)
            return;
        const QObjectList &children = thisWidget->children();
        for (QObject *child : children) {
            UIComponents::MyStyledWidget *styledWidget =
                dynamic_cast<UIComponents::MyStyledWidget *>(child);
            if (styledWidget != nullptr)
                styledWidget->updateStyledTheme();
        }
    };
};
} // namespace UIComponents

#endif // MYSTYLEDWIDGET_H

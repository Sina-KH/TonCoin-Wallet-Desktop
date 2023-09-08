#ifndef MYTHEMEMANAGER_H
#define MYTHEMEMANAGER_H

#include "my_style_sheet.h"

namespace UIComponents {
enum ThemeName { light, dark };

// Hold current selected theme and return style based on current theme.
class MyThemeManager {
  public:
    static MyThemeManager &getInstance() {
        static MyThemeManager instance;
        return instance;
    }

    UIComponents::ThemeName getCurrentTheme() const {
        return UIComponents::ThemeName::light;
    }

    void setCurrentTheme(const UIComponents::ThemeName &theme) {
        currentTheme = theme;
        // You can emit a signal here to notify other parts of the application
        // about the theme change.
    }

    QString getCurrentStylesheet(MyStyleSheet stylesheet) const {
        if (currentTheme == UIComponents::ThemeName::dark)
            return stylesheet.dark;
        return stylesheet.light;
    }

  private:
    MyThemeManager() {} // Private constructor to enforce singleton pattern
    UIComponents::ThemeName currentTheme;
};
} // namespace UIComponents
#endif // MYTHEMEMANAGER_H

#include "my_theme_manager.h"
#include "my_style_sheet.h"

#include <QString>

// Hold current selected theme and return style based on current theme.
class ThemeManager {
  public:
    static ThemeManager &getInstance() {
        static ThemeManager instance;
        return instance;
    }

    QString getCurrentTheme() const { return currentTheme; }

    void setCurrentTheme(const QString &theme) {
        currentTheme = theme;
        // You can emit a signal here to notify other parts of the application
        // about the theme change.
    }

    QString getCurrentStylesheet(MyStyleSheet stylesheet) const {
        if (currentTheme == "dark")
            return stylesheet.dark;
        return stylesheet.light;
    }

  private:
    ThemeManager() {} // Private constructor to enforce singleton pattern
    QString currentTheme;
};

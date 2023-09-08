//
// Created by Sina KH on 9/7/23.
//

#include "my_button.h"
#include "ui_components/theme/my_style_sheet.h"
#include <ui_components/color/my_colors.h>
#include <ui_components/theme/my_theme_manager.h>

QString primaryStyleLight = "QPushButton {"
                            "    background-color: " +
                            UIComponents::MyColors::primary +
                            ";"
                            "    color: white;"
                            "    border-radius: 6px;"
                            "}"
                            "QPushButton:hover {"
                            "    background-color: " +
                            UIComponents::MyColors::primaryDark +
                            ";"
                            "}";

QString primaryStyleDark = "QPushButton {"
                           "    background-color: " +
                           UIComponents::MyColors::primary +
                           ";"
                           "    color: white;"
                           "    border-radius: 6px;"
                           "    padding: 12px 20px;"
                           "}"
                           "QPushButton:hover {"
                           "    background-color: " +
                           UIComponents::MyColors::primaryDark +
                           ";"
                           "}";

MyStyleSheet primaryStyleSheet =
    MyStyleSheet{primaryStyleLight, primaryStyleDark};

QString secondaryStyle = "QPushButton {"
                         "    background-color: rgba(0, 0, 0, 0);"
                         "    color:" +
                         UIComponents::MyColors::primaryDark +
                         ";"
                         "    border-radius: 6px;"
                         "}";

MyStyleSheet secondaryStyleSheet = MyStyleSheet{secondaryStyle};

UIComponents::MyButton::MyButton(QWidget *parent, QString title,
                                 Type buttonType)
    : QPushButton(parent) {
    this->buttonType = buttonType;

    setMinimumHeight(42);
    setMinimumWidth(160);
    setText(title);

    auto font = QFont("Inter");
    font.setPointSize(14);
    font.setWeight(QFont::Weight::Normal);
    setFont(font);

    updateStyledButton();
}

void UIComponents::MyButton::updateStyledTheme() { updateStyledButton(); }

void UIComponents::MyButton::updateStyledButton() {
    switch (buttonType) {
    case Type::Primary:
        setStyleSheet(MyThemeManager::getInstance().getCurrentStylesheet(
            primaryStyleSheet));
        break;
    case Type::Secondary:
        setStyleSheet(MyThemeManager::getInstance().getCurrentStylesheet(
            secondaryStyleSheet));
        break;
    }
    UIComponents::MyStyledWidget::updateStyledTheme();
}

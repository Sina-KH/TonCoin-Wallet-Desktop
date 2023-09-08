//
// Created by Sina KH on 9/7/23.
//

#include "MyButton.h"
#include "UIComponents/theme/MyStyleSheet.h"
#include <UIComponents/color/MyColors.h>
#include <UIComponents/theme/MyThemeManager.cpp>

QString primaryStyleLight = "QPushButton {"
                           "    background-color: " + UIComponents::MyColors::primary + ";"
                                                                          "    color: white;"
                                                                          "    border-radius: 6px;"
                                                                          "    padding: 12px 20px;"
                                                                          "}"
                                                                          "QPushButton:hover {"
                                                                          "    background-color: " + UIComponents::MyColors::primaryDark + ";"
                                                                          "}";

QString primaryStyleDark = "QPushButton {"
                       "    background-color: " + UIComponents::MyColors::primary + ";"
                       "    color: white;"
                       "    border-radius: 6px;"
                       "    padding: 12px 20px;"
                       "}"
                       "QPushButton:hover {"
                           "    background-color: " + UIComponents::MyColors::primaryDark + ";"
                       "}";

MyStyleSheet primaryStyleSheet = MyStyleSheet {primaryStyleLight, primaryStyleDark};

UIComponents::MyButton::MyButton(QWidget *parent, QString title, Type buttonType)
        : QPushButton(parent)
{
    setFixedHeight(42);
    setFixedHeight(160);

    setText(title);
    switch (buttonType) {
    case Type::Primary:
        setStyleSheet(ThemeManager::getInstance().getCurrentStylesheet(primaryStyleSheet));
        break;
    case Type::Secondary:
        break;
    }
}

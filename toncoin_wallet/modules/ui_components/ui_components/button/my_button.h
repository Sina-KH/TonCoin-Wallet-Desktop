//
// Created by Sina KH on 9/7/23.
//

#ifndef TONCOIN_WALLET_DESKTOP_MYBUTTON_H
#define TONCOIN_WALLET_DESKTOP_MYBUTTON_H

#include <QPushButton>

#include <ui_components/theme/my_styled_widget.h>

namespace UIComponents {

class MyButton : public QPushButton, public MyStyledWidget {
    Q_OBJECT

  public:
    enum Type { Primary, Secondary };

    MyButton(QWidget *parent = nullptr, QString title = "",
             Type buttonType = Type::Primary);
    void updateStyledTheme() override;

  private:
    Type buttonType;
    void updateStyledButton();
};
} // namespace UIComponents

#endif // TONCOIN_WALLET_DESKTOP_MYBUTTON_H

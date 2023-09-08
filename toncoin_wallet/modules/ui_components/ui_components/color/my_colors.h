#ifndef MYCOLORS_H
#define MYCOLORS_H

#include <QString>

namespace UIComponents {
// All colors used in all the themes
class MyColors {
  public:
    static const QString primary;
    static const QString primaryDark;
};

const QString MyColors::primary = "#339CEC";
const QString MyColors::primaryDark = "#2899E0"; // TODO:: update
} // namespace UIComponents

#endif // MYCOLORS_H

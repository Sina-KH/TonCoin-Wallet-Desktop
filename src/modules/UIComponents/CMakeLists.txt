project(UIComponents)

set(SUBMODULE_SOURCES
        UIComponents/button/MyButton.h
        UIComponents/button/MyButton.cpp
        UIComponents/label/MyLabel.h
        UIComponents/label/MyLabel.cpp
        UIComponents/color/MyColors.h
        UIComponents/theme/MyThemeManager.h
        UIComponents/theme/MyThemeManager.cpp
        UIComponents/theme/MyStyleSheet.h

)
add_library(UIComponents ${SUBMODULE_SOURCES})

target_include_directories(UIComponents PUBLIC .)

target_link_libraries(UIComponents PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

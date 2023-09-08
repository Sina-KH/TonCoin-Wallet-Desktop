project(UIComponents)

set(SUBMODULE_SOURCES
        UIComponents/Button/MyButton.h
        UIComponents/Button/MyButton.cpp
        UIComponents/Label/MyLabel.h
        UIComponents/Label/MyLabel.cpp
        UIComponents/Color/MyColors.h
        UIComponents/Theme/MyThemeManager.h
        UIComponents/Theme/MyThemeManager.cpp
        UIComponents/Theme/MyStyleSheet.h

)
add_library(UIComponents ${SUBMODULE_SOURCES})

target_include_directories(UIComponents PUBLIC .)

target_link_libraries(UIComponents PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

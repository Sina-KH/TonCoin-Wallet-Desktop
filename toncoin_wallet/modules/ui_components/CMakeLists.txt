project(UIComponents)

add_library(UIComponents
    ui_components/button/my_button.h
    ui_components/button/my_button.cpp
    ui_components/label/my_label.h
    ui_components/label/my_label.cpp
    ui_components/color/my_colors.h
    ui_components/theme/my_theme_manager.h
    ui_components/theme/my_theme_manager.cpp
    ui_components/theme/my_style_sheet.h
)

target_include_directories(UIComponents PUBLIC .)

target_link_libraries(UIComponents PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

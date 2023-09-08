project(UICreateWallet)

add_library(UICreateWallet
    ui_create_wallet/screens/intro/intro_screen.h
    ui_create_wallet/screens/intro/intro_screen.cpp
)

target_include_directories(UICreateWallet PUBLIC .)

target_link_libraries(UICreateWallet PRIVATE UIComponents)
target_link_libraries(UICreateWallet PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

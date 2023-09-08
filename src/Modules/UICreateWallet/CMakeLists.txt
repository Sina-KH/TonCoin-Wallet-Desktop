project(UICreateWallet)

set(SUBMODULE_SOURCES
        UICreateWallet/Screens/IntroScreen/IntroScreen.h
        UICreateWallet/Screens/IntroScreen/IntroScreen.cpp
)
add_library(UICreateWallet ${SUBMODULE_SOURCES})

target_include_directories(UICreateWallet PUBLIC .)

target_link_libraries(UICreateWallet PRIVATE UIComponents)
target_link_libraries(UICreateWallet PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

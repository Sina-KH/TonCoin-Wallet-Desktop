project(UICreateWallet)

set(SUBMODULE_SOURCES
        UICreateWallet/screens/IntroScreen/IntroScreen.h
        UICreateWallet/screens/IntroScreen/IntroScreen.cpp
)
add_library(UICreateWallet ${SUBMODULE_SOURCES})

target_include_directories(UICreateWallet PUBLIC .)

target_link_libraries(UICreateWallet PRIVATE UIComponents)
target_link_libraries(UICreateWallet PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

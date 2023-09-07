set(SUBMODULE_SOURCES
        screens/IntroScreen/IntroScreen.h
        screens/IntroScreen/IntroScreen.cpp
)

add_library(UICreateWallet ${SUBMODULE_SOURCES})

target_link_libraries(UICreateWallet PRIVATE UIComponents)
target_link_libraries(UICreateWallet PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

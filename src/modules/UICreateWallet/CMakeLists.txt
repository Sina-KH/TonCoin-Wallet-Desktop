set(SUBMODULE_SOURCES
        button/MyButton.h
        button/MyButton.cpp
)

add_library(UIComponents ${SUBMODULE_SOURCES})

target_link_libraries(UIComponents PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
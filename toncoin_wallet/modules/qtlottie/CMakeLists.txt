set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(PUBLIC_HEADERS
    qtlottie/qtlottie_global.h
    qtlottie/qtlottiedrawengine.h
    qtlottie/qtlottiedrawenginefactory.h
)

set(PRIVATE_HEADERS
    qtlottie/qtlottiedrawengine_skottie.h
    qtlottie/qtlottiedrawengine_rlottie.h
)

set(SOURCES
    qtlottie/qtlottiedrawenginefactory.cpp
    qtlottie/qtlottiedrawengine_skottie.cpp
    qtlottie/qtlottiedrawengine_rlottie.cpp
)

list(APPEND PUBLIC_HEADERS qtlottie/qtlottiewidget.h)
list(APPEND SOURCES qtlottie/qtlottiewidget.cpp)

add_library(qtlottie
    ${PUBLIC_HEADERS}
    ${PRIVATE_HEADERS}
    ${SOURCES}
)

target_compile_definitions(qtlottie PRIVATE
    QT_NO_CAST_FROM_ASCII
    QT_NO_CAST_TO_ASCII
    QT_NO_URL_CAST_FROM_STRING
    QT_NO_CAST_FROM_BYTEARRAY
    QT_NO_KEYWORDS
    QT_NO_NARROWING_CONVERSIONS_IN_CONNECT
    QT_NO_FOREACH
    QT_USE_QSTRINGBUILDER
    QT_DEPRECATED_WARNINGS
    QT_DISABLE_DEPRECATED_BEFORE=0x060500 # Remember to bump it when new Qt version releases.
    QTLOTTIE_BUILD_LIBRARY
)

target_link_libraries(qtlottie PRIVATE
    Qt${QT_VERSION_MAJOR}::Gui
)

target_link_libraries(qtlottie PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
)

target_link_libraries(qtlottie PRIVATE
    rlottie
)

target_include_directories(qtlottie PUBLIC .)

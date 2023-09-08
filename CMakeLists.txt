cmake_minimum_required(VERSION 3.5)

project(Toncoin-Wallet-Desktop VERSION 0.0.6 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools)

set(PROJECT_NAME Toncoin-Wallet-Desktop)

# Multi-language .ts files
set(TS_FILES
        toncoin_wallet/translations/en_US.ts
)

set(PROJECT_SOURCES
        toncoin_wallet/main.cpp
        toncoin_wallet/my_window.cpp
        toncoin_wallet/my_window.h
)

# Add SubModules
add_subdirectory(toncoin_wallet/modules/ui_components)
add_subdirectory(toncoin_wallet/modules/ui_create_wallet)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_create_translation(QM_FILES ${CMAKE_CURRENT_SOURCE_DIR} ${TS_FILES})
    configure_file(toncoin_wallet/Translations/translations.qrc ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

    qt_add_executable(${PROJECT_NAME}
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        ${CMAKE_CURRENT_BINARY_DIR}/translations.qrc
        ${QM_FILES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Toncoin-Wallet-Desktop APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    qt5_create_translation(QM_FILES ${CMAKE_CURRENT_BINARY_DIR} ${TS_FILES})
    configure_file(toncoin_wallet/translations/translations.qrc ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

    if(ANDROID)
        add_library(${PROJECT_NAME} SHARED
            ${PROJECT_SOURCES}
            ${CMAKE_CURRENT_BINARY_DIR}/translations.qrc
            ${QM_FILES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(${PROJECT_NAME}
            ${PROJECT_SOURCES}
            ${CMAKE_CURRENT_BINARY_DIR}/translations.qrc
            ${QM_FILES}
        )
    endif()
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Link SubModules
target_link_libraries(${PROJECT_NAME} PRIVATE UIComponents)
target_link_libraries(${PROJECT_NAME} PRIVATE UICreateWallet)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Toncoin-Wallet-Desktop)
endif()
set_target_properties(Toncoin-Wallet-Desktop PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Toncoin-Wallet-Desktop
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Toncoin-Wallet-Desktop)
endif()

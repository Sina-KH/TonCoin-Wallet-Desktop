cmake_minimum_required(VERSION 3.13)

project(Toncoin-Wallet-Desktop VERSION 0.0.15 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt Packages
find_package(QT NAMES Qt6 REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools Gui)

set(PROJECT_NAME Toncoin-Wallet-Desktop)

# Multi-language .ts files
set(TS_FILES
        toncoin_wallet/translations/en_US.ts
)

# Main source files
set(PROJECT_SOURCES
        toncoin_wallet/main.cpp
        toncoin_wallet/my_window.cpp
        toncoin_wallet/my_window.h
)

# Add SubModules
add_subdirectory(toncoin_wallet/modules/qtlottie)
add_subdirectory(toncoin_wallet/modules/rlottie)
add_subdirectory(toncoin_wallet/modules/ui_components)
add_subdirectory(toncoin_wallet/modules/ui_create_wallet)

# Assets
configure_file(toncoin_wallet/assets/assets.qrc ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(toncoin_wallet/assets/fonts/Inter.ttf ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(toncoin_wallet/assets/animations/Start.json ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
set(ASSET_FILES
    ${CMAKE_CURRENT_BINARY_DIR}/assets.qrc
    ${CMAKE_CURRENT_BINARY_DIR}/Inter.ttf
    ${CMAKE_CURRENT_BINARY_DIR}/Start.json
)

qt_create_translation(QM_FILES ${CMAKE_CURRENT_SOURCE_DIR} ${TS_FILES})
configure_file(toncoin_wallet/translations/translations.qrc ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

qt_add_executable(${PROJECT_NAME}
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
    ${CMAKE_CURRENT_BINARY_DIR}/translations.qrc
    ${QM_FILES}
    ${ASSET_FILES}
)

# Link to Qt widgets
target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Link SubModules
target_link_libraries(${PROJECT_NAME} PRIVATE qtlottie)
target_link_libraries(${PROJECT_NAME} PRIVATE UIComponents)
target_link_libraries(${PROJECT_NAME} PRIVATE UICreateWallet)

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

qt_finalize_executable(Toncoin-Wallet-Desktop)

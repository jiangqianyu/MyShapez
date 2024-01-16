cmake_minimum_required(VERSION 3.5)

project(MyShapez VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Multimedia)

set(PROJECT_SOURCES
        main.cpp
        WindowControl.cpp
        WindowControl.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(MyShapez
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        config.h
        res.qrc
        Hub.h Hub.cpp
        Scene.h Scene.cpp
        PlayScene.h PlayScene.cpp
        GameMap.h GameMap.cpp
        Building.h Building.cpp
        Shape.h
        Miner.h Miner.cpp
        Belt.h Belt.cpp
        timer.h timer.cpp
        vec.h
        Trash.h Trash.cpp
        Cutter.h Cutter.cpp
        RoundScene.h RoundScene.cpp
        ChooseScene.h ChooseScene.cpp
        ShopScene.h ShopScene.cpp
        StartScene.h StartScene.cpp
        WinScene.h WinScene.cpp
        HelpScene.h HelpScene.cpp
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET MyShapez APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(MyShapez SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(MyShapez
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(MyShapez PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(MyShapez PRIVATE Qt${QT_VERSION_MAJOR}::Multimedia)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.MyShapez)
endif()
set_target_properties(MyShapez PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS MyShapez
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(MyShapez)
endif()

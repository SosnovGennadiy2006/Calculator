cmake_minimum_required(VERSION 3.20)
project(src)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "D:/Qt/6.2.1/mingw81_64")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(src main.cpp mainWindow.cpp mainWindow.h resources.qrc
libs/muParser.cpp
libs/muParserBase.cpp
libs/muParserBytecode.cpp
libs/muParserCallback.cpp
libs/muParserComplex.cpp
libs/muParserDLL.cpp
libs/muParserError.cpp
libs/muParserInt.cpp
libs/muParserTest.cpp
libs/muParserTokenReader.cpp
main.cpp
        mainWindow.cpp
        widgets/panelWidgets/abstractPanelWidget.cpp
        widgets/panelWidgets/calculatorWidget.cpp
        widgets/panelWidgets/historyWidget.cpp
widgets/buttons/customButton.cpp
widgets/menu/menu.cpp
        widgets/buttons/menuButton.cpp
        widgets/sections/abstractPanelSection.cpp
        widgets/sections/calculatorPanelSection.cpp
        widgets/sections/historyPanelSection.cpp
        widgets/titleBars/hideTitlebar.cpp
widgets/titleBars/titlebar.cpp
        widgets/titleBars/viewTitlebar.cpp
        widgets/windows/customWindow.cpp
        widgets/windows/panelWindows/abstractPanelWindow.cpp
        widgets/windows/panelWindows/calculatorWindow.cpp
        widgets/windows/panelWindows/historyWindow.cpp
libs/muParser.h
libs/muParserBase.h
libs/muParserBytecode.h
libs/muParserCallback.h
libs/muParserComplex.h
libs/muParserDLL.h
libs/muParserDef.h
libs/muParserError.h
libs/muParserFixes.h
libs/muParserInt.h
libs/muParserStack.h
libs/muParserTest.h
libs/muParserToken.h
libs/muParserTokenReader.h
        mainWindow.h
        widgets/panelWidgets/abstractPanelWidget.h
        widgets/panelWidgets/calculatorWidget.h
        widgets/panelWidgets/historyWidget.h
widgets/buttons/customButton.h
widgets/menu/menu.h
        widgets/buttons/menuButton.h
        widgets/QHoverWatcher.h
        widgets/sections/abstractPanelSection.h
        widgets/sections/calculatorPanelSection.h
        widgets/sections/historyPanelSection.h
        widgets/titleBars/hideTitlebar.h
widgets/titleBars/titlebar.h
        widgets/titleBars/viewTitlebar.h
        widgets/windows/customWindow.h
        widgets/windows/panelWindows/abstractPanelWindow.h
        widgets/windows/panelWindows/calculatorWindow.h
        widgets/windows/panelWindows/historyWindow.h widgets/windows/hideWindow.cpp widgets/windows/hideWindow.h widgets/panelWidgets/programmerCalculatorWidget.cpp widgets/panelWidgets/programmerCalculatorWidget.h)
target_link_libraries(src
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

if (WIN32)
    set(DEBUG_SUFFIX)
#    if (CMAKE_BUILD_TYPE MATCHES "Debug")
#        set(DEBUG_SUFFIX "d")
#    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()

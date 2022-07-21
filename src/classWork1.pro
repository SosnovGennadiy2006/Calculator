QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    libs/muParser.cpp \
    libs/muParserBase.cpp \
    libs/muParserBytecode.cpp \
    libs/muParserCallback.cpp \
    libs/muParserComplex.cpp \
    libs/muParserDLL.cpp \
    libs/muParserError.cpp \
    libs/muParserInt.cpp \
    libs/muParserTest.cpp \
    libs/muParserTokenReader.cpp \
    main.cpp \
    mainwindow.cpp \
    widgets/customButton.cpp \
    widgets/historywidget.cpp

HEADERS += \
    libs/muParser.h \
    libs/muParserBase.h \
    libs/muParserBytecode.h \
    libs/muParserCallback.h \
    libs/muParserComplex.h \
    libs/muParserDLL.h \
    libs/muParserDef.h \
    libs/muParserError.h \
    libs/muParserFixes.h \
    libs/muParserInt.h \
    libs/muParserStack.h \
    libs/muParserTest.h \
    libs/muParserToken.h \
    libs/muParserTokenReader.h \
    mainwindow.h \
    widgets/customButton.h \
    widgets/historywidget.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

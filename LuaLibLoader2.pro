TEMPLATE = lib
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

# include(qmake_modules/findPhysFS.pro)
# include(qmake_modules/findSFML.pro)
include(qmake_modules/findLuaJIT.pro)
include(qmake_modules/findLibraryLinker.pro)

SOURCES += \
    ExtensionFramework.cpp \
    ExtensionFactory.cpp

HEADERS += \
    ExtensionFramework.hpp \
    ExtensionFactory.hpp

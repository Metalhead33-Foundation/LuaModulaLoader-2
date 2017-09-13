# CONFIG(release, debug|release): LIBS += -lluajit
# CONFIG(debug, debug|release): LIBS += -lluajit
CONFIG(release, debug|release): LIBS += -lluajit-5.1
CONFIG(debug, debug|release): LIBS += -lluajit-5.1

INCLUDEPATH += "/usr/include/luajit-2.0/"
DEPENDPATH += "/usr/include/luajit-2.0/"

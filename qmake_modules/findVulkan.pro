# LIBS += -L"/home/user/Projects/SFML/lib"

CONFIG(release, debug|release): LIBS += -lvulkan
CONFIG(debug, debug|release): LIBS += -lvulkan
# CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-window-d -lsfml-system-d

# INCLUDEPATH += "/usr/include/SFML"
# DEPENDPATH += "/usr/include/SFML"

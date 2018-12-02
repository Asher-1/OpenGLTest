TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    glad.c \
    cubemaps_environment_mapping.cpp

INCLUDEPATH += D:/develop/tools/OpenGL/include \


CONFIG(debug, debug|release): {
    LIBS += -LD:/develop/tools/OpenGL/lib/Debug \
    -lopengl32 \
    -lglfw3dll \
    -lassimp \

} else:CONFIG(release, debug|release): {
    LIBS += -LD:/develop/tools/OpenGL/lib/Release \
    -lopengl32 \
    -lglfw3dll \
    -lassimp \
}

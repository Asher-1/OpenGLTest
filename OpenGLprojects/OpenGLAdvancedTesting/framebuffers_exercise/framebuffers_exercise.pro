TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    glad.c \
    framebuffers_exercise.cpp

INCLUDEPATH += G:/develop/OpenGL/include \


CONFIG(debug, debug|release): {
    LIBS += -LG:/develop/OpenGL/lib/Debug \
    -lopengl32 \
    -lglfw3dll \
    -lassimp \

} else:CONFIG(release, debug|release): {
    LIBS += -LG:/develop/OpenGL/lib/Release \
    -lopengl32 \
    -lglfw3dll \
    -lassimp \
}

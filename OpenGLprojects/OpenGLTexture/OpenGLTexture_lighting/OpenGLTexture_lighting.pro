TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    main.cpp \
    glad.c \

INCLUDEPATH += G:/develop/OpenGL/include

CONFIG(debug, debug|release): {
    LIBS += -LG:/develop/OpenGL/lib/Debug \
    -lopengl32 \
    -lglfw3dll \

} else:CONFIG(release, debug|release): {
    LIBS += -LG:/develop/OpenGL/lib/Release \
    -lopengl32 \
    -lglfw3dll \
}

HEADERS += \
    Shader.h \
    Camera.h



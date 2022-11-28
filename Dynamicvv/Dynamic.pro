QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
CONFIG += consoles
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += include/
VPATH += src/
SOURCES += \
    copypastecell.cpp \
    generar.cpp \
    inicio.cpp \
    main.cpp \
    copypaste.cpp \
    tabnew.cpp \
    sha256.cpp \
    Register.cpp \

HEADERS += \
    include/generar.h \
    include/copypastecell.h \
    include/copypaste.h \
    include/tabnew.h \
    include/Block.h \
    include/BlockChain.h\
    include/ChainHash.h\
    include/CircularArray.h\
    include/ForwardList.h\
    include/heap.h\
    include/Index.h\
    include/List.h\
    include/Node.h\
    include/Prueba.h\
    include/Register.h\
    include/data.csv \
    include/inicio.h \


FORMS += \
    ui/generar.ui \
    ui/inicio.ui \
    ui/copypastecell.ui \
    ui/tabnew.ui \
    ui/copypaste.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

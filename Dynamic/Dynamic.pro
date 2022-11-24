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
    dialog.cpp \
    main.cpp \
    copypaste.cpp \
    tabnew.cpp \
    window.cpp  ../sha256.cpp ../Register.cpp

HEADERS += \
    dialog.h \
    include/copypastecell.h \
    include/copypaste.h \
    include/tabnew.h \
    window.h ../sha256.h ../Block.h ../BlockChain.h ../ForwardList/List.h ../ForwardList/ForwardList.h ../ChainHash.h ../Register.h ../Index.h ../Vector/CircularArray.h ../AVL/avl.h AVL/node.h ../Vector/queue.h

FORMS += \
    dialog.ui \
    mainwindow.ui \
    ui/copypastecell.ui \
    ui/tabnew.ui \
    ui/copypaste.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

QT += testlib sql
QT -= gui

CONFIG += c++1z qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \ 
    main.cpp \
    tst_conversionsnamespace.cpp \
    tst_structtotuple.cpp \
    tst_tupletostruct.cpp \
    tst_typelist.cpp

INCLUDEPATH += ../TupleConversionsProject/TupleConversions

HEADERS += \
    tst_conversionsnamespace.h \
    tst_structtotuple.h \
    tst_tupletostruct.h \
    tst_typelist.h

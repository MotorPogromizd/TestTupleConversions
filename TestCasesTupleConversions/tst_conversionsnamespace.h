#pragma once

#include <QtTest>

//#include "jsonobject.h"
#include "conversions.h"

class ConversionsNamespace : public QObject
{
    Q_OBJECT

public:
    explicit ConversionsNamespace(){}//;
    ~ConversionsNamespace(){}//;

private slots:
    void initTestCase(){}//;
    void cleanupTestCase(){}//;

    void testTypeNames();
    void testTypeNames_data();

    void testDataValueBool();
    void testDataValueInt();
    void testDataValueInt64();
    void testDataValueDouble();
    //void testDataValueChar();
    void testDataValueQString();
    void testDataValueQDateTime();
    void testDataValueUnknown();

    void testDataValueType();
    void testDataValueType_data();

    void testIsLvalue();
    void testIsLvalue_data();

};





//QTEST_APPLESS_MAIN(ConversionsNamespace)

//#include "tst_conversionsnamespace.moc"

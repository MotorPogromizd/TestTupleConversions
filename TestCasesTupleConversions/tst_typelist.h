#pragma once

#include <QtTest>

class TestTypeList : public QObject
{
    Q_OBJECT
public:
    explicit TestTypeList(){}
    ~TestTypeList(){}

private slots:
    void initTestCase(){}
    void cleanupTestCase(){}

    void testListLength();
    void testListLength_data();

    void testHasType();
    void testHasType_data();

    void testTypeItemIndex();
    void testTypeItemIndex_data();

    void testValidIndex();
    void testValidIndex_data();

    void testTypeAtIndex();
    void testTypeAtIndex_data();

    void testTupleToTypeList();
    void testTupleToTypeList_data();
};


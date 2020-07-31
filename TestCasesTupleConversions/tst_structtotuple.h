#ifndef TST_STRUCTTOTUPLE_H
#define TST_STRUCTTOTUPLE_H

#include <QtTest>

class StructToTuple : public QObject
{
    Q_OBJECT

public:
    StructToTuple(){}
    ~StructToTuple(){}

private slots:
    void initTestCase(){}//;
    void cleanupTestCase(){}//;
    void testEmptyStruct();
    void testOneElementStruct();
    void testTwoElementsStruct();
    void testAllKnownTypesStruct();
    void testEmptyStructType();
    void testOneElementStructType();
    void testTwoElementsStructType();
    void testAllKnownTypesStructType();

    void testNestedStructType();
};

#endif // TST_STRUCTTOTUPLE_H

#ifndef TST_TUPLETOSTRUCT_H
#define TST_TUPLETOSTRUCT_H

#include <QtTest>

class TupleToStruct : public QObject
{
    Q_OBJECT
public:
    TupleToStruct(){}
    ~TupleToStruct(){}

signals:

private slots:
    void initTestCase(){}//;
    void cleanupTestCase(){}//;

    void testOneElementBracesConstructible();
    void testTwoElementsBracesConstructible();
    void testThreeElementsBracesConstructible();
    void testSixElementsBracesConstructible();

    void testOneElementBracesStrictlyConstructible();
    void testTwoElementsBracesStrictlyConstructible();
    void testThreeElementsBracesStrictlyConstructible();
    void testSixElementsBracesStrictlyConstructible();

    void testEmptyTuple();
    void testOneElementTuple();
    void testTwoElementsTuple();
    void testAllKnownTypesTuple();
    void testWrongTypesTuple();
    // TODO test with nested struct

};

#endif // TST_TUPLETOSTRUCT_H

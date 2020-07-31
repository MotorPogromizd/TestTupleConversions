#include "tst_tupletostruct.h"

#include "structconversions.h"

void TupleToStruct::testOneElementBracesConstructible() {
    struct Struct {
        int a;
    };
    bool constructible
            = StructConversions::IsBracesConstructible<
            Struct, int
            >::value;
    QVERIFY(constructible);
    bool notConstructible
            = StructConversions::IsBracesConstructible<
            Struct, QString
            >::value;
    QVERIFY(!notConstructible);
}

void TupleToStruct::testTwoElementsBracesConstructible() {
    struct Struct {
        int a;
        QString s;
    };
    bool constructible
            = StructConversions::IsBracesConstructible<
            Struct, int, QString
            >::value;
    QVERIFY(constructible);
    bool notConstructible
            = StructConversions::IsBracesConstructible<
            Struct, QString, int
            >::value;
    QVERIFY(!notConstructible);
}

void TupleToStruct::testThreeElementsBracesConstructible() {
    struct Struct {
        int a;
        QString s;
        double d;
    };
    bool constructible
            = StructConversions::IsBracesConstructible<
            Struct,
            int, QString, double
            >::value;
    QVERIFY(constructible);
    bool notConstructible
            = StructConversions::IsBracesConstructible<
            Struct,
            double, QString, int
            >::value;
    QVERIFY(!notConstructible);
}

void TupleToStruct::testSixElementsBracesConstructible() {
    struct Struct {
        int a;
        QString s;
        double d;
        qint64 i;
        bool b;
        QDateTime t;
    };
    bool constructible
            = StructConversions::IsBracesConstructible<
            Struct,
            int, QString, double,
            qint64, bool, QDateTime
            >::value;
    QVERIFY(constructible);
    bool notConstructible
            = StructConversions::IsBracesConstructibleV<
            Struct, QString, int
            >;
    QVERIFY(!notConstructible);
}

//////
void TupleToStruct::testOneElementBracesStrictlyConstructible() {
    struct Struct {
        int a;
    };
    bool constructible
            = StructConversions::IsBracesStrictlyConstructible<
            Struct, int
            >::value;
    QVERIFY(constructible);
    bool notConstructible
            = StructConversions::IsBracesStrictlyConstructible<
            Struct, QString // NOTE delete ", QString"
            >::value;
    QVERIFY(!notConstructible);
}

void TupleToStruct::testTwoElementsBracesStrictlyConstructible() {
    struct Struct {
        int a;
        QString s;
    };
    bool constructible
            = StructConversions::IsBracesStrictlyConstructible<
            Struct,
            int, QString
            >::value;
    QVERIFY(constructible);
    bool notConstructible
            = StructConversions::IsBracesStrictlyConstructibleV<
            Struct,
            int
            >;
    QVERIFY(!notConstructible);
}

void TupleToStruct::testThreeElementsBracesStrictlyConstructible() {
    struct Struct {
        int a;
        QString s;
        double d;
    };
    bool constructible
            = StructConversions::IsBracesStrictlyConstructible<
            Struct,
            int, QString, double
            >::value;
    QVERIFY(constructible);
    bool notConstructible
            = StructConversions::IsBracesStrictlyConstructible<
            Struct,
            int, QString
            >::value;
    QVERIFY(!notConstructible);
    bool notConstructible2
            = StructConversions::IsBracesStrictlyConstructible<
            Struct,
            int
            >::value;
    QVERIFY(!notConstructible2);
}

void TupleToStruct::testSixElementsBracesStrictlyConstructible() {
    struct Struct {
        int a;
        QString s;
        double d;
        qint64 i;
        bool b;
        QDateTime t;
    };
    bool constructible
            = StructConversions::IsBracesStrictlyConstructible<
            Struct,
            int, QString, double,
            qint64, bool, QDateTime
            >::value;
    QVERIFY(constructible);
    bool notConstructible
            = StructConversions::IsBracesStrictlyConstructible<
            Struct,
            int, QString, double
            >::value;
    QVERIFY(!notConstructible);
}


void TupleToStruct::testEmptyTuple() {
    std::tuple t{};
    struct Struct{};

    bool res = std::is_same<
            Struct,
            decltype(StructConversions::makeFromTuple<Struct>(t))
            >{};
    QVERIFY(res);
}

void TupleToStruct::testOneElementTuple() {
    int val = 1;
    std::tuple t{val};
    struct Struct{
        int a;
    };
    auto resVal = StructConversions::makeFromTuple<Struct>(t);
    QCOMPARE(val, resVal.a);
    bool res = std::is_same<
            Struct,
            decltype(resVal)
            >{};
    QVERIFY(res);
}

void TupleToStruct::testTwoElementsTuple() {
    int intVal = 1;
    double dVal = 6.5;
    std::tuple t{intVal, dVal};
    struct Struct {
        int a;
        double d;
    };
    auto resVal = StructConversions::makeFromTuple<Struct>(t);
    QCOMPARE(intVal, resVal.a);
    QCOMPARE(dVal, resVal.d);
    bool res = std::is_same<
            Struct,
            decltype(resVal)
            >{};
    QVERIFY(res);
}

void TupleToStruct::testAllKnownTypesTuple() {
    int intVal = 1;
    QString sVal = "ololo";
    double dVal = 6.5;
    qint64 iVal = Q_UINT64_C(89);
    bool bVal = true;
    QDateTime tVal = QDateTime::currentDateTime();
    std::tuple t{intVal, sVal, dVal, iVal, bVal, tVal};
    struct Struct {
        int a;
        QString s;
        double d;
        qint64 i;
        bool b;
        QDateTime t;
    };
    auto resVal = StructConversions::makeFromTuple<Struct>(t);
    QCOMPARE(intVal, resVal.a);
    QCOMPARE(sVal, resVal.s);
    QCOMPARE(dVal, resVal.d);
    QCOMPARE(iVal, resVal.i);
    QCOMPARE(bVal, resVal.b);
    QCOMPARE(tVal, resVal.t);
    bool res = std::is_same<
            Struct,
            decltype(resVal)
            >{};
    QVERIFY(res);
}

void TupleToStruct::testWrongTypesTuple() {
    int val = 1;
    std::tuple t{val};

    struct Struct {
        int a;
        char c;
    };

    auto s = StructConversions::makeFromTuple<Struct>(t);
    QCOMPARE(val, s.a);
}


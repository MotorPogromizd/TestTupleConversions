#include "tst_structtotuple.h"

#include <QDateTime>

#include "structconversions.h"


void StructToTuple::testEmptyStruct() {
    struct Struct {};
    Struct s;
    auto t = TupleConversions::makeTuple(s);

    QCOMPARE(std::tuple_size_v<decltype(t)>, 0);
}

void StructToTuple::testOneElementStruct() {    
    struct Struct {
        int a;
    };
    int val = 100;
    Struct s{val};
    auto t = TupleConversions::makeTuple(s);

    QCOMPARE(std::tuple_size_v<decltype(t)>, 1);
    QCOMPARE(std::get<0>(t), val);
}

void StructToTuple::testTwoElementsStruct() {
    struct Struct {
        int a;
        QDateTime t;
    };
    int val = 100;
    Struct s{val, QDateTime::currentDateTime()};
    auto t = TupleConversions::makeTuple(s);

    QCOMPARE(std::tuple_size_v<decltype(t)>, 2);
    bool test1 = std::is_same<std::tuple<int, QDateTime>, decltype(t)>{};
    QVERIFY(test1);
    QCOMPARE(std::get<0>(t), val);
    QCOMPARE(std::get<1>(t), s.t);
}

void StructToTuple::testAllKnownTypesStruct() {
    struct Struct {
        int i;
        double d;
        qint64 i64;
        bool b;
        QString s;
        QDateTime t;
    };
    int val = 100;
    Struct s{
        val, 4.6, quint64(6L), false, QString("str"), QDateTime::currentDateTime()
    };
    auto t = TupleConversions::makeTuple(s);

    QCOMPARE(std::tuple_size_v<decltype(t)>, 6);
    QCOMPARE(std::get<0>(t), s.i);
    QCOMPARE(std::get<1>(t), s.d);
    QCOMPARE(std::get<2>(t), s.i64);
    QCOMPARE(std::get<3>(t), s.b);
    QCOMPARE(std::get<4>(t), s.s);
    QCOMPARE(std::get<5>(t), s.t);
}




void StructToTuple::testEmptyStructType() {
    struct Struct {};
    Struct s{};
    auto t = TupleConversions::makeTuple(s);
    auto res = std::is_same<
            std::tuple<>,
            decltype(t)
            >{};
    QVERIFY(res);
}

void StructToTuple::testOneElementStructType() {
    struct Struct {
        int i;
    };

    Struct s{2};

    auto t = TupleConversions::makeTuple(s);
    auto res = std::is_same<
            std::tuple<
                int
                >,
            decltype(t)
            >{};
    QVERIFY(res);
    //QVERIFY(false);
}

void StructToTuple::testTwoElementsStructType() {
    struct Struct {
        int i;
        QDateTime j;
    };

    Struct s{2, QDateTime::currentDateTime()};

    auto t = TupleConversions::makeTuple(s);
    auto res = std::is_same<
            std::tuple<
                int,
                QDateTime
                >,
            decltype(t)
            >{};
    QVERIFY(res);

}

void StructToTuple::testAllKnownTypesStructType() {
    struct Struct {
        int i;
        double d;
        qint64 i64;
        bool b;
        QString s;
        QDateTime t;
    };
    int val = 100;
    Struct s{
        val, 4.6, quint64(6L), false, QString("str"), QDateTime::currentDateTime()
    };
    auto t = TupleConversions::makeTuple(s);
    bool test1 = std::is_same<std::tuple<int, double, qint64,
            bool, QString, QDateTime>, decltype(t)>{};
    QVERIFY(test1);

}

void StructToTuple::testNestedStructType() {
    struct Struct {
        struct Nested {int a;} nested;
        int i;
        int j;
    };

    Struct s{{1},2,3};

    auto t = TupleConversions::makeTuple(s);
    auto res = std::is_same<
            std::tuple<
                Struct::Nested,
                int,
                int
                >,
            decltype(t)
            >{};
    //Struct(t);
    QVERIFY(res);
}

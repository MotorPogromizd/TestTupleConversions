#include "tst_typelist.h"

#include "typelist.h"

void TestTypeList::testListLength() {
    QFETCH(size_t, test_size);
    QFETCH(size_t, result);

    QCOMPARE(test_size, result);
}

void TestTypeList::testListLength_data() {
    QTest::addColumn<size_t>("test_size");
    QTest::addColumn<size_t>("result");

    size_t count = 100u;

    using Conversions::TypeList;
    struct SomeStruct {
        int number;
    };

    enum SimpleEnum {
        SimpleEnumElement0,
        SimpleEnumElement1,
    };

    enum class ComplexEnum {
        ComplexEnumElement0,
        ComplexEnumElement1,
    };

    {
        using tl = TypeList<>;
        count  = tl::length;
    }
    QTest::addRow("Test empty list") << count << size_t(0u);

    {
        using tl = TypeList<int>;
        count  = tl::length;
    }
    QTest::addRow("Test one element list with primitive type")
            << count << size_t(1u);

    {
        using tl = TypeList<SomeStruct>;
        count  = tl::length;
    }
    QTest::addRow("Test one element list with complex type")
            << count <<  size_t(1u);

    {
        using tl = TypeList<SimpleEnum>;
        count  = tl::length;
    }
    QTest::addRow("Test one element list with enum type")
            << count <<  size_t(1u);

    {
        using tl = TypeList<ComplexEnum>;
        count  = tl::length;
    }
    QTest::addRow("Test one element list with enum type")
            << count <<  size_t(1u);

    {
        using tl = TypeList<int, int>;
        count  = tl::length;
    }
    QTest::addRow("Test two element list with primitive type")
            << count <<  size_t(2u);

    {
        using tl = TypeList<SomeStruct, SomeStruct>;
        count  = tl::length;
    }
    QTest::addRow("Test two element list with complex type")
            << count <<  size_t(2u);

    {
        using tl = TypeList<int, SomeStruct>;
        count  = tl::length;
    }
    QTest::addRow("Test two element list with combo type")
            << count <<  size_t(2u);

    {
        using tl = TypeList<int, SomeStruct, char>;
        count  = tl::length;
    }
    QTest::addRow("Test three element list")
            << count <<  size_t(3u);

    {
        using tl = TypeList<int, SomeStruct, char, QString>;
        count  = tl::length;
    }
    QTest::addRow("Test four element list")
            << count <<  size_t(4u);

    {
        using tl = TypeList<SomeStruct, int, QString, int, char, SomeStruct>;
        count  = tl::length;
    }
    QTest::addRow("Test six element list")
            << count <<  size_t(6u);



}

void TestTypeList::testHasType() {
    QFETCH(bool, contains_in_list);
    QFETCH(bool, must_contains);

    QCOMPARE(contains_in_list, must_contains);
}

void TestTypeList::testHasType_data() {
    QTest::addColumn<bool>("contains_in_list");
    QTest::addColumn<bool>("must_contains");

    bool result = false;

    using Conversions::TypeList;
    using Conversions::TypeChecker;

    struct SomeStruct {
        int number;
    };

    enum SimpleEnum {
        SimpleEnumElement0,
        SimpleEnumElement1,
    };

    enum class ComplexEnum {
        ComplexEnumElement0,
        ComplexEnumElement1,
    };

    {
        using tl = TypeList<>;
        result = TypeChecker<int, tl>::hasType;
    }
    QTest::addRow("Test empty list")
            << false << result;

    {
        using tl = TypeList<int>;
        result = TypeChecker<int, tl>::hasType;
    }
    QTest::addRow("Test one element list that contains int")
            << true << result;

    {
        using tl = TypeList<int>;
        result = TypeChecker<double, tl>::hasType;
    }
    QTest::addRow("Test one element list that not contains int")
            << false << result;

    {
        using tl = TypeList<SomeStruct>;
        result = TypeChecker<SomeStruct, tl>::hasType;
    }
    QTest::addRow("Test one element list that contains SomeStruct")
            << true << result;

    {
        using tl = TypeList<SomeStruct>;
        result = TypeChecker<double, tl>::hasType;
    }
    QTest::addRow("Test one element list that not contains SomeStruct")
            << false << result;

    {
        using tl = TypeList<SimpleEnum>;
        result = TypeChecker<SimpleEnum, tl>::hasType;
    }
    QTest::addRow("Test one element list that contains SimpleEnum")
            << true << result;

    {
        using tl = TypeList<SimpleEnum>;
        result = TypeChecker<int, tl>::hasType;
    }
    QTest::addRow("Test one element list that not contains SimpleEnum for int")
            << false << result;

    {
        using tl = TypeList<SimpleEnum>;
        result = TypeChecker<ComplexEnum, tl>::hasType;
    }
    QTest::addRow("Test one element list that not contains SimpleEnum for ComplexEnum")
            << false << result;

    {
        using tl = TypeList<SimpleEnum>;
        result = TypeChecker<SomeStruct, tl>::hasType;
    }
    QTest::addRow("Test one element list that not contains SimpleEnum for SomeStruct")
            << false << result;

    {
        using tl = TypeList<ComplexEnum>;
        result = TypeChecker<ComplexEnum, tl>::hasType;
    }
    QTest::addRow("Test one element list that contains ComplexEnum")
            << true << result;

    {
        using tl = TypeList<ComplexEnum>;
        result = TypeChecker<int, tl>::hasType;
    }
    QTest::addRow("Test one element list that not contains ComplexEnum for int")
            << false << result;

    {
        using tl = TypeList<ComplexEnum>;
        result = TypeChecker<SimpleEnum, tl>::hasType;
    }
    QTest::addRow("Test one element list that not contains ComplexEnum for SimpleEnum")
            << false << result;

    {
        using tl = TypeList<ComplexEnum>;
        result = TypeChecker<SomeStruct, tl>::hasType;
    }
    QTest::addRow("Test one element list that not contains ComplexEnum for SomeStruct")
            << false << result;

    {
        using tl = TypeList<int, SomeStruct>;
        result = TypeChecker<SomeStruct, tl>::hasType;
    }
    QTest::addRow("Test two element list that contains SomeStruct with second int")
            << true << result;

    {
        using tl = TypeList<SomeStruct, int>;
        result = TypeChecker<SomeStruct, tl>::hasType;
    }
    QTest::addRow("Test two element list that contains")
            << true << result;

    {
        using tl = TypeList<SomeStruct, int>;
        result = TypeChecker<double, tl>::hasType;
    }
    QTest::addRow("Test two element list that not contains")
            << false << result;

    {
        using tl = TypeList<int, SomeStruct>;
        result = TypeChecker<double, tl>::hasType;
    }
    QTest::addRow("Test two element list that not contains")
            << false << result;

}

void TestTypeList::testTypeItemIndex() {
    QFETCH(size_t, test_size);
    QFETCH(size_t, result);

    QCOMPARE(test_size, result);
}

void TestTypeList::testTypeItemIndex_data() {
    QTest::addColumn<size_t>("test_size");
    QTest::addColumn<size_t>("result");

    size_t index = 100u; // non-zero

    using Conversions::TypeList;
    using Conversions::ListIndex;
    struct SomeStruct {
        int number;
    };

    enum SimpleEnum {
        SimpleEnumElement0,
        SimpleEnumElement1,
    };

    enum class ComplexEnum {
        ComplexEnumElement0,
        ComplexEnumElement1,
    };

    {
        using tl = TypeList<int>;
        using li = ListIndex<int, tl>;
        index  = li::value;
    }
    QTest::addRow("Test one element list")
            << index <<  size_t(0u);

    {
        using tl = TypeList<SomeStruct>;
        using li = ListIndex<SomeStruct, tl>;
        index  = li::value;
    }
    QTest::addRow("Test one element list")
            << index <<  size_t(0u);

    {
        using tl = TypeList<SimpleEnum>;
        using li = ListIndex<SimpleEnum, tl>;
        index  = li::value;
    }
    QTest::addRow("Test one element list")
            << index <<  size_t(0u);

    {
        using tl = TypeList<ComplexEnum>;
        using li = ListIndex<ComplexEnum, tl>;
        index  = li::value;
    }
    QTest::addRow("Test one element list")
            << index <<  size_t(0u);

    {
        using tl = TypeList<int, SomeStruct>;
        using li = ListIndex<int, tl>;
        index  = li::value;
    }
    QTest::addRow("Test two element list")
            << index <<  size_t(0u);

    {
        using tl = TypeList<SomeStruct, int>;
        using li = ListIndex<int, tl>;
        index  = li::value;
    }
    QTest::addRow("Test two element list")
            << index <<  size_t(1u);

    {
        using tl = TypeList<int, SimpleEnum>;
        using li = ListIndex<int, tl>;
        index  = li::value;
    }
    QTest::addRow("Test two element list")
            << index <<  size_t(0u);

    {
        using tl = TypeList<SimpleEnum, int>;
        using li = ListIndex<int, tl>;
        index  = li::value;
    }
    QTest::addRow("Test two element list")
            << index <<  size_t(1u);

    {
        using tl = TypeList<int, SimpleEnum>;
        using li = ListIndex<SimpleEnum, tl>;
        index  = li::value;
    }
    QTest::addRow("Test two element list")
            << index <<  size_t(1u);

    {
        using tl = TypeList<SimpleEnum, int>;
        using li = ListIndex<SimpleEnum, tl>;
        index  = li::value;
    }
    QTest::addRow("Test two element list")
            << index <<  size_t(0u);

    {
        using tl = TypeList<int, ComplexEnum>;
        using li = ListIndex<int, tl>;
        index  = li::value;
    }
    QTest::addRow("Test two element list")
            << index <<  size_t(0u);

    {
        using tl = TypeList<ComplexEnum, int>;
        using li = ListIndex<int, tl>;
        index  = li::value;
    }
    QTest::addRow("Test two element list")
            << index <<  size_t(1u);

    {
        using tl = TypeList<int, ComplexEnum>;
        using li = ListIndex<ComplexEnum, tl>;
        index  = li::value;
    }
    QTest::addRow("Test two element list")
            << index <<  size_t(1u);

    {
        using tl = TypeList<ComplexEnum, int>;
        using li = ListIndex<ComplexEnum, tl>;
        index  = li::value;
    }
    QTest::addRow("Test two element list")
            << index <<  size_t(0u);

    {
        using tl = TypeList<SomeStruct, int>;
        using li = ListIndex<SomeStruct, tl>;
        index  = li::value;
    }
    QTest::addRow("Test two element list")
            << index <<  size_t(0u);

    {
        using tl = TypeList<int, SomeStruct>;
        using li = ListIndex<SomeStruct, tl>;
        index  = li::value;
    }
    QTest::addRow("Test two element list")
            << index <<  size_t(1u);

    {
        using tl = TypeList<SomeStruct, int, QString, int, char, SomeStruct>;
        using li = ListIndex<int, tl>;
        //qDebug() << li::Checker::hasType;
        index  = li::value;
    }
    QTest::addRow("Test six element list")
            << index <<  size_t(1u);

    {
        index = 0u;
        using tl = TypeList<SomeStruct, int, QString, int, char, SomeStruct>;
        index = Conversions::ListIndexV<int, tl>;
        //qDebug() << li::Checker::hasType;
        //index  = li::value;
    }
    QTest::addRow("Test six element list with ListIndexV")
            << index <<  size_t(1u);

}

void TestTypeList::testValidIndex() {
    QFETCH(bool, test_size);
    QFETCH(bool, result);

    QCOMPARE(test_size, result);
}

void TestTypeList::testValidIndex_data() {
    QTest::addColumn<bool>("test_size");
    QTest::addColumn<bool>("result");

    bool result = false;

    using Conversions::TypeList;
    using Conversions::ValidIndex;
    using Conversions::ValidIndexV;

    {
        using tl = TypeList<>;
        result = ValidIndex<tl, 0u>::value;
    }
    QTest::addRow("Test empty list 0")
            << false << result;

    {
        using tl = TypeList<>;
        result = ValidIndex<tl, 1u>::value;
    }
    QTest::addRow("Test empty list 1")
            << false << result;

    {
        using tl = TypeList<int>;
        result = ValidIndex<tl, 0u>::value;
    }
    QTest::addRow("Test one element list 0")
            << true << result;

    {
        using tl = TypeList<int>;
        result = ValidIndexV<tl, 1u>;
    }
    QTest::addRow("Test one element list 1")
            << false << result;



    {
        using tl = TypeList<int, double>;
        result = ValidIndex<tl, 0u>::value;
    }
    QTest::addRow("Test two element list 0")
            << true << result;

    {
        using tl = TypeList<int, double>;
        result = ValidIndex<tl, 1u>::value;
    }
    QTest::addRow("Test two element list 1")
            << true << result;

    {
        using tl = TypeList<int, double>;
        result = ValidIndex<tl, 2u>::value;
    }
    QTest::addRow("Test two element list 2")
            << false << result;
}

void TestTypeList::testTypeAtIndex() {
    QFETCH(bool, test_size);
    QFETCH(bool, result);

    QCOMPARE(test_size, result);

}

void TestTypeList::testTypeAtIndex_data() {
    QTest::addColumn<bool>("test_size");
    QTest::addColumn<bool>("result");

    bool result = false;

    using std::is_same_v;
    using Conversions::TypeList;
    using Conversions::TypeAt;
    using Conversions::TypeAtT;


    {
        using tl = TypeList<int>;
        using needed = TypeAt<tl, 0u>::Type;
        result = std::is_same_v<int, needed>;
    }
    QTest::addRow("Test one element list")
            << true << result;

    {
        using tl = TypeList<int, double>;
        using needed = TypeAt<tl, 0u>::Type;
        result = std::is_same_v<int, needed>;
    }
    QTest::addRow("Test two element list")
            << true << result;

    {
        using tl = TypeList<int, double>;
        using needed = TypeAt<tl, 1u>::Type;
        result = std::is_same_v<double, needed>;
    }
    QTest::addRow("Test two element list")
            << true << result;

    {
        using tl = TypeList<int, double, float>;
        using needed = TypeAt<tl, 0u>::Type;
        result = std::is_same_v<int, needed>;
    }
    QTest::addRow("Test three element list")
            << true << result;

    {
        using tl = TypeList<int, double, float>;
        using needed = TypeAt<tl, 1u>::Type;
        result = std::is_same_v<double, needed>;
    }
    QTest::addRow("Test three element list")
            << true << result;

    {
        using tl = TypeList<int, double, float>;
        using needed = TypeAtT<tl, 2u>;
        result = std::is_same_v<float, needed>;
    }
    QTest::addRow("Test three element list")
            << true << result;



}

void TestTypeList::testTupleToTypeList() {
    QFETCH(bool, test_size);
    QFETCH(bool, result);

    QCOMPARE(test_size, result);
}

void TestTypeList::testTupleToTypeList_data() {
    QTest::addColumn<bool>("test_size");
    QTest::addColumn<bool>("result");

    bool result = false;

    using Conversions::TypeList;
    using Conversions::TupleTypeList;
    struct SomeStruct {
        int number;
    };

    {
        using t = std::tuple<>;
        using tl = TupleTypeList<t>::Value;
        using needed = TypeList<>;
        result = std::is_same_v<tl, needed>;
    }
    QTest::addRow("Test empty tuple")
            << true << result;

    {
        using t = std::tuple<int>;
        using tl = TupleTypeList<t>::Value;
        using needed = TypeList<int>;
        result = std::is_same_v<tl, needed>;
    }
    QTest::addRow("Test one element tuple")
            << true << result;

    {
        using t = std::tuple<double>;
        using tl = TupleTypeList<t>::Value;
        using needed = TypeList<int>;
        result = std::is_same_v<tl, needed>;
    }
    QTest::addRow("Test one element tuple")
            << false << result;

    {
        using t = std::tuple<double>;
        using tl = TupleTypeList<t>::Value;
        using needed = TypeList<SomeStruct>;
        result = std::is_same_v<tl, needed>;
    }
    QTest::addRow("Test one element tuple")
            << false << result;

    {
        using t = std::tuple<double>;
        using tl = TupleTypeList<t>::Value;
        using needed = TypeList<>;
        result = std::is_same_v<tl, needed>;
    }
    QTest::addRow("Test one element tuple")
            << false << result;

    {
        using t = std::tuple<SomeStruct>;
        using tl = TupleTypeList<t>::Value;
        using needed = TypeList<SomeStruct>;
        result = std::is_same_v<tl, needed>;
    }
    QTest::addRow("Test one element tuple")
            << true << result;

    {
        using t = std::tuple<SomeStruct>;
        using tl = TupleTypeList<t>::Value;
        using needed = TypeList<>;
        result = std::is_same_v<tl, needed>;
    }
    QTest::addRow("Test one element tuple")
            << false << result;

    {
        using t = std::tuple<SomeStruct>;
        using tl = TupleTypeList<t>::Value;
        using needed = TypeList<double>;
        result = std::is_same_v<tl, needed>;
    }
    QTest::addRow("Test one element tuple")
            << false << result;

    {
        using t = std::tuple<int, double>;
        using tl = TupleTypeList<t>::Value;
        using needed = TypeList<int, double>;
        result = std::is_same_v<tl, needed>;
    }
    QTest::addRow("Test two element tuple")
            << true << result;

    {
        using t = std::tuple<int, double>;
        using tl = TupleTypeList<t>::Value;
        using needed = TypeList<double, int>;
        result = std::is_same_v<tl, needed>;
    }
    QTest::addRow("Test two element tuple")
            << false << result;

    {
        using t = std::tuple<int, double>;
        using tl = TupleTypeList<t>::Value;
        using needed = TypeList<int>;
        result = std::is_same_v<tl, needed>;
    }
    QTest::addRow("Test two element tuple")
            << false << result;

    {
        using t = std::tuple<int, double>;
        using tl = TupleTypeList<t>::Value;
        using needed = TypeList<double>;
        result = std::is_same_v<tl, needed>;
    }
    QTest::addRow("Test two element tuple")
            << false << result;

    {
        using t = std::tuple<int, double>;
        using tl = TupleTypeList<t>::Value;
        using needed = TypeList<SomeStruct, double>;
        result = std::is_same_v<tl, needed>;
    }
    QTest::addRow("Test two element tuple")
            << false << result;

    {
        using t = std::tuple<int, double>;
        using tl = TupleTypeList<t>::Value;
        using needed = TypeList<int, SomeStruct>;
        result = std::is_same_v<tl, needed>;
    }
    QTest::addRow("Test two element tuple")
            << false << result;

    {
        using t = std::tuple<SomeStruct, int, QString, int, char, SomeStruct>;
        using tl = TupleTypeList<t>::Value;
        using needed = TypeList<SomeStruct, int, QString, int, char, SomeStruct>;
        result = std::is_same_v<tl, needed>;
    }
    QTest::addRow("Test six element tuple")
            << true << result;

}

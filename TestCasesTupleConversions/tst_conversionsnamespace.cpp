#include "tst_conversionsnamespace.h"

void ConversionsNamespace::testTypeNames() {
    QFETCH(QString, test_size);
    QFETCH(QString, result);

    QCOMPARE(test_size, result);
}

void ConversionsNamespace::testTypeNames_data() {
    QTest::addColumn<QString>("test_size");
    QTest::addColumn<QString>("result");

    QString result;

    {
        result = Conversions::typeName<bool>();
    }
    QTest::addRow("Test bool") << result << QString("Bool");

    {
        result = Conversions::typeName<int>();
    }
    QTest::addRow("Test int") << result << QString("Integer");

    {
        result = Conversions::typeName<qint64>();
    }
    QTest::addRow("Test qint64") << result << QString("Int64");

    {
        result = Conversions::typeName<decltype(0LL)>();
    }
    QTest::addRow("Test long long") << result << QString("Int64");

    {
        result = Conversions::typeName<double>();
    }
    QTest::addRow("Test double") << result << QString("Double");

//    {
//        result = Conversions::typeName<char>();
//    }
//    QTest::addRow("Test double") << result << QString("Char");

    {
        result = Conversions::typeName<QString>();
    }
    QTest::addRow("Test QString") << result << QString("QString");

    {
        result = Conversions::typeName<QDateTime>();
    }
    QTest::addRow("Test QDateTime") << result << QString("QDateTime");

    {
        result = Conversions::typeName<QDate>();
    }
    QTest::addRow("Test QDate") << result << QString("Unknown");

    {
        result = Conversions::typeName<QTime>();
    }
    QTest::addRow("Test QTime") << result << QString("Unknown");

    {
        result = Conversions::typeName<float>();
    }
    QTest::addRow("Test float") << result << QString("Unknown");

    {
        result = Conversions::typeName<char>();
    }
    QTest::addRow("Test char") << result << QString("Unknown");

}

void ConversionsNamespace::testDataValueBool() {
    QCOMPARE(Conversions::toStoredDataValue(true), true);
    QCOMPARE(Conversions::toStoredDataValue(false), false);
}

void ConversionsNamespace::testDataValueInt() {
    QCOMPARE(Conversions::toStoredDataValue(5), 5);
    QCOMPARE(Conversions::toStoredDataValue(0), 0);
    QCOMPARE(Conversions::toStoredDataValue(INT_MAX), INT_MAX);
    QCOMPARE(Conversions::toStoredDataValue(INT_MIN), INT_MIN);
}

void ConversionsNamespace::testDataValueInt64() {
    QCOMPARE(Conversions::toStoredDataValue(qint64(5L)),
             qint64(5L));
    QCOMPARE(Conversions::toStoredDataValue(qint64(0L)),
             qint64(0L));
    QCOMPARE(Conversions::toStoredDataValue(qint64(INT64_MAX)),
             qint64(INT64_MAX));
    QCOMPARE(Conversions::toStoredDataValue(qint64(INT64_MIN)),
             qint64(INT64_MIN));
    //__INT64_C
}

void ConversionsNamespace::testDataValueDouble() {
    QCOMPARE(Conversions::toStoredDataValue(5.0), 5.0);
    QCOMPARE(Conversions::toStoredDataValue(0.0), 0.0);
    // TODO add border values
}

//void ConversionsNamespace::testDataValueChar() {
//    QCOMPARE(Conversions::dataValue('A'),
//             QString('A'));
//    QCOMPARE(Conversions::dataValue(char(0)),
//             QString(char(0)));
//    QCOMPARE(Conversions::dataValue(char(255)),
//             QString(char(255)));
//    QCOMPARE(Conversions::dataValue(char(-128)),
//             QString(char(-128)));
//}

void ConversionsNamespace::testDataValueQString() {
    QCOMPARE(Conversions::toStoredDataValue(QStringLiteral("Ololo")),
             QString("Ololo"));
}

void ConversionsNamespace::testDataValueQDateTime() {
    QDateTime dt(QDateTime::currentDateTime());
    QCOMPARE(Conversions::toStoredDataValue(dt),
             dt.toMSecsSinceEpoch());
}

void ConversionsNamespace::testDataValueUnknown() {
    QCOMPARE(Conversions::toStoredDataValue(0.5f),
             false);
    QCOMPARE(Conversions::toStoredDataValue('F'),
             false);
}

void ConversionsNamespace::testDataValueType() {
    QFETCH(bool, test_size);
    QFETCH(bool, result);

    QCOMPARE(test_size, result);
}

void ConversionsNamespace::testDataValueType_data() {
    QTest::addColumn<bool>("test_size");
    QTest::addColumn<bool>("result");

    bool val;
    val = std::is_same<
                decltype(Conversions::toStoredDataValue(true)),
                bool
                >{};
    QTest::addRow("Test bool") << val << true;
    val = std::is_same<
            decltype(Conversions::toStoredDataValue(false)),
            bool
            >{};
    QTest::addRow("Test bool false") << val << true;
    val = std::is_same<
            decltype(Conversions::toStoredDataValue(0)),
            int
            >{};
    QTest::addRow("Test int") << val << true;

    val = std::is_same<
                decltype(Conversions::toStoredDataValue(qint64(0L))),
                qint64
                >{};
    QTest::addRow("Test qint64") << val << true;

    val = std::is_same<decltype(Conversions::toStoredDataValue(0.0)), double>{};
    QTest::addRow("Test double") << val << true;

    //val = std::is_same<decltype(Conversions::dataValue('A')), QString>{};
    //QTest::addRow("Test char") << val << true;

    val = std::is_same<
                decltype(
                    Conversions::toStoredDataValue(
                        QString("ololo")
                        )
                    ),
                QString
                >{};
    QTest::addRow("Test QString") << val << true;

    QDateTime dt(QDateTime::currentDateTime());
    val = std::is_same<
            decltype(Conversions::toStoredDataValue(dt)),
            qint64>{};
    QTest::addRow("Test QDateTime") << val << true;

    val = !std::is_same<
                decltype(Conversions::toStoredDataValue("dt")),
                decltype(Conversions::alwaysFalse<decltype("dt")>{})>{};
    QTest::addRow("Test char*") << val << true;

    val = !std::is_same<decltype(Conversions::toStoredDataValue('A')), QString>{};
    QTest::addRow("Test char") << val << true;
}

void ConversionsNamespace::testIsLvalue() {
    QFETCH(bool, test_size);
    QFETCH(bool, result);

    QCOMPARE(test_size, result);
}

void ConversionsNamespace::testIsLvalue_data() {
    QTest::addColumn<bool>("test_size");
    QTest::addColumn<bool>("result");

    QTest::addRow("Test const reference") << Conversions::IsConstLvalueV<const int&> << true;
    QTest::addRow("Test const value") << Conversions::IsConstLvalueV<const int> << false;
    QTest::addRow("Test reverence") << Conversions::IsConstLvalueV<int&> << false;
    QTest::addRow("Test value") << Conversions::IsConstLvalueV<int> << false;
}

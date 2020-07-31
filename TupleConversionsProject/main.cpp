#include <QCoreApplication>

#include <tuple>
#include <type_traits>

#include <iostream>
#include <QDebug>

#include "TupleConversions/tupleconversions.h"
#include "TupleConversions/structconversions.h"
#include "TupleConversions/typelist.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    using Conversions::TypeList;
    using Conversions::TypeChecker;
    using Conversions::ListIndex;
    using Conversions::ListIndexV;

    using tl = TypeList<char, int, double>;
    using tc = TypeChecker<double, tl>;

    qDebug() << tc::hasType;

    using myint = int;
    auto val  = ListIndexV<myint, tl>;
    qDebug() << val;//li::value;

    return a.exec();
}

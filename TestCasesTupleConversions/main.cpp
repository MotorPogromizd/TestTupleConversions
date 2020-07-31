#include "tst_conversionsnamespace.h"
#include "tst_structtotuple.h"
#include "tst_tupletostruct.h"
#include "tst_typelist.h"


int main(int argc, char *argv[])
{
    {
        ConversionsNamespace cn;
        QTest::qExec(&cn, argc, argv);
    }
    {
        StructToTuple stt;
        QTest::qExec(&stt, argc, argv);
    }
    {
        TupleToStruct tts;
        QTest::qExec(&tts, argc, argv);
    }
    {
        TestTypeList ttl;
        QTest::qExec(&ttl, argc, argv);
    }
    return 0;
}

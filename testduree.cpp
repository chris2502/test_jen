#include "testduree.h"

void TestDuree::testIsCopyDuree(void)
{
    CPPUNIT_ASSERT(false == duree->isCopyDuree(*duree));
}

void TestDuree::setUp(void)
{
    duree = new Duree(3, 45, 59);
}

void TestDuree::tearDown(void)
{
   delete duree;
}

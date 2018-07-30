#include "testduree.h"

void TestDuree::testIsCopyDuree(void)
{
    CPPUNIT_ASSERT(true == duree->isCopyDuree(*duree));
}

void TestDuree::testOperatorPlus(void)
{
	Duree duree2(1, 2, 3);
        Duree dureeExpected(4, 48, 2);
	Duree dureeResult = *duree + duree2;
        CPPUNIT_ASSERT_EQUAL(dureeExpected.getHour(), dureeResult.getHour());
        CPPUNIT_ASSERT_EQUAL(dureeExpected.getMin(), dureeResult.getMin());
        CPPUNIT_ASSERT_EQUAL(dureeExpected.getSec(), dureeResult.getSec());
}

void TestDuree::testOperatorMoins(void)
{
    Duree duree2(1, 50, 3);
    Duree dureeExpected(1, 55, 56);
    Duree dureeResult = *duree - duree2;
    CPPUNIT_ASSERT_EQUAL(dureeExpected.getHour(), dureeResult.getHour());
    CPPUNIT_ASSERT_EQUAL(dureeExpected.getMin(), dureeResult.getMin());
    CPPUNIT_ASSERT_EQUAL(dureeExpected.getSec(), dureeResult.getSec());
}

void TestDuree::testOperatorEgal(void)
{
    Duree dureeExpected(2, 45, 59);

    CPPUNIT_ASSERT_EQUAL(*duree, *duree);
    CPPUNIT_ASSERT_EQUAL(dureeExpected, *duree);
}

void TestDuree::testOperatorDifferent(void)
{
    Duree dureeExpected(2, 45, 59);
    bool assertExpected = dureeExpected != *duree;
    CPPUNIT_ASSERT(true == assertExpected);
}

void TestDuree::setUp(void)
{
    duree = new Duree(3, 45, 59);
}

void TestDuree::tearDown(void)
{
   delete duree;
}

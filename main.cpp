//#include "test.h"
//#include "duree.h"
#include "testduree.h"


CPPUNIT_TEST_SUITE_REGISTRATION( TestDuree );

int main(int argc, char** argv)
{
    CPPUNIT_NS::TestResult testresult;
    CPPUNIT_NS::TestResultCollector collectedresults;
        testresult.addListener (&collectedresults);
            CPPUNIT_NS::BriefTestProgressListener progress;
        testresult.addListener (&progress);
    CPPUNIT_NS::TestRunner testrunner;
    testrunner.addTest (CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest ());
    testrunner.run(testresult);
    CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults, std::cerr);
    compileroutputter.write ();
    ofstream xmlFileOut("cppTestDureeResult.xml");
    XmlOutputter xmlOut(&collectedresults, xmlFileOut);
    xmlOut.write();
    return collectedresults.wasSuccessful() ? 0 : 1;

        /*displayTest();

	Duree duree1(2, 30, 40);
	Duree duree2(6, 30, 40);
	if(duree1 == duree2)
		cout << duree1 << "et" << duree2 << "sont égaux" << endl;
	else
		cout << duree1 << "et" << duree2 << "ne sont pas égaux" << endl;
	
	Duree duree3;
	cin >> duree3;

	if(duree1 == duree3)
		cout << duree1 << "et" << duree3 << "sont égaux" << endl;
	else
		cout << duree1 << "et" << duree3 << "ne sont pas égaux" << endl;
        Duree* listDuree = new (nothrow) Duree[3];
	if(listDuree != nullptr){
	listDuree[0] = duree1;
	listDuree[1] = duree2;
	listDuree[2] = duree3;
	
	for(int i=0 ; i<3; i++)
	{
		cout << listDuree[i];
	}
}


	cout << "--------"<<endl;

        cout <<"duree1: "<< duree1 << "/ duree2:" << duree2 << "/ duree3:" << duree3<<endl;
        Duree duree;

	for(int i=0 ; i<3; i++)
	{
		cout << listDuree[i];
                duree = duree + listDuree[i];
	}

        cout <<"sum = " << duree << endl;
        string result = (duree1.isCopyDuree(duree2))?"true":"false";
        cout <<"bool = " <<  result<< endl;
        delete[] listDuree;*/
	return 0;
}

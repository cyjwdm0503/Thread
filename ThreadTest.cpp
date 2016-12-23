#include "ThreadTest.h"
#include <iostream>
#include <ctime>
using namespace std;

int threadnum=0;

CThreadTest::CThreadTest():CThread()
{
	
	num = ++threadnum;
	
}

CThreadTest::~CThreadTest()
{

}

bool CThreadTest::ExitInstance()
{
	cout<<"CThreadTest::ExitInstance"<<num<<endl;

	glo->UnLock();
	return CThread::ExitInstance();
}

bool CThreadTest::InitInstance()
{
	//CMutex glo("test");
	glo->Lock();
	cout<<"CThreadTest::InitInstance"<<num<<endl;
	return CThread::InitInstance();
}

void CThreadTest::Run()
{

	srand(time(NULL));
	int ms = (rand()%5+1)*1000;
	cout<<num<<"SleepMs"<<ms<<endl;
	SleepMs(ms);
	cout<<"CThreadTest::Run"<<num<<endl;
}

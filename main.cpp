#include "ThreadTest.h"
#include <ctime>

int main(int,char**)
{

	CThreadTest test1;
	test1.Create();
	CThreadTest test2;
	test2.Create();
	CThreadTest test3;
	test3.Create();
	CThreadTest test4;
	test4.Create();
	CThreadTest test5;
	test5.Create();
	test5.Join();
	return 0;
}
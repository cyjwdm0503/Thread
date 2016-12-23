#include "Thread.h"
#include "Mutex.h"

static CMutex* glo =  new CMutex("TEST");

class CThreadTest:public CThread
{
public:
	CThreadTest();
	~CThreadTest();
	virtual bool ExitInstance();
	virtual bool InitInstance();
	virtual void Run();
private:
	int num;
};


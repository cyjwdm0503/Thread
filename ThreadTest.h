#include "Thread.h"
#include "Mutex.h"
#include "Semaphore.h"
static CSemaphore* glo =  new  CSemaphore(3,"TEST");

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


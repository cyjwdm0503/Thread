#ifndef THREAD_H
#define THREAD_H

#include "Common.h"

#ifdef UNIX
typedef unsigned long DWORD;
typedef pthread_t THREAD_HANDLE;
typedef void* LPVOID;
#elif WINDOWS
//typedef unsigned long DWORD;
typedef HANDLE THREAD_HANDLE;
#endif

class CThread
{
public:
	CThread();
	virtual ~CThread();
	bool Create(void);
	virtual bool ExitInstance();
	virtual bool InitInstance();
	virtual void Run();
	bool Join();
	void SleepMs(int ms);
	THREAD_HANDLE GetHandle();

#ifdef WINDOWS
	static DWORD WINAPI _ThreadEntry(LPVOID pParam);
#elif UNIX
	static void * _ThreadEntry(void *pParam);
#endif

private:
	THREAD_HANDLE  m_hThread;
	DWORD m_IDThread;

};

#endif
#ifndef MUTEX_H
#define MUTEX_H

#ifdef UNIX
#include "pthread.h"
#elif WINDOWS
#include <windows.h>
#endif

class CMutex
{
public:
	CMutex();
	CMutex(const char* name);
	~CMutex();
	void Lock();
	void UnLock();
	bool TryLock();

public:
#ifdef WINDOWS
	HANDLE m_lock;
#elif UNIX
	
#endif
};

#endif
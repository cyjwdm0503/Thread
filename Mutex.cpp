#include "Mutex.h"


CMutex::CMutex()
{
#ifdef WINDOWS
	m_lock =  CreateMutex(NULL,FALSE,NULL);
#elif UNIX
#endif
}

CMutex::CMutex( const char* name )
{
#ifdef WINDOWS
	m_lock =  CreateMutex(NULL,FALSE,name);
	if(m_lock != NULL)
	{
		if(GetLastError() == ERROR_ALREADY_EXISTS)
		{
			m_lock =  OpenMutex(MUTEX_ALL_ACCESS,FALSE,name);
		}
	}
#elif UNIX
#endif
}

CMutex::~CMutex()
{
#ifdef WINDOWS
	CloseHandle(m_lock);
#endif
}

void CMutex::Lock()
{
#ifdef WINDOWS
	WaitForSingleObject(m_lock,INFINITE);
#elif UNIX

#endif

}

void CMutex::UnLock()
{
#ifdef WINDOWS
	ReleaseMutex(m_lock);
#endif
}

bool CMutex::TryLock()
{
#ifdef WINDOWS
	return (WaitForSingleObject(m_lock,0) == WAIT_OBJECT_0);
#elif UNIX

#endif
}


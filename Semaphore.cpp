#include "Semaphore.h"
CSemaphore::CSemaphore( int count,const char* name)
{
#ifdef WINDOWS
	m_semap = CreateSemaphore(NULL,count,count,name);
	if(m_semap != NULL)
	{
		if(GetLastError() == ERROR_ALREADY_EXISTS)
		{
			m_semap = OpenSemaphore(SEMAPHORE_ALL_ACCESS,FALSE,name);
		}
	}
#else

#endif
}

void CSemaphore::Lock( void )
{
#ifdef WINDOWS
	WaitForSingleObject(m_semap,INFINITE);
#else

#endif // WINDOWS
}

void CSemaphore::UnLock()
{
#ifdef WINDOWS
	ReleaseSemaphore(m_semap,1,NULL);
#else

#endif // WINDOWS

}

bool CSemaphore::TryLock()
{
#ifdef WINDOWS
	return WaitForSingleObject(m_semap,0) == WAIT_OBJECT_0 ;
#else

#endif
}


#include "Thread.h"


CThread::CThread()
{
	m_IDThread = 0;
#ifdef UNIX
	m_hThread.p = NULL;
	m_hThread.x =  0;
#elif WINDOWS
	m_hThread = (THREAD_HANDLE)0;
#endif

}

CThread::~CThread()
{
	m_IDThread = 0;
#ifdef UNIX
	m_hThread.p = NULL;
	m_hThread.x =  0;
#elif WINDOWS
	m_hThread = (THREAD_HANDLE)0;
#endif
}

bool CThread::Create( void )
{
#ifdef UNIX
	
#elif WINDOWS
	m_hThread = ::CreateThread(NULL,0,_ThreadEntry,this,0,&m_IDThread);
#endif
	return true;
}

bool CThread::ExitInstance()
{
	return true;
}

bool CThread::InitInstance()
{
	return true;
}

void CThread::Run()
{

}

void CThread::SleepMs(int ms)
{
	::Sleep(ms);
}

THREAD_HANDLE CThread::GetHandle()
{
	return m_hThread;
}

#ifdef WINDOWS
DWORD WINAPI CThread::_ThreadEntry( LPVOID pParam )
{
	CThread* pthread = (CThread*)pParam;
	if(pthread != NULL)
	{
		if(pthread->InitInstance() != false)
		{
			pthread->Run();
		}
		pthread->ExitInstance();
	}
	return 0;
}
#elif UNIX
static void * _ThreadEntry(void *pParam)
{
	return NULL;
}
#endif


bool CThread::Join()
{
#ifdef WINDOWS
	return (WaitForSingleObject(GetHandle(),INFINITE) != 0);
#elif UNIX

#endif
}
//#define UNIX
#ifndef COMMON_H
#define COMMON_H


#ifdef UNIX
#include "pthread.h"
#elif WINDOWS
#include <windows.h>
#include <process.h>

#endif

#endif
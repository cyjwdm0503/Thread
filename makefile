

CC=g++
CFLAGS= -ldl -lpthread -g 
INCLUDE= -I.
alllob=main.o Thread.o ThreadTest.o Mutex.o


target:testmain
main.o:main.cpp
	$(CC) $(CFLAGS) -o $@ -c $<
Mutex.o: Mutex.cpp Mutex.h
	$(CC) $(CFLAGS) -o $@ -c $<

MutexGuard.o:MutexGuard.cpp MutexGuard.h
	$(CC) $(CFLAGS) -o $@ -c $<
Thread.o:Thread.cpp Thread.h
	$(CC) $(CFLAGS) -o $@ -c $<
testmain:$(alllob)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm *.o

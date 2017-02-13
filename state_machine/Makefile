
CC = clang++
CFLAGS = -g -c -std=c++11  


xmain : main.o motor.o StateMachine.o
	$(CC) -o $@ $<

main.o : main.cpp
	$(CC) $(CFLAGS) -o $@ $<

motor.o : Motor.cpp
	$(CC) $(CFLAGS) -o $@ $<

StateMachine.o : StateMachine.cpp
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f *.o
	rm -f xmain
	rm -f a.out


#EventData.h main main.cpp Makefile 
#Makefile# Makefile~ Motor.cpp Motor.h StateMachine.cpp StateMachine.h x.cpp

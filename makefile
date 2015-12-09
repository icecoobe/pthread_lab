
CFLAGS=-pthread -g -Wall

SOURCES= alarm.c alarm_fork.c alarm_thread.c \
	 thread_error.c

PROGRAMS=$(SOURCES:.c=)

all:$(PROGRAMS)

alarm:alarm.c
	$(CC) $(CCFLAGS) -o alarm alarm.c

alarm_fork:alarm_fork.c
	$(CC) $(CFLAGS) -o alarm_fork alarm_fork.c

alarm_thread: alarm_thread.c
	$(CC) $(CFLAGS) -o alarm_thread alarm_thread.c

thread_error: thread_error.c
	$(CC) $(CFLAGS) -o thread_error thread_error.c

clean:
	@rm -rf $(PROGRAMS) *.o

recompile:clean all

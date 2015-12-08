
CFLAGS=-pthread -g -Wall

SOURCES= alarm.c alarm_fork.c alarm_thread.c
PROGRAMS=$(SOURCES:.c=)

all:$(PROGRAMS)

alarm:alarm.c
	$(CC) $(CCFLAGS) -o alarm alarm.c

alarm_fork:alarm_fork.c
	$(CC) $(CFLAGS) -o alarm_fork alarm_fork.c

alarm_thread: alarm_thread.c
	$(CC) $(CFLAGS) -o alarm_thread alarm_thread.c

clean:
	@rm -rf $(PROGRAMS) *.o

recompile:clean all

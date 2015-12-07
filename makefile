
CFLAGS=-pthread -g -Wall

SOURCES= alarm.c alarm_fork.c alarm_thread.c
PROGRAMS=$(SOURCES:.c=)
alarm_thread: alarm_thread.c
	$(CC) $(CFLAGS) -o alarm_thread alarm_thread.c
	echo $(SOURCES)
clean:
	rm $(PROGRAMS)

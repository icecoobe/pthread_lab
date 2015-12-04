
CFLAGS=-pthread -g -Wall

SOURCES= alarm_thread.c
alarm_thread: alarm_thread.c
	$(CC) $(CFLAGS) -o alarm_thread alarm_thread.c
	echo $(SOURCES)
clean:
	rm alarm_thread

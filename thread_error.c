
#include <pthread.h>
#include <stdio.h>
#include <errno.h>
#include <string.h> // strerror

int main(int argc, char* argv[])
{
    pthread_t thread;
    int status;
    
    // Attempt to join with an uninitialized thread.
    // in many cases, it will return ESRCH(3): no such a thread
    // Maybe the thread id happens to be valid, it is almost certainly
    // that of the initial thread, which is running main().
    // in that case, we will get an EDEADLK(self-deadlock),
    // or it may hang. If it hangs, quit and try again.
    status = pthread_join(thread, NULL);
    if (status != 0)
    {
	fprintf(stderr, "error %d: %s\n", status , strerror(status));
    }
    return status;
}

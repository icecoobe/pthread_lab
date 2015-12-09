
#include <pthread.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    pthread_t thread = pthread_self();
    pthread_t thread2 = pthread_self();
    int ret = pthread_equal(thread, thread2);
    printf("current thread id:%d\n", thread);
    printf("current thread2 id:%d\nequal to thread2: %d\n", thread2, ret);
    return 0;
}

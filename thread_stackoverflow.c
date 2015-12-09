#include <pthread.h>
#include <stdio.h>
#include <string.h>

void* thread_proc(void*);

int main(void)
{
    //char array[10*1024*1024];

    pthread_t thread_id;
    int a;
    printf("main thread id: %d\n", pthread_self());
    int ret = pthread_create(&thread_id, NULL, thread_proc, &a);
    printf("status:%d (%s)\n", ret, strerror(ret));
    while (1)
    {
	sleep(1);
    }
    return 0;
}

/*
 * 进程的stack大小几乎是无限制的，但是线程则不是
 * TODO: 本代码中，主线程也不能使用10M的stack空间，也会提示segment falt
 *	 如何明显地证明线程中stack的限制呢,亦或者主线程和子线程无明显差别?
 */
void* thread_proc(void* args)
{
    char array[10*1024*1024];
    int* p = (int*)args;
    array[10*1024*1024 - 1] = 10;
    *p = array[10*1024*1024 - 1]; 

    printf("thread id: %d\n", pthread_self());
    pthread_detach(pthread_self());
    return array;
}

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
long long int n = 0;
void *thread_func(void* arg)
{
    printf("%d\n",pthread_self ()&0x7f00);
    for(int i = 0; i < 10000; ++i)
        ++n;
    pthread_exit(NULL);
}

int main()
{
    for(int i = 0; i < 10; ++i)
    {
        pthread_t pid;
        pthread_create(&pid, NULL, thread_func, NULL);
        pthread_join (pid, NULL); 
        pthread_detach(pid);
    }
    sleep(1); //等待所有线程正常退出
    printf("%d\n",n);
    return 0;
}
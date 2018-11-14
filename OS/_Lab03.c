#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex;	 	//全局互斥量
pthread_cond_t notfull;		//条件变量
//buffer.h
/*********************/
typedef int buffer_item;
#define BUFFER_SIZE 1000
#define OVER -1
/*********************/

/* the buffer */
buffer_item buffer[BUFFER_SIZE];
int readpos,writepos;
int main(int argc, char *argv[]){
    pthread_t prod_id,cons_id;
    // 1. Get command line arguments argv[1], argv[2], argv[3]
    // 2. Initialize buffer
    pthread_mutex_init(&mutex,NULL);
    pthread_cond_init(&notfull,NULL);
    // 3. Create producer thread(s)
    pthread_create(&prod_id,NULL,producer,NULL);
    // 4. Create consumer thread(s)
    pthread_create(&cons_id,NULL,consumer,NULL);
    // 5. Sleep
    pthread_join();
    pthread_join();
    // 6. Exit
    pthread_mutex_destroy(&mutex);	//摧毁互斥量
    return 0;
}

void *producer(void *param){
    buffer_item rand;
    for (int n=0;n<=BUFFER_SIZE;n++){
        
    }
}

void *consumer (void *param){
    buffer_item rand;
    
    while (TRUE){
        /* sleep for a random period of time */
        sleep(rand()%10);
        if (remove_item(&rand))
        	fprintf("report error condition");
        else 
            printf("consumer consumed %f\n",rand);        
    }
}














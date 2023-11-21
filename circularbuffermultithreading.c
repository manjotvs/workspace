#include <stdio.h>
#include <stdint.h>
#include <semaphore.h>
#include <pthread.h>
//#undef __deprecated
#define N 3

int b[N];
uint32_t in = 0, out = 0;
pthread_mutex_t lock;
sem_t *s1,*s2;


void init() 
{ 
    if (pthread_mutex_init(&lock, NULL) != 0) { 
        printf("\n mutex init has failed\n"); 
    } 
    s1 = sem_open("sa", O_CREAT|O_EXCL, 0644, N);
    if(s1 ==SEM_FAILED)
        printf("FAiled\n");
    s2 = sem_open("sb", O_CREAT|O_EXCL, 0644, 0);
    if(s2 ==SEM_FAILED)
        printf("FAiled\n");
    sem_unlink ("sa");  
    sem_unlink ("sb");  
}

void enqueue(int value) 
{
    sem_wait( s1 );
    pthread_mutex_lock(&lock); 
    printf("enqueue\n");
    b[in] = value;
    in = (in + 1) % (N);
    pthread_mutex_unlock(&lock);
    sem_post(s2);
}
int dequeue(){
    int ret = sem_wait(s2);
    //sem_getvalue(s2,&ret);
    printf("Ret: %d\n",ret );
    pthread_mutex_lock(&lock);
    int result = b[out];
    out = (out +1) % (N);
    pthread_mutex_unlock(&lock);
    sem_post(s1);
    return result;
}

void display()
{
    uint8_t i = 0;
    printf("Current Elements in buffer:");
    while(i < N)
    {
        printf(" %d", b[i++]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    init();
    enqueue(1);
    enqueue(2);
    enqueue(3);
    //display();
    //enqueue(4);
    //enqueue(5);
    //display();
    printf("%d\n",dequeue() );
    printf("%d\n",dequeue() );
    printf("%d\n",dequeue() );
    printf("%d\n",dequeue() );
    printf("%d\n",dequeue() );
    sem_close(s1);
    sem_close(s2);
    return 0;
}
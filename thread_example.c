#include <stdio.h>
#include <pthread.h>

pthread_mutex_t lock;

void *inc()
{
static int count;
	
	pthread_mutex_lock(&lock);
	for(int i=0;i<9000000;i++)
	{

		count++;

	}
	printf("%d\n", count);

	pthread_mutex_unlock(&lock);
	return NULL;
}

int main()
{
	pthread_t thread1;
	pthread_t thread2;
	if (pthread_mutex_init(&lock, NULL) != 0) { 
        printf("\n mutex init has failed\n"); 
        return 1; 
    } 
	if(pthread_create(&thread1, NULL, inc, NULL) !=0)
		printf("Cannot Create thread1\n");
	if(pthread_create(&thread2, NULL, inc, NULL) !=0)
		printf("Cannot Create thread2\n");
	//pthread_join(thread1, NULL);
	//pthread_join(thread2, NULL);
	while(1);
    pthread_mutex_destroy(&lock); 
	return 0;
}
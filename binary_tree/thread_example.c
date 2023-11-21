#include <stdio.h>
#include <pthread.h>

void* inc(void*)
{
	static int count;
	for(int i=0;i<10;i++)
		count++;
	printf("%d\n", count);
}

int main()
{
	pthread_t thread1;
	pthread_t thread2;
	pthread_create(thread1, NULL, &inc, NULL);
	pthread_create(thread2, NULL, &inc, NULL);
	return 0;
}
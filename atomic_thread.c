#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>

#define BIG_NUM 1000000
#if __STDC_NO_ATOMIC__==1
#error "HELP"
#endif

uint64_t _Atomic x = 0;
void count_to_big()
{
	for(int i=0;i<BIG_NUM;i++)
	{
		x+=i;
	}
}
void* thread_func()
{
	//count_to_big();
		for(int i=0;i<BIG_NUM;i++)
	{
		 x+=i;
	}
	return NULL;
}

int main()
{
	pthread_t t1,t2;
	int p1 = pthread_create(&t1, NULL, thread_func, NULL);
	int p2 = pthread_create(&t1, NULL, thread_func, NULL);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	printf("%llu\n",x);
	return 0;

}
#include <stdio.h>


int cal_fb_memorization(int N, int *lt)
{
	if(lt[N] == -1)
	{
   		if( N<=1)
   		{
   			lt[N] = N;
   			return N;
   		}
   		else
   		{
   			lt[N] = cal_fb_memorization(N-1, lt) + cal_fb_memorization(N-2, lt);
   		}
	}
	return lt[N];
}


int fib_memorization(int N)
{
    int lt[N+1];
    int i = 0;
    while(i < N+1)
        lt[i++] = -1;
    return(cal_fb_memorization(N, lt));

}

int fib(int N)
{
	int lt[N];
	lt[0] = 0;
	lt[1] = 1;
	for(int i = 2; i < N+1; i++)
	{
		lt[i] = lt[i-1] + lt[i-2];
	}
	return lt[N];
}

int main()
{
	int n = 30;
	printf("%d\n",fib(n));
	printf("%d\n",fib_memorization(n));
	return 0;
}
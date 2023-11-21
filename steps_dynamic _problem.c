#include <stdio.h>


int solve(int n) 
{  
   // base case 
   if (n < 0)  
      return 0; 
   if (n == 0)   
      return 1;   
  
   return solve(n-1) + solve(n-3) + solve(n-5); 
}   

int lt[50];
int solve_memorization(int n) 
{  
    if (n < 0)  
    	return 0; 
    if(lt[n] == -1)
    {
    	if(n  == 0)
    	{
    		lt[n] = 1;
    		return lt[n];
    	}
		lt[n] = (solve_memorization(n-1)+solve_memorization(n-3)+solve_memorization(n-5) );
		
	}
  
	return lt[n];
}   



int main()
{
	int n =0;
	for(int i=0; i<50; i++)
		lt[i] = -1;
	printf("%d\n",solve(n));
	printf("%d\n",solve_memorization(n));
	return 0;
}
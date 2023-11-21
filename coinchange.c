#include <stdio.h>
#include <stdlib.h>
//#include <stdlib.h>
#include <string.h>

#define MIN_NUM(x, y) (((x) < (y)) ? (x) : (y))

int coinChange(int* coins, int coinsSize, int amount){
    coinsSize++;
    amount++;
    printf("coinsSize: %d %d\n",coinsSize,amount);
    int **table = (int **)malloc(coinsSize * sizeof(int *)); 
    int i = 0;
    for (i=0; i<coinsSize; i++) 
    {
        table[i] = (int *)malloc(amount * sizeof(int));
        memset(&table[i][0], 0x00, amount * sizeof(uint8_t) );
    }
    printf("hjoijoi\n");
//      int  count = 0; 
// int j;
//     for (i = 0; i <  coinsSize; i++) 
//       for (j = 0; j < amount; j++) 
//          table[i][j] = ++count;  // OR *(*(arr+i)+j) = ++count 
  
//     for (i = 0; i <  coinsSize; i++) 
//       for (j = 0; j < amount; j++) 
//          printf("%d ", table[i][j]);
    int j = 1;
    for(i=1;i<coinsSize;i++)
    {
        for(j=1;j<amount;j++)
        {
            printf("I1: %d J1:%d\n",i,j);
            if(coins[(i-1)]>j)
            {
                table[i][j] = table[(i-1)][j];
            }
            else
            {
                printf("hi\n");
                table[i][j] = MIN_NUM(table[i-1][j] , (table[i][j-coins[i]])+1);
            }
        }
    }
    printf("hello");
    int ret = table[coinsSize-1][amount-1];
    free(table);
   return ret;

}

int main()
{
    int coins[] = {1,2,5};
    int amount = 11;
    printf("ANSWER: %d\n", coinChange(coins,sizeof(coins)/sizeof(coins[0]),amount));
    return 0;
}
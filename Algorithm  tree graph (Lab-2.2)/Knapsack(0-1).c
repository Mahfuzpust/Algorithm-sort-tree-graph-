//0-1 Knapsack
#include<stdio.h>

int max(int a, int b)
{
    return (a > b)? a : b;
}
int knapSack(int w, int wt[], int val[], int n)
{
   int i, j;
   int array[n+1][w+1];
   for (i = 0; i <= n; i++)
   {
       for (j =0; j<=w; j++)
       {
           if (i==0 || j==0)
               array[i][j] = 0;
           else if (wt[i-1] <= j)
                 array[i][j] = max(val[i-1] + array[i-1][j-wt[i-1]],  array[i-1][j]);
           else
                 array[i][j] = array[i-1][j];
       }
   }
   return array[n][w];
}


int main()
{
    int i, n, val[20], wt[20], W;

    printf("Enter number of items:");
    scanf("%d", &n);

    printf("Enter value and weight of items:\n");
    for(i = 0;i < n; ++i){
        scanf("%d%d", &val[i], &wt[i]);
    }

    printf("Enter size of knapsack:");
    scanf("%d", &W);

    printf("%d", knapSack(W, wt, val, n));
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    int m; //m= number of chocolates in each selection done by akshit
    int t; //t = number of test cases
    int *n = malloc(sizeof(int)); //n= pointer that points to number of chocolates
    int i;
   scanf("%d",&t);
    
    for(i=0;i<t;i++)
    scanf("%d",(n+i));
    
    for(i=0;i<t;i++)
    {
        m = (*(n+i)/2)+1;
        printf("%d\n",m);
    }
    return 0;
   
}
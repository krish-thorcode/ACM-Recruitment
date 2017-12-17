#include<stdio.h>

int main()
{
    int x;
    scanf("%d",&x);
    int count;
    int aux_x;
 
    do
    {
        count = 0;
        for(aux_x=x,count=0; aux_x!=0; aux_x = (aux_x & (aux_x<<1)),count++)
            continue;
        
        if(count != 1)
            x++;

     }while(count != 1);

     printf("%d\n",x);
     return 0;
}



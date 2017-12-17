#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *x = (int*)malloc(sizeof(int)); //pointer to point to each number given in each test case
    int test_cases,i;
    scanf("%d",&test_cases);
    
    for(i=0;i<test_cases;i++)
        scanf("%d",(x+i));
    
    int count;
    int aux_x;
    
    for(i=0;i<test_cases;i++)
    {    
        do
        {
            count = 0;
            for(aux_x=*(x+i),count=0; aux_x!=0; aux_x = (aux_x & (aux_x<<1)),count++)
                continue;
            
            if(count != 1)
                (*(x+i))++;

         }while(count != 1);
    }

    for(i=0;i<test_cases;i++)
        printf("%d\n",*(x+i));
    return 0;
}



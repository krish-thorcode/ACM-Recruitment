#include<stdio.h>
#include<stdlib.h>
int main()
{
	unsigned long int size, no_of_oper;
	scanf("%lu%lu",&size,&no_of_oper);

	unsigned long int pos1,pos2;

	unsigned long long int k;

	long double arr[size];

	long int i,j;

	for(i=0;i<size;i++)
		arr[i] = 0;

	for(i=0;i<no_of_oper;i++)
	{
        scanf("%lu%lu%llu",&pos1,&pos2,&k);
        
        for(j=pos1-1;j<pos2;j++)
		  arr[j] += k;
	}

	unsigned long double max = arr[0];

	for(i=1;i<size;i++)
	{
		if(max<(arr[i]))
			max = arr[i];
	}

	printf("%lf\n",max%1000000007);

	return 0;
}
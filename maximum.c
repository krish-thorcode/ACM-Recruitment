#include<stdio.h>
#include<stdlib.h>
int main()
{
	int size, no_of_oper;
	scanf("%d%d",&size,&no_of_oper);

	int pos1,pos2,k;
	

	int arr[size];

	int i,j;

	for(i=0;i<size;i++)
		arr[i] = 0;

	for(i=0;i<no_of_oper;i++)
	{
        scanf("%d%d%d",&pos1,&pos2,&k);
        
        for(j=pos1-1;j<pos2;j++)
		  arr[j] += k;
	}

	int max = arr[0];

	for(i=1;i<size;i++)
	{
		if(max<(arr[i]))
			max = arr[i];
	}

	printf("%d",max%1000000007);

	return 0;
}
#include<stdio.h>
#define MAX 1000000
#define DIV 1000000007
#define MAX_OP 100000

int main()
{
	unsigned long long int arr[MAX];
	unsigned long int no_of_operations;
	unsigned long int i,j,size;
	
	scanf("%lu",&size);
	scanf("%lu",&no_of_operations);

	unsigned long int a[no_of_operations],b[no_of_operations],k[no_of_operations];
	
	for(i=0;i<no_of_operations;i++)
		arr[i] = 0;
	
	
	for(i=0;i<no_of_operations;i++)
		scanf("%lu%lu%lu",&a[i],&b[i],&k[i]);

	i=0;
	for(j=a[i];j<=b[i];)
   {
		arr[j-1] += k[i];
		i++;
		j=a[i];
           //if(arr[j-1]>=DIV)
               //arr[j-1] %= DIV;
		if(i+1 == no_of_operations)
			break;
    }
	
		
	unsigned long long int max = arr[0];
	
	for(i=1;i<size;i++)
	{
		if(max < arr[i])
			max = arr[i];
	}
	
	printf("%llu\n",(max%DIV));
		
	return 0;
}
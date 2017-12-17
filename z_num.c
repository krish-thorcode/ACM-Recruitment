#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
	int test_cases;
	int *term = (int*)malloc(sizeof(int));

	scanf("%d",&test_cases);

	int *a,*b,*n;
	int aux_a,aux_b,c;
	a=(int*)malloc(sizeof(int));
	b=(int*)malloc(sizeof(int));
	n=(int*)malloc(sizeof(int));
	
	int i;

	for(i=0;i<test_cases;i++)
	{
		scanf("%d",(a+i))
		scanf("%d",(b+i))
		scanf("%d",(n+i))
	}

	for(i=0;i<test_cases;i++)
	{
		aux_a = *(a+i);
		aux_b = *(b+i);

		c = aux_b + 2*aux_a;
		aux_a=aux_b;
		aux_b=c;
	}

	return 0;
}
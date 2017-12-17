#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
	int test_cases;
	int *term = (int*)malloc(sizeof(int));

	scanf("%d",&test_cases);

	int a,b,i,n,c,j;

	//for(i=0;i<test_cases;i++)
	//{
		
		i=0,j=0;
		do//(j=0;j<n-1 && test_cases != 0;j++,test_cases--)
		{
			scanf("%d%d%d",&a,&b,&n);
			c = b + 2*a;
			a=b;
			b=c;
			j++;
			*(term+i++) = b;
		}while(j<n-1 && i<test_cases);

		
	//}

	for(i=0;i<test_cases;i++)
		printf("%d\n",*(term+i));


	return 0;
}
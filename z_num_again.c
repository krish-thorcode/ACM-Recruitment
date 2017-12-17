#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
	int test_cases,flag1=0,flag2=0;
	long long int *term = (long long int*)malloc(sizeof(long long int));

	scanf("%d",&test_cases);

	long int i,j,n;
	long long int c,a,b;

	if(test_cases>1 && test_cases < 10000)
	{
		flag1=1;
		for(i=0;i<test_cases;i++)
		{
			scanf("%lld%lld%ld",&a,&b,&n);

			if((a<1000000000)&&(b<1000000000)&&(n<1000000000))
			{
				flag2 = 1;
				for(j=0;j<n-1;j++)
				{
					c = b + 2*a;
					a=b;
					b=c;
				}

				*(term+i) = b;
			}
		}
	}

	if(flag1 == 1 && flag2 == 1)
	{
	//	puts("haha");
		for(i=0;i<test_cases;i++)
			printf("%lld\n",(*(term+i))%10000000009);
	}

	return 0;
}
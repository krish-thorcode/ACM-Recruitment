#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int find_term(int first, int n, int i)
{
	if(n==1)
		return 2;
	
	int second = first + pow(4, i-2);
	
	if( i == n+1 )
		return second;
	
	find_term(second,n,++i);

	return ;
}


int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	
	int i;
	
	int *term_n = (int*)malloc(sizeof(int));
	
	int a,b,n,coeff_n;
	int even_coeff_f0,even_coeff_f1;
	int odd_coeff_f0,odd_coeff_f1;
	
	if(test_cases>1 && test_cases < 10000)
	{
		for(i=0;i<test_cases;i++)
		{
			scanf("%d%d%d",&a,&b,&n);
			if((1<a<1000000000)&&(1<b<1000000000)&&(1<n<1000000000))
			{
				if( n%2 ==0 )
				{
					coeff_n = find_term(1,(n/2),2);
					//printf("%d\n",term_n);
					even_coeff_f0 = coeff_n;
					even_coeff_f1 = coeff_n - 1;
					
					*(term_n+i) = even_coeff_f0*a + even_coeff_f1*b;
					//printf("%d\n",term_n);
				}
				
				else
				{
					coeff_n = find_term(1,(n/2),2);
					//printf("%d\n",term_n);
					even_coeff_f0 = coeff_n;
					even_coeff_f1 = coeff_n - 1;
					
					odd_coeff_f1 = even_coeff_f0 + even_coeff_f1 ;
					odd_coeff_f0 = odd_coeff_f1 - 1;
					
					*(term_n+i) = odd_coeff_f0*a + odd_coeff_f1*b;
					//printf("%d\n",term_n);
				}
			}
		}
	}
	
	for(i=0;i<test_cases;i++)
		printf("%d\n",*(term_n+i));
	
	return 0;
}
		
#include<stdio.h>
#include<stdlib.h>

unsigned long long int M[2][2] = {{1,2},{1,0}};

unsigned long long int a,b; //base values, a = f(0),b=f(1)

int multiply(unsigned long long int F[2][2], unsigned long long int M[2][2])
{
  int first=  ((F[0][0])*(M[0][0])%1000000009) + ((F[0][1])*(M[1][0])%1000000009);
 int second =  ((F[0][0])*(M[0][1])%1000000009) +  ((F[0][1])*(M[1][1])%1000000009);
 int third =  ((F[1][0])*(M[0][0])%1000000009) + ((F[1][1])*(M[1][0])%1000000009);
 int fourth =  ((F[01][0])*(M[0][01])%1000000009)+ ((F[01][01])*(M[1][1])%1000000009);
 
  F[0][0] = first%1000000009;
  F[0][1] = second%1000000009;
  F[1][0] = third%1000000009;
  F[1][1] = fourth%1000000009;
  return 0;
}

int power_and_find_term(unsigned long long int F[2][2], unsigned long long int n)
{
  if( n == 0 )
      return 0;
  else if (n==1)
    return 0;
 
  
  power_and_find_term(F, n/2);//Recursively calculates the power of the matrix.
  multiply(F, F);//Doess F^2 n.2 times Therefore givimng me F
 
  if (n%2 != 0)
     multiply(F, M);//IF n is not a perfect a multiple of two we lose out a factor of 1 due to integer division This accounts for it.

 unsigned long long int base_matrx[2][1] = {{b},{a}};


		int first = ((F[0][0])*(base_matrx[0][0])%1000000009) + ((F[0][1])*(base_matrx[1][0])%1000000009);
	
	return first;
}



unsigned long long int find_term(unsigned long long int n)
{
	unsigned long long int C[2][2] = {{1,2},{1,0}};//since f(n) = f(n-1) +2(f(n-2)), in A = C*B, C = {{1,2},{1,0}}
	unsigned long long int term = power_and_find_term(C,n-1);
	return term;
}


int main()
{
	int test_cases;
	scanf("%d",&test_cases);

	int i;
	unsigned long long int n,terms[test_cases]; //a = f(0),b=f(1), ie, the base values
	//terms = (unsigned long long int*)malloc(sizeof(unsigned long long int));

	
	for(i=0;i<test_cases;i++)
	{
		scanf("%lld%lld%lld",&a,&b,&n);

		terms[i] = find_term(n);

	}

	for(i=0;i<test_cases;i++)
		printf("%lld\n",terms[i]%1000000009);

	return 0;
}
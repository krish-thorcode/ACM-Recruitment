#include<stdio.h>
#include<stdlib.h>


unsigned long long int a,b; //base values, a = f(0),b=f(1)

unsigned long long int power_and_find_term(unsigned long long int F[2][2],unsigned long long int n)
{
	int i,first,second,third,fourth;
	unsigned long long int M[2][2] = {{1,2},{1,0}}; //for multiplying in the loop
	for(i=0;i<n-1;i++) //i<n-1 since for eg, pow=3 will be found when matrix will be multiplied twice with itself
	{
		first=  ((F[0][0]%1000000009)*(M[0][0]%1000000009)%1000000009) + ((F[0][1]%1000000009)*(M[1][0]%1000000009)%1000000009);
		second =  ((F[0][0]%1000000009)*(M[0][1]%1000000009)%1000000009) +  ((F[0][1]%1000000009)*(M[1][1]%1000000009)%1000000009);
		third =  ((F[1][0]%1000000009)*(M[0][0]%1000000009)%1000000009) + ((F[1][1]%1000000009)*(M[1][0]%1000000009)%1000000009);
		fourth =  ((F[01][0]%1000000009)*(M[0][01]%1000000009)%1000000009)+ ((F[01][01]%1000000009)*(M[1][1]%1000000009)%1000000009);
		F[0][0] = first%1000000009;
		F[0][1] = second%1000000009;
		F[1][0] = third%1000000009;
		F[1][1] = fourth%1000000009;
	}

	//printf("%d\n",first);

	unsigned long long int base_matrx[2][1] = {{b},{a}};

	for(i=0;i<2;i++)
		first = ((F[0][0]%1000000009)*(base_matrx[0][0]%1000000009)%1000000009) + ((F[0][1]%1000000009)*(base_matrx[1][0]%1000000009)%1000000009);
	
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
	unsigned long long int n,*terms; //a = f(0),b=f(1), ie, the base values
	terms = (unsigned long long int*)malloc(sizeof(unsigned long long int));

	
	for(i=0;i<test_cases;i++)
	{
		scanf("%lld%lld%lld",&a,&b,&n);

		*(terms+i) = find_term(n);

	}

	for(i=0;i<test_cases;i++)
		printf("%lld\n",*(terms+i));
}
// C++ implementation of simple approach to
// find maximum value after m range increments.
#define MAX 1000000
#define DIV 1000000007
#define MAX_OP 100000
#include<bits/stdc++.h>
using namespace std;

// Function to find maximum value after 'm' operations
unsigned long long int findMax(unsigned long long int n, unsigned long long int m, unsigned long long int a[], unsigned long long int b[], unsigned long long int k[])
{
	unsigned long long int arr[n+1];
	memset(arr, 0, sizeof(arr));

	// Start performing 'm' operations
	for (unsigned long long int i=0; i<m; i++)
	{
		// Store lower and upper index i.e. range
		unsigned long long int lowerbound = a[i];
		unsigned long long int upperbound = b[i];

		// Add k to the lower_bound
		arr[lowerbound] += k[i];

		// Reduce upper_bound+1 indexed value by k
		arr[upperbound+1] -= k[i];
	}

	// Find maximum sum possible from all values
	long long sum = 0, res = INT_MIN;
	for (unsigned long long int i=0; i < n; ++i)
	{
		sum += arr[i];
		res = max(res, sum);
	}

	// return maximum value
	return res;
}

// Driver code
int main()
{
	// Number of values
	unsigned long long int n,m;
    cin>>n>>m;
    
    unsigned long long int a[MAX_OP],b[MAX_OP],k[MAX_OP];
    
    for(unsigned long long int i=0;i<m;i++)
        cin>>a[i]>>b[i]>>k[i];

	// m is number of operations.
	

	cout << findMax(n, m, a, b, k)%DIV;
	return 0;
}

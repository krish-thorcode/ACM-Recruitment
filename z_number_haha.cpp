#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const ll MOD = 1000000007;
 
struct Matrix {
	ll mat[2][2];
};
 
Matrix mul(Matrix a, Matrix b) {
	ll m = (a.mat[0][0]*b.mat[0][0])%MOD + (a.mat[0][1]*b.mat[1][0])%MOD;
	ll n = (a.mat[0][0]*b.mat[0][1])%MOD + (a.mat[0][1]*b.mat[1][1])%MOD;
	ll o = (a.mat[1][0]*b.mat[0][0])%MOD + (a.mat[1][1]*b.mat[1][0])%MOD;
	ll p = (a.mat[1][0]*b.mat[0][1])%MOD + (a.mat[1][1]*b.mat[1][1])%MOD;
	a.mat[0][0] = m;
	a.mat[0][1] = n;
	a.mat[1][0] = o;
	a.mat[1][1] = p;
	return a;
}
 
Matrix pangkat(Matrix x, ll power) {
	if (power == 1) return x;
	Matrix ans = pangkat(mul(x, x), power/2);
	if (power%2 == 1) 
		mul(ans, x);

	return ans;
}
 
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	unsigned long long int a,b;
	
	ll T, N;
	Matrix z;
	cin >> T;
	cin>>a>>b;
	unsigned long long int base_matrx[2][1] = {{b},{a}};

	while (T--) {
		cin >> N;

			z.mat[0][0] = 1;
			z.mat[0][1] = 2;
			z.mat[1][0] = 1;
			z.mat[1][1] = 0;
			z = pangkat(z, N-2);
			cout << (((z.mat[0][0])*(base_matrx[0][0])) + ((z.mat[0][1])*(base_matrx[1][0])))%MOD << "\n";
	}
}
#include<bits/stdc++.h>
using namespace std;
#define ll				long long int
#define vi				vector<int>
#define vl				vector<ll>
#define	pii				pair<int,int>
#define pil				pair<int, ll>
#define pll				pair<ll, ll>
#define pli 			pair<ll, int>
#define pb(v, a)		v.push_back(a)
#define mp(a, b)		make_pair(a, b)
#define MOD				1000000007
#define rep(i, a, b)	for(i=a; i<=b; ++i)
#define rrep(i, a, b)	for(i=a; i>=b; --i)
#define si(a)			scanf("%d", &a)
#define sl(a)			scanf("%lld", &a)
#define pi(a)			printf("%d", a)
#define pl(a)			printf("%lld", a)
#define pn 				printf("\n")
ll pow_mod(ll a, ll b)
{
	ll res = 1;
	while(b)
	{
		if(b & 1)
			res = (res * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}
ll pow2[1000005], pow3[1000005];
void pre_compute()
{
	int i;
	pow2[0] = 1;
	pow3[0] = 1;
	rep(i, 1, 1000000)
	{
		pow2[i] = (2 * pow2[i - 1]) % MOD;
		pow3[i] = (3 * pow3[i - 1]) % MOD;
	}
}
int main()
{
	pre_compute();
	int t, i, n;
	si(t);
	ll ans;
	rep(i, 1, t)
	{
		si(n);
		ans = (pow2[n] * pow2[n]) % MOD;
		ans -= 2 * pow3[n];
		while(ans < 0)
			ans += MOD;
		if(ans >= MOD)
			ans = ans % MOD;
		ans += pow2[n];
		if(ans >= MOD)
			ans = ans % MOD;
		pl(ans);
		pn;
	}
	return 0;
}
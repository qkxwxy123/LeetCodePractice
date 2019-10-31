#include "iostream"
#include "cstdio"
#define ll long long
using namespace std;
int n;
ll pw(ll x, ll k)
{
	ll ans = 1;
	while (k)
	{
		if (k & 1)
			ans = (ans * x) % n;
		x = (x * x) % n;
		k >>= 1;
	}
	return ans % n;
}


int main()
{
	freopen("CircleNOIP2013.in", "r", stdin);
	freopen("CircleNOIP2013.out", "w", stdout);
	ll m, k, x;
	cin >> n >> m >> k >> x;
	cout << (x + (m * pw(10, k) % n)) % n << endl;
	return 0;
}
#include "iostream"
#include "cstdio"
#include "algorithm"
#include "cmath"
#define maxn 50010
using namespace std;

int f[maxn][20], dp[maxn][20];
int n, q, height, r, l;
int maxx = -1, minn = 0x7fffffff;

int main()
{
	freopen("lineup.in", "r", stdin);
	freopen("lineup.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> height;
		f[i][0] = height;
		dp[i][0] = height;
	}

	for (int j = 1; (1 << j) <= n; j++)
		for (int i = 1; i + (1 << j) - 1 <= n; i++)
		{
			f[i][j] = max(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
			dp[i][j] = min(dp[i][j - 1], dp[i + (1 << j - 1)][j - 1]);
		}
	
	for (int i = 1; i <= q; i++)
	{
		cin >> l >> r;
		int k = log2(r - l + 1);
		maxx = max(f[l][k], f[r - (1 << k) + 1][k]);
		minn = min(dp[l][k], dp[r - (1 << k) + 1][k]);
		cout << maxx - minn << endl;
	}
	return 0;
}
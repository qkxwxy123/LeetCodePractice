#include "iostream"
#include "cstdio"
#include "algorithm"
#include "cmath"
#define maxn 1000010
using namespace std;

int n, k;
int f[maxn][30], dp[maxn][30], num;

int main()
{
	freopen("window.in", "r", stdin);
	freopen("window.out", "w", stdout);
	cin >> n >> k;
	for (int i = 0; i < maxn; i++)
		for (int j = 0; j < 20; j++)
			f[i][j] = -10000000, dp[i][j] = 10000000;
	for (int i = 1; i <= n; i++)
	{
		cin >> num;
		f[i][0] = dp[i][0] = num;
	}

	for(int j = 1; (1 << j) <= n; j++)
		for (int i = 1; i + (1 << j) - 1 <= n; i++)
		{
			f[i][j] = max(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
			dp[i][j] = min(dp[i][j - 1], dp[i + (1 << j - 1)][j - 1]);
		}

	for (int i = 1; i <= n - k + 1; i++)
	{
		int r = i + k - 1;
		int kk = log2(r - i + 1);
		cout << min(dp[i][kk], dp[r - (1 << kk) + 1][kk]) << ' ';
	}
	cout << endl;
	for (int i = 1; i <= n - k + 1; i++)
	{
		int r = i + k - 1;
		int kk = log2(r - i + 1);
		cout << max(f[i][kk], f[r - (1 << kk) + 1][kk]) << ' ';
	}
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
using namespace std;
int n, m, res[100], ans = 0;

void dfs(int x, int dep)
{
	for (int i = 1; i <= n; i++)
	{
		res[x] = i;
		int s = 0, flag = 1;
		for (int j = 1; j <= x; j++)
			s += res[j];                          //求和
		for(int j = 1; j < x; j++)
			if (res[j] > res[j + 1])
			{
				flag = 0;
				break;
			}
		if (s > n)                                 //和超过了人数
			break;
		if (x == m && s == n && flag && dep == 1)  //人数刚好且分组刚好
			ans++;
		else if (x == m && s == n && flag && dep == 2)
		{
			for (int j = 1; j <= m; j++)
				cout << res[j] << ' ';
			cout << endl;
		}
		if (x < m)
			dfs(x + 1, dep);	
	}
}

int main()
{
	freopen("dataa.in", "r", stdin);
	freopen("dataa.out", "w", stdout);
	scanf("%d %d", &n, &m);
	dfs(1, 1);
	cout << ans << endl;
	dfs(1, 2);
	return 0;
}
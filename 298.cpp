#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#define MAXN 50100
using namespace std;
int N, K, D, x, y;
int ans = 0;
int pre[MAXN * 3];             //n 是同类 n + n是天敌， n * 3是食物

int find(int x)
{
	if (x == pre[x])
		return x;
	return pre[x] = find(pre[x]);
}

void Union(int x, int y)
{
	pre[find(x)] = find(y);
}

int main()
{
	freopen("eat.in", "r", stdin);
	freopen("eat.out", "w", stdout);
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N * 3; i++)
		pre[i] = i;

	while (K--)
	{
		scanf("%d %d %d", &D, &x, &y);
		if (x > N || y > N)
			ans++;
		else
		{
			if (D == 1)
			{
				if (find(x + N) == find(y) || find(x + N * 2) == find(y))
				{
					ans++;
					continue;
				}
				else
				{
					Union(x, y);
					Union(x + N, y + N);
					Union(x + (N << 1), y + (N << 1));
				}
			}
			else
			{
				if (x == y || find(x) == find(y) || find(x) == find(y + N))   //y是x的天敌
				{
					ans++;
					continue;
				}
				else
				{
					Union(x, y + (N << 1));
					Union(x + N, y);
					Union(x + (N << 1), y + N);
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
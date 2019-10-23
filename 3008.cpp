#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#define MAXN 10100
using namespace std;

int pre[MAXN], n, m;
int x, y, ans = 0;

int find(int x)
{
	if (x == pre[x])
		return x;
	return pre[x] = find(pre[x]);
}

void Union(int x, int y)
{
	int xpre = find(x);
	int ypre = find(y);
	pre[xpre] = ypre;
}

int main()
{
	freopen("friendscircle.in", "r", stdin);
	freopen("friendscircle.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		pre[i] = i;
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &x, &y);
		if (find(x) != find(y))
			Union(x, y);
	}

	for (int i = 1; i <= n; i++)
	{
		if (find(i) == find(1))
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}
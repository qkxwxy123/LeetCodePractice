#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAXN 10010
using namespace std;

int n, ct;
int pre[MAXN];

struct Land
{
	int x1, y1, x2, y2;

	bool operator<(const Land& a)const
	{
		if (x1 != a.x1)
			return x1 < a.x1;
		return y1 < a.y1;
	}
}land[MAXN];

int find(int x)
{
	if (x == pre[x])
		return x;
	return pre[x] = find(pre[x]);
}

int Union(int x, int y)
{
	int xPre = find(x);
	int yPre = find(y);
	if (xPre == yPre)
		return 0;
	else
	{
		pre[xPre] = yPre;
		return 1;
	}
}

int judge(const Land& a, const Land& b)
{
	if (a.y1 - 1 > b.y2 || a.y2 + 1 < b.y1)
		return 0;
	if (a.x2 + 1 == b.x1)
	{
		if (a.y1 - 1 == b.y2 || a.y2 + 1 == b.y1)
			return 0;
		else
			return 1;
	}
	else
		return 1;
}

int main()
{
	freopen("jx.in", "r", stdin);
	freopen("jx.out", "w", stdout);
	scanf("%d", &n);
	ct = n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d %d", &land[i].x1, &land[i].y1, &land[i].x2, &land[i].y2);
		pre[i] = i;
	}
	sort(land, land + n);
	for (int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n && land[j].x1 <= land[i].x2 + 1; j++)
			if (judge(land[i], land[j]) && Union(i, j))
			{
				ct--;
			}
	}
	printf("%d\n", ct);
	return 0;
}
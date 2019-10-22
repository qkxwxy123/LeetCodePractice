#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#define MAXN 1000100
using namespace std;

int N, M, pre[MAXN] = { 0 }, Q;
int ai, bi;

int find(int x)
{
	if (x == pre[x])
		return x;
	return pre[x] = find(pre[x]);
}

void Union(int x, int y)
{
	int xPre = find(x);
	int yPre = find(y);
	if (xPre != yPre)
		pre[y] = xPre;
}

void preWork()
{
	for (int i = 1; i <= N; i++)
		pre[i] = i;
}

int main()
{
	freopen("relations.in", "r", stdin);
	freopen("relations.out", "w", stdout);
	scanf("%d%d", &N, &M);
	preWork();

	while (M--)
	{
		scanf("%d %d", &ai, &bi);
		Union(ai, bi);
	}
	scanf("%d", &Q);
	while (Q--)
	{
		scanf("%d %d", &ai, &bi);
		int aPre = find(ai);
		int bPre = find(bi);
		if (aPre != bPre)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}
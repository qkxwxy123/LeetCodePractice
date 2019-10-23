#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
int ans = 0;
int c[1000][1000] = { 0 };
int vis[1000][1000] = { 0 };
int X[8] = { 1, 0, -1, 0, 1, -1, 1, -1};
int Y[8] = { 0, 1, 0, -1, -1, 1, 1, -1};

void dfs(int x, int y)
{
	if (!c[x][y] || vis[x][y])
		return;
	vis[x][y] = 1;
	for (int i = 0; i < 8; i++)
	{
		int dx = x + X[i], dy = y + Y[i];
		dfs(dx, dy);
	}
}

int main()
{
	freopen("common.in", "r", stdin);
	freopen("common.out", "w", stdout);
	memset(c, 0, sizeof(c));
	memset(vis, 0, sizeof(vis));
	scanf("%d", &N);
	getchar();
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%1d", &c[i][j]);
		}
		getchar();
	}
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (!vis[i][j] && c[i][j])
			{
				ans++;
				dfs(i, j);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
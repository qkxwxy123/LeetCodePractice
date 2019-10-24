#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#define MAXN 110
using namespace std;
int edge[MAXN][MAXN];
int res[MAXN];
int temp[MAXN]; //��ʱ����
int n, m, p, maxDis, minDis = 99999999, ans = 99999999;

void dfs(int x, int now)   //x��ʾ����������˼�����now��ʾ�ӵĵ�
{
	if (x == p + 1)
	{
		maxDis = 0;
		for (int i = 0; i < n; i++)
		{
			minDis = 99999999;
			for (int j = 1; j <= p; j++)
			{
				minDis = min(minDis, edge[i][temp[j]]);  //�ҵ���ׯi��p��ѧУ������Ǹ�ѧУ�ľ���
			}
			maxDis = max(maxDis, minDis);         //�ҵ��Ժ������Զ�ľ���
		}
		if (ans > maxDis)                        //��Զ��ѧ���ߵ�·����
		{
			ans = maxDis;
			memset(res, 0, sizeof(res));
			for (int i = 0; i < n; i++)
				res[i] = temp[i];
		}
		return;
	}
	for (int i = now + 1; i < n; i++)
	{
		temp[x] = i;
		dfs(x + 1, i);
	}
}

int main()
{
	freopen("djsc.in", "r", stdin);
	freopen("djsc.out", "w", stdout);
	int x, y, v;
	scanf("%d %d %d", &n, &m, &p);
	for(int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			edge[i][j] = 99999999;
			edge[i][i] = 0;
		}
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &x, &y, &v);
		edge[x][y] = edge[y][x] = v;
	}
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				edge[i][j] = min(edge[i][j], edge[i][k] + edge[k][j]);
	dfs(1, -1);
	for (int i = 1; i <= p; i++)
		printf("%d ", res[i]);
	return 0;
}
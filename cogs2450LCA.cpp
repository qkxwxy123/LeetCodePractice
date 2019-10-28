#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "cstdio"
#include "cstring"
#define maxn 10010
using namespace std;
int n, m, from, to, k;
struct Edge
{
	int to, val, pre;
}e[maxn << 1];

struct query
{
	int to, id, pre;
}q[maxn << 2];

struct AA
{
	int x, i;
}a[maxn];

int lastE[maxn] = { 0 };
int lastQ[maxn] = { 0 };
int p[maxn] = { 0 };
int dis[maxn], anc[maxn], ans[maxn << 1];
bool vis[maxn << 1] = { 0 };
int cnt = 0, cnt1 = 0, cnt2 = 0, top = 0;

void inserte(int from, int to, int val)
{
	e[++cnt1].to = to;
	e[cnt1].val = val;
	e[cnt1].pre = lastE[from];
	lastE[from] = cnt1;
}

void insertq(int from, int to, int i)
{
	q[++cnt2].to = to;
	q[cnt2].id = i;
	q[cnt2].pre = lastQ[from];
	lastQ[from] = cnt2;
}

int findRoot(int x)
{
	static int y, root;
	root = anc[x];
	while (anc[root] != root)
		root = anc[root];
	while (anc[x] != x)
	{
		y = anc[x];
		anc[x] = root;
		x = y;
	}
	return root;
}

void dfs(int x)
{
	int y, i;
	a[++top].x = x;
	a[top].i = lastE[x];
	while (top)
	{
		x = a[top].x;
		i = a[top].i;
		if (e[i].to == p[x])
			i = e[i].pre;
		if (i)
		{
			a[top].i = e[i].pre;
			y = e[i].to;
			p[y] = x;
			dis[y] = dis[x] + e[i].val;
			a[++top].x = y;
			a[top].i = lastE[y];
			anc[y] = y;
 		}
		else
		{
			vis[x] = 1;
			for (int i = lastQ[x]; i; i = q[i].pre)
			{
				y = q[i].to;
				if (vis[y])
				{
					ans[q[i].id] = dis[x] + dis[y] - (dis[findRoot(y)] << 1);
				}
			}
			anc[x] = p[x];
			top--;
		}
	}
}




int main()
{
	freopen("distance.in", "r", stdin);
	freopen("distance.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n - 1; i++)
	{
		scanf("%d %d %d", &from, &to, &k);
		inserte(from, to, k);
		inserte(to, from, k);
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &from, &to);
		insertq(from, to, i);
		insertq(to, from, i);
	}
	dis[1] = p[1] = 0;
	dfs(1);
	
	for (int i = 0; i < m; i++)
		printf("%d\n", ans[i]);
	return 0;
}
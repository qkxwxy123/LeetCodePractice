#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "cstdio"
#define maxn 101000
using namespace std;

struct Edge
{
	int to, val, pre;
	Edge() :to(0), val(0), pre(0) {};
}e[maxn << 2];

struct query
{
	int to, id, pre;
}q[maxn << 1];

struct A
{
	int x, i;
}a[maxn];

int p[maxn], n, m, Q, lastE[maxn] = { 0 }, lastQ[maxn] = { 0 }, fr, To, V;
int ans[maxn] = { 0 }, top = 0, anc[maxn] = { 0 };
bool vis[maxn << 1] = { 0 };
int cnt1 = 0, cnt2 = 0, dis[maxn] = { 0 };

void insert1(int from, int to, int val)
{
	e[++cnt1].to = to;
	e[cnt1].val = val;
	e[cnt1].pre = lastE[from];
	lastE[from] = cnt1;
}

void insert2(int from, int to, int id)
{
	q[++cnt2].to = to;
	q[cnt2].id = id;
	q[cnt2].pre = lastQ[from];
	lastQ[from] = cnt2;
}

int findRoot(int x)
{
	static int y, root;
	root = anc[x];
	while (root != anc[root])
	{
		root = anc[root];
	}
	while (x != anc[x])
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
			a[++top].i = lastE[y];
			a[top].x = y;
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
	freopen("ThefallingofZLX.in", "r", stdin);
	freopen("ThefallingofZLX.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &fr, &To, &V);
		insert1(fr, To, V);
		insert1(To, fr, V);
	}
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++)
	{
		scanf("%d %d", &fr, &To);
		insert2(fr, To, i);
		insert2(To, fr, i);
	}

	dfs(1);

	for (int i = 0; i < Q; i++)
		printf("%d\n", ans[i]);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "cstdio"
#include "vector"
#include "cstring"
#define max(x, y) (x) > (y) ? (x) : (y)
#define swap(x, y) {int tmp = x; x = y; y = tmp;}
#define maxn 200010
using namespace std;

struct Edge
{
	int to, pre;
}e[maxn << 2];

int n, K, Ai[maxn], Pi[maxn], ans[maxn] = { 0 }, cnt1 = 0, lastE[maxn] = { 0 };           
int p[maxn], dis[maxn] = { 0 }, rt;
int Size[maxn], son[maxn];                         //size[n] 表示n的子树中节点个数  son[n]表示n的子树中节点数最多的树的根
int top[maxn], deps[maxn];                        //deps表示政党i的最大深度的节点序号  ，top表示树的直径的起始点用来求lca

void insert1(int from, int to)
{
	e[++cnt1].to = to;
	e[cnt1].pre = lastE[from];
	lastE[from] = cnt1;
}

void dfs(int x)
{
	int y;
	Size[x] = 1;
	dis[x] = dis[p[x]] + 1;
	for (int i = lastE[x]; i; i = e[i].pre)
	{
		y = e[i].to;
		if (p[x] == y)
			continue;
		p[y] = x;
		dfs(y);
		Size[x] += Size[y];
		if (Size[son[x]] < Size[y])
			son[x] = y;
	}
}

void dfs2(int u, int Top)
{
	top[u] = Top;
	if (son[u])
		dfs2(son[u], Top);
	int v;
	for (int i = lastE[u]; i; i = e[i].pre)
	{
		v = e[i].to;
		if (p[u] != v && son[u] != v)
			dfs2(v, v);
	}

}

int LCA(int x, int y)
{
	for (; top[x] != top[y]; y = p[top[y]])
	{
		if (dis[top[x]] > dis[top[y]])
			swap(x, y);
	}
	return dis[x] < dis[y] ? x : y;
}



int main()
{
	//freopen("cowpol.in", "r", stdin);
	//freopen("cowpol.out", "w", stdout);
	scanf("%d %d", &n, &K);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d", &Ai[i], &Pi[i]);
		if (Pi[i] != 0)
			insert1(Pi[i], i);
		else
			rt = i;
	}
	dfs(rt);
	dfs2(rt, rt);
	for (int i = 1; i <= n; i++)
	{
		if (dis[i] > dis[deps[Ai[i]]])
			deps[Ai[i]] = i;
	}
	int lca = 0;
	for (int i = 1; i <= n; i++)
	{
		lca = LCA(i, deps[Ai[i]]);
		ans[Ai[i]] = max(ans[Ai[i]], dis[i] + dis[deps[Ai[i]]] - 2 * dis[lca]);
	}
	for (int i = 1; i <= K; i++)
		printf("%d\n", ans[i]);
	return 0;
}
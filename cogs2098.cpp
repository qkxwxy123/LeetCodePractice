#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 1010
using namespace std;
struct edge
{
	int to;
	edge* pre;
	edge() :to(0), pre(NULL) {};
}e[MAXN << 1];

int n, q;
int s1, t1, s2, t2;
int a, b, cnt = 0;
edge* preV[MAXN] = { NULL };                //preV[n]用于取以n为起点的边的地址，依次更新，如果链式遍历每个以n为起点的边
int p[MAXN] = { 0 };                        //p[n] 为n的父亲节点
bool vis[MAXN << 1];

void insert(int a, int b)
{
	e[cnt].to = b;
	e[cnt].pre = preV[a];
	preV[a] = &e[cnt++];
}

void dfs(int x)             //遍历处理p数组
{
	int y;
	for (edge* ee = preV[x]; ee; ee = ee->pre)
	{
		y = ee->to;
		if (y == p[x])
			continue ;
		p[y] = x;
		dfs(y);
	}
}

int LCA(int x, int y)       //找到x和y的lca
{
	memset(vis, 0, sizeof(vis));
	while (x)
	{
		vis[x] = true;
		x = p[x];
	}
	while (y)
	{
		if(vis[y])
			return y;
		y = p[y];
	}
	return x;
}

int query(int lca, int s, int t) //查询lca是否在s和t的路径上
{
	int l = LCA(s, t);
	do
	{
		if (lca == s)              //判断是否lca就是节点s
			return true;
		if (s == l)              //判断节点s是否是s和t的lca
			break;
		s = p[s];                 //往上走
	} while (s);
	/*不能用while的原因是：如果s刚好就等于L，无法进入循环，就无法对于lca==s返回true，如果将s==l放后边，则s = p[s]就把s转移了*/
	while (t && t != l)
	{
		if (lca == t)
			return true;
		t = p[t];
	}
	return false;
}

int main()
{
	//freopen("asm_virus.in", "r", stdin);
	//freopen("asm_virus.out", "w", stdout);
	scanf("%d %d", &n, &q);
	for (int i = 1; i < n; i++)
	{
		scanf("%d %d", &a, &b);
		insert(a, b);
		insert(b, a);
	}
	dfs(1);
	int firLCA, secLCA;
	while (q--)
	{
		scanf("%d %d %d %d", &s1, &t1, &s2, &t2);
		firLCA = LCA(s1, t1);
		secLCA = LCA(s2, t2);
		if (query(firLCA, s2, t2) || query(secLCA, s1, t1))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
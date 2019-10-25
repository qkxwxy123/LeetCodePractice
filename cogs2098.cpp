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
edge* preV[MAXN] = { NULL };                //preV[n]����ȡ��nΪ���ıߵĵ�ַ�����θ��£������ʽ����ÿ����nΪ���ı�
int p[MAXN] = { 0 };                        //p[n] Ϊn�ĸ��׽ڵ�
bool vis[MAXN << 1];

void insert(int a, int b)
{
	e[cnt].to = b;
	e[cnt].pre = preV[a];
	preV[a] = &e[cnt++];
}

void dfs(int x)             //��������p����
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

int LCA(int x, int y)       //�ҵ�x��y��lca
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

int query(int lca, int s, int t) //��ѯlca�Ƿ���s��t��·����
{
	int l = LCA(s, t);
	do
	{
		if (lca == s)              //�ж��Ƿ�lca���ǽڵ�s
			return true;
		if (s == l)              //�жϽڵ�s�Ƿ���s��t��lca
			break;
		s = p[s];                 //������
	} while (s);
	/*������while��ԭ���ǣ����s�պþ͵���L���޷�����ѭ�������޷�����lca==s����true�������s==l�ź�ߣ���s = p[s]�Ͱ�sת����*/
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
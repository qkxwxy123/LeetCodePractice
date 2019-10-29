#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "cstdio"
#include "cstring"

#define ll long long
#define maxn 100100
using namespace std;

struct Edge
{
	ll to, pre;
	Edge() :to(), pre(0) {};
}e[maxn << 2];
bool vis[maxn << 1];
int prt[maxn], n, w[maxn], last[maxn << 1];
int cnt = 0;
ll sum = 0;
int s[maxn];                                          //以x为根的点的权值和
//int sz[maxn];                                         //子孙节点个数

void insert(int from, int to)
{
	e[++cnt].to = to;
	e[cnt].pre = last[from];
	last[from] = cnt;
}

void dfs(int x)
{
	//sz[x] = 1;                                        //从x开始，子孙节点个数为1
	s[x] = w[x];                                      //包含自己，子节点权值和为w_x
	int y;
	for (int i = last[x]; i; i = e[i].pre)
	{
		y = e[i].to;
		if (y == prt[x])
			continue;
		prt[y] = x;
		dfs(y);
		s[x] = (s[x] + s[y]) % 1000000007;             //回溯后，子节点和累加上来
		//sz[x] += sz[y];                               //子节点个数累加
	}

	ll ss = s[x], tmp = 0;
	for (int i = last[x]; i; i = e[i].pre)
	{
		y = e[i].to;
		if (y == prt[x])
			continue;
		//ss-s_y即为除了y和它的子节点权值和 其余节点的权值和，乘积满足Σwi*wj
		tmp = (tmp + ((ll)s[y] * ((ss - s[y] + 1000000007) % 1000000007) % 1000000007)) % 1000000007;
		//每个乘积会被算两次但父节点和子节点不会，因此再加上s_y * wx
		tmp = (tmp + ((ll)s[y] * w[x] % 1000000007)) % 1000000007;
	}
	//对每个x，都有i==j的时候，x和自己的乘积以及LCA也是它自己
	tmp = (tmp + ((ll)w[x] * w[x] % 1000000007)) % 1000000007;
	//前边只有wi wj，统一乘wLCA
	tmp = ((ll)tmp * w[x]) % 1000000007;
	sum = (sum + tmp) % 1000000007;
}

int main()
{
	freopen("asm_algo.in", "r", stdin);
	freopen("asm_algo.out", "w", stdout);
	int x, y;
	scanf("%d %d", &n, &w[1]);
	for (int i = 2; i <= n; i++)
	{
		scanf("%d %d", &x, &y);
		w[i] = y;
		insert(x, i);
	}
	
	dfs(1);
	printf("%lld\n", sum);
	return 0;
}
#include "iostream"
#include "cstdio"
#include "algorithm"
#define maxn 2020
using namespace std;

struct edge
{
	int fro, to, val;
}e[maxn * maxn];

int n, edgeNum = 0, x, f[maxn], sum = 0;

bool cmp(edge a, edge b)
{
	return a.val < b.val;
}

int find(int x)
{
	if (x == f[x])
		return x;
	return f[x] = find(f[x]);
}

void Union(int x, int y)
{
	f[find(x)] = find(y);
}

int main()
{
	freopen("mcst.in", "r", stdin);
	freopen("mcst.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		f[i] = i;
	for(int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			cin >> x;
			if (x != -1)
			{
				e[++edgeNum].fro = i;
				e[edgeNum].to = j;
				e[edgeNum].val = x;
			}
		}
	sort(e + 1, e + edgeNum + 1, cmp);
	for (int i = 1; i < edgeNum; i++)
	{
		if (find(e[i].fro) != find(e[i].to))
		{
			Union(e[i].fro, e[i].to);
			sum += e[i].val;
		}
	}

	cout << sum << endl;
	return 0;
}
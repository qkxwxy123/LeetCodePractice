#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "cstdio"
#include "vector"
#include "queue"
#include "cstring"
#include "cmath"
#define maxn 1010
#define ll long long
using namespace std;

vector<int> A[maxn << 1];
vector<int> B[maxn << 1];
queue<int> q;
struct ches
{
	double x, y, z;
	ches() :x(0), y(0), z(0) {};
}b[maxn];
int T, n,  vis[maxn];
double h, r;
double ddis[maxn];

double dis(ches a, ches b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z));
}

void addE(int from, int to, double val)
{
	A[from].push_back(to);
	A[to].push_back(from);
	B[from].push_back(val);
	B[to].push_back(val);
}

void spfa(int x)
{
	//memset(ddis, 1e60, sizeof(ddis));
	for (int i = 0; i <= n + 1; i++)
		ddis[i] = 1e60;
	memset(vis, 0, sizeof(vis));
	vis[x] = 1;
	ddis[x] = 0;
	q.push(x);
	while (!q.empty())
	{
		int cd = q.front();
		q.pop();
		vis[cd] = 0;
		for (int j = 0; j < A[cd].size(); j++)
		{
			int u = A[cd][j];
			if (ddis[u] > ddis[cd] + B[cd][j] && ddis[cd] != 1e60)
			{
				ddis[u] = ddis[cd] + B[cd][j];
				if (!vis[u])
				{
					vis[u] = 1;
					q.push(u);
				}
			}
		}
	}
}

int main()
{
	freopen("2017cheese.in", "r", stdin);
	freopen("2017cheese.out", "w", stdout);
	int x, y, z;
	scanf("%d", &T);
	while (T--)
	{
		for (int i = 0; i <= n + 1; i++)
		{
			A[i].clear();
			B[i].clear();
		}
		scanf("%d %lf %lf", &n, &h, &r);
		for (int i = 1; i <= n; i++)
			scanf("%lf %lf %lf", &b[i].x, &b[i].y, &b[i].z);
		for (int i = 1; i <= n; i++)
		{
			if (b[i].z <= r)
				addE(0, i, b[i].z);
		}
		for(int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
			{
				if (i == j)
					continue;
				double D = dis(b[i], b[j]);
				if (D <= 2 * r)
					addE(i, j, D);
			}
		for (int i = 1; i <= n; i++)
		{
			if (h - b[i].z <= r)
				addE(i, n + 1, h - b[i].z);
		}
		spfa(0);
		if (ddis[n + 1] != 1e60)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}

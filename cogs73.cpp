#include "iostream"
#include "cstdio"
#include "vector"
#include "queue"
#include "cstring"
#define maxn 110
using namespace std;

int n, m, s, e;
int fro, to;
bool vis[maxn] = { 0 };
int dis[maxn] = { 0 };
vector<int>A[maxn];
vector<int>B[maxn];
queue<int>q;

int main()
{
	freopen("city.in", "r", stdin);
	freopen("city.out", "w", stdout);
	cin >> n >> m >> s >> e;
	for (int i = 0; i < m; i++)
	{
		cin >> fro >> to;
		A[fro].push_back(to);
		B[fro].push_back(1);
	}

	memset(dis, 127 / 2, sizeof(dis));
	q.push(s);
	dis[s] = 0;
	vis[s] = 1;
	while (!q.empty())
	{
		int to = q.front();
		q.pop();
		vis[to] = 0;
		for (int i = 0; i < A[to].size(); i++)
		{
			int u = A[to][i];
			if (dis[u] > dis[to] + B[to][i])
			{
				dis[u] = dis[to] + B[to][i];
				if (!vis[u])
				{
					vis[u] = 1;
					q.push(u);
				}
			}
		}
	}

	cout << dis[e] + 1 << endl;
	return 0;
}
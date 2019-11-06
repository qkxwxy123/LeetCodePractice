#include "iostream"
#include "cstdio"
#include "vector"
#include "queue"
#include "cstring"
#define max(x, y) (x) > (y) ? (x) : (y)
#define maxn 1010
using namespace std;

vector<int>A[maxn];
vector<int>B[maxn];
queue<int>q;
int n, m, X;
int fro, to, val;
int dis[maxn], dis2[maxn];
bool vis[maxn];
int sum = -1;
int main()
{
	freopen("sparty.in", "r", stdin);
	freopen("sparty.out", "w", stdout);
	cin >> n >> m >> X;
	for (int i = 0; i < m; i++)
	{
		cin >> fro >> to >> val;
		A[fro].push_back(to);
		B[fro].push_back(val);
	}

	memset(dis, 127 / 2, sizeof(dis));
	dis[X] = 0;
	vis[X] = 1;
	q.push(X);
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

	for (int s = 1; s <= n; s++)
	{
		memset(dis2, 127 / 2, sizeof(dis2));
		memset(vis, 0, sizeof(vis));
		dis2[s] = 0;
		vis[s] = 1;
		q.push(s);
		while (!q.empty())
		{
			int to = q.front();
			q.pop();
			vis[to] = 0;
			for (int i = 0; i < A[to].size(); i++)
			{
				int u = A[to][i];
				if (dis2[u] > dis2[to] + B[to][i])
				{
					dis2[u] = dis2[to] + B[to][i];
					if (!vis[u])
					{
						vis[u] = 1;
						q.push(u);
					}
				}
			}
		}
		
		sum = max(sum, dis2[X] + dis[s]);
	}
	cout << sum << endl;
	return 0;
}
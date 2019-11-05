#include "iostream"
#include "cstdio"
#include "vector"
#include "queue"
#include "cstring"
#define maxn 110

using namespace std;
int n, m, fr, to, val;
vector<int>A[maxn];
vector<int>B[maxn];
queue<int> q;
int dis[maxn] = { 0 };
bool vis[maxn] = { 0 };
int longest, minn = 1000000, res;
int main()
{
	freopen("djsa.in", "r", stdin);
	freopen("djsa.out", "w", stdout);
	int flag = 1, loc1, loc2;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> fr >> to >> val;
		flag = 1;
		for (int j = 0; j < A[fr].size(); j++)
			if (A[fr][j] == to)
				flag = 0, loc1 = j;
		for (int j = 0; j < A[to].size(); j++)
			if (A[to][j] == fr)
				flag = 0, loc2 = j;
		if (flag)
		{
			A[fr].push_back(to);
			A[to].push_back(fr);
			B[fr].push_back(val);
			B[to].push_back(val);
		}
		else
		{
			B[fr][loc1] = val;
			B[to][loc2] = val;
		}
	}

	for (int i = 0; i < n; i++)
	{
		longest = -1;
		memset(dis, 127 / 2, sizeof(dis));
		memset(vis, 0, sizeof(vis));
		dis[i] = 0;
		vis[i] = 1;
		q.push(i);
		while (!q.empty())
		{
			int to = q.front();
			q.pop();
			vis[to] = 0;
			for (int j = 0; j < A[to].size(); j++)
			{
				int u = A[to][j];
				if (dis[u] > dis[to] + B[to][j])
				{
					dis[u] = dis[to] + B[to][j];
					if (!vis[u])
					{
						vis[u] = 1;
						q.push(u);
					}
				}
			}
		}

		for (int j = 0; j < n; j++)
		{
			if (i == j)
				continue;
			longest = max(longest, dis[j]);

		}
		if (longest < minn)
		{
			minn = longest;
			res = i;
		}
	}

	cout << res << endl;
	return 0;
}
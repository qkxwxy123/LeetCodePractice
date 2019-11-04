#include "iostream"
#include "cstdio"
#include "vector"
#include "queue"
#include "cstring"
#define maxn 110
using namespace std;
int n, m, s, from, t, v, dis[maxn], path[110][110] = { 0 };
bool vis[maxn];
vector<int>A[maxn];
vector<int>B[maxn];
queue<int>q;



int main()
{
	freopen("djs.in", "r", stdin);
	freopen("djs.out", "w", stdout);
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++)
	{
		cin >> from >> t >> v;
		A[from].push_back(t);
		B[from].push_back(v);
	}
	for (int i = 0; i < n; i++)
		dis[i] = 10000000;
	q.push(s);
	vis[s] = 1;
	dis[s] = 0;
	path[s][0] = 1;
	for (int i = 0; i < n; i++)
		path[i][1] = s;
	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		vis[t] = 0;
		for (int i = 0; i < A[t].size(); i++)
		{
			int thr = A[t][i];
			if (dis[thr] > dis[t] + B[t][i])
			{
				dis[thr] = dis[t] + B[t][i];
				path[thr][0] = path[t][0];
				for (int j = 1; j <= path[t][0]; j++)
					path[thr][j] = path[t][j];
				path[thr][0]++;
				path[thr][path[thr][0]] = thr;
				if (!vis[thr])
				{
					vis[thr] = 1;
					q.push(thr);
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << i << ":" << endl;
		if (i == s)
			cout << "no" << endl;
		else if (path[i][0] == 0)
			cout << "no" << endl;
		else
		{
			cout << "path:";
			for (int j = 1; j <= path[i][0]; j++)
				cout << path[i][j] << " ";
			cout << endl;
			cout << "cost:";
			cout << dis[i] << endl;
		}
	}
	return 0;
}
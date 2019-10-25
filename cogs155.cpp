#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;
int n, m, k, R, C;
int map[110][110] = {0};
bool vis[110][110];
int count = 0, ans = 0;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
struct Land
{
	int x, y;
}land;
queue<Land>q;
inline void bfs(int x, int y)
{
	queue<Land>q;
	land.x = x;
	land.y = y;
	int cnt = 1;
	q.push(land);
	vis[x][y] = 1;
	while(!q.empty())
	{
		Land now = q.front();
		q.pop();
		if(cnt > ans)
			ans = cnt;
		for(int i = 0; i < 4; i++)
		{
			Land n = now;
			n.x += dx[i], n.y += dy[i];
			if(!vis[n.x][n.y] && map[n.x][n.y] == 1)
			{
				cnt++;
				vis[n.x][n.y] = 1;
				q.push(n);
			}
		}
	}
}

int main()
{
	freopen("lake.in", "r", stdin);
	freopen("lake.out", "w", stdout); 
	memset(vis, 0, sizeof(vis));
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 0; i < k; i++)
	{
		scanf("%d %d", &R, &C);
		map[R][C] = 1;
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(map[i][j] == 1 && vis[i][j] == 0)
			{
				bfs(i, j);
			}
		}
	}
	cout << ans <<endl;
	return 0;
}

#include "cstdio"
#include "iostream"
#include "queue"
using namespace std;
int a, b, n, i, x, sum = 0, times = 0;
priority_queue<int>q;
int main()
{
	freopen("dry.in", "r", stdin);
	freopen("dry.out", "w", stdout);
	scanf("%d %d %d", &n, &a, &b);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &x);
		q.push(x);
	}
	while(q.top() - sum > 0)
	{
		int k = q.top();
		q.pop();
		k -= b;
		sum += a;
		q.push(k);
		times++;
	}
	cout << times <<endl;
	return 0;
}
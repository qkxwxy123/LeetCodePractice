#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "cstdio"
#include "cmath"
#include "cstdlib"
#define maxn 500010
#define max(x, y)  ((x) > (y) ? (x):(y))
using namespace std;
int n, a, b, l = 0, r = 0, mid, maxx = 0;
int wet[maxn];
int main()
{
	freopen("dry.in", "r", stdin);
	freopen("dry.out", "w", stdout);
	scanf("%d %d %d", &n, &a, &b);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &wet[i]);
		maxx = max(maxx, wet[i]);
	}
	if (maxx % a == 0)
		r = maxx / a;
	else
		r = maxx / a + 1;
	if (b == 0)
	{
		printf("%d\n", r);
		return 0;
	}
	int flag = 1, cnt = 0, extdry, temp;
	mid = (l + r) >> 1;
	while (l < r)
	{
		flag = 1, cnt = 0;
		extdry = a * mid;
		for (int i = 0; i < n; i++)
		{
			if (extdry < wet[i])
			{
				if ((wet[i] - extdry) % b == 0)
					temp = (wet[i] - extdry) / b;
				else
					temp = (wet[i] - extdry) / b + 1;
				cnt += temp;
				if (cnt > mid)
				{
					flag = 0;
					break;
				}
			}
		}
		if (flag)
			r = mid;
		else
			l = mid + 1;
		mid = (l + r) >> 1;
	}
	printf("%d\n", mid);
	return 0;
}
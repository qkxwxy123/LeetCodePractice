#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAXN 10010
using namespace std;
int N;
int maxL, maxR, L, R;

struct Peo
{
	int start, end;
	bool operator<(const Peo& a)const
	{
		if(start != a.start)
			return start < a.start;
		return end < a.end;
	}
}people[MAXN];
int main()
{
	freopen("milk2.in", "r", stdin);
	freopen("milk2.out", "w", stdout);
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d %d", &people[i].start, &people[i].end);
	sort(people, people + N);
	L = people[0].start, R = people[0].end;
	maxL = R - L, maxR = 0;
	for (int i = 1; i < N; i++)
	{
		if (people[i].start <= R)
		{
			if (people[i].end > R)
				R = people[i].end;
		}
		else
		{
			maxL = max(maxL, R - L);
			maxR = max(maxR, people[i].start - R);
			L = people[i].start;
			R = people[i].end;
		}
	}
	printf("%d %d\n", maxL, maxR);
	return 0;
}
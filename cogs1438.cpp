#include "iostream"
#include "cstdio"
#include "algorithm"
#define maxn 100100
#define ll long long
using namespace std;

struct stick
{
	int length, id;
	bool operator < (const stick& a)const
	{
		return length < a.length;
	}
}s[maxn], d[maxn];

ll temp[maxn], n, a[maxn];
ll sum = 0;

void merge(ll b[], ll l, ll r)
{
	for (int i = l; i <= r; i++)
	{
		temp[i] = b[i];
	}
	int mid = (l + r) >> 1;
	int i = l, j = mid + 1;
	for (int pos = l; pos <= r; pos++)
	{
		if (i == mid + 1)
		{
			a[pos] = temp[j];
			j++;
		}
		else if (j == r + 1)
		{
			a[pos] = temp[i];
			i++;
		}
		else if (temp[i] > temp[j])
		{
			a[pos] = temp[j];
			j++;
			sum += mid - i + 1;
			sum %= 99999997;
		}
		else
		{
			a[pos] = temp[i];
			i++;
		}
	}
}

void msort(ll b[], ll l, ll r)
{
	if (l == r)
		return;
	int mid = (l + r) >> 1;
	msort(b, l, mid);
	msort(b, mid + 1, r);
	merge(b, l, r);
}

int main()
{
	freopen("MatchNOIP2013.in", "r", stdin);
	freopen("MatchNOIP2013.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i].length;
		s[i].id = i;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> d[i].length;
		d[i].id = i;
	}
	sort(s, s + n);
	sort(d, d + n);
	for (int i = 0; i < n; i++)
	{
		a[s[i].id] = d[i].id;
	}
	msort(a, 0, n - 1);
	cout << sum % 99999997 << endl;
	return 0;
}
#include "iostream"
#include "cstdio"
#include "algorithm"
#include "cmath"
using namespace std;

int f[1000010][20] = { 0 };
int n, Q, leftI, rightI;
int h[1000010] = { 0 };
int main()
{
	//freopen("climb.in", "r", stdin);
	//freopen("climb.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n + 1; i++)
	{
		cin >> h[i];
		f[i][0] = h[i];
	}

	for (int j = 1; (1 << j) <= n + 1; j++)
		for (int i = 1; i + (1 << j) - 1 <= n + 2; i++)
			f[i][j] = max(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);

	cin >> Q;
	
	for (int i = 0; i < Q; i++)
	{
		cin >> leftI >> rightI;
		int k = log2(rightI - leftI + 1);
		cout << max(f[leftI + 1][k], f[rightI + 1 - (1 << k) + 1][k]) << endl;
	}
	return 0;
}
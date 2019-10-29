#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "cstdio"
#include "cstring"

#define ll long long
#define maxn 100100
using namespace std;

struct Edge
{
	ll to, pre;
	Edge() :to(), pre(0) {};
}e[maxn << 2];
bool vis[maxn << 1];
int prt[maxn], n, w[maxn], last[maxn << 1];
int cnt = 0;
ll sum = 0;
int s[maxn];                                          //��xΪ���ĵ��Ȩֵ��
//int sz[maxn];                                         //����ڵ����

void insert(int from, int to)
{
	e[++cnt].to = to;
	e[cnt].pre = last[from];
	last[from] = cnt;
}

void dfs(int x)
{
	//sz[x] = 1;                                        //��x��ʼ������ڵ����Ϊ1
	s[x] = w[x];                                      //�����Լ����ӽڵ�Ȩֵ��Ϊw_x
	int y;
	for (int i = last[x]; i; i = e[i].pre)
	{
		y = e[i].to;
		if (y == prt[x])
			continue;
		prt[y] = x;
		dfs(y);
		s[x] = (s[x] + s[y]) % 1000000007;             //���ݺ��ӽڵ���ۼ�����
		//sz[x] += sz[y];                               //�ӽڵ�����ۼ�
	}

	ll ss = s[x], tmp = 0;
	for (int i = last[x]; i; i = e[i].pre)
	{
		y = e[i].to;
		if (y == prt[x])
			continue;
		//ss-s_y��Ϊ����y�������ӽڵ�Ȩֵ�� ����ڵ��Ȩֵ�ͣ��˻����㦲wi*wj
		tmp = (tmp + ((ll)s[y] * ((ss - s[y] + 1000000007) % 1000000007) % 1000000007)) % 1000000007;
		//ÿ���˻��ᱻ�����ε����ڵ���ӽڵ㲻�ᣬ����ټ���s_y * wx
		tmp = (tmp + ((ll)s[y] * w[x] % 1000000007)) % 1000000007;
	}
	//��ÿ��x������i==j��ʱ��x���Լ��ĳ˻��Լ�LCAҲ�����Լ�
	tmp = (tmp + ((ll)w[x] * w[x] % 1000000007)) % 1000000007;
	//ǰ��ֻ��wi wj��ͳһ��wLCA
	tmp = ((ll)tmp * w[x]) % 1000000007;
	sum = (sum + tmp) % 1000000007;
}

int main()
{
	freopen("asm_algo.in", "r", stdin);
	freopen("asm_algo.out", "w", stdout);
	int x, y;
	scanf("%d %d", &n, &w[1]);
	for (int i = 2; i <= n; i++)
	{
		scanf("%d %d", &x, &y);
		w[i] = y;
		insert(x, i);
	}
	
	dfs(1);
	printf("%lld\n", sum);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#define MAXLENGTH 10000
using namespace std;
//typedef unsigned char SString[1000100];
int nextP[1000100];
char s[1000100], t[1000100];
int slen, tlen;

void getNext(char*);
int indexKMP(char*, char*, int);
int getLen(char*);

void getNext(char* T)
{
	int i = 0, j = -1;
	nextP[0] = -1;
	while (i < tlen)
	{
		if (j == -1 || T[i] == T[j])
		{
			++i, ++j;
			if (T[i] != T[j])
				nextP[i] = j;
			else
				nextP[i] = nextP[j];
		}
		else
			j = nextP[j];
	}
}

int indexKMP(char* S, char* T, int pos) //从pos处开始匹配
{
	int i = pos, j = 0, res = 0;
	getNext(T);
	while (i < slen)
	{
		while (j != -1 && S[i] != T[j]) j = nextP[j];
		i++, j++;
		if (j == tlen)
			res++;
	}
	return res;
}

int getLen(char* T)
{
	int len = 0;
	for (int i = 0; T[i] != '\0'; i++)
		len++;
	return len;
}
int main()
{
	freopen("oulipo.in", "r", stdin);
	freopen("oulipo.out", "w", stdout);
	int x;
	cin >> x;
	while (x--)
	{
		scanf("%s%s", t, s);
		slen = getLen(s);
		tlen = getLen(t);
		cout << indexKMP(s, t, 0) << endl;
	}
	return 0;
}
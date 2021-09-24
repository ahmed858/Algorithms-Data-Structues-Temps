#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e5 + 5, M = 1e6 + 5, LG = 17;
 
typedef long long ll;
 
int n, arr[N] = {5, 4, 3, 2, 1}, sp[N][LG], lg[N];
 
void buildSp()
{
	lg[0] = -1;
	for(int i = 0 ; i < n ; i++)
	{
		lg[i + 1] = lg[i] + !(i & (i + 1));
	}
	for(int i = 0; i < n; i++) sp[i][0] = i;
	for(int j = 1 ; j < LG ; j++)
	{
		for(int i = 0 ; i + (1<<j) <= n ; i++)
		{
			int lf = sp[i][j - 1];
			int rt = sp[i + (1<<(j - 1))][j - 1];
			sp[i][j] = arr[lf] < arr[rt] ? lf : rt;
		}
	}
}
 
int RMQ(int s, int e)
{
	int len = e - s + 1;
	int lf = sp[s][lg[len]];
	int rt = sp[e - (1<<lg[len]) + 1][lg[len]];
	return arr[lf] < arr[rt] ? lf : rt;
}
 
int main()
{
//	freopen("input.in", "rt", stdin);
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", arr + i);
	buildSp();
	int q, s, e;
	scanf("%d", &q);
	while(q--)
	{
		scanf("%d%d", &s, &e);
		printf("%d\n", arr[RMQ(s, e)]);
	}
	return 0;
}

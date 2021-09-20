#include<bits/stdc++.h>
#define ll				    long long
#define endl			    "\n"
#define sz(x)			    x.size()
using namespace std;
const ll  MAX_CHAR=26,SUM_ALL_NODES=1e6+5;
int sz=1,root;
int nxt[SUM_ALL_NODES][MAX_CHAR],cnt[SUM_ALL_NODES];
// nxt work as adj matrix
void add(string str) {
    int cur = root, x, n = sz(str);
    for (int i = 0; i < n; i++) {
        x = str[i] - 'a';
        if (nxt[cur][x] == -1)nxt[cur][x] = ++sz;

        cur = nxt[cur][x];
        cnt[cur]++;
    }
}
void remove(string str) {
    // dont remove before find it
    int cur = root, x, n = sz(str);
    for (int i = 0; i < n; i++) {
        x = str[i] - 'a';

        cur = nxt[cur][x];
        cnt[cur]--;
    }
}
int find(string str) {
    int cur = root, x, n = sz(str);
    for (int i = 0; i < n; i++) {
        x = str[i] - 'a';
        if (nxt[cur][x] == -1) return 0;
        cur = nxt[cur][x];
        if (cnt[cur] == 0)return 0;
    }
    return cnt[cur];
}
void init(){
    memset(nxt,-1,sizeof nxt);
    root=0;
}
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
int main() {
    fast();
    init();
    int n, m;   string str;
    cin>>n>>m;

    while(n--) cin>>str, add(str);
    while(m--)
    {
        cin>>str;
        printf("%d\n", find(str));
    }
    return 0;
}
/*
input:

12 6
bulldog
dog
dogged
doggedly
doggerel
dogma
dogmatic
dogmatism
dogs
catastroph
catastroph
doctor
cat
dog
dogg
do
doctrinography
dogge
================================================
output:
2
8
3
9
0
3

 * */

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
int main() {
    init();
    int t;
    cin >> t;
    while (t--) {
        int q;
        string s;
        cin >> q >> s;
        if (q == 1)
            add(s);
        else if (q == 2) {
            if (find(s))
                remove(s);
        } else cout << "Prefix: \'" << s << "\' appear in set " << find(s) << " Times.\n";
    }
}
/*
input:

10
1 ahmded
1 ahmed
1 xxxz
1 ahmedmalk
1 o
2 hamada
3 ahmed
3 ahm
3 o
3 v
================================================
output:

Prefix: 'ahmed' appear in set 2 Times.
Prefix: 'ahm' appear in set 3 Times.
Prefix: 'o' appear in set 1 Times.
Prefix: 'v' appear in set 0 Times.


 * */

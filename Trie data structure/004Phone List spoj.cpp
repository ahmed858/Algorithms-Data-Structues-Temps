#include<bits/stdc++.h>
#define ll				    long long
#define endl			    "\n"
#define sz(x)			    x.size()
using namespace std;
const ll  MAX_CHAR=10,SUM_ALL_NODES=1e7+5;
int sz=1,root;
int nxt[SUM_ALL_NODES][MAX_CHAR],cnt[SUM_ALL_NODES];
// nxt work as adj matrix
void add(string str) {
    int cur = root, x, n = sz(str);
    for (int i = 0; i < n; i++) {
        x = str[i] - '0';
        if (nxt[cur][x] == -1)nxt[cur][x] = ++sz;

        cur = nxt[cur][x];
        cnt[cur]++;
    }
}
void remove(string str) {
    // dont remove before find it
    int cur = root, x, n = sz(str);
    for (int i = 0; i < n; i++) {
        x = str[i] - '0';

        cur = nxt[cur][x];
        cnt[cur]--;
    }
}
int find(string str) {
    int cur = root, x, n = sz(str);
    for (int i = 0; i < n; i++) {
        x = str[i] - '0';
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
vector<string>v;
int n;
void solve(){
    for(int i=0;i<n;i++){
        remove(v[i]);
        if( find(v[i])){
            cout<<"NO\n"<<endl;
            return;
        }
        add(v[i]);
    }
    cout<<"YES\n"<<endl;
}
int main() {
    fast();

    int t;
    cin >> t;
    while (t--) {
        init();
        cin>>n;
        v=vector<string>(n);
        for(int i=0;i<n;i++){
            cin>>v[i];add(v[i]);
        }
        solve();
    }
}
/*
input:

2
3
911
97625999
91125426
5
113
12340
123440
12345
98346
================================================
output:
NO
YES

 * */

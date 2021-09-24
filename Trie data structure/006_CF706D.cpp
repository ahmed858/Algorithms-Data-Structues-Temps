#include<bits/stdc++.h>
#define ll				    long long
#define endl			    "\n"
#define sz(x)			    x.size()
using namespace std;
const ll  MAX_CHAR=2,SUM_ALL_NODES=7e6+5;
int sz=1,root;
int nxt[SUM_ALL_NODES][MAX_CHAR],cnt[SUM_ALL_NODES];
// nxt work as adj matrix
void add(int  n) {
    int cur=root;
    for(int i=30;i>=0;i--){
        int dir= (n>>i)&1;
        if(nxt[cur][dir]==-1)
            nxt[cur][dir]=sz++;

        cur=nxt[cur][dir];
        cnt[cur]++;
    }
}
void remove(int n) {
    // find it first
    int cur=root;
    for(int i=30;i>=0;i--){
        int dir= ((n>>i)&1);
        cur=nxt[cur][dir];
        cnt[cur]--;
    }
}
int find(int n) {
    int cur = root;
    for (int i = 30; i >= 0; i--) {
        int dir = ((n >> i) & 1);
        if (nxt[cur][dir] == -1)
            return 0;
        cur = nxt[cur][dir];
        if (!cnt[cur])return 0;
    }
    return cnt[cur];
}
int ans(int n){
    int cur = root;
    int result=0;
    for (int i = 30; i >= 0; i--) {
        int dir = (n >> i) & 1;
        if(nxt[cur][!dir]!=-1 and cnt[nxt[cur][!dir]])
        {
            result|=(1<<i);
            cur = nxt[cur][!dir];
        }
        else cur = nxt[cur][dir];
    }
    return result;
}
void init(){
    memset(nxt,-1,sizeof nxt);
    root=0;
    add(0);
}
int main() {
    init();
    int t;
    cin >> t;
    while (t--) {
        char q;
        int s;
        cin >> q >> s;
        if (q == '+')
            add(s);
        else if (q == '-') {
            if (find(s))
                remove(s);
        } else cout <<  ans(s) <<endl;
    }
}

#include<bits/stdc++.h>
#define ll				    long long
#define endl			    '\n'
#define sz(x)			    x.size()
using namespace std;
void fast(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
}
const ll  N=1e5+5,M=1e5+5,LG=17;//take care about LG
vector<int> adj [N];
int par[N],d[N],n,sp[N*2][LG+1],lg[N*2];

vector<int>flatten,depth;
int idx[N*2];
void dfs(int u) {

    idx[u]=flatten.size();
    flatten.emplace_back(u);
    depth.push_back(d[u]);
    for (int &v: adj[u]) {
        if(v==par[u])continue;
        d[v] = d[u] + 1;
        par[v] = u;
        dfs(v);
        flatten.emplace_back(u);
        depth.push_back(d[u]);
    }
}
void buildSP() {
    lg[0] = -1;
    for (int i = 0; i < depth.size(); i++) {
        lg[i + 1] = lg[i] + !(i & (i + 1));
        sp[i][0] = i;
    }
    for (int j = 1; (1 << j) < depth.size(); j++) {
        for (int i = 0; i + (1 << j) < depth.size(); i++) {
            int lf = sp[i][j - 1];
            int rt = sp[i + (1 << (j - 1))][j - 1];
            sp[i][j] = depth[lf] < depth[rt] ? lf : rt;
        }
    }
}
int RMQ(int l,int r) {
    if(l > r) swap(l, r);
    int len = r - l + 1;
    int lf = sp[l][lg[len]];
    int rt = sp[r - (1 << lg[len]) + 1][lg[len]];
    return  depth[lf] < depth[rt] ? lf : rt;

}
int LCA(int u,int v) {
    return flatten[RMQ(idx[u],idx[v])];
}
int main() {

    int t, c = 1;
    scanf("%d", &t);
    while (t--) {
        scanf("%d",  &n);
        flatten.clear();
        depth.clear();
        for (int i = 1; i <= n; i++)
            adj[i].clear();
        int u, v;
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            scanf("%d", &u);
            while (u--) {
                scanf("%d", &v);
                adj[i].push_back(v);
                adj[v].push_back(i);
            }
        }
        dfs(1);
        buildSP();
        int q;
        scanf("%d", &q);
        printf("Case %d:\n", c++);
        while (q--) {
            scanf("%d%d", &u, &v);
            printf("%d\n", LCA(u, v));
        }
    }
}

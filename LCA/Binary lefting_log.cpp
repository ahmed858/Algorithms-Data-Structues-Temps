/*
O(log(N))
*/

#include<bits/stdc++.h>
#define ll				    long long
#define endl			    '\n'
#define sz(x)			    x.size()
using namespace std;

const ll  N=2e5+5,M=1e5+5,LG=17;//take care about LG
vector<int> adj [N];
int par[N][LG+1],depth[N],n;
void dfs(int u) {

    for (int j = 1; j < LG; j++) {
        par[u][j] = par[par[u][j - 1]][j - 1];
    }
    for (int &v: adj[u]) {
        if(v==par[u][0])continue;
        depth[v] = depth[u] + 1;
        par[v][0] = u;
        dfs(v);
    }
}
int getKthParent(int u,int k) {
    while (k) {
        int bit = __lg(k);
        u = par[u][bit];
        k -= (1 << bit);
    }
    return u;
}
int LCA(int u,int v) {
    if (depth[v] > depth[u])swap(u, v);
    int d = depth[u] - depth[v];
    if (d) u = getKthParent(u, d);// now its equal
    if (u == v)return u;
    for (int bit = __lg(depth[u]); ~bit; bit--) {//take care about LG
        if (par[u][bit] != par[v][bit]) {
            u = par[u][bit];
            v = par[v][bit];
        }
    }
    // here im in one step before LCA, so return parent u
    return par[u][0];
}
int main() {

    int t, c = 1;
    scanf("%d", &t);
    while (t--) {
        scanf("%d",  &n);
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
        int q;
        scanf("%d", &q);
        printf("Case %d:\n", c++);
        while (q--) {
            scanf("%d%d", &u, &v);
            printf("%d\n", LCA(u, v));
        }
    }
}

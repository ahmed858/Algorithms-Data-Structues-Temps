#include<bits/stdc++.h>
#define ll				    long long
#define endl			    '\n'
#define sz(x)			    x.size()
using namespace std;
const ll  N=2e5+5,M=1e5+5,LG=17;
vector<int> adj [N];
int par[N][LG],depth[N],n;
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

int main() {
    scanf("%d", &n);
    int u, v;
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &u, &v);
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
  
    dfs(1);
  
  for (int i = 1; i <= n; i++) {
        printf("%d:", i);
        for (int j = 1; j < 6; j++) {
            printf("%d ", getKthParent(i,j));
        }
        puts("");
    }
    return 0;
}
/*
9
1 2
1 3
1 4
3 7
3 6
4 5
7 8
8 9
*/

#include<bits/stdc++.h>
#define ll				    long long
#define endl			    "\n"
using namespace std;
const ll  MAX_CHAR=4,SUM_ALL_NODES=6e5+5;
int sz=1,root;
int nxt[SUM_ALL_NODES][MAX_CHAR];
bool isEnd[SUM_ALL_NODES];
// nxt work as adj matrix
void add(string str) {
    int cur = root, x, n = str.size();
    for (int i = 0; i < n; i++) {
        x = str[i] - 'a';
        if (nxt[cur][x] == -1)nxt[cur][x] = ++sz;
        cur = nxt[cur][x];
    }
    isEnd[cur]=true;
}
string s;
bool find(int cur,int idx,bool differ) {
    if(idx==s.size()) {
        return (differ && isEnd[cur]);
    }
    bool ret =0;
    for(int i=0;i<3;i++) {
        int nxtt = nxt[cur][i];
        if (nxtt == -1)continue;
        if (i != s[idx] - 'a' && differ)continue; // i in diff but i pick one before

        else if (i != s[idx] - 'a')
            ret |= find(nxtt, idx + 1, true);
        else ret |= find(nxtt, idx + 1, differ);
    }
    return ret;
}
void init(){
    memset(nxt,-1,sizeof nxt);
    memset(isEnd,0,sizeof isEnd);
    root=0;
}
int main() {
    init();
    int n,m;
    cin>>n>>m;
    while (n--){
        cin>>s;
        add(s);
    }
    while (m--){
        cin>>s;
        if(find(0,0,false))
            cout<<"YES\n";
        else cout<<"NO\n";
    }
}
/*
input:

2 3
aaaaa
acacaca
aabaa
ccacacc
caaac
==========
output:
YES
NO
NO
*/

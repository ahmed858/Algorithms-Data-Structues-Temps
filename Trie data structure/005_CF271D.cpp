#include<bits/stdc++.h>
#define ll				    long long
#define endl			    "\n"
#define sz(x)			    x.size()
using namespace std;
const ll  MAX_CHAR=26;
struct Node {
    Node *nxt[MAX_CHAR];
    bool isleaf;
    int cnt;
    Node(){
        memset(nxt,0,sizeof nxt);
        isleaf=0;
        cnt=0;
    }
}*root;
void add(string str,int j) {
    Node *cur = root;
    int x,n=sz(str);
    for (int i = j; i<n; i++) {
        x = str[i] - 'a';
        if (cur->nxt[x] == NULL)
            cur->nxt[x] = new Node();
        cur = cur->nxt[x];
        cur->cnt++;// to count the prefix in a set
    }
    cur->isleaf = true;
}

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
int k,isBad[26];
int solve(Node*cur,int cnt){
    if(cnt>k)return 0;
    int ans=1;
    for(int i=0;i<26;i++){
        if(cur->nxt[i]!=NULL)
            ans+= solve(cur->nxt[i],cnt+isBad[i]);
    }
    return  ans;
}
int main() {
    fast();
    root = new Node();
    string s, t;
    cin >> s >> t >> k;
    for (int i = 0; i < MAX_CHAR; i++)
        if (t[i] == '0')
            isBad[i] = 1;
    for (int i = 0; i < sz(s); i++) {
        add(s, i);
    }
    cout << solve(root, 0) - 1 << endl;
}

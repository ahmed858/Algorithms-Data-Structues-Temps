#include<bits/stdc++.h>
#define ll				    long long
#define endl			    "\n"
#define sz(x)			    x.size()
using namespace std;
const ll  MAX_CHAR=26,N=100;
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
void add(string str) {
    Node *cur = root;
    int x,n=sz(str);
    for (int i = 0; i<n; i++) {
        x = str[i] - 'a';
        if (cur->nxt[x] == NULL)
            cur->nxt[x] = new Node();
        cur = cur->nxt[x];
        cur->cnt++;// to count the prefix in a set
    }
    cur->isleaf = true;
}
void remove(string str) {
    Node *cur = root;
    int x,n=sz(str);
    for (int i = 0; i<n; i++) {
        x = str[i] - 'a';
        cur = cur->nxt[x];
        cur->cnt--;// be careful find this prefix before remove
    }
    cur->isleaf = false;
}
int find (string str) {
    Node *cur = root;
    int x,n=sz(str);
    for (int i = 0; i<n; i++) {
        x = str[i] - 'a';
        if (cur->nxt[x] == NULL)
            return 0;
        cur = cur->nxt[x];
        if (cur->cnt == 0) return 0;
    }
    return cur->cnt;// how many this prefix appear in a set ?
    return cur->isleaf;

}

int main() {
    root = new Node();
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
        } else cout << "Prefix: \'"<<s<<"\' appear in set " << find(s) << " Times.\n";
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

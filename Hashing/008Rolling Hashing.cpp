#include<bits/stdc++.h>
#define ll				    long long
#define endl			    "\n"
using namespace std;
const ll N=1e5+5,base=127,mod=1e9+7;
ll pw[N];
ll get_hash(string str,int n) {
    ll ret = 0;
    for (int i = 0; i < n; i++)
        ret = (ret + ((pw[i] * str[i]) % mod)) % mod;
    return ret;
}
ll power(ll x,ll y) {
    ll ret = 1;
    while (y) {
        if (y & 1)ret = (ret * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return ret;
}
void init() {
    pw[0] = 1;
    for (int i = 1; i < N; i++)
        pw[i] = (pw[i - 1] * base) % mod;
}
int main() {
    init();
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    ll patHash = get_hash(t, t.size());
    ll curHash = get_hash(s, t.size());
    ll baseInv = power(base, mod - 2);
    if (curHash == patHash)
        cout << "Match in idx: " << 0 << endl;
    for (int i = m; i < n; i++) {
        // subtract s[i-m]
        // divide by base  :  multiply by baseInverse
        // add  base^m-1 * s[i]
        curHash = curHash - s[i - m];
        curHash = curHash * baseInv;
        curHash = (curHash + pw[m - 1] * s[i]) % mod;
        if (curHash == patHash) {
            cout << "Match in idx: " << i - m + 1 << endl;
        }
    }
}
/*
input:
aabaaabaab
aab
==========
output:
Match in idx: 0
Match in idx: 4
Match in idx: 7
*/

  #include<bits/stdc++.h>
#define ll				    long long
#define endl			    "\n"
using namespace std;
const ll N=1e5+5,base=127,mod=1e9+7;
string s, t;
ll pw[N],baseInv[N],Hash[N];
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
    pw[0] = baseInv[0] = 1;
    ll inv = power(base, mod - 2);
    for (int i = 1; i < N; i++) {
        pw[i] = (pw[i - 1] * base) % mod;
        baseInv[i] = (baseInv[i - 1] * inv) % mod;
    }
    for (int i = 0; i < s.size(); i++) {
        Hash[i] = (Hash[i - 1] + (pw[i] * s[i])) % mod;
    }
}
ll get_hash(string str,int n) {
    ll ret = 0;
    for (int i = 0; i < n; i++){
        ret = (ret + ((pw[i] * str[i]) % mod)) % mod;
    }
    return ret;
}
ll get_hash(int l,int r) {
    ll ret;
    ret = l ? (((Hash[r] - Hash[l - 1] + mod) % mod) * baseInv[l]) % mod : Hash[r];
    return ret;
}
int main() {

    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    init();// here after the read strings
    ll patHash = get_hash(t, t.size());
    for (int i = m - 1; i < n; i++) {
        if (get_hash(i - m + 1, i) == patHash)
            cout << "Match in idx: " << i - m + 1 << endl;
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

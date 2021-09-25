#include<bits/stdc++.h>
#define ll				    long long
#define endl			    '\n'
#define sz(x)			    x.size()
using namespace std;
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
const ll  N=1e5+5,LG=17;
int n, arr[N] , sp[N][LG], lg[N];
unordered_map<int,ll> ans;
void buildSp() {
    lg[0] = -1;
    for (int i = 0; i < n; i++) {
        lg[i + 1] = lg[i] + !(i & (i + 1));
    }
    for (int i = 0; i < n; i++) sp[i][0] = arr[i];
    for (int j = 1; j < LG; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            int lf = sp[i][j - 1];
            int rt = sp[i + (1 << (j - 1))][j - 1];
            sp[i][j] = __gcd(lf, rt);
        }
    }
}
int RMQ(int s, int e){
    int len = e - s + 1;
    int lf = sp[s][lg[len]];
    int rt = sp[e - (1<<lg[len]) + 1][lg[len]];
    return __gcd(lf, rt);
}
int main() {
    fast();
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    // preprocesses
    buildSp();
    for (int i = 0; i < n; i++) {
        int j = i, g;
        while (j < n) {// actually this loop iterates log2(1e9) in worst case
            int s = j + 1, e = n - 1, mid, ind = n;
            g = RMQ(i, j);
            while (s <= e) {
                mid = (e + s) / 2;
                if (g != RMQ(i, mid)) {
                    ind = mid;
                    e = mid - 1;
                } else
                    s = mid + 1;
            }
            //cout<<i<< " "<<j<<" "<<g<<endl;
            ans[g] += ind - j;
            j = ind;
        }

    }
    int q, x;
    cin >> q;
    while (q--) {
        cin >> x;
        cout << ans[x] << endl;
    }
    return 0;
}

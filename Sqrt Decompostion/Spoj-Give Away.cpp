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
const int  N=5e5+5,SQ = sqrt(N)+10,bSize=SQ,M=1e6+5;//take care about LG
int n,q,arr[N],sorted[N];
void build() {
    for (int i = 0; i < n; i += bSize) {
        sort(sorted + i, sorted + min(n, i + bSize));
    }
}
void update(int idx,int val) {
    int bIdx = idx / bSize;
    for (int i = bIdx; ; i++) {
        if (arr[idx] == sorted[i]) {
            //Im in the value bucket
            sorted[i] = val;
            while (i + 1 < min(n, (bIdx + 1) * bSize) and sorted[i + 1] < sorted[i]) {
                swap(sorted[i + 1], sorted[i]);
                i++;
            }
            while (i - 1 >= bIdx * bSize and sorted[i - 1] > sorted[i]) {
                swap(sorted[i - 1], sorted[i]);
                i--;
            }
            break;
        }
    }
    arr[idx] = val;
}
int query(int l,int r,int x) {
    int cnt = 0;
    while (l <= r) {
        if (l % bSize == 0 && min(n - 1, l + bSize) <= r) {
            cnt += (sorted + min(n, l + bSize)) - lower_bound( sorted + l, sorted + min(n, l + bSize), x ) ;
            l += bSize;
        } else {
            cnt += (arr[l] >= x);
            l++;
        }
    }
    return cnt;
}
int main() {
    fast();
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i], sorted[i] = arr[i];
    build();
    cin >> q;
    int a, b, c, t;
    while (q--) {
        cin >> t;
        if (!t) {
            cin >> a >> b >> c;
            cout << query(--a, --b, c) << endl;
        } else {
            cin >> a >> b;
            update(--a, b);
        }
    }
    return 0;
}

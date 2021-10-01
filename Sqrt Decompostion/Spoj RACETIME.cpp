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
const int  N=2e5+5,SQ = sqrt(N)+5,bSize=SQ;//take care about LG
int arr[N],sorted[N],n;
void update(int val,int idx) {
    int bidx = idx / bSize;
    for (int i = bidx * bSize;  ; i++) {
        if (arr[idx] == sorted[i]) {
            sorted[i] = val;
            while (i + 1 <  min(n, (bidx + 1) * bSize) and sorted[i + 1] < sorted[i]) {
                swap(sorted[i], sorted[i + 1]);i++;
            }
            while (i - 1 >= bidx * bSize and sorted[i - 1] > sorted[i]) {
                swap(sorted[i], sorted[i - 1]);i--;
            }
            break;
        }
    }
    arr[idx] = val;
}
int query(int l,int r,int x) {
    int cnt = 0;
    while (l <= r) {
        if (l % bSize == 0 and min(n - 1, l + bSize) <= r) {
            cnt += lower_bound(sorted + l, sorted + min(n, l + bSize ), x + 1) - (sorted + l);
            //cnt += upper_bound(sorted+l,sorted +min(n,l+bSize-1),x) - (sorted+l);
            l += bSize;
        } else {
            cnt += (arr[l] <= x);
            l++;
        }
    }
    return cnt;
}
int main() {
    fast();
    int q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> arr[i], sorted[i] = arr[i];
    for (int i = 0; i < n; i += bSize) {
        sort(sorted + i, sorted + min(n, i + bSize));
    }
    char t;
    int l, r, idx, v;
    while (q--) {
        cin >> t;
        if (t == 'M') {
            cin >> idx >> v;
            update(v, --idx);
        } else {
            cin >> l >> r >> v;
            cout << query(--l, --r, v) << endl;

        }
    }
}

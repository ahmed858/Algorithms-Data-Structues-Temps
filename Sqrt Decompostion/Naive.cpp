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
int arr[N],mn[SQ],n;
void build() {
    for (int i = 0; i < n; i++) {
        if (i % bSize == 0)
            mn[i / bSize] = arr[i];
        else mn[i / bSize] = min(mn[i / bSize], arr[i]);
    }
}
int query(int l,int r) {
    int ret = arr[l];
    while (l <= r) {
        if (l % bSize == 0 && min(n - 1, l + bSize - 1) <= r ) {
            ret = min(ret, mn[l]);
            l += bSize;
        } else {
            ret = min(ret, arr[l]);
            l++;
        }
    }
    return ret;
}
void update(int v,int idx) {
    int bInd = idx / bSize;
    arr[idx] = mn[bInd]
    v;
    for (int i = bInd * bSize; i < min(n, (bInd + 1) * bSize); i++)
        mn[bInd] = min(mn[bInd], arr[i]);
}
int main() {
    fast();
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    build();
    int q;
    cin>>q;
    while (q--){
        int l,r;
        cin>>l>>r;
        cout<<query(l,r)<<endl;
    }

}

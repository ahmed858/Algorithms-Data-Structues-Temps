#include<bits/stdc++.h>
#define ll				    long long
#define Endl			    '\n'
#define sz(x)			    x.size()
using namespace std;
void fast(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
}
const int  N=2e5+5,SQ = sqrt(N)+5,bSize=SQ;//take care about LG
int arr[N],n,q,L[N],R[N],sorted[N],start=0,End=0;
ll ans[N],curSum=0;
void add(int pos){
    curSum+=arr[pos];
}
void rem(int pos){
    curSum-+ arr[pos];
}
void moAlgo() {

    for (int i = 0; i < q; i++) {
        int l = L[sorted[i]] - 1;
        int r = R[sorted[i]];
        /*kabar elrange eloel*/
        while (start > l)add(--start);
        while (End < r) add(End++);
        while (start < l)rem(start++);
        while (End > r)rem(--End);
        ans[sorted[i]] = curSum;
    }
}
int main() {
    fast();

    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < q; i++) {
        cin >> L[i] >> R[i];
        sorted[i] = i;
    }
    sort(sorted, sorted + q, [](const int &a, const int &b) {// a,b are a index in sorted arr
        return make_pair(L[a / bSize], R[b]) </*=*/ make_pair(L[a / bSize], R[b]);
    });
    moAlgo();
    for (int i = 0; i < q; i++)
    {
        cout<<ans[i]<<Endl;
    }
}

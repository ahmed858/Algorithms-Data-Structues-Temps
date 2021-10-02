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
const int  N=2e5+5,SQ = sqrt(N)+5,bSize=SQ,M=1e6+5;//take care about LG
int arr[N],n,q,L[N],R[N],sorted[N],start=0,End=0,cnt[M];
ll ans[N],curSum=0;
void add(int pos){
    curSum+= 1LL*arr[pos]*cnt[arr[pos]]++;
    curSum+= 1LL*arr[pos]*cnt[arr[pos]];

}
void rem(int pos) {
    curSum-= 1LL*arr[pos]*cnt[arr[pos]]--;
    curSum-= 1LL*arr[pos]*cnt[arr[pos]];

}
void moAlgo() {

    for (int i = 0; i < q; i++) {
        int l = L[sorted[i]] - 1;
        int r = R[sorted[i]];

        while (start > l)add(--start);
        while (End < r) add(End++);
        while (start < l)rem(start++);
        while (End > r)rem(--End);
        ans[sorted[i]] = curSum;
    }
    return;
}
int main() {
    //fast();
    scanf("%d%d", &n, &q);

    for (int i = 0; i < n; i++) scanf("%d", arr + i);
    for (int i = 0; i < q; i++) {
        scanf("%d%d", L + i, R + i);
        sorted[i] = i;
    }

    sort(sorted, sorted + q, [](const int &a, const int &b) {// a,b are a index in sorted arr
        return make_pair(L[a] / bSize, R[a]) </*=*/ make_pair(L[b] / bSize, R[b]);
    });
    moAlgo();
    for (int i = 0; i < q; i++) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}

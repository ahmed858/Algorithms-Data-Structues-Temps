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
const int  N=5e5+5,SQ = sqrt(N)+5,bSize=SQ;//take care about LG

int arr[N],ans[SQ][SQ];
void update(int x,int y) {
    arr[x] += y;
    for (int i = 1; i < SQ; i++) {
        ans[i][x % i] += y;
    }
}
int query(int x,int y) {
    if (x < SQ)return ans[x][y];
    int ret = 0;
    for (int i = y; i < N; i += x)
        ret += arr[i];
    return ret;
}
int main() {
    fast();
  
    int q;
    cin >> q;
    while (q--) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            update(x, y);
        } else{
            cout << query(x, y) << endl;
        }
    }

}

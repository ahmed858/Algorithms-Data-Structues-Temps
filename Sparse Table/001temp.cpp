#include<bits/stdc++.h>
#define ll				    long long
#define endl			    "\n"
#define sz(x)			    x.size()
using namespace std;
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
const ll  N=1e5+5,LG=17;
int n,arr[N] ,sp[N][LG],lg[N];
void buildSp() {
    //lg[0] = lg[1] = 0;  if begin from 1
    lg[0] = -1;
    for (int i = 0; i < n; i++) {
        //lg[i] = lg[i / 2] + 1; begin from 1
        lg[i + 1] = lg[i] + !(i & (i + 1));// this equal lg[i] = lg[i>>1] + 1; in fast
    }
    for (int i = 0; i < n; i++)
        sp[i][0] = i;

    for (int j = 1; j < LG; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {

            int lf = sp[i][j - 1];
            int rt = sp[i + (1 << (j - 1) )] [j - 1];
            sp[i][j] = arr[lf] < arr[rt] ? lf : rt;

        }
    }
}
int RMQ(int s,int e) {
    int len = s - e + 1;
    int lf = sp[s][lg[len]];
    int rt = sp[e - (1 << lg[len]) + 1][lg[len]];
    return arr[lf] < arr[rt] ? lf : rt;
}
int main() {
	fast();
    cin >> n;
    for (int i = 0; i < n; i++)cin>>arr[i];
    buildSp();
    int q, s, e;
    cin >> q;
    while (q--) {
        cin >> s >> e;
        cout << arr[RMQ(s, e)] << endl;
    }
}
/*

 */

#include<bits/stdc++.h>
using namespace std;
 
typedef long long LL;
const LL MaxN = 1 + 1e5;
LL n, a[MaxN], kq = -1e18 - 1, b[MaxN], ma[MaxN], mi[MaxN], x, ma1[MaxN], mi1[MaxN];
 
int main(){
    #ifndef ONLINE_JUDGE
        #define TASK "A"
        freopen(TASK".inp","r",stdin);
        freopen(TASK".out","w",stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    #endif // ONLINE_JUDGE
    cin >> n;
    mi[0] = 1e7;
    ma[0] = -1e7;
    for(int i = 1 ; i <= n ; ++i){
        cin >> x;
        mi[i] = min(mi[i - 1], x);
        ma[i] = max(ma[i - 1], x);
    }
    ma1[1] = -1e13;
    mi1[1] = 1e13;
    //for(int i = 1 ; i <= n ; ++i) cout << mi[i] << " " << ma[i] << endl;
    //cout << endl;
    for(int i = 1 ; i <= n ; ++i){
        cin >> x;
        if(i == 1) continue;
        ma1[i] = max(ma1[i - 1], max(ma[i - 1] * x, mi[i - 1] * x));
        mi1[i] = min(mi1[i - 1], min(mi[i - 1] * x, ma[i - 1] * x));
    }
    //for(int i = 2 ; i <= n ; ++i) cout << mi1[i] << " " << ma1[i] << endl;
    for(int i = 1 ; i <= n ; ++i){
        cin >> x;
        if(i > 2) kq = max(kq, max(x * mi1[i - 1], x * ma1[i - 1]));
        //cout << kq << endl;
    }
    cout << kq << endl;
 
    return 0;
}
// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e5;

LL n, a[MaxN], d[MaxN], t, cnt[MaxN], m;
pair<LL, LL> q[MaxN], kq[MaxN];

void InOut(){
    #define TASK "BANK"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}
int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> t;
    for(int i = 1 ; i <= n ; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1 ; i <= n ; ++i) d[i] = d[i - 1] + a[i];
    // for(int i = 1 ; i <= n ; ++i) cout << d[i] << " ";
    // cout << endl;
    for(int te = 0 ; te < t ; ++te){
        cin >> q[te].first;
        q[te].second = te;
    }

    LL j = 1;
    sort(q, q + t);
    for(int i = 0 ; i < t ; ++i){
        LL te = q[i].first;
        // cout << te << endl;
        while(j <= n && d[j + 1] <= te) j++;
        LL l = j, r = n;
        while(l < r){
            LL tg = (l + r + 1) / 2;
            if(d[tg] - d[tg - j] > te) r = tg - 1;
            else l = tg;
        }
        kq[q[i].second].first = j;
        kq[q[i].second].second = a[l - j + 1];
    }

    for(int i = 0 ; i < t ; ++i) cout << kq[i].first << " " << kq[i].second << endl;
    
    return 0;
}
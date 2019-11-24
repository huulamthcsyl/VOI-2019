// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e6, INF = 1e18;

LL n, a[MaxN], d[MaxN], m, q, t;

void InOut(){
    #define TASK "ABC"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    // InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    for(int te = 0 ; te < t ; ++te){
        cin >> n >> m >> q;
        for(int i = 0 ; i < n ; ++i) cin >> a[i];
        LL k = 0, j = 0, kq = INF;
        for(int i = 0 ; i < n ; ++i){
            d[a[i]]++;
            if(d[a[i]] == 1) k++;
            if((i - j + 1) == q) kq = min(kq, k);
            if((i - j + 1) <= q) continue;
            d[a[j]]--;
            if(d[a[j]] == 0) k--;
            kq = min(kq, k);
            j++;
        }
        for(int i = 0 ; i < n ; ++i) d[a[i]] = 0;
        cout << kq << endl;
    }

    return 0;
}
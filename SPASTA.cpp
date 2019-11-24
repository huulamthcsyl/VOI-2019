// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e5;

LL n, a[MaxN], m, k, t, s, x;

void InOut(){
    #define TASK "SPASTA"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> k >> n >> t;
    if(k > m - n){
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0 ; i < n ; ++i) cin >> a[i];
    sort(a, a + n);
    LL j = k;
    for(int i = 0 ; i < n ; ++i)
    if(a[i] <= j){
        s += a[i];
        j++;
    }
    cout << t * k + j * (j + 1) / 2 - s << endl;

    return 0;
}
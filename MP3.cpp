// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 4e5;

LL n, a[MaxN], b[MaxN], k, m, d[MaxN], kq, h;

void InOut(){
    #define TASK "ABC"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

LL log2(LL k){
    LL kq = 0;
    while((1 << kq) < k) kq++;
    return kq;
}

int main(){
    // InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> h;
    for(int i = 0 ; i < n ; ++i) cin >> b[i];
    sort(b, b + n);
    LL k = 1;
    m = 1;
    for(int i = 0 ; i < n ; ++i){
        if(i == 0){
            a[m] = k;
            d[k]++;
            continue;
        }
        if(b[i] == b[i - 1]){
            d[k]++;
            continue;
        }
        k++;
        m++;
        a[m] = k;
        d[k]++;
    }
    // cout << m << endl;
    // for(int i = 0 ; i <= m ; ++i) cout << a[i] << " ";
    // cout << endl;
    // for(int i = 0 ; i <= m ; ++i) cout << d[a[i]] << " ";
    // cout << endl;
    for(int i = 1 ; i <= m ; ++i) d[i] = d[i - 1] + d[i];
    // for(int i = 1 ; i <= m ; ++i) cout << d[i] << " ";
    // cout << endl;
    LL dis = m;
    while(dis && log2(dis) * n > h * 8) dis--;
    for(int i = dis ; i <= m ; ++i) kq = max(kq, d[i] - d[i - dis]);
    cout << n - kq << endl;
    
    return 0;
}
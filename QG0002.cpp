// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e5;

LL n, a[MaxN], f[MaxN], b[MaxN], c[MaxN];

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
    cin >> n;
    for(int i = 1 ; i <= n ; ++i) cin >> a[i] >> b[i] >> c[i];
    f[n] = a[n];
    if(n > 1) f[n - 1] = min(a[n] + a[n - 1], b[n - 1]);
    for(int i = n - 2 ; i > 0 ; --i) 
    f[i] = min(f[i + 1] + a[i], min(f[i + 2] + b[i], f[i + 3] + c[i]));
    cout << f[1] << endl;

    return 0;
}
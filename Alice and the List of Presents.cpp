// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e5, MOD = 7 + 1e9;

LL n, a[MaxN], m;

LL Mu(LL a, LL n){
    if(n == 0) return 1;
    LL tg = Mu(a, n / 2);
    if(n % 2) return (((tg * tg) % MOD) * a) % MOD;
    else return (tg * tg) % MOD;
}

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
    cin >> n >> m;
    cout << Mu((Mu(2, m) - 1), n) % MOD << endl;

    return 0;
}
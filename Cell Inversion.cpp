// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 2e5, MOD = 7 + 1e9;

LL n, a[MaxN], d[MaxN], kq = 1;
string s;

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
    cin >> s;
    n *= 2;
    for(int i = 0 ; i < n ; ++i)
    if(s[i] == 'W') a[i] = 0;
    else a[i] = 1;
    if(!a[0] || !a[n - 1]){
        cout << 0 << endl;
        return 0;
    }
    LL k = 1;
    d[0] = 1;
    for(int i = 1 ; i < n ; ++i)
    if(k % 2 == a[i]){
        d[i] = 0;
        k--;
    }
    else{
        d[i] = 1;
        k++;   
    }
    LL s = 0;
    for(int i = 0 ; i < n ; ++i) s += d[i];
    if(s != n / 2){
        cout << 0 << endl;
        return 0;
    }
    k = 0;
    for(int i = 0 ; i < n ; ++i)
    if(!d[i]){
        kq = (kq * k) % MOD;
        k--;
    } else k++;
    for(int i = 1 ; i <= n / 2 ; ++i) kq = (kq * i) % MOD;
    cout << kq << endl;

    return 0;
}
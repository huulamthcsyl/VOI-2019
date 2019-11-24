// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e5;

LL n, a[MaxN], s, s1, kq;

void InOut(){
    #define TASK "ABC"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0 ; i < n ; ++i){
        cin >> a[i];
        s += a[i];
    }
    sort(a, a + n);
    for(int i = 0 ; i < n ; ++i){
        kq = max(kq, s * s + s1 * s1);
        s -= a[i];
        s1 += a[i];
    }
    cout << kq << endl;

    return 0;
}
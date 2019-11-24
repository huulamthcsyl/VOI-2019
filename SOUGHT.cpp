// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e5;

LL n, a[MaxN], x, y, z, k, ma, kq;

void InOut(){
    #define TASK "SOUGHT"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for(int i = 0 ; i < n ; ++i){
        cin >> x >> y >> z;
        if(x > k) continue;
        if((k - x) % y) continue;
        kq += z;
    }
    cout << kq << endl;

    return 0;
}
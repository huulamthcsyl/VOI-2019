// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e5;

LL n, a[MaxN], x, y, z, t;

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
        cin >> x >> y >> z;
        LL kq = 0;
        LL k = min(y, z / 2);
        y -= k;
        kq += k * 3;
        if(y) kq += min(x, y / 2) * 3;
        cout << kq << endl;
    }

    return 0;
}
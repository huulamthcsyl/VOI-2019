// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e5;

LL n, a[MaxN], t, d[MaxN];

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
    d[0] = 1;
    for(int i = 1 ; i <= 38 ; ++i) d[i] = d[i - 1] * 3;
    for(int te = 0 ; te < t ; ++te){
        cin >> n;
        LL kq = 0;
        for(int i = 0 ; i <= 38 ; ++i){
            kq += d[i];
            if(kq >= n) break;
        }
        for(int i = 38 ; i >= 0 ; --i)
        if(kq - d[i] >= n) kq -= d[i];
        cout << kq << endl;
    }

    return 0;
}
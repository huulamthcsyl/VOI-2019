// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e5;

LL n, a[MaxN], t, x;

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
    cin >> t;
    for(int te = 0 ; te < t ; ++te){
        LL mi = 1e18, k;
        string kq = "";
        for(int i = 0 ; i < 10 ; ++i){
            cin >> x;
            if(x < mi){
                mi = x;
                k = i;
            }
        }
        if(mi == 0){
            cout << k << endl;
            continue;
        }
        kq = "1";
        for(int i = 0 ; i < mi - 1 ; ++i) kq += "0";
        kq += to_string(k);
        cout << kq << endl;
    }

    return 0;
}
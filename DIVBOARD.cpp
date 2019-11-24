// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e3;

LL n, a[MaxN][MaxN], d[MaxN][MaxN], kq = 1e18, m;

template <typename T> void read(T &t) {
    t = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    do { (t *= 10) += ch - '0'; ch = getchar(); } while (isdigit(ch)); t *= f;
}

void InOut(){
    #define TASK "DIVBOARD"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read(n);
    read(m);
    for(int i = 1 ; i <= n ; ++i)
    for(int j = 1 ; j <= m ; ++j){
        read(a[i][j]);
        d[i][j] = d[i - 1][j] + d[i][j - 1] - d[i - 1][j  - 1] + a[i][j];
    }
    // for(int i = 1 ; i <= n ; ++i){
    //     for(int j = 1 ; j <= m ; ++j) cout << d[i][j] << " ";
    //     cout << endl;
    // }
    for(int i = 1 ; i <= n - 1 ; ++i){
        LL dis1 = 1e18, dis2 = 1e18, x1 = 0, x2 = 0, x3 = 0, x4 = 0;
        for(int j = 1 ; j <= m - 1 ; ++j)
        if(abs(d[i][m] - d[i][j] - d[i][j]) <= dis1){
            dis1 = abs(d[i][m] - d[i][j] - d[i][j]);
            x1 = d[i][m] - d[i][j];
            x2 = d[i][j];
        }
        if(x1 > x2) swap(x1, x2);
        for(int j = 1 ; j <= m - 1 ; ++j){
            LL x5 = d[n][j] - d[i][j];
            LL x6 = d[n][m] - d[i][m] - d[n][j] + d[i][j];
            if(abs(x6 - x5) <= dis2){
                dis2 = abs(x6 - x5);
                x3 = x5;
                x4 = x6;
            }
        }
        if(x3 > x4) swap(x3, x4);
        kq = min(kq, max(x2, x4) - min(x1, x3));
    }
    cout << kq << endl;

    return 0;
}
// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef int LL;
const LL MaxN = 21;

LL n, a[MaxN][MaxN], d[LL(2e6) + LL(1e5)][MaxN];

template <typename T> void read(T &t) {
    t = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    do { (t *= 10) += ch - '0'; ch = getchar(); } while (isdigit(ch)); t *= f;
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
    read(n);
    for(int i = 0 ; i <= n ; ++i)
    for(int j = 0 ; j <= n ; ++j) read(a[i][j]);
    memset(d, 0x3f3f3f, sizeof d);
    for(int i = 1 ; i <= n / 2 ; ++i) d[1 << i][i] = a[0][i];
    for(int is = 1 ; is < (1 << (n + 1)) ; ++is){
        LL kt = 1;
        for(int i = 1 ; i <= n / 2 ; ++i)
        if(!((is >> i) & 1) && ((is >> (n / 2 + i)) & 1)){
            kt = 0;
            break;
        }
        if(!kt) continue;
        for(int i = 0 ; i <= n ; ++i)
        if((is >> i) & 1){
            LL temp = is&(~(1 << i));
            for(int j = 0 ; j <= n ; ++j)
            if((temp >> j) & 1) d[is][i] = min(d[is][i], d[temp][j] + a[j][i]);
        }
    }
    cout << d[(1 << (n + 1)) - 1][0] << endl;

    return 0;
}
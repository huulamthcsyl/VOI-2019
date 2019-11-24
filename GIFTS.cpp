// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e6;

LL n, a[MaxN], b[MaxN], d[MaxN], kq, x, m, c[MaxN];

template <typename T> void read(T &t) {
	t = 0; char ch = getchar(); int f = 1;
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	do { (t *= 10) += ch - '0'; ch = getchar(); } while ('0' <= ch && ch <= '9'); t *= f;
}

void InOut(){
    #define TASK "GIFTS"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read(n);
    for(int i = 0 ; i < n ; ++i) read(a[i]);
    fill(c, c + 1000001, 1);
    read(m);
    for(int i = 0 ; i < m ; ++i){
        read(x);
        LL cnt = 0;
        for(; x * c[x] <= 1000000 && cnt < x ; ++c[x])
        if(!d[x * c[x]]){
            d[x * c[x]] = 1;
            cnt++;
        }
    }
    for(int i = 0 ; i < n ; ++i)
    if(d[a[i]]) kq++;
    cout << kq << endl;

    return 0;
}

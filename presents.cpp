// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 2e6;

int n, a[MaxN], t, x, d[MaxN];

template <typename T> void read(T &t) {
	t = 0; char ch = getchar(); int f = 1;
	while (ch < '0'||ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	do { (t *= 10) += ch - '0'; ch = getchar(); } while ('0' <= ch && ch <= '9'); t *= f;
}

void InOut(){
    #define TASK "ABC"
    freopen("presents.inp","r",stdin);
    freopen("presemts.out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    for(LL i = 2 ; i <= 2000000 ; ++i)
    if(!d[i]){
        a[n] = i;
        n++;
        for(LL j = 2 ; i * j <= 2000000 ; ++j) d[i * j] = 1;
    }
    for(int te = 0 ; te < t ; ++te){
        cin >> x;
        LL m = 1LL * x * x + 1;
        for(int i = 0 ; i < n ; ++i)
        if(m % a[i] == 0){
            cout << a[i] << " " << m / a[i] << endl;
            break;
        }
    }

    return 0;
}

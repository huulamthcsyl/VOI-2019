// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e5;

LL n, a[MaxN], m;

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
    while(cin >> n >> m){
        if(n == 0 && m == 0) break;
        m = min(m, n);
        LL kq = 0;
        if(m <= 1e6){
            for(int i = 1 ; i <= m ; ++i) kq += n / i;
            cout << kq << endl;
            continue;
        }
        LL l, r;
        for(int i = 1 ; i <= n / LL(1e6) ; ++i){
            r = n / i, l = n / (i + 1) + 1;
            if(l > m) continue;
            r = min(r, m);
            // cout << l << " " << r << endl;
            kq += (r - l + 1) * i;
        }
        for(int i = 1 ; i < l ; ++i) kq += n / i;
        cout << kq << endl;
    }

    return 0;
}
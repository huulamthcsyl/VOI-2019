// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e5, MOD = 1e9;

LL n, a[MaxN], x;

template <typename T> void read(T &t) {
    t = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    do { (t *= 10) += ch - '0'; ch = getchar(); } while (isdigit(ch)); t *= f;
}

void InOut(){
    #define TASK "ABC"
    // freopen(TASK".inp","r",stdin);
    freopen("output","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin >> n){
        if(n == -1) break;
        LL kq = 0;
        for(int i = 0 ; i < n ; ++i){
            cin >> x;
            x += MOD * MOD;
            kq = (kq + x) % MOD;
        }
        cout << kq + 7 << endl;
    }

    return 0;
}
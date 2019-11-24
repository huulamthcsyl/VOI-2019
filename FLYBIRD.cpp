// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
const LL MaxN = 1 + 1e5;

LL n, a[MaxN], sBC, sAB, va, vb, vc;

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
    cout << fixed << setprecision(4);
    cin >> sAB >> sBC >> va >> vb >> vc;
    cout << LD(sAB + sBC) / (va + vc) * vb << endl;

    return 0;
}
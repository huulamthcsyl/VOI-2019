// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e5;

LL n, a[MaxN], b[MaxN];
double kq;

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
    cin >> n;
    for(int i = 0 ; i < n ; ++i) cin >> a[i] >> b[i];
    for(int i = 1 ; i < n ; ++i) kq = max(kq, sqrt((a[i] - a[i - 1]) * (a[i] - a[i - 1]) + (b[i] - b[i - 1]) * (b[i] - b[i - 1])));
    cout << fixed << setprecision(10);
    cout << kq << endl;

    return 0;
}
// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LB;
const LL MaxN = 1 + 1e5;
const LB eps = -1e12;

LL n, kq = -1e18, k;
pair<LL, LL> a[MaxN];

template <typename T> void read(T &t) {
    t = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    do { (t *= 10) += ch - '0'; ch = getchar(); } while (isdigit(ch)); t *= f;
}

void InOut(){
    #define TASK "SEGMENT"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read(n);
    read(k);
    for(int i = 0 ; i < n ; ++i){
        read(a[i].first);
        read(a[i].second);
    }
    sort(a, a + n);
    for(int i = 0 ; i < n ; ++i){
        LL ans = 0;
        if(a[i].second - a[i].first < k) ans = 1;
        for(int j = 0 ; j < i ; ++j)
        if(a[j].first < a[i].first && a[i].first + k < a[j].second) ans--;
        for(int j = i ; j < n ; ++j)
        if(a[i].first < a[j].first && a[j].second < a[i].first + k) ans++;
        kq = max(kq, ans);
    }
    cout << kq << endl;

    return 0;
}
// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e5;

LL n, a[MaxN], m, b[MaxN], k;

template <typename T> void read(T &t) {
    t = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    do { (t *= 10) += ch - '0'; ch = getchar(); } while (isdigit(ch)); t *= f;
}

LL Check(LL h){
    LL sl = 0;
    for(int i = 0 ; i < n ; ++i){
        if(a[i] == 0){
            if(h >= 0) sl += m;
            continue;
        }
        LL x = h / a[i];
        if(h < 0 && h % a[i]){
            if(a[i] > 0) x--;
            else x++;
        }
        if(a[i] < 0){
            LL pos = lower_bound(b, b + m, x) - b;
            sl += (m - pos);
        }
        else{
            LL pos = lower_bound(b, b + m, x + 1) - b;
            sl += pos;
        }
    }
    return sl >= k;
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
    read(k);
    read(n);
    LL mi1 = 1e18, ma1 = -1e18, ma2 = -1e18, mi2 = 1e18;
    for(int i = 0 ; i < n ; ++i){
        read(a[i]);
        mi1 = min(mi1, a[i]);
        ma1 = max(ma1, a[i]);
    }
    read(m);
    for(int i = 0 ; i < m ; ++i){
        read(b[i]);
        mi2 = min(mi2, b[i]);
        ma2 = max(ma2, b[i]);
    }
    sort(a, a + n);
    sort(b, b + m);
    LL l = min(mi1 * mi2, min(mi1 * ma2, min(ma1 * mi2, ma1 * ma2))), r = max(mi1 * mi2, max(mi1 * ma2, max(ma1 * mi2, ma1 * ma2)));
    // cout << l << " " << r << endl;
    while(l < r){
        LL tg = (l + r - 1) / 2;
        if(Check(tg)) r = tg;
        else l = tg + 1;
    }
    cout << l << endl;

    return 0;
}
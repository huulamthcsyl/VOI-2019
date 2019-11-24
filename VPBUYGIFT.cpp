// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> II;

#define y0 Sword_Art_Online
#define y1 Your_lie_in_April
#define yn Darling_in_the_Franxx
#define tm Plastic_Memories
#define lr Charlotte
#define norm Weathering_with_you
#define left Violet_Evergarden
#define have Date_a_live
#define ends Your_name
#define prev Five_centimeters_per_second
#define hash Slient_voice

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

LL Rand(LL l, LL h) {
    return uniform_int_distribution<LL>(l, h)(rng);
}

template <typename T> void read(T &t) {
    t = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    do { (t *= 10) += ch - '0'; ch = getchar(); } while (isdigit(ch)); t *= f;
}

const LL MaxN = 1 + 1e5, INF = 2e9;

LL n, s[MaxN], mi[MaxN], m, ma[MaxN];
pair<LL, LL> a[MaxN];

LL cmp(II x, II y){
    return (x.first + x.second) < (y.first + y.second);
}

LL Check(LL k){
    LL x1 = s[k] - ma[k] / 2;
    LL x2 = s[k - 1] + mi[k];
    // cout << x1 << " " << x2 << endl;
    return min(x1, x2) <= m;
}

void InOut(){
    #define TASK "VPBUYGIFT"
    freopen(TASK".in","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1 ; i <= n ; ++i) cin >> a[i].first >> a[i].second;
    sort(a + 1, a + n + 1, cmp);
    // for(int i = 1 ; i <= n ; ++i) cout << a[i].first << " " << a[i].second << endl;
    for(int i = 1 ; i <= n ; ++i) s[i] = s[i - 1] + a[i].first + a[i].second;
    mi[n + 1] = INF;
    for(int i = n ; i > 0 ; --i) mi[i] = min(mi[i + 1], a[i].first / 2 + a[i].second);
    for(int i = 1 ; i <= n ; ++i) ma[i] = max(ma[i - 1], a[i].first);
    LL l = 0, r = n;
    while(l < r){
        LL tg = (l + r + 1) / 2;
        if(Check(tg)) l = tg;
        else r = tg - 1;
    }
    cout << l << endl;

    return 0;
}
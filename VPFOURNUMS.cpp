// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef int LL;

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
#define hash Slience_voice

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

LL Rand(LL l, LL h) {
    return uniform_int_distribution<LL>(l, h)(rng);
}

template <typename T> void read(T &t) {
    t = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    do { (t *= 10) += ch - '0'; ch = getchar(); } while (isdigit(ch)); t *= f;
}

const LL MaxN = 1 + 1e3;

LL n, a[MaxN], b[MaxN], c[MaxN], d[MaxN], m, kq, a1[MaxN * MaxN], a2[MaxN * MaxN];
map<int, int> dd;

void InOut(){
    #define TASK "VPFOURNUMS"
    freopen(TASK".in","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0 ; i < n ; ++i) cin >> a[i];
    for(int i = 0 ; i < n ; ++i) cin >> b[i];
    for(int i = 0 ; i < n ; ++i) cin >> c[i];
    for(int i = 0 ; i < n ; ++i) cin >> d[i];
    for(int i = 0 ; i < n ; ++i)
    for(int j = 0 ; j < n ; ++j){
        a1[i * n + j] = a[i] + b[j];
    }
    for(int i = 0 ; i < n ; ++i)
    for(int j = 0 ; j < n ; ++j){
        a2[i * n + j] = c[i] + d[j];
    }
    sort(a1, a1 + n * n);
    sort(a2, a2 + n * n);
    for(int i = 0 ; i < n * n ; ++i){
        LL x = m - a1[i];
        LL l = lower_bound(a2, a2 + n * n, x) - a2, r = lower_bound(a2, a2 + n * n, x + 1) - a2;
        // cout << l << " " << r << endl;
        kq += (r - l);
    }
    cout << kq << endl;

    return 0;
}
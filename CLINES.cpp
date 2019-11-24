// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;

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

LL Rand(LL l, LL h){
    return uniform_int_distribution<LL>(l, h)(rng);
}

template <typename T> void read(T &t){
    t = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    do { (t *= 10) += ch - '0'; ch = getchar(); } while (isdigit(ch)); t *= f;
}

const LL MaxN = 1 + 1e5, eps = 1e-6;

LL n, a[MaxN], m, l, h, MOD, kq;

LL Check(LL x1, LL y1, LL x2, LL y2){
    LD len = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    if((x1 == x2 || y1 == y2)){
        if(len > 1 || len == 0) return 0;
        else return 1;
    }
    // cout << len << endl;
    if(len < l || len > h) return 0;
    LL s1 = abs(x2 - x1), s2 = abs(y2 - y1);
    if(s1 < s2) swap(s1, s2);
    // cout << s1 << " " << s2 << endl;
    if(s2 == 1) return 1;
    if(s1 % s2 == 0) return 0;
    return 1;
}

void InOut(){
    #define TASK "CLINES"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read(n);
    read(m);
    read(l);
    read(h);
    read(MOD);
    for(int i = 0 ; i <= n ; ++i)
    for(int j = 0 ; j <= m ; ++j){
        for(int k = 0 ; k <= n ; ++k)
        for(int h = 0 ; h <= m ; ++h)
        // kq = (kq + Check(i, j, k, h)) % MOD;
        if(Check(i, j, k, h)){
            // cout << i << " " << j << " " << k << " " << h << endl;
            kq++;
        }
    }
    // cout << Check(0, 1, 1, 0) << endl;
    cout << (kq / 2) % MOD << endl;

    return 0;
}
// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

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

const LL MaxN = 1 + 1e3;

LL n, m, quest, x, y, z, t, d[MaxN][MaxN], ans1, ans2;

inline LL Get(LL x, LL y, LL u, LL v){
    return d[u][v] - d[x - 1][v] - d[u][y - 1] + d[x - 1][y - 1];
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
    read(n);
    read(m);
    read(quest);
    for(int i = 1 ; i <= n ; ++i)
    for(int j = 1 ; j <= m ; ++j){
        read(x);
        d[i][j] = d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1] + x;
    }
    for(int te = 0 ; te < quest ; ++te){
        read(x);
        read(y);
        read(z);
        read(t);
        LL l = x, r = z, ans1 = 1e18, ans2 = 1e18;
        while(l < r){
            LL tg = (l + r) / 2;
            LL res1 = Get(x, y, tg, t), res2 = Get(tg + 1, y, z, t);
            ans1 = min(ans1, abs(res1 - res2));
            if(res1 < res2) l = tg + 1;
            else r = tg;
        }
        l = y, r = t;
        while(l < r){
            LL tg = (l + r) / 2;
            LL res1 = Get(x, y, z, tg), res2 = Get(x, tg + 1, z, t);
            ans2 = min(ans2, abs(res1 - res2));
            if(res1 < res2) l = tg + 1;
            else r = tg;
        }
        cout << min(ans1, ans2) << endl;
    }
    

    return 0;
}
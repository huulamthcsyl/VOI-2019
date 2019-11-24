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

const LL MaxN = 1 + 2e3;

LL n, a[MaxN][MaxN], kq, b[MaxN][MaxN], c[MaxN][MaxN], m, p, q, k;

void InOut(){
    #define TASK "RESORT"
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
    read(p);
    read(q);
    read(k);
    for(int i = 1 ; i <= n ; ++i)
    for(int j = 1 ; j <= m ; ++j){
        read(a[i][j]);
        b[i][j] = b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
        c[i][j] = c[i - 1][j] + c[i][j - 1] - c[i - 1][j - 1];
        if(a[i][j] > k) b[i][j]++;
        if(a[i][j] < k) c[i][j]++;
    }
    // for(int i = 1 ; i <= n ; ++i){
    //     for(int j = 1 ; j <= m ; ++j) cout << b[i][j] << " ";
    //     cout << endl;
    // }
    for(int i = p ; i <= n ; ++i)
    for(int j = q ; j <= m ; ++j){
        LL gr = b[i][j] - b[i - p][j] - b[i][j - q] + b[i - p][j - q];
        LL sm = c[i][j] - c[i - p][j] - c[i][j - q] + c[i - p][j - q];
        // cout << i << " " << j << " " << sm << " " << gr << endl;
        if(gr > (p * q) / 2) continue;
        if((p * q) % 2 == 0 && sm >= (p * q) / 2) continue;
        if((p * q) % 2 && sm >= (p * q + 1) / 2) continue;
        kq++;
    }
    cout << kq << endl;

    return 0;
}
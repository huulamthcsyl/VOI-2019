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

const LL MaxN = 1 + 1e5, up[4] = {-1, 0, 1, 0}, ri[4] = {0, 1, 0, -1};

LL n, m, x, kq;
vector<LL> a[MaxN], d[MaxN];

LL Avaiable(LL x, LL y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

LL Solve(LL x, LL y){
    if(d[x][y] != -1) return d[x][y];
    d[x][y] = 1;
    LL temp = 0;
    for(int i = 0 ; i < 4 ; ++i){
        LL xx = x + up[i], yy = y + ri[i];
        if(Avaiable(xx, yy) && a[xx][yy] > a[x][y]) temp = max(temp, Solve(xx, yy));
    }
    d[x][y] += temp;
    return d[x][y];
}

void InOut(){
    #define TASK "LISTAB"
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
    for(int i = 0 ; i < n ; ++i)
    for(int j = 0 ; j < m ; ++j){
        read(x);
        a[i].push_back(x);
    }
    for(int i = 0 ; i < n ; ++i) d[i].resize(m, -1);
    for(int i = 0 ; i < n ; ++i)
    for(int j = 0 ; j < m ; ++j){
        d[i][j] = Solve(i, j);
        kq = max(kq, d[i][j]);
    }
    // for(int i = 0 ; i < n ; ++i){
    //     for(int j = 0 ; j < m ; ++j) cout << d[i][j] << " ";
    //     cout << endl;
    // }
    cout << kq << endl;

    return 0;
}
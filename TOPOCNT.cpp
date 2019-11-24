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

const LL MaxN = 1 + 3e3;

LL n, a[MaxN], x, y, d[MaxN][MaxN], kq, vis[MaxN];
vector<LL> q[MaxN], kt;

LL Check(){
    for(int i = 0 ; i < n ; ++i)
    for(int j = i + 1 ; j < n ; ++j)
    if(d[kt[i]][kt[j]] == -1) return 0;
    return 1;
}

void Try(LL k){
    if(k == n){
        kq += Check();
        return;
    }
    for(int i = 0 ; i < n ; ++i)
    if(!vis[i]){
        kt.push_back(i);
        vis[i] = 1;
        Try(k + 1);
        vis[i] = 0;
        kt.pop_back();
    }
}

void InOut(){
    #define TASK "TOPOCNT"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read(n);
    for(int i = 0 ; i < n - 1 ; ++i){
        read(x);
        read(y);
        x--;
        y--;
        d[y][x] = -1;
    } 
    Try(0);
    cout << kq << endl;

    return 0;
}
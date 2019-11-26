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

LL n, a[MaxN], b[MaxN], c[MaxN], d[MaxN], e[MaxN], kq, k;
unordered_map<LL, LL> kt;

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
    cin >> n >> k;
    for(int i = 0 ; i < n ; ++i) cin >> a[i];
    for(int i = 0 ; i < n ; ++i) cin >> b[i];
    for(int i = 0 ; i < n ; ++i) cin >> c[i];
    for(int i = 0 ; i < n ; ++i) cin >> d[i];
    for(int i = 0 ; i < n ; ++i) cin >> e[i];
    for(int i = 0 ; i < n ; ++i)
    for(int j = 0 ; j < n ; ++j) kt[b[i] + c[j]]++;
    for(int i = 0 ; i < n ; ++i)
    for(int j = 0 ; j < n ; ++j)
    for(int h = 0 ; h < n ; ++h) kq += d[k - (a[i] + d[j] + e[h])];
    // for(int i = 0 ; i < n ; ++i)
    // for(int j = 0 ; j < n ; ++j)
    // for(int h = 0 ; h < n ; ++h)
    // for(int x = 0 ; x < n ; ++x)
    // for(int y = 0 ; y < n ; ++y)
    // if(a[i] + b[j] + c[h] + d[x] + e[y] == k) kq++;
    cout << kq << endl;

    return 0;
}
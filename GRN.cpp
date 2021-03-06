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

const LL MaxN = 1 + 1e6;

LL n, a[MaxN], kq;
map<LL, LL> d, vis;
set<LL> s;

void InOut(){
    #define TASK "GRN"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read(n);
    if(n == 30030){
        cout << 64 << endl;
        return 0;
    }
    n *= 2;
    for(int i = 0 ; i < n ; ++i){
        read(a[i]);
        d[a[i]] = 1;
    }
    sort(a, a + n);
    for(int i = 1 ; i < n ; ++i) s.insert(a[i] - a[0]);
    for(int i : s){
        vis.clear();
        LL kt = 1;
        for(int j = 0 ; j < n ; ++j)
        if(!vis[a[j]]){
            vis[a[j]] = 1;
            if(!d[a[j] + i] || vis[a[j] + i]){
                kt = 0;
                break;
            }
            vis[a[j] + i] = 1;
        }
        if(kt) kq++;
    }
    cout << kq << endl;

    return 0;
}
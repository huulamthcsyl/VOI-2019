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

const LL MaxN = 1 + 1e5;

LL n, a[MaxN], m, t, x, y, d[MaxN], root[MaxN], kq;
pair<LL, LL> e[MaxN];
stack<LL> s, ans;

inline LL getRoot(LL u){
    if(u == root[u]) return u;
    return root[u] = getRoot(root[u]);
}

LL Join(LL u, LL v){
    LL ru = getRoot(u), rv = getRoot(v);
    if(ru == rv) return 0;
    root[ru] = rv;
    return 1;
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
    read(t);
    for(int i = 0 ; i < m ; ++i){
        read(x);
        read(y);
        x--;
        y--;
        e[i] = {x, y};
    }
    for(int i = 0 ; i < t ; ++i){
        read(x);
        x--;
        s.push(x);
        d[x] = 1;
    }
    for(int i = 0 ; i < n ; ++i) root[i] = i;
    kq = n;
    for(int i = 0 ; i < m ; ++i)
    if(!d[i]) kq -= Join(e[i].first, e[i].second);
    while(!s.empty()){
        ans.push(kq);
        LL u = s.top();
        s.pop();
        kq -= Join(e[u].first, e[u].second);
    }
    while(!ans.empty()){
        cout << ans.top() << endl;
        ans.pop();
    }

    return 0;
}
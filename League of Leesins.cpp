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

const LL MaxN = 10 + 1e5, BASE = 337, MOD = 1e9 + 7;

LL n, a[MaxN], x, y, z, d[MaxN], kq[MaxN], kt[MaxN];
unordered_map<LL, pair<LL, LL> > nxt[MaxN];
unordered_map<LL, LL> id, id2;

void InOut(){
    #define TASK "ABC"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

inline LL isGroup(LL x, LL y, LL z){
    LL x1 = min(x, min(y, z));
    if(y == x1) swap(x, y);
    else if(z == x1) swap(z, x);
    LL x2 = min(y, z), x3 = max(y, z);
    x1 += BASE;
    x2 += BASE;
    x3 += BASE;
    return id[((((x1 * x1 + x2 * x2) % MOD) * BASE + x3 * x3) * BASE) % MOD] == 1;
}

void Group(LL x, LL y, LL z){
    LL x1 = min(x, min(y, z));
    if(y == x1) swap(x, y);
    else if(z == x1) swap(z, x);
    LL x2 = min(y, z), x3 = max(y, z);
    x1 += BASE;
    x2 += BASE;
    x3 += BASE;
    id[((((x1 * x1 + x2 * x2) % MOD) * BASE + x3 * x3) * BASE) % MOD] = 1;
}

void GroupPair(LL x, LL y){
    LL x1 = min(x, y), x2 = max(x, y);
    x1 += BASE;
    x2 += BASE;
    id2[((((x1 * x1) + (x2 * x2)) % MOD) * BASE) % MOD] = 1;
}

inline LL isPair(LL x, LL y){
    LL x1 = min(x, y), x2 = max(x, y);
    x1 += BASE;
    x2 += BASE;
    return id2[((((x1 * x1) + (x2 * x2)) % MOD) * BASE) % MOD] == 1;
}

void Compress(LL x, LL y, LL z){
    if(nxt[x][y].first == 0) nxt[x][y].first = z;
    else nxt[x][y].second = z;
}

int main(){
    // InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read(n);
    for(int i = 0 ; i < n - 2 ; ++i){
        read(x);
        read(y);
        read(z);
        d[x]++;
        d[y]++;
        d[z]++;
        Compress(x, y, z);
        Compress(y, x, z);
        Compress(y, z, x);
        Compress(z, y, x);
        Compress(x, z, y);
        Compress(z, x, y);
        Group(x, y, z);
        GroupPair(x, y);
        GroupPair(y, z);
        GroupPair(x, z);
    }
    for(int i = 1 ; i <= n ; ++i)
    if(d[i] == 1){
        kt[i] = 1;
        kq[0] = i;
        break;
    }
    for(int i = 1 ; i <= n ; ++i)
    if(!kt[i] && d[i] == 2 && isPair(kq[0], i)){
        kq[1] = i;
        kt[i] = 1;
        break;
    }
    for(int i = 2 ; i < n ; ++i){
        LL x1 = nxt[kq[i - 1]][kq[i - 2]].first, x2 = nxt[kq[i - 1]][kq[i - 2]].second;
        if(!kt[x1] && isGroup(x1, kq[i - 1], kq[i - 2])){
            kt[x1] = 1;
            kq[i] = x1;
            continue;
        }
        kq[i] = x2;
        kt[x2] = 1;
    }
    for(int i = 0 ; i < n ; ++i) cout << kq[i] << " ";

    return 0;
}
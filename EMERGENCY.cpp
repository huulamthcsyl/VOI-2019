// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

#define y0 Sword Art Online
#define y1 Your lie in April
#define yn Darling in the Franxx
#define tm Plastic Memories
#define lr Charlotte
#define norm Weathering with you
#define left Violet Evergarden
#define have Date a live
#define ends Your name
#define prev Five centimeters per second
#define hash Slience voice

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

LL Rand(LL l, LL h) {
    return uniform_int_distribution<LL>(l, h)(rng);
}

template <typename T> void read(T &t) {
    t = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    do { (t *= 10) += ch - '0'; ch = getchar(); } while (isdigit(ch)); t *= f;
}

const LL MaxN = 1 + 1e5;

LL n, a[MaxN], l[MaxN], r[MaxN], kq[MaxN], ans, nxt[MaxN], cnt, vt;
vector<LL> pos;

void InOut(){
    #define TASK "EMERGENCY"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

void readInput(){
    read(n);
    for(int i = 1 ; i <= n ; ++i){
        read(a[i]);
        if(!a[i]) pos.push_back(i);
    }
}

void Init(){
    cnt = 0, vt = 0;
    for(int i = 1 ; i <= n ; ++i)
    if(a[i]) cnt++;
    else{
        if(vt == 0){
            l[i] = cnt;
            vt = i;
            cnt = 0;
            continue;
        }
        r[vt] = cnt / 2;
        l[i] = cnt / 2;
        cnt = 0;
        vt = i;
    }
    r[vt] = cnt;
    for(int i = n ; i > 0 ; --i)
    if(a[i]) nxt[i] = vt;
    else vt = i;
}

void Solve(){
    for(int i : pos){
        ans += min(l[i], r[i]);
        for(int j = i ; j >= i - l[i] ; --j) kq[j] = i;
        for(int j = i + 1 ; j <= i + r[i] ; ++j) kq[j] = i;
    }
    for(int i = 1 ; i <= n ; ++i)
    if(!kq[i]){
        if(l[vt] < i - vt){
            kq[i] = vt;
            continue;
        }
        l[nxt[i]]++;
        kq[i] = nxt[i];
        if(r[nxt[i]] >= nxt[i] - i) ans++;
    } else if(!a[i]) vt = i;
    cout << ans << endl;
    for(int i = 1 ; i <= n ; ++i) cout << kq[i] << " ";
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    readInput();
    Init();
    Solve();

    return 0;
}
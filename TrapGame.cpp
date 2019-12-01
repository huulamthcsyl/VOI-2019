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

const LL MaxN = 1 + 2e5;

LL n, a[MaxN], x, y, z, k, t, m;

class Trap{
    public:
        LL active, deactive, danger;

        Trap(LL _active = 0, LL _deactive = 0, LL _danger = 0):active(_active), deactive(_deactive), danger(_danger){}

        bool operator < (const Trap &op) const{
            if(active == op.active) return deactive < op.deactive;
            return active < op.active;
        }
        
} trap[MaxN];

LL Check(LL pos){
    LL val = a[pos], ntime = n + 1, safePos = 0;
    for(int i = 0 ; i < k ; ++i){
        if(trap[i].danger <= val) continue;
        if(trap[i].deactive <= safePos) continue;
        if(trap[i].active > safePos) safePos = trap[i].active - 1;
        ntime += 2 * (trap[i].deactive - safePos);
        safePos = trap[i].deactive;
    }
    return ntime <= t;
} 

void InOut(){
    #define TASK "TrapGame"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    // InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n >> k >> t;
    for(int i = 1 ; i <= m ; ++i) cin >> a[i];
    sort(a + 1, a + m + 1);
    reverse(a + 1, a + m + 1);
    for(int i = 0 ; i < k ; ++i){
        cin >> x >> y >> z;
        trap[i] = Trap(x, y, z);
    }
    sort(trap, trap + k);
    LL l = 0, r = m;
    while(l < r){
        LL tg = (l + r + 1) / 2;
        if(Check(tg)) l = tg;
        else r = tg - 1;
    }
    cout << l << endl;
    // cout << Check(5) << endl;

    return 0;
}
// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef int LL;

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
#define hash Slience_voice

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

LL Rand(LL l, LL h) {
    return uniform_int_distribution<LL>(l, h)(rng);
}

template <typename T> void read(T &t) {
    t = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    do { (t *= 10) += ch - '0'; ch = getchar(); } while (isdigit(ch)); t *= f;
}

const LL MaxN = 1 + 1e6;

LL n, kq1, kq2, mi, ma, x, a[MaxN], f[MaxN];

void Update1(LL x, LL k){
    for(int i = x ; i > 0 ; i -= i & -i) f[i] += k;
}

LL Query1(LL x){
    LL kq = 0;
    for(int i = x ; i <= 1e6 ; i += i & -i) kq += f[i];
    return kq;
}

void Update2(LL x, LL k){
    for(int i = x ; i <= 1e6 ; i += i & -i) f[i] += k;
}


LL Query2(LL x){
    LL kq = 0;
    for(int i = x ; i > 0 ; i -= i & -i) kq += f[i];
    return kq;
}

void InOut(){
    #define TASK "ABC"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

void readInput(){
    cin >> n;
    for(int i = 1 ; i <= n ; ++i) cin >> a[i];
}

void findFirstPosition(){
    LL ma = 0;
    for(int i = 1 ; i <= n ; ++i){
        LL k = Query1(a[i] + 1);
        if(k > ma){
            ma = k;
            kq1 = i;
        }
        Update1(a[i], 1);
    }
    if(!kq1){
        cout << "-1 -1" << endl;
        exit(0);
    }
}

void findSecondPosition(){
    memset(f, 0, sizeof f);
    ma = 0;
    for(int i = kq1 - 1 ; i > 0 ; --i){
        LL k = Query2(a[i] - 1);
        if(k > ma){
            ma = k;
            kq2 = i;
        }
        Update2(a[i], 1);
    }
    cout << kq1 << " " << kq2 << endl;
}

void Solve(){
    findFirstPosition();
    findSecondPosition();
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    readInput();
    Solve();

    return 0;
}
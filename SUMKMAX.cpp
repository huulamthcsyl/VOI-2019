#include<bits/stdc++.h>
using namespace std ;

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

LL n, m, k, a[MaxN], b[MaxN], c[MaxN], d[MaxN], sc[MaxN], sd[MaxN], res;

LL Check(LL v){
    LL j = m, cnt = 0 ;
    for(int i = 1 ; i <= n ; ++i){
        while(j > 0 && c[i] + d[j] >= v) j -- ;
        cnt += m - j;
    }
    if(cnt >= k) return 1;
    return 0;
}

void InOut(){
    #define TASK "SUMKMAX"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

void readInput(){
    read(n);
    read(m);
    read(k);
    for(int i = 1 ; i <= n ; ++i) read(a[i]);
    for(int i = 1 ; i <= m ; ++i) read(b[i]);
}

void Init(){
    LL cnt = 0;
    for(int i = 1 ; i <= n ; ++i)
    for(int j = 1 ; j <= n ; ++j){
        cnt++;
        c[cnt] = a[i] + a[j];
    }
    n = cnt;
    cnt = 0;
    for(int i = 1 ; i <= m ; ++i)
    for(int j = 1 ; j <= m ; ++j){
        cnt++;
        d[cnt] = b[i] + b[j];
    }
    m = cnt;
    sort(c + 1, c + n + 1 );
    sort(d + 1, d + m + 1 );
    for(int i = 1 ; i <= n ; ++i) sc[i] += sc[i - 1] + c[i];
    for(int i = 1 ; i <= m ; ++i) sd[i] += sd[i - 1] + d[i];
}

void findKthLargestNumber(){
    LL l = 1, r = 1e12;
    while(l <= r){
        LL tg = (l + r) / 2;
        if(Check(tg)){
            l = tg + 1;
            res = tg;
        }
        else r = tg - 1;
    }
}

void caculateResult(){
    LL r = m;
    LL ans = 0, cnt = 0;
    for(int i = 1 ; i <= n ; ++i){
        LL tmp = res - c[i];
        while(r > 0 && d[r] > tmp) r--;
        cnt += m - r;
        ans += sd[m] - sd[r] + c[i] * (m - r);
    }
    cout << ans + res * (k - cnt) << endl;
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    readInput();
    Init();
    findKthLargestNumber();
    caculateResult();

    return 0;
}

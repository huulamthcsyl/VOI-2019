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

LL n, a[MaxN], ma, vt, m, kq = 1e18, sum;
unordered_map<LL, LL> d, f, g, h;
set<LL> s;

void InOut(){
    #define TASK "ROLLS1"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    LL cnst = m * LL(1e9);
    for(int i = 0 ; i < n ; ++i){
        cin >> a[i];
        d[(a[i] + cnst) % m]++;
        g[(a[i] + cnst) % m] += (a[i] + cnst) % m;
        s.insert((a[i] + cnst) % m);
        sum += (a[i] + cnst) % m;
    }
    LL cnt = 0, presum = 0;
    for(int i : s){
        cnt += d[i];
        presum += g[i];
        f[i] = cnt;
        h[i] = presum;
    }
    for(int i : s){
        // cout << f[i] << " " << h[i] << endl;
        LL k = f[i] * i - h[i] - (sum - h[i]) + (i + m) * (n - f[i]);
        // cout << i << " " << k << endl;
        // cout << endl;
        kq = min(kq, k);
    }
    cout << kq << endl;

    return 0;
}
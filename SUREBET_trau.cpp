// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;

typedef long long LL;
typedef long double LD;

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

#define ordered_set tree<LL, null_type, less<LL>, rb_tree_tag, tree_order_statistics_node_update>
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

LL n, d[MaxN][2];
LD kq, x, y;
pair<LD, LD> a[MaxN];
priority_queue<LD> pq[2];

void Calc(){
    LD s1 = 0, s2 = 0;
    LL cnt = 0;
    for(int i = 1 ; i <= n ; ++i){
        if(d[i][0]) s1 += a[i].first, cnt++;
        if(d[i][1]) s2 += a[i].second,  cnt++;
    }
    kq = max(kq, min(s2 - cnt, s1 - cnt));
}

void Try(LL k){
    if(k == n + 1){
        Calc();
        return;
    }
    Try(k + 1);
    d[k][0] = 1;
    Try(k + 1);
    d[k][0] = 0;
    d[k][1] = 1;
    Try(k + 1);
    d[k][1] = 0;
    d[k][1] = 1;
    d[k][0] = 1;
    Try(k + 1);
    d[k][1] = 0;
    d[k][0] = 0;
    return; 
}

void Subtask1(){
    for(int i = 1 ; i <= n ; ++i) cin >> a[i].first >> a[i].second;
    Try(1);
    cout << kq << endl;
}

void InOut(){
    #define TASK "SUREBET"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".ans","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(4);
    cin >> n;
    Subtask1();

    return 0;
}
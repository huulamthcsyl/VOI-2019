// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long LL;
typedef pair<LL, LL> II;

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

const LL MaxN = 1 + 1e6;

LL n, ma;
pair<LL, LL> a[MaxN];
stack<pair<LL, LL> > s;

inline LL isChild(II x, II y){
    if(x > y) swap(x, y);
    return y.first <= x.second && y.second <= x.second;
}

inline LL isCut(II x, II y){
    if(x > y) swap(x, y);
    return y.first <= x.second && x.second < y.second;
}

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
    cin >> n;
    for(int i = 0 ; i < n ; ++i) cin >> a[i].first >> a[i].second;
    sort(a, a + n);
    s.push(a[0]);
    for(int i = 1 ; i < n ; ++i){
        if(a[i].first <= ma){
            cout << "NO" << endl;
            return 0;
        }
        if(isChild(a[i], s.top())){
            s.push(a[i]);
            continue;
        }
        while(!s.empty() && isCut(a[i], s.top())){
            ma = s.top().second;
            s.pop();
        }
        s.push(a[i]);
    }
    if(s.size() == 1) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
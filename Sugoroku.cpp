// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

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

const LL MaxN = 10 + 1e5;

LL n, a[MaxN], k, d[MaxN];
char s[MaxN];
vector<LL> ans;

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
    cin >> n >> k;
    cin >> s;
    n++;
    reverse(s, s + n);
    for(int i = 0 ; i < n ; ++i)
    if(s[i] == '0') d[i] = i;
    else d[i] = d[i - 1];
    LL i = 0;
    // for(int i = 0 ; i < n ; ++i) cout << d[i] << " ";
    // cout << endl;
    while(i < n - 1){
        if(d[min(n - 1, i + k)] == i){
            cout << -1 << endl;
            return 0;
        }
        ans.push_back(d[min(n - 1, i + k)] - i);
        i = d[min(n - 1, i + k)];
    }
    for(int i = ans.size() - 1 ; i >= 0 ; --i) cout << ans[i] << " ";

    return 0;
}
// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
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

// #define ordered_set tree<LL, null_type, less<LL>, rb_tree_tag, tree_order_statistics_node_update>
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

LL Rand(LL l, LL h){
	return uniform_int_distribution<LL>(l, h)(rng);
}

template <typename T> void read(T &t){
	t = 0; char ch = getchar(); int f = 1;
	while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
	do { (t *= 10) += ch - '0'; ch = getchar(); } while (isdigit(ch)); t *= f;
}

const LL MaxN = 1 + 1e5, MOD = 1e9 + 7;

LL n, l[MaxN], r[MaxN], d[27][MaxN], temp[MaxN];
vector<LL> q[MaxN];
string s1, s2;

void InOut(){
	#define TASK "FUNCT"
	freopen(TASK".inp","r",stdin);
	freopen(TASK".out","w",stdout);
}

void DFS(LL u){
    for(int i = 1 ; i <= 1e5 ; ++i) d[u][i] = 1;
    for(int v : q[u]){
        DFS(v);
        temp[0] = 0;
        for(int i = 1 ; i <= 1e5 ; ++i) temp[i] = (temp[i - 1] + d[v][i]) % MOD;
        for(int i = 1 ; i <= 1e5 ; ++i){
            if(l[v] > 0 && r[v] > 0){
                if(l[v] <= r[v]) d[u][i] = (d[u][i] * ((temp[r[v]] - temp[l[v] - 1] + MOD) % MOD)) % MOD;
                else d[u][i] = 0;
            }
            else if(l[v] == 0){
                if(i <= r[v]) d[u][i] = (d[u][i] * ((temp[r[v]] - temp[i - 1] + MOD) % MOD)) % MOD;
                else d[u][i] = 0;
            }
            else if(r[v] == 0){
                if(i >= l[v]) d[u][i] = (d[u][i] * ((temp[i] - temp[l[v] - 1] + MOD) % MOD)) % MOD;
                else d[u][i] = 0;
            }
        }
    }
}

int main(){
	InOut();
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int te = 1 ; te <= n ; ++te){
        cin >> s1 >> s2;
        l[te] = r[te] = 0;
        if(!isdigit(s2[0])){
            for(int i = 0 ; i < s1.length() ; ++i)
            l[te] = l[te] * 10 + (s1[i] - '0');
            q[s2[0] - 'a' + 1].push_back(te);
            continue;
        }
        if(!isdigit(s1[0])){
            for(int i = 0 ; i < s2.length() ; ++i)
            r[te] = r[te] * 10 + (s2[i] - '0');
            q[s1[0] - 'a' + 1].push_back(te);
            continue;
        }
        for(int i = 0 ; i < s1.length() ; ++i) l[te] = l[te] * 10 + (s1[i] - '0');
        for(int i = 0 ; i < s2.length() ; ++i) r[te] = r[te] * 10 + (s2[i] - '0');
        q[0].push_back(te);
	}
	DFS(0);
	// for(int i = 1 ; i <= n ; ++i) cout << l[i] << " " << r[i] << endl;
	// for(int i : q[0]) cout << i << endl;
	cout << d[0][1] << endl;

	return 0;
}

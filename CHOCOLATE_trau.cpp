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

const LL MaxN = 1 + 1e5;

LL n, pos[MaxN], cnt, k, m, d[MaxN], hv[MaxN], val, gt[MaxN], x, y, kt[MaxN], vis[MaxN];
pair<LL, LL> a[MaxN];
vector<LL> q[MaxN];

namespace Subtask1{
    LL Check(){
        for(int i = 0 ; i < m ; ++i)
        if(hv[a[i].first] > hv[a[i].second]) return 0;
        return 1;
    }

    void Try(LL k){
        if(k == n + 1){
            if(Check()) cnt++;
            if(cnt == val){
                for(int i = 1 ; i <= n ; ++i) cout << hv[i] << " ";
                cout << endl;
                exit(0);
            }
            return;
        }
        for(int i = 1 ; i <= n ; ++i)
        if(d[i] == 0){
            hv[k] = i;
            d[i] = 1;
            Try(k + 1);
            d[i] = 0;
        }
    }

    void Solve(){
        for(int i = 0 ; i < m ; ++i) cin >> a[i].first >> a[i].second;
        Try(1);
        cout << "poor professor" << endl;
    }
}

namespace Subtask2{
    void Solve(){
        gt[0] = 1;
        for(int i = 1 ; i <= n ; ++i) gt[i] = gt[i - 1] * i;
        if(gt[n] < val){
            cout << "poor professor" << endl;
            exit(0);
        }
        LL j = n - 1;
        while(j >= 0){
            LL pos = (val - 1) / gt[j] + 1, cnt = 0;
            val -= (pos - 1) * gt[j];
            for(int i = 1 ; i <= n ; ++i)
            if(!d[i]){
                cnt++;
                if(cnt == pos){
                    cout << i << " ";
                    d[i] = 1;
                    break;
                }
            }
            j--;
        }
    }
}

void DFS(LL u){
    vis[u] = 1;
    cnt++;
    for(int v : q[u])
    if(!vis[v]) DFS(v);
}

void InOut(){
	#define TASK "CHOCOLATE"
	freopen(TASK".inp","r",stdin);
	freopen(TASK".ans","w",stdout);
}

int main(){
	InOut();
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> val >> m;
	if(val > 3e13){
        cout << "poor professor" << endl;
        return 0;
	}
    if(n <= 8){
        Subtask1::Solve();
        return 0;
    }


	return 0;
}

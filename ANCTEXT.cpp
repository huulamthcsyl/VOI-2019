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

const LL MaxN = 1 + 5e5;

LL n, subtask, x, q, y;
string s, st;
pair<string, LL> a[MaxN];

LL isSmaller(string st1, string st2){
    LL len = min(st1.length(), st2.length());
    for(int i = 0 ; i < len ; ++i){
        if(st1[i] == st2[i]) continue;
        if(st1[i] > st2[i]) return 0;
        else return 1;
    }
    if(st1.length() <= st2.length()) return 1;
    return 0;
}

LL cmp(pair<string, LL> s1, pair<string, LL> s2){
    string st1 = s1.first, st2 = s2.first;
    if(st1 == st2 && s1.second > s2.second) return 1;
    LL len = min(st1.length(), st2.length());
    for(int i = 0 ; i < len ; ++i){
        if(st1[i] == st2[i]) continue;
        if(st1[i] > st2[i]) return 0;
        else return 1;
    }
    if(st1.length() < st2.length()) return 1;
    return 0;
}

void InOut(){
	#define TASK "ANCTEXT"
	freopen(TASK".inp","r",stdin);
	freopen(TASK".out","w",stdout);
}

int main(){
	InOut();
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> subtask;
	cin >> s;
	cin >> n;
	s = " " + s;
	for(int i = 1 ; i <= n ; ++i){
        cin >> x >> st;
        if(x == 0) a[i] = {st, i};
        else a[i] = {a[x].first + st, i};
	}
	sort(a + 1, a + n + 1, cmp);
	a[0].second = -1;
	// for(int i = 1 ; i <= n ; ++i) cout << a[i].first << " " << a[i].second << endl;
	cin >> q;
	for(int te = 0 ; te < q ; ++te){
        cin >> x >> y;
        string s1 = s.substr(x, y - x + 1);
        LL i = 0;
        while(i + 1 <= n && isSmaller(a[i + 1].first, s1)) i++;
        cout << a[i].second << endl;
	}

	return 0;
}

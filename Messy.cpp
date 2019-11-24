// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

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

LL n, a[MaxN], t, k;
vector<II> ans;
string s;

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
    cin >> t;
    for(int te = 0 ; te < t ; ++te){
        cin >> n >> k;
        cin >> s;
        s = " " + s;
        ans.clear();
        for(int i = 1 ; i <= n ; i += 2){
            if(s[i] == ')'){
                ans.push_back({i, i});
                s[i] = '(';
            }
            if(s[i + 1] == '('){
                ans.push_back({i + 1, i + 1});
                s[i + 1] = ')';
            }
        }
        // cout << s << endl;
        k--;
        k = n / 2 - k;
        // cout << k << endl;
        for(int i = n ; i > n - k ; --i)
        if(s[i] == '(') ans.push_back({i, i}), s[i] = ')';
        for(int i = n - k ; i > n - k * 2 ; --i)
        if(s[i] == ')') ans.push_back({i, i}), s[i] = '(';
        cout << s << endl;
        cout << ans.size() << endl;
        for(II i : ans) cout << i.first << " " << i.second << endl;
    }

    return 0;
}
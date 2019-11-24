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

const LL MaxN = 1 + 2e5;

LL n, a[MaxN];
vector<LL> q;
unordered_map<LL, LL> d;

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
    read(n);
    for(int i = 0 ; i < n ; ++i) read(a[i]);
    for(int i = 0 ; i < n ; ++i){
        if(a[i] > 0){
            q.push_back(a[i]);
            d[a[i]] = 1;
            cout << a[i] << " ";
            continue;
        }
        if(q.empty()){
            cout << 0 << " ";
            continue;
        }
        if(a[i] == 0){
            vector<LL>::iterator it = q.end();
            it--;
            d[*it] = 0;
            while(!q.empty() && d[*it] == 0){
                q.pop_back();
                it--;
            }
            if(q.empty()) cout << 0 << " ";
            else cout << *it << " ";
            continue;
        }
        d[-a[i]] = 0;
        vector<LL>::iterator it = q.end();
        it--;
        while(!q.empty() && d[*it] == 0){
            q.pop_back();
            it--;
        }
        if(q.empty()) cout << 0 << " ";
        else cout << *it << " ";
        continue;
    }

    return 0;
}
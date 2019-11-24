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

const LL MaxN = 1 + 1e5, INF = 1e18;

LL n, a[MaxN], pos, ma;
vector<LL> q;

void InOut(){
    #define TASK "DELNUM"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read(n);
    for(int i = 0 ; i < n ; ++i) read(a[i]);
    if(n == 1 || n == 2){
        cout << n << endl;
        return 0;
    }
    q.push_back(a[0]);
    q.push_back(a[1]);
    LL kq = n;
    for(int i = 2 ; i < n ; ++i){
        while(q.size() > 1 && q[q.size() - 2] > q[q.size() - 1] && q[q.size() - 1] < a[i]){
            q.pop_back();
            kq--;
        }
        q.push_back(a[i]);
    }
    cout << kq << endl;

    return 0;
}
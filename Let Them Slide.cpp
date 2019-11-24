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

const LL MaxN = 1 + 1e6;

LL n, a[MaxN], m, row, kq[MaxN];
deque<II> dq;

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
    read(row);
    read(m);
    for(int r = 0 ; r < row ; ++r){
        read(n);
        for(int i = 0 ; i < n ; ++i) read(a[i]);
        while(!dq.empty()) dq.pop_back();
        for(int i = 0 ; i < m ; ++i){
            while(!dq.empty() && n - dq.front().first > m - i) dq.pop_front();
            if(i < n){
                while(!dq.empty() && a[i] > dq.back().second) dq.pop_back();
                dq.push_back({i, a[i]});
            }
            if(dq.front().second < 0 && (i < m - n || i >= n)) kq[i] += 0;
            else kq[i] += dq.front().second;
        }
    }
    for(int i = 0 ; i < m ; ++i) cout << kq[i] << " ";

    return 0;
}
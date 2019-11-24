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

const LL MaxN = 1 + 3e5;

LL n, a[MaxN], m, x, y, deg[MaxN], ma, kq;
vector<LL> q[MaxN], vertex;

void InOut(){
    #define TASK "DIAMONGR"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read(n);
    read(m);
    for(int i = 0 ; i < m ; ++i){
        read(x);
        read(y);
        q[x].push_back(y);
        q[y].push_back(x);
        deg[x]++;
        deg[y]++;
        if(deg[x] == 3) vertex.push_back(x);
        if(deg[y] == 3) vertex.push_back(y);
    }
    if(vertex.empty()){
        cout << 0 << endl;
        return 0;
    }
    for(int i = 0 ; i < vertex.size() ; ++i)
    for(int j = i + 1 ; j < vertex.size() ; ++j){
        LL cnt = 0, kt = 0;
        LL u = vertex[i], v = vertex[j];
        for(int k : q[u])
        if(v == k){
            kt = 1;
            break;
        }
        if(!kt) continue;
        for(int k : q[u])
        for(int h : q[v])
        if(k == h) cnt++;
        kq += cnt / 2; 
    }
    cout << kq << endl;

    return 0;
}
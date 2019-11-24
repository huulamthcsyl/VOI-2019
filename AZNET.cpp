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
 
const LL MaxN = 1 + 1e5;
 
LL n, a[MaxN], m, b[MaxN], x, y, z, t, root[MaxN], ans[MaxN];
 
class Edge{
    public:
        LL u, v, id;
        Edge(LL _u = 0, LL _v = 0, LL _id = 0):u(_u), v(_v), id(_id){}
};
 
inline LL getRoot(LL u){
    if(u == root[u]) return u;
    return root[u] = getRoot(root[u]);
}
 
vector<Edge> q[3];
 
LL Join(LL u, LL v){
    LL ru = getRoot(u), rv = getRoot(v);
    if(ru == rv) return 0;
    root[ru] = rv;
    return 1;
}
 
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
    read(t);
    for(int te = 0 ; te < t ; ++te){
        read(n);
        read(m);
        q[1].clear();
        q[2].clear();
        for(int i = 1 ; i < n ; ++i) read(a[i]);
        for(int i = 1 ; i < n ; ++i) read(b[i]);
        for(int i = 0 ; i < m ; ++i){
            read(x);
            read(y);
            read(z);
            q[z].push_back(Edge(x, y, i + 1));
        }
        LL mi, ma = 0;
        for(int i = 1 ; i <= n ; ++i) root[i] = i;
        for(Edge e : q[1])
        if(Join(e.u, e.v)) ma++;
        for(int i = 1 ; i <= n ; ++i) root[i] = i;
        LL temp = 0;
        for(Edge e : q[2])
        if(Join(e.u, e.v)) temp++;
        mi = n - 1 - temp;
        LL kq = 1e18, k = 0;
        // cout << mi << " " << ma << endl;
        for(int i = mi ; i <= ma ; ++i)
        if(a[i] + b[n - 1 - i] < kq){
            kq = min(kq, a[i] + b[n - 1 - i]);
            k = i;
        }
        // cout << k << endl;
        memset(ans, 0, sizeof ans);
        for(int i = 1 ; i <= n ; ++i) root[i] = i;
        for(Edge e : q[2]) Join(e.u, e.v);
        for(Edge e : q[1]) ans[e.id] = Join(e.u, e.v);
        for(int i = 1 ; i <= n ; ++i) root[i] = i;
        for(Edge e : q[1])
        if(ans[e.id]){
            Join(e.u, e.v);
            k--;
        }
        // cout << k << endl;
        for(Edge e : q[1])
        if(k <= 0) break;
        else if(Join(e.u, e.v)){
            ans[e.id] = 1;
            k--;
        }
        // for(int i = 1 ; i <= n ; ++i) cout << root[i] << endl;
        for(Edge e : q[2])
        if(Join(e.u, e.v)) ans[e.id] = 1;
        for(int i = 1 ; i <= m ; ++i)
        if(ans[i]) cout << i << " ";
        cout << endl;
    }
 
    return 0;
} 
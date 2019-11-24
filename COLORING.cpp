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

const LL MaxN = 1 + 1e3, up[4] = {-1, 0, 1, 0}, ri[4] = {0, 1, 0, -1};

LL n, a[MaxN][MaxN], m, id[MaxN][MaxN], ncc, d[MaxN * MaxN], col[MaxN * MaxN], nedge, root[MaxN * MaxN], d1[MaxN * MaxN], kq, vis[MaxN][MaxN];

struct Edge{

    LL u, v, c1, c2;

    Edge(LL _u = 0, LL _v = 0, LL _c1 = 0, LL _c2 = 0):u(_u), v(_v), c1(_c1), c2(_c2){}

    bool operator < (const Edge &op) const{
        if(c1 != op.c1) return c1 < op.c1;
        if(c2 != op.c2) return c2 < op.c2;
        return 0;
    }

    void Print(){
        cout << u << " " << v << " " << c1 << " " << c2 << endl;
    }

} e[MaxN * MaxN];

LL getRoot(LL u){
    if(u == root[u]) return u;
    return root[u] = getRoot(root[u]);
}

LL Avaiable(LL x, LL y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

void BFS(LL x, LL y){
    queue<II> q;
    q.push({x, y});
    while(!q.empty()){
        II temp = q.front();
        q.pop();
        LL u = temp.first, v = temp.second;
        // cout << u << " " << v << endl;
        id[u][v] = ncc;
        d[ncc]++;
        for(int i = 0 ; i < 4 ; ++i){
            LL xx = u + up[i], yy = v + ri[i];
            if(Avaiable(xx, yy) && a[xx][yy] == a[x][y] && id[xx][yy] == 0) q.push({xx, yy});
        }
    }
}

void findEdge(LL x, LL y){
    queue<II> q;
    q.push({x, y});
    vis[x][y] = 1;
    while(!q.empty()){
        II temp = q.front();
        q.pop();
        LL u = temp.first, v = temp.second;
        for(int i = 0 ; i < 4 ; ++i){
            LL xx = u + up[i], yy = v + ri[i];
            if(!Avaiable(xx, yy)) continue;
            if(a[xx][yy] != a[x][y]){
                nedge++;
                e[nedge] = Edge(id[x][y], id[xx][yy], min(col[id[x][y]], col[id[xx][yy]]), max(col[id[x][y]], col[id[xx][yy]]));
            }
            else if(!vis[xx][yy]){
                vis[xx][yy] = 1;
                q.push({xx, yy});
            }
        }
    }
}

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
    read(n);
    read(m);
    for(int i = 0 ; i < n ; ++i)
    for(int j = 0 ; j < m ; ++j) read(a[i][j]);
    for(int i = 0 ; i < n ; ++i)
    for(int j = 0 ; j < m ; ++j)
    if(!id[i][j]){
        ncc++;
        col[ncc] = a[i][j];
        BFS(i, j);
    }
    for(int i = 0 ; i < n ; ++i)
    for(int j = 0 ; j < m ; ++j) findEdge(i, j);
    sort(e + 1, e + nedge + 1);
    // for(int i = 1 ; i <= nedge ; ++i) e[i].Print();
    for(int i = 1 ; i <= ncc ; ++i) root[i] = i;
    queue<LL> q;
    set<LL> s;
    memcpy(d1, d, sizeof d);
    e[0] = e[1];
    for(int i = 1 ; i <= nedge ; ++i){
        if(e[i].c1 != e[i - 1].c1 || e[i].c2 != e[i - 1].c2){
            while(!q.empty()){
                root[q.front()] = q.front();
                q.pop();
            }
            while(!s.empty()){
                d[*s.begin()] = d1[*s.begin()];
                s.erase(s.begin());
            }
        }
        LL u = e[i].u, v = e[i].v;
        LL ru = getRoot(u), rv = getRoot(v);
        if(ru == rv) continue;
        root[ru] = rv;
        d[rv] += d[ru];
        q.push(ru);
        s.insert(rv);
        kq = max(kq, d[rv]);
    }
    cout << kq << endl;

    return 0;
}
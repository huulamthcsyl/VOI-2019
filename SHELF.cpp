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

const LL MaxN = 1 + 2e5, INF = 1e18;

LL n, x1, x2, y, kq, l[MaxN], r[MaxN], hi[MaxN], d[MaxN];
pair<LL,pair<LL, LL> > a[MaxN];
set<LL> s;

struct Shelf{

    int x1, x2, y;

    Shelf(LL _x1 = 0, LL _x2 = 0, LL _y = 0): x1(_x1), x2(_x2), y(_y){}

    bool operator < (const Shelf& op) const{
        if(y < op.y) return 1;
        if(y == op.y && x1 < op.x1) return 1;
        return 0;
    }

} b[MaxN];

struct Node{
    LL val, lazy;
} maxNode[4 * MaxN];

class Tree{

    LL le[4 * MaxN], ri[4 * MaxN], leaf[MaxN], qi, qj, up;

    void Down(LL node){
        LL t = maxNode[node].lazy;

        maxNode[node * 2].lazy = max(maxNode[node * 2].lazy, t);
        maxNode[node * 2].val =  max(maxNode[node * 2].val, t);

        maxNode[node * 2 + 1].lazy = max(maxNode[node * 2 + 1].lazy, t);
        maxNode[node * 2 + 1].val = max(maxNode[node * 2 + 1].val, t);

        maxNode[node].lazy = 0;
    }

    void Inc(LL node){
        if(le[node] > qj || ri[node] < qi) return;
        if(qi <= le[node] && ri[node] <= qj){
            maxNode[node].val = max(maxNode[node].val, up);
            maxNode[node].lazy = max(maxNode[node].lazy, up);
            return;
        }
        Down(node);
        Inc(node * 2);
        Inc(node * 2 + 1);
        maxNode[node].val = max(maxNode[node * 2].val, maxNode[node * 2 + 1].val);
    }

    LL findMax(LL node){
        if(qi > ri[node] || qj < le[node]) return -1e18;
        if(qi <= le[node] && ri[node] <= qj) return maxNode[node].val;
        Down(node);
        return max(findMax(node * 2), findMax(node * 2 + 1));
    }

    public:
        void Build(LL node, LL l, LL r){
            le[node] = l;
            ri[node] = r;
            if(l == r){
                return;
            }
            Build(node * 2, l, (l + r) / 2);
            Build(node * 2 + 1, (l + r) / 2 + 1, r);
        }

        void Update(LL l, LL r, LL k){
            qi = l;
            qj = r;
            up = k;
            Inc(1);
        }

        LL Query(LL x){
            qi = x;
            qj = x;
            return findMax(1);
        }

} tree;

void InOut(){
    #define TASK "SHELF"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

void readInput(){
    read(n);
    for(int i = 0 ; i < n ; ++i){
        read(x1);
        read(x2);
        read(y);
        a[i * 2] = {x1, {i, 0}};
        a[i * 2 + 1] = {x2, {i, 1}};
        hi[i] = y;
    }
}

void Init(){
    sort(a, a + n * 2);
    for(int i = 0 ; i < 2 * n ; ++i){
        s.insert(a[i].first);
        if(a[i].second.second) r[a[i].second.first] = s.size();
        else l[a[i].second.first] = s.size();
    }
    for(int i = 0 ; i < n ; ++i) b[i] = Shelf(l[i], r[i], hi[i]);
    sort(b, b + n);
}

void Solve(){
    tree.Build(1, 1, LL(s.size()));
    for(int i = 0 ; i < n ; ++i){
        kq += (b[i].y - tree.Query(b[i].x1));
        kq += (b[i].y - tree.Query(b[i].x2));
        tree.Update(b[i].x1, b[i].x2, b[i].y);
    }
    cout << kq << endl;
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    readInput();
    Init();
    Solve();

    return 0;
}
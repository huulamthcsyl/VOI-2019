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

LL n, a[MaxN], x, y, t, quest;

class Node{
    public:
        LL val, lazy;
};

class Tree{

    Node TNode[4 * MaxN];
    LL le[4 * MaxN], ri[4 * MaxN], leaf[MaxN], qi, qj;

    void Push(LL node){
        LL temp = TNode[node].lazy;
        if(temp == 0) return;
        TNode[node * 2].lazy = (temp + 1) / 2 - TNode[node * 2].lazy;
        TNode[node * 2].val = (temp + 1) / 2 - TNode[node * 2].val;
        TNode[node * 2 + 1].lazy = (temp - (temp + 1) / 2) - TNode[node * 2 + 1].lazy;
        TNode[node * 2 + 1].val = (temp - (temp + 1) / 2) - TNode[node * 2 + 1].val;
        TNode[node].lazy = 0;
    }

    void Change(LL node){
        if(qi > ri[node] || qj < le[node]) return;
        if(qi <= le[node] && ri[node] <= qj){
            TNode[node].lazy = (ri[node] - le[node] + 1) - TNode[node].lazy;
            TNode[node].val = (ri[node] - le[node] + 1) - TNode[node].val;
            return;
        }
        Push(node);
        Change(node * 2);
        Change(node * 2 + 1);
        TNode[node].val = TNode[node * 2].val + TNode[node * 2 + 1].val;
    }

    LL Find(LL node){
        if(qi > ri[node] || qj < le[node]) return 0;
        if(qi <= le[node] && ri[node] <= qj) return TNode[node].val;
        Push(node);
        return Find(node * 2) + Find(node * 2 + 1);
    }

    public:
        void Build(LL node, LL l, LL r){
            le[node] = l;
            ri[node] = r;
            if(l == r){
                TNode[node].val = 0;
                TNode[node].lazy = 0;
                return;
            }
            Build(node * 2, l, (l + r) / 2);
            Build(node * 2 + 1, (l + r) / 2 + 1, r);
        }

        void Update(LL x, LL y){
            qi = x;
            qj = y;
            Change(1);
        }

        LL Query(LL x, LL y){
            qi = x;
            qj = y;
            return Find(1);
        }

} tree;

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
    cin >> n >> t;
    tree.Build(1, 1, n);
    for(int te = 0 ; te < t ; ++te){
        cin >> quest >> x >> y;
        if(quest == 1) tree.Update(x, y);
        else cout << tree.Query(x, y) << endl;
    }
    // tree.Update(2, 3);
    // cout << tree.Query(1, 2) << endl;

    return 0;
}
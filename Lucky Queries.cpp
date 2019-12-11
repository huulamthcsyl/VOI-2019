// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
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

#define ordered_set tree<LL, null_type, less<LL>, rb_tree_tag, tree_order_statistics_node_update>
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

LL n, a[MaxN], q, x, y;
string s, query;

struct Node{

    LL n4, n7, n47, n74, lazy;

    Node(LL _n4 = 0, LL _n7 = 0, LL _n47 = 0, LL _n74 = 0, LL _lazy = 0):n4(_n4), n7(_n7), n47(_n47), n74(_n74), lazy(_lazy){}

    Node operator + (Node &op){
        LL x1 = n4 + op.n4, x2 = n7 + op.n7, x3 = max(n47 + op.n7, n4 + op.n47), x4 = max(n74 + op.n4, n7 + op.n74);
        return Node(x1, x2, x3, x4);
    }

    void Swap(){
        swap(n4, n7);
        swap(n47, n74);
    }

};

class Tree{

    Node TNode[4 * MaxN];
    LL le[4 * MaxN], ri[4 * MaxN], qi, qj;

    void Swap(LL node){
        TNode[node].Swap();
        TNode[node].lazy ^= 1;
        return;
    }

    void Push(LL node){
        if(TNode[node].lazy == 0) return;
        Swap(node * 2);
        Swap(node * 2 + 1);
        TNode[node].lazy = 0;
        return;
    }

    void Change(LL node){
        if(qi > ri[node] || qj < le[node]) return;
        if(qi <= le[node] && ri[node] <= qj){
            Swap(node);
            return;
        }
        Push(node);
        Change(node * 2);
        Change(node * 2 + 1);
        TNode[node] = TNode[node * 2] + TNode[node * 2 + 1];
    }

    public:
        void Build(LL node, LL l, LL r){
            le[node] = l;
            ri[node] = r;
            if(l == r){
                TNode[node].n47++;
                TNode[node].n74++;
                if(s[l] == '4') TNode[node].n4++;
                else TNode[node].n7++;
                return;
            }
            Build(node * 2, l, (l + r) / 2);
            Build(node * 2 + 1, (l + r) / 2 + 1, r);
            TNode[node] = TNode[node * 2] + TNode[node * 2 + 1];
        }

        void Update(LL x, LL y){
            qi = x;
            qj = y;
            Change(1);
        }

        LL Query(){
            return TNode[1].n47;
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
    cin >> n >> q;
    cin >> s;
    tree.Build(1, 0, n - 1);
    for(int te = 0 ; te < q ; ++te){
        cin >> query;
        if(query == "count") cout << tree.Query() << endl;
        else{
            cin >> x >> y;
            x--;
            y--;
            tree.Update(x, y);
        }
    }

    return 0;
}
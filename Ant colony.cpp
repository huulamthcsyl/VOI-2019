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

const LL MaxN = 1 + 1e5;

LL n, a[MaxN], x, y, q;

LL GCD(LL x, LL y){
    if(x < y) swap(x, y);
    while(y){
        LL tg = y;
        y = x % y;
        x = tg;
    }
    return x;
}

class Node{

    public:
        LL val, cnt;

        Node(LL _val = 0, LL _cnt = 0):val(_val), cnt(_cnt){}

        Node operator + (const Node &op){
            LL nval = GCD(val, op.val);
            if(nval != val && nval != op.val) return Node(nval, 0);
            if(nval == val && nval == op.val) return Node(nval, cnt + op.cnt);
            if(nval == val) return Node(nval, cnt);
            if(nval == op.val) return Node(nval, op.cnt);
            return Node(0, 0);
        }
};

class Tree{

    Node TNode[4 * MaxN];
    LL le[4 * MaxN], ri[4 * MaxN], qi, qj;

    Node Find(LL node){
        if(qi > ri[node] || qj < le[node]) return Node(0, 0);
        if(qi <= le[node] && ri[node] <= qj) return TNode[node];
        return Find(node * 2) + Find(node * 2 + 1);
    }

    public:
        void Build(LL node, LL l, LL r){
            le[node] = l;
            ri[node] = r;
            if(l == r){
                TNode[node].val = a[l];
                TNode[node].cnt++;
                return;
            }
            Build(node * 2, l, (l + r) / 2);
            Build(node * 2 + 1, (l + r) / 2 + 1, r);
            TNode[node] = TNode[node * 2] + TNode[node * 2 + 1];
        }

        LL Query(LL x, LL y){
            qi = x;
            qj = y;
            return Find(1).cnt;
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
    cin >> n;
    for(int i = 0 ; i < n ; ++i) cin >> a[i];
    tree.Build(1, 0, n - 1);
    cin >> q;
    for(int i = 0 ; i < q ; ++i){
        cin >> x >> y;
        x--;
        y--;
        cout << (y - x + 1) - tree.Query(x, y) << endl;
    }

    return 0;
}
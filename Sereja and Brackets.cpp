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
string s;

class Node{

    public:
        LL len, open, close;

        Node(LL _len = 0, LL _open = 0, LL _close = 0):len(_len), open(_open), close(_close){}

        Node operator + (const Node &op){
            LL mi = min(open, op.close);
            LL nlen = len + op.len + mi, nopen = open + op.open - mi, nclose = close + op.close - mi;
            return Node(nlen, nopen, nclose);
        }

};

class Tree{

    Node TNode[4 * MaxN];
    LL le[4 * MaxN], ri[4 * MaxN], qi, qj;

    Node Find(LL node){
        if(qi > ri[node] || qj < le[node]) return Node(0, 0, 0);
        if(qi <= le[node] && ri[node] <= qj) return TNode[node];
        return Find(node * 2) + Find(node * 2 + 1);
    }

    public:
        void Build(LL node, LL l, LL r){
            le[node] = l;
            ri[node] = r;
            if(l == r){
                if(s[l] == '(') TNode[node].open++;
                else TNode[node].close++;
                return;
            }
            Build(node * 2, l, (l + r) / 2);
            Build(node * 2 + 1, (l + r) / 2 + 1, r);
            TNode[node] = TNode[node * 2] + TNode[node * 2 + 1];
        }

        LL Query(LL x, LL y){
            qi = x;
            qj = y;
            return Find(1).len;
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
    cin >> s;
    cin >> q;
    LL n = s.length();
    tree.Build(1, 0, n - 1);
    for(int i = 0 ; i < q ; ++i){
        cin >> x >> y;
        x--;
        y--;
        cout << tree.Query(x, y) * 2 << endl;
    }

    return 0;
}
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

LL n, a[MaxN], q, x, y, query;

struct Node{
    LL sum, max;
};

class Tree{

    Node TNode[4 * MaxN];
    LL le[4 *  MaxN], ri[4 * MaxN], qi, qj;

    void Change(LL node){
        if(qi > ri[node] || qj < le[node]) return;
        if(TNode[node].max == 1) return;
        if(le[node] == ri[node]){
            TNode[node].sum = floor(sqrt(TNode[node].sum));
            TNode[node].max = floor(sqrt(TNode[node].max));
            return;
        }
        Change(node * 2);
        Change(node * 2 + 1);
        TNode[node].sum = TNode[node * 2].sum + TNode[node * 2 + 1].sum;
        TNode[node].max = max(TNode[node * 2].max, TNode[node * 2 + 1].max);
    }

    LL findSum(LL node){
        if(qi > ri[node] || qj < le[node]) return 0;
        if(qi <= le[node] && ri[node] <= qj) return TNode[node].sum;
        return findSum(node * 2) + findSum(node * 2 + 1);
    }

    public:
        void Build(LL node, LL l, LL r){
            le[node] = l;
            ri[node] = r;
            if(l == r){
                TNode[node].max = a[l];
                TNode[node].sum = a[l];
                return;
            }
            Build(node * 2, l, (l + r) / 2);
            Build(node * 2 + 1, (l + r) / 2 + 1, r);
            TNode[node].sum = TNode[node * 2].sum + TNode[node * 2 + 1].sum;
            TNode[node].max = max(TNode[node * 2].max, TNode[node * 2 + 1].max);
        }

        void Update(LL x, LL y){
            qi = x;
            qj = y;
            Change(1);
        }

        LL Query(LL x, LL y){
            qi = x;
            qj = y;
            return findSum(1);
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
    read(n);
    read(q);
    for(int i = 1 ; i <= n ; ++i) read(a[i]);
    tree.Build(1, 1, n);
    for(int te = 0 ; te < q ; ++te){
        read(query);
        read(x);
        read(y);
        if(query == 1){
            tree.Update(x, y);
            continue;
        }
        cout << tree.Query(x, y) << endl;
    }

    return 0;
}
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

LL n, a[MaxN], kq;
pair<LL, LL> b[MaxN];

class Tree{

    LL TNode[4 * MaxN], le[4 * MaxN], ri[4 * MaxN], leaf[MaxN], qi, qj;

    LL Find(LL node){
        if(qi > ri[node] || qj < le[node]) return 0;
        if(qi <= le[node] && ri[node] <= qj) return TNode[node];
        return Find(node * 2) + Find(node * 2 + 1);
    }

    public:
        void Build(LL node, LL l, LL r){
            le[node] = l;
            ri[node] = r;
            if(l == r){
                leaf[l] = node;
                return;
            }
            Build(node * 2, l, (l + r) / 2);
            Build(node * 2 + 1, (l + r) / 2 + 1, r);
        }

        void Update(LL x, LL k){
            LL h = leaf[x];
            TNode[h] += k;
            for(h /= 2 ; h ; h /= 2) TNode[h] = TNode[h * 2] + TNode[h * 2 + 1];
        }

        LL Query(LL x, LL y){
            qi = x;
            qj = y;
            return Find(1);
        }
} LTree, RTree;

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
    for(int i = 1 ; i <= n ; ++i){
        cin >> b[i].first;
        b[i].second = i;
    }
    sort(b + 1, b + n + 1);
    LL temp = 1;
    for(int i = 1 ; i <= n ; ++i){
        a[b[i].second] = temp;
        temp++;
    }
    LTree.Build(1, 1, n);
    RTree.Build(1, 1, n);
    for(int i = 1 ; i <= n ; ++i) RTree.Update(a[i], 1);
    for(int i = 2 ; i < n ; ++i){
        LTree.Update(a[i - 1], 1);
        RTree.Update(a[i - 1], - 1);
        kq += LTree.Query(a[i] + 1, 1e6) * RTree.Query(1, a[i] - 1);
    }
    cout << kq << endl;

    return 0;
}
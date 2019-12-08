// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;

typedef int LL;

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

const LL MaxN = 1 + 5e5;

LL n, a[MaxN], q, x, y, z, quest, ans;

LL GCD(LL x, LL y){
    if(x < y) swap(x, y);
    while(y){
        LL tg = y;
        y = x % y;
        x = tg;
    }
    return x;
}

class Tree{
    
    LL TNode[4 * MaxN], le[4 * MaxN], ri[4 * MaxN], leaf[MaxN], qi, qj, quest;
    
    void Find(LL node){
        if(ans > 1) return;
        if(qi > ri[node] || qj < le[node]) return;
        if(TNode[node] % quest == 0) return;
        if(le[node] == ri[node]){
            ans++;
            return;
        }
        if(ans > 1) return;
        Find(node * 2);
        Find(node * 2 + 1);
    }
    
    public:
        void Build(LL node, LL l, LL r){
            le[node] = l;
            ri[node] = r;
            if(l == r){
                leaf[l] = node;
                TNode[node] = a[l];
                return;
            }
            Build(node * 2, l, (l + r) / 2);
            Build(node * 2 + 1, (l + r) / 2 + 1, r);
            TNode[node] = GCD(TNode[node * 2], TNode[node * 2 + 1]);
        }
        
        void Update(LL x, LL k){
            LL h = leaf[x];
            TNode[h] = k;
            for(h /= 2 ; h ; h /= 2) TNode[h] = GCD(TNode[h * 2], TNode[h * 2 + 1]);
        }
        
        void Query(LL x, LL y, LL k){
            qi = x;
            qj = y;
            quest = k;
            Find(1);
        }
        
        void Test(){
            cout << TNode[5] << endl;
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
    for(int i = 1 ; i <= n ; ++i) read(a[i]);
    tree.Build(1, 1, n);
    read(q);
    for(int te = 0 ; te < q ; ++te){
        read(quest);
        if(quest == 1){
            read(x);
            read(y);
            read(z);
            ans = 0;
            tree.Query(x, y, z);
            if(ans < 2) cout << "YES" << endl;
            else cout << "NO" << endl;
            continue;
        }
        read(x);
        read(y);
        tree.Update(x, y);
    }
       
    return 0;
}

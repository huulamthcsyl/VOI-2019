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

const LL MaxN = 1 + 2e5;

LL n, a[MaxN], q;
string s;

struct Node{
    LL val, lazy;
};

class Tree{

    Node TNode[8 * MaxN];
    LL le[8 * MaxN], ri[8 * MaxN], qi, qj, inc;

    void Push(LL node){
        TNode[node * 2].val += TNode[node].lazy;
        TNode[node * 2].lazy += TNode[node].lazy;
        TNode[node * 2 + 1].val += TNode[node].lazy;
        TNode[node * 2 + 1].lazy += TNode[node].lazy;
        TNode[node].lazy = 0;
        return;
    }

    void Change(LL node){
        if(qi > ri[node] || qj < le[node]) return;
        if(qi <= le[node] && ri[node] <= qj){
            TNode[node].val += inc;
            TNode[node].lazy += inc;
            return;
        }
        Push(node);
        Change(node * 2);
        Change(node * 2 + 1);
        TNode[node].val = min(TNode[node * 2].val, TNode[node * 2 + 1].val);
    }

    LL Find(LL node){
        if(qi > ri[node] || le[node] > qj) return 1e18;
        if(qi <= le[node] && ri[node] <= qj) return TNode[node].val;
        Push(node);
        return min(Find(node * 2), Find(node * 2 + 1));
    }

    public:
        void Build(LL node, LL l, LL r){
            le[node] = l;
            ri[node] = r;
            if(l == r){
                TNode[node].val = a[l];
                return;
            }
            Build(node * 2, l, (l + r) / 2);
            Build(node * 2 + 1, (l + r) / 2 + 1, r);
            TNode[node].val = min(TNode[node * 2].val, TNode[node * 2 + 1].val);
        }

        void Update(LL x, LL y, LL k){
            qi = x;
            qj = y;
            inc = k;
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
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read(n);
    for(int i = 0 ; i < n ; ++i){
        read(a[i]);
        a[i + n] = a[i];
    }
    tree.Build(1, 0, n * 2 - 1);
    read(q);
    for(int te = 0 ; te < q ; ++te){
        LL x = 0, y = 0, z = 0;
        string s = "";
        char ch = getchar();
        while(ch != '\n' && ch != EOF){
            s += ch;
            ch = getchar();
        }
        LL i = 0;
        while(s[i] != ' '){
            x = x * 10 + s[i] - '0';
            i++;
        }
        i++;
        while(s[i] != ' ' && i < s.length()){
            y = y * 10 + s[i] - '0';
            i++;
        }
        if(y < x) y += n;
        if(i == s.length()){
            cout << tree.Query(x, y) << endl;
            continue;
        }
        LL cnt = 1;
        i++;
        if(s[i] == '-'){
            cnt = -1;
            i++;
        }
        while(i < s.length()){  
            z = z * 10 + s[i] - '0';
            i++;
        }
        z *= cnt;
        // cout << x << " " << y << " " << z << endl;
        tree.Update(x, y, z);
    }

    return 0;
}
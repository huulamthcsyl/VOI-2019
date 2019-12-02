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

LL n, a[MaxN];
string s;
char kq[MaxN];

struct Node{
    LL ma, mi, lazy;
};

class Tree{

    Node TNode[4 * MaxN];
    LL le[4 * MaxN], ri[4 * MaxN], qi, qj, inc;

    void Push(LL node){
        TNode[node * 2].lazy += TNode[node].lazy;
        TNode[node * 2].mi += TNode[node].lazy;
        TNode[node * 2].ma += TNode[node].lazy;
        TNode[node * 2 + 1].lazy += TNode[node].lazy;
        TNode[node * 2 + 1].mi += TNode[node].lazy;
        TNode[node * 2 + 1].ma += TNode[node].lazy;
        TNode[node].lazy = 0;
    }

    void Change(LL node){
        if(le[node] > qj || ri[node] < qi) return;
        if(qi <= le[node] && ri[node] <= qj){
            TNode[node].lazy += inc;
            TNode[node].ma += inc;
            TNode[node].mi += inc;
            return;
        }
        Push(node);
        Change(node * 2);
        Change(node * 2 + 1);
        TNode[node].mi = min(TNode[node * 2].mi, TNode[node * 2 + 1].mi);
        TNode[node].ma = max(TNode[node * 2].ma, TNode[node * 2 + 1].ma);
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

        void Update(LL x, LL y, LL k){
            qi = x;
            qj = y;
            inc = k;
            Change(1);
        }

        LL QueryMin(){
            return TNode[1].mi;
        }

        LL QueryMax(){
            return TNode[1].ma;
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
    tree.Build(1, 1, n);
    cin >> s;
    s = " " + s;
    LL pos = 1, k = 0;
    for(int i = 1 ; i <= n ; ++i){
        if(s[i] == 'R'){
            pos++;
        } else if(s[i] == 'L'){
            pos = max(1 * 1LL, pos - 1);
        } else{
            if(kq[pos] == '('){
                if(s[i] == ')') tree.Update(pos, n, -2), kq[pos] = ')', k -= 2;
                else if(s[i] != '(' && s[i] != '(') tree.Update(pos, n, -1), kq[pos] = ' ', k--;
            } else if(kq[pos] == ')'){
                if(s[i] == '(') tree.Update(pos, n, 2), kq[pos] = '(', k += 2;
                else if(s[i] != '(' && s[i] != ')') tree.Update(pos, n, 1), kq[pos] = ' ', k++;
            } else{
                if(s[i] == ')') tree.Update(pos, n, -1), kq[pos] = ')', k--;
                else if(s[i] == '(') tree.Update(pos, n, 1), kq[pos] = '(', k++;
            }
        }
        if(tree.QueryMin() != 0 || k != 0) cout << -1 << " ";
        else cout << tree.QueryMax() << " ";
    }

    return 0;
}
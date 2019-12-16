
// Problem : E. A Simple Task
// Contest : Codeforces Round #312 (Div. 2)
// URL : https://codeforces.com/contest/558/problem/E
// Memory Limit : 512.000000MB 
// Time Limit : 5000.000000milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor2)

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

const LL MaxN = 1 + 1e6;

LL n, a[MaxN], x, y, quest, q;
string s;

class Node{
    public:
        LL val[27], ch;  
        
        Node(){
            for(int i = 1 ; i <= 26 ; ++i) val[i] = 0;
            ch = 0;
        }
        
        Node(LL _val[]){
            for(int i = 1 ; i <= 26 ; ++i) val[i] = _val[i];
            ch = 0;
        }
        
        Node(LL pos, LL _val, LL _ch){
            for(int i = 1 ; i <= 26 ; ++i) val[i] = 0;
            val[pos] = _val;
            ch = _ch;
        }
        
        Node operator + (const Node &op){
            LL temp[27];
            for(int i = 1 ; i <= 26 ; ++i) temp[i] = val[i] + op.val[i];
            return Node(temp);
        }
        
};

class Tree{

    Node TNode[4 * MaxN];
    LL le[MaxN], ri[MaxN], qi, qj, inc;
    string result = "";
    
    void Push(LL node){
        TNode[node * 2] = Node(TNode[node].ch, ri[node * 2] - le[node * 2] + 1, TNode[node].ch);
        TNode[node * 2 + 1] = Node(TNode[node].ch, ri[node * 2 + 1] - le[node * 2 + 1] + 1, TNode[node].ch);
        TNode[node].ch = 0;
        return;
    }
    
    Node Find(LL node){
        if(qi > ri[node] || qj < le[node]) return Node();
        if(qi <= le[node] && ri[node] <= qj) return TNode[node];
        if(TNode[node].ch) Push(node);
        return Find(node * 2) + Find(node * 2 + 1);
    }
    
    void Change(LL node){
        if(qi > ri[node] || qj < le[node]) return;
        if(qi <= le[node] && ri[node] <= qj){
            TNode[node].ch = inc;
            TNode[node] = Node(inc, ri[node] - le[node] + 1, inc);
            return;
        }
        if(TNode[node].ch) Push(node);
        Change(node * 2);
        Change(node * 2 + 1);
        TNode[node] = TNode[node * 2] + TNode[node * 2 + 1];
    }
    
    void getKey(LL node){
        if(le[node] == ri[node]){
            result += char(TNode[node].ch + 'a' - 1);
            // cout << TNode[node].ch << endl;
            return;
        }
        if(TNode[node].ch) Push(node);
        getKey(node * 2);
        getKey(node * 2 + 1);
    }
    
    public:
        void Build(LL node, LL l, LL r){
            le[node] = l;
            ri[node] = r;
            if(l == r){
                TNode[node].val[s[l] - 'a' + 1]++;
                TNode[node].ch = s[l] - 'a' + 1;
                // cout << TNode[node].ch << endl;
                return;
            }
            Build(node * 2, l, (l + r) / 2);
            Build(node * 2 + 1, (l + r) / 2 + 1, r);
            TNode[node] = TNode[node * 2] + TNode[node * 2 + 1];
        }
        
        void Update(LL l, LL r, LL k){
            qi = l;
            qj = r;
            inc = k;
            Change(1);
        }
        
        Node Query(LL l, LL r){
            qi = l;
            qj = r;
            return Find(1);
        }
        
        string getResult(){
            getKey(1);
            return result;
        }
    
} tree;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    cin >> s;
    s = " " + s;
    tree.Build(1, 1, n);
    for(int te = 0 ; te < q ; ++te){
        cin >> x >> y >> quest;
        Node temp = tree.Query(x, y);
        // for(int i = 1 ; i <= 26 ; ++i) cout << temp.val[i] << " ";
        // cout << endl;
        if(quest){
            for(int i = 1 ; i <= 26 ; ++i)
            if(temp.val[i]){
                tree.Update(x, x + temp.val[i] - 1, i);
                x += temp.val[i];
            }
            continue;
        }
        for(int i = 26 ; i > 0 ; --i)
        if(temp.val[i]){
            tree.Update(x, x + temp.val[i] - 1, i);
            x += temp.val[i];
        }
    }
    cout << tree.getResult() << endl;
       
    return 0;
}

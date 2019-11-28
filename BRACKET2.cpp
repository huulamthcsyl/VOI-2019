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

LL n, a[MaxN], t, d[MaxN], x, y, k, b[MaxN];
string s;

class Node{
    public:
        LL val, lazy;
};

class Tree{

    protected:
        Node TNode[4 * MaxN];
        LL le[4 * MaxN], ri[4 * MaxN], qi, qj;

};

class MinTree : public Tree{

    LL inc;

    void Push(LL node){
        TNode[node * 2].val += TNode[node].lazy;
        TNode[node * 2].lazy += TNode[node].lazy;
        TNode[node * 2 + 1].val += TNode[node].lazy;
        TNode[node * 2 + 1].lazy += TNode[node].lazy;
        TNode[node].lazy = 0;
    }

    void Change(LL node){
        if(qi > ri[node] || le[node] > qj) return;
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
        if(le[node] > qj || ri[node] < qi) return 1e18;
        if(qi <= le[node] && ri[node] <= qj) return TNode[node].val;
        Push(node);
        return min(Find(node * 2), Find(node * 2 + 1));
    }

    public:
        void Build(LL node, LL l, LL r){
            le[node] = l;
            ri[node] = r;
            if(l == r){
                TNode[node].val = d[l];
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

} MTree;

class SumTree : public Tree{

    LL leaf[4 * MaxN];

    LL Find(LL node){
        if(qi > ri[node] || qj < le[node]) return 0;
        if(qi <= le[node] && ri[node] <= qj) return TNode[node].val;
        return Find(node * 2) + Find(node * 2 + 1);
    }

    public:
        void Build(LL node, LL l, LL r){
            le[node] = l;
            ri[node] = r;
            if(l == r){
                TNode[node].val = b[l];
                leaf[l] = node;
                return;
            }
            Build(node * 2, l, (l + r) / 2);
            Build(node * 2 + 1, (l + r) / 2 + 1, r);
            TNode[node].val = TNode[node * 2].val + TNode[node * 2 + 1].val;
        }

        void Update(LL x, LL k){
            LL h = leaf[x];
            TNode[h].val += k;
            for(h /= 2 ; h ; h /= 2) TNode[h].val = TNode[h * 2].val + TNode[h * 2 + 1].val;
        }

        LL Query(LL x, LL y){
            if(y == 0) return 0;
            qi = x;
            qj = y;
            return Find(1);
        }

} STree;

void InOut(){
    #define TASK "BRACKET2"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    // InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> t;
    cin >> s;
    s = " " + s;
    for(int i = 1 ; i <= n ; ++i)
    if(s[i] == '(') d[i] = d[i - 1] + 1;
    else d[i] = d[i - 1] - 1;
    MTree.Build(1, 1, n);
    for(int i = 1 ; i <= n ; ++i) b[i] = d[i] - d[i - 1];
    // for(int i = 1 ; i <= n ; ++i) cout << d[i] << " ";
    // cout << endl;
    STree.Build(1, 1, n);
    for(int te = 0 ; te < t ; ++te){
        LL quest;
        cin >> quest;
        if(quest == 2){
            cin >> x >> y;
            if((y - x + 1) % 2){
                cout << "NO" << endl;
                continue;
            }
            // cout << STree.Query(x, y) << " " << STree.Query(1, x - 1) << endl;
            if(STree.Query(x, y) != 0){
                cout << "NO" << endl;
                continue;
            }
            if(MTree.Query(x, y) < STree.Query(1, x - 1)){
                cout << "NO" << endl;
                continue;
            }
            cout << "YES" << endl;
            continue;
        }
        char ch;
        cin >> x >> ch;
        if(ch == '(' && s[x] == ')'){
            s[x] = '(';
            MTree.Update(x, n, 2);
            STree.Update(x, 2);
        }
        else if(ch == ')' && s[x] == '('){
            s[x] = ')';
            MTree.Update(x, n, -2);
            STree.Update(x, -2);
        }
    }
    // STree.Update(2, 2);
    // cout << STree.Query(2, 7) << endl;
    // MTree.Update(7, 7, -2);
    // cout << MTree.Query(2, 7) << endl;

    return 0;
}
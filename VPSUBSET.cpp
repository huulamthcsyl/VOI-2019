// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> II;

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

LL n, a[MaxN], d[MaxN];
stack<II> s;

class Tree{

    LL maxNode[4 * MaxN], le[4 * MaxN], ri[4 * MaxN], leaf[MaxN], qi, qj, inc;

    void Push(LL node){
        maxNode[node * 2] = max(maxNode[node * 2], maxNode[node]);
        maxNode[node * 2 + 1] = max(maxNode[node * 2 + 1], maxNode[node]);
    }

    void Change(LL node){
        if(qi > ri[node] || qj < le[node]) return;
        if(qi <= le[node] && ri[node] <= qj){
            maxNode[node] = max(maxNode[node], inc);
            return;
        }
        Push(node);
        Change(node * 2);
        Change(node * 2 + 1);
    }

    LL findMax(LL node){
        if(qi > ri[node] || qj < le[node]) return -1e18;
        if(qi <= le[node] && ri[node] <= qj) return maxNode[node];
        Push(node);
        return max(findMax(node * 2), findMax(node * 2 + 1));
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

        void Update(LL l, LL r, LL k){
            qi = l;
            qj = r;
            inc = k;
            Change(1);
        }

        LL Query(LL x, LL y){
            qi = x;
            qj = y;
            return findMax(1);
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
    for(int i = 1 ; i <= n + 1 ; ++i){
        while(!s.empty() && a[i] < s.top().first){
            d[s.top().second] += (i - s.top().second - 1);
            s.pop();
        }
        s.push({a[i], i});
    }
    while(!s.empty()) s.pop();
    for(int i = n ; i >= 0 ; --i){
        while(!s.empty() && a[i] < s.top().first){
            d[s.top().second] += (s.top().second - i - 1);
            s.pop();
        }
        s.push({a[i], i});
    }
    // for(int i = 1 ; i <= n ; ++i) cout << d[i] << " ";
    // cout << endl;
    for(int i = 1 ; i <= n ; ++i) tree.Update(1, d[i] + 1, a[i]);
    for(int i = 1 ; i <= n ; ++i) cout << tree.Query(i, i) << " ";

    return 0;
}

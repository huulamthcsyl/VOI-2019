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

LL Rand(LL l, LL h) {
    return uniform_int_distribution<LL>(l, h)(rng);
}

template <typename T> void read(T &t) {
    t = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    do { (t *= 10) += ch - '0'; ch = getchar(); } while (isdigit(ch)); t *= f;
}

const LL MaxN = 1 + 1e5;

LL n, a[MaxN], kq = -1e18, x, y, sl, s;

class Tree{

    LL minNode[4 * MaxN], le[4 * MaxN], ri[4 * MaxN], leaf[MaxN], qi, qj;

    LL findMin(LL node){
        if(qi > ri[node] || qj < le[node]) return 1e18;
        if(qi <= le[node] && ri[node] <= qj) return minNode[node];
        return min(findMin(node * 2), findMin(node * 2 + 1));
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
            minNode[h] = k;
            for(h /= 2 ; h ; h /= 2) minNode[h] = min(minNode[h * 2], minNode[h * 2 + 1]);
        }

        LL Query(LL x, LL y){
            qi = max(x, LL(0));
            qj = y;
            if(y < x) return 0;
            return findMin(1);
        }

} tree;

void InOut(){
    #define TASK "VPMAXSUBARR"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x >> y;
    for(int i = 1 ; i <= n ; ++i) cin >> a[i];
    tree.Build(1, 0, n);
    for(int i = 1 ; i <= n ; ++i){
        s += a[i];
        tree.Update(i, s);
        if(i < x) continue;
        LL mi = tree.Query(i - y, i - x);
        // cout << mi << endl;
        kq = max(kq, s - mi);
    }
    cout << kq << endl;

    return 0;
}
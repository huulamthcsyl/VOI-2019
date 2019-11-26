// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
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

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
LL Rand(LL l, LL h){
    return uniform_int_distribution<LL>(l, h)(rng);
}

template <typename T> void read(T &t){
    t = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    do { (t *= 10) += ch - '0'; ch = getchar(); } while (isdigit(ch)); t *= f;
}

const LL MaxN = 30001;

LL n, a[MaxN], t, x, y, k;

class Tree{

    vector<LL> TNode[4 * MaxN];
    LL le[4 * MaxN], ri[4 * MaxN], qi, qj, quest;

    LL Find(LL node){
        if(le[node] > qj || ri[node] < qi) return 0;
        if(qi <= le[node] && ri[node] <= qj){
            LL temp = upper_bound(TNode[node].begin(), TNode[node].end(), quest) - TNode[node].begin();
            return TNode[node].size() - temp;
        }
        return Find(node * 2) + Find(node * 2 + 1);
    }

    public:
        void Build(LL node, LL l, LL r){
            le[node] = l;
            ri[node] = r;
            if(l == r){
                TNode[node].push_back(a[l]);
                return;
            }
            Build(node * 2, l, (l + r) / 2);
            Build(node * 2 + 1, (l + r) / 2 + 1, r);
            TNode[node].resize(r - l + 1);
            merge(TNode[node * 2].begin(), TNode[node * 2].end(), TNode[node * 2 + 1].begin(), TNode[node * 2 + 1].end(), TNode[node].begin());
        }

        LL Query(LL x, LL y, LL k){
            qi = x;
            qj = y;
            quest = k;
            return Find(1);
        }

        void Test(){
            for(int i : TNode[2]) cout << i << " ";
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
    scanf("%d", &n);
    for(int i = 1 ; i <= n ; ++i) scanf("%d", &a[i]);
    tree.Build(1, 1, n);
    // tree.Test();
    scanf("%d", &t);
    for(int te = 0 ; te < t ; ++te){
        scanf("%d%d%d", &x, &y, &k);
        printf("%d\n", tree.Query(x, y, k));
    }

    return 0;
}

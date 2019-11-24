// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e6;

LL n, x, y, kq[MaxN], pos[MaxN], ans[MaxN];

template <typename T> void read(T &t) {
    t = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    do { (t *= 10) += ch - '0'; ch = getchar(); } while (isdigit(ch)); t *= f;
}

struct Result{

    LL f, s, id;

    Result(LL _f = 0, LL _s = 0, LL _id = 0):f(_f), s(_s), id(_id){}

    bool operator < (const Result& op) const{
        if(f < op.f) return 1;
        if(f == op.f && s < op.s) return 1;
        return 0;
    }

    void Print(){
        cout << f << " " << s << " " << id << endl;
    }

} a[MaxN];

class RTree{

    LL maxNode[4 * MaxN], le[4 * MaxN], ri[4 * MaxN], leaf[MaxN], qi, qj;

    LL findMax(LL node){
        if(qi > ri[node] || qj < le[node]) return -1e18;
        if(qi <= le[node] && ri[node] <= qj) return maxNode[node];
        return max(findMax(node * 2), findMax(node * 2 + 1));
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
            maxNode[h] = k;
            for(h /= 2 ; h ; h /= 2) maxNode[h] = max(maxNode[h * 2], maxNode[h * 2 + 1]);
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
    for(int i = 1 ; i <= n ; ++i){
        read(x);
        read(y);
        a[i] = Result(x, y, i);
    }
    sort(a + 1, a + n + 1);
    // for(int i = 1 ; i <= n ; ++i) a[i].Print();
    tree.Build(1, 0, 1000000);
    for(int i = n ; i > 0 ; --i){
        pos[i] = tree.Query(0, a[i].s - 1);
        if(pos[i] == 0) pos[i] = i;
        tree.Update(a[i].s, i);
    }
    for(int i = 1 ; i <= n ; ++i) pos[i] = max(pos[i], pos[i - 1]);

    for (int i = n; i > 0; --i) pos[i] = max(pos[i], pos[pos[i]]);

    for(int i = 1 ; i <= n ; ++i) ans[a[i].id] = pos[i] - 1;
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << '\n';

    return 0;
}

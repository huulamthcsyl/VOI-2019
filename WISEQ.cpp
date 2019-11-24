// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e5;

LL n, a[MaxN], m, d[MaxN], f[MaxN];

namespace Subtask1{

    void Solve(){
        LL kq = 0;
        for(int i = 0 ; i < n ; ++i){
            d[i] = 1;
            f[i] = a[i];
            for(int j = 0 ; j < i ; ++j)
            if(a[j] < a[i] && ((f[j] + a[i] <= m && d[j] + 1 > d[i]) || (d[j] + 1 == d[i] && f[j] + a[i] < f[i]))){
                f[i] = f[j] + a[i];
                d[i] = d[j] + 1;
            }
            kq = max(kq, d[i]);
        }
        cout << kq << endl;
    }

}

namespace Subtask2{

    class Tree{

        LL maxNode[4 * MaxN], le[4 * MaxN], ri[4 * MaxN], leaf[MaxN], qi, qj;

        LL findMax(LL node){
            if(le[node] > qj || ri[node] < qi) return -1e18;
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

    void Solve(){
        LL kq = 0;
        tree.Build(1, 0, n);
        for(int i = 0 ; i < n ; ++i){
            LL x = tree.Query(0, a[i] - 1);
            tree.Update(a[i], x + 1);
            kq = max(kq, x + 1);
        }
        cout << kq << endl;
    }

}

void InOut(){
    #define TASK "WISEQ"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0 ; i < n ; ++i) cin >> a[i];
    if(n <= 500) Subtask1::Solve();
    else Subtask2::Solve();
    // Subtask2::Solve();

    return 0;
}
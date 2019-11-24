// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e5;

LL n, d[MaxN], x, kq, a[MaxN];

class Tree{

    LL sumNode[4 * MaxN], le[4 * MaxN], ri[4 * MaxN], leaf[MaxN], qi, qj;

    LL findSum(LL node){
        if(le[node] > qj || ri[node] < qi) return 0;
        if(qi <= le[node] && ri[node] <= qj) return sumNode[node];
        return findSum(node * 2) + findSum(node * 2 + 1);
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
            sumNode[h]++;
            for(h /= 2 ; h ; h /= 2) sumNode[h] = sumNode[h * 2] + sumNode[h * 2 + 1];
        }

        LL Query(LL l, LL r){
            qi = l;
            qj = r;
            return findSum(1);
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
    for(int i = 1 ; i <= n ; ++i){
        cin >> x;
        d[x] = n - i + 1;
    }
    for(int i = 0 ; i < n ; ++i) cin >> a[i];
    for(int i = n - 1 ; i >= 0 ; --i){
        if(tree.Query(d[a[i]] + 1, n)) kq++;
        tree.Update(d[a[i]], 1);
    }
    cout << kq << endl;

    return 0;
}
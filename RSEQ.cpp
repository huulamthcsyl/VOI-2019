// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e5;

LL n, a[MaxN], t, x;

struct Node{

    LL le, ri, value, sum;

    Node(LL _le = 0, LL _ri = 0, LL _value = 0, LL _sum = 0):le(_le), ri(_ri), value(_value), sum(_sum){}

};

class Tree{

    Node maxNode[4 * MaxN];
    LL le[4 * MaxN], ri[4 * MaxN], leaf[MaxN];

    public:
        void Build(LL node, LL l, LL r){
            le[node] = l;
            ri[node] = r;
            if(l == r){
                maxNode[node].le = maxNode[node].ri = maxNode[node].value = maxNode[node].sum = a[l];
                leaf[l] = node;
                return;
            }
            Build(node * 2, l, (l + r) / 2);
            Build(node * 2 + 1, (l + r) / 2 + 1, r);
            maxNode[node].le = maxNode[node * 2].le + maxNode[node * 2 + 1].le;
            maxNode[node].ri = maxNode[node * 2].ri + maxNode[node * 2 + 1].ri;
            maxNode[node].value = maxNode[node * 2].value + maxNode[node * 2 + 1].value;
            maxNode[node].sum = maxNode[node * 2].sum + maxNode[node * 2 + 1].sum;
        }

        void Update(LL x){
            LL h = leaf[x];
            maxNode[h].le = -1e18;
            maxNode[h].ri = -1e18;
            maxNode[h].value = -1e18;
            maxNode[h].sum = -1e18;
            for(h /= 2 ; h ; h /= 2){
                maxNode[h].le = maxNode[h * 2].le;
                if(maxNode[h * 2].le == maxNode[h * 2].sum) maxNode[h].le = max(maxNode[h].le, maxNode[h].le + maxNode[h * 2 + 1].le);
                maxNode[h].ri = maxNode[h * 2 + 1].ri;
                if(maxNode[h * 2 + 1].ri == maxNode[h * 2 + 1].sum) maxNode[h].ri = max(maxNode[h].ri, maxNode[h * 2].ri + maxNode[h].ri);
                maxNode[h].value = max(max(maxNode[h * 2].value, maxNode[h * 2 + 1].value), maxNode[h * 2].ri + maxNode[h * 2 + 1].le);
                maxNode[h].sum = maxNode[h * 2].sum + maxNode[h * 2 + 1].sum;
            }
        }

        LL Query(){
            return maxNode[1].value;
        }

        void Test(){
            cout << maxNode[1].value << endl;
        }

} tree;

void InOut(){
    #define TASK "RSEQ"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> t;
    for(int i = 1 ; i <= n ; ++i) cin >> a[i];
    tree.Build(1, 1, n);
    for(int te = 0 ; te < t ; ++te){
        cin >> x;
        tree.Update(x);
        cout << tree.Query() << endl;
    }

    return 0;
}
// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e5;

LL n, a[MaxN], b[MaxN];

struct Node{

    LL value, mi, lazy;

    Node(LL _value = 0, LL _mi = 0, LL _lazy = 0): value(_value), mi(_mi), lazy(_lazy){}

};

class Tree{

    Node sumNode[4 * MaxN];
    LL le[4 * MaxN], ri[4 * MaxN], leaf[MaxN], qi, qj;

    void Push(LL node){
        sumNode[node * 2].value += sumNode[node].lazy;
        sumNode[node * 2].lazy += sumNode[node].lazy;
        sumNode[node * 2 + 1].value += sumNode[node].lazy;
        sumNode[node * 2 + 1].lazy += sumNode[node].lazy;
        sumNode[node].lazy = 0;
    }

    void Inc(LL node, LL k){
        if(le[node] > qj || ri[node] < qi) return;
        if(qi <= le[node] && ri[node] <= qj){
            sumNode[node].value += k;
            sumNode[node].lazy += k;
            return;
        }
        Push(node);
        Inc(node * 2, k);
        Inc(node * 2 + 1, k);
    }

    public:
        void Build(LL node, LL l, LL r){
            le[node] = l;
            ri[node] = r;
            if(l == r){
                sumNode[node].value = a[l];
                sumNode[node].mi = b[l] - a[l];
                return;
            }
            Build(node * 2, l, (l + r) / 2);
            Build(node * 2 + 1, (l + r) / 2 + 1, r);
            sumNode[node].value = sumNode[node * 2].value + sumNode[node * 2 + 1].value;
            sumNode[node].mi = min(sumNode[node * 2].mi, sumNode[node * 2 + 1].mi);
        }

        void Update(LL l, LL r, LL k){
            qi = l;
            qj = r;
            Inc(1, k);
        }


} tree;

void InOut(){
    #define TASK "ABC"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0 ; i < n ; ++i) cin >> a[i] >> b[i];

    return 0;
}
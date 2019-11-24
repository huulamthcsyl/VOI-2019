// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 1e6;

LL n, a[MaxN], m, k, b[3 * MaxN], kq[MaxN], ans, h;
pair<LL, LL> d[3 * MaxN];
deque<LL> result;
set<LL> s;

struct Tree{

    LL maxNode[12 * MaxN], le[12 * MaxN], ri[12 * MaxN], leaf[3 * MaxN], qi, qj;

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

    LL findMax(LL node){
        if(le[node] > qj || ri[node] < qi) return -1e18;
        if(qi <= le[node] && ri[node] <= qj) return maxNode[node];
        return max(findMax(node * 2), findMax(node * 2 + 1));
    }

    LL Query(LL x, LL y){
        qi = x;
        qj = y;
        return findMax(1);
    }

    void Test(){
        cout << maxNode[3] << endl;
    }

} tree;

void InOut(){
	#define TASK "SUBSEQ"
	freopen(TASK".inp","r",stdin);
	freopen(TASK".out","w",stdout);
}

int main(){
	InOut();
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for(int i = 0 ; i < n ; ++i){
        cin >> a[i];
        d[m] = {a[i], i};
        m++;
        d[m] = {a[i] - k, i + n};
        m++;
        d[m] = {a[i] + k, i + 2 * n};
        m++;
	}
	sort(d, d + m);
	for(int i = 0 ; i < m ; ++i){
        s.insert(d[i].first);
        b[d[i].second] = s.size();
	}
	tree.Build(1, 1, m);
	for(int i = 0 ; i < n ; ++i){
        LL x = tree.Query(b[i + n], b[i + 2 * n]);
        kq[i] = x + 1;
        ans = max(ans, x + 1);
        tree.Update(b[i], kq[i]);
	}
	cout << ans << endl;
	LL i = n - 1;
	for(; i >= 0 ; --i)
    if(kq[i] == ans){
        result.push_front(i);
        h = a[i];
        ans--;
        break;
    }
    for(int j = i ; j >= 0 && ans ; --j)
    if(abs(a[j] - h) <= k && kq[j] == ans){
        result.push_front(j);
        h = a[j];
        ans--;
    }
    for(int i : result) cout << a[i] << " ";

    return 0;
}

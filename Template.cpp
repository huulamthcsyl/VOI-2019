#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <ctime>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
const int inf = 1e9+100500;
 
const int sz = 1<<17;
 
vi rmq[sz * 2];
int a[sz];
 
int get(int l, int r, int x) {
    int s = 0;
    l += sz;
    r += sz;
    while (l < r) {
        if (l%2 == 1) s += lower_bound(all(rmq[l]), x) - rmq[l].begin();
        if (r%2 == 0) s += lower_bound(all(rmq[r]), x) - rmq[r].begin();
        l = (l+1) / 2;
        r = (r-1) / 2;
    }
    if (l == r) s += lower_bound(all(rmq[l]), x) - rmq[l].begin();
    return s;
}
 
int main() {
    #define TASK "ABC"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
    int n;
    cin >> n;
    forn(i, n) cin >> a[i];
    forn(i, n) rmq[i+sz] = {a[i]};
    ford(i, sz) if (i) {
        rmq[i].resize(rmq[i*2].size() + rmq[i*2+1].size());
        merge(all(rmq[i*2]), all(rmq[i*2+1]), rmq[i].begin());
    }
    int m;
    cin >> m;
    forn(i, m) {
        int l, r, x;
        cin >> l >> r >> x;
        int a = get(l, r, x);
        cout << a << endl;
    }
    // cout << s << endl;

    return 0;
}
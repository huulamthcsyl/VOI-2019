#include<bits/stdc++.h>
 
#define maxn 200005
 
using namespace std;
typedef long long ll;
 
int n, m, k, t;
int a[maxn];
int l[maxn], r[maxn], d[maxn], id[maxn];
 
bool cmp(int x, int y){
    return l[x] < l[y] || (l[x] == l[y] && r[x] < r[y]);
}
 
bool check(int ret){
    int cnt = t - n - 1;
    int x = 0, y = -1;
    for (int i = 0; i < k; ++i)
        if (ret < d[id[i]]){
            if (l[id[i]] > y) {
                cnt -= (y - x + 1) * 2;
                x = l[id[i]];
                y = r[id[i]];
            }
            else y = max(y, r[id[i]]);
        }
    cnt -= (y - x + 1) * 2;
    return cnt >= 0;
}
int main(){
    #define TASK "TrapGame"
    freopen(TASK".inp", "r", stdin); freopen(TASK".ans", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
 
    cin >> m >> n >> k >> t;
    for (int i = 1; i <= m; ++i)
        cin >> a[i];
    a[0] = int(3e5);
    sort(a, a + m + 1); reverse(a, a + m + 1);
 
    for (int i = 0; i < k; ++i){
        cin >> l[i] >> r[i] >> d[i];
        id[i] = i;
    }
    sort(id, id + k, cmp);
 
    int lo = 0, hi = m;
    while (lo < hi){
        int mid = (lo + hi + 1) / 2;
        if (check(a[mid])) lo = mid;
        else hi = mid - 1;
    }
    cout << lo;
    return 0;
}
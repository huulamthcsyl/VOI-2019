#include <bits/stdc++.h>

using namespace std;

#define long long long
#define FOR(i, a, b) for(int i = a, _b = (b) ; i <= _b ; i++)
#define FORD(i, a, b) for(int i = a, _b = (b) ; i >= _b ; i--)

const int NX = 1e5 + 10;
const long inf = 1e18 + 10;
struct T {
    long s, v;
    T (int v = 0, int s = 0) : v(v), s(s) {}
    bool operator < (const T &other) const {
        return v + s < other.v + other.s;
    }
} a[NX];

long N, M;

bool can (int number) {
    long sum = 0;
    long r = 0, pos = 0;
    FOR (i, 1, N) {
        if (sum + a[i].v + a[i].s <= M) {
            r++;
            sum += a[i].v + a[i].s;
            pos = i;
        }
        else break;
    }
    if (r >= number) return true;
    if (r < number - 1) return false;
    /// vi tri <= pos da mua
    long maxv = 0;
    FOR (i, 1, pos) {
        maxv = max(maxv, a[i].v);
    }
    if (sum - maxv / 2 + a[pos + 1].v + a[pos + 1].s <= M) return true;
    long minmon = inf + inf;
    FOR (i, pos + 1, N) {
        minmon = min(minmon, a[i].v / 2 + a[i].s);
    }
    if (sum + minmon <= M) return true;
    return false;
    /// vi tri > pos chua mua

}


int main() {
    #define file "VPBUYGIFT"
    freopen(file".inp","r",stdin);
    freopen(file".ans","w", stdout);

    cin >> N >> M;
    FOR (i, 1, N) {
        cin >> a[i].v >> a[i].s;
    }
    a[N + 1].s = a[N + 1].v = inf;
    N++;
    sort (a + 1, a + 1 + N);
    int low = 0, high = N - 1, res = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (can(mid)) {
            res = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }
    cout << res;
    return 0;
}

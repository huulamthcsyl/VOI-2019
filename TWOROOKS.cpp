#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("-Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("omit-frame-pointer")

using ll = long long;

int main() {
    #define TASK "ABC"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<ll>> a(n, vector<ll>(m));
    vector<ll> rows(n);
    vector<ll> cols(m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            rows[i] += a[i][j];
            cols[j] += a[i][j];
        }
    }


    ll best = 0;

    // one row, three col
    {
        for (int i = 0; i < n; i++) {
            priority_queue<ll, vector<ll>, greater<ll>> pq;
            for (int j = 0; j < m; j++) {
                ll val = cols[j] - a[i][j];
                if (pq.size() == 3 && pq.top() < val)
                    pq.pop(), pq.push(val);
                else if (pq.size() < 3)
                    pq.push(val);
            }
            ll res = 0;
            while (!pq.empty())
                res += pq.top(), pq.pop();
            best = max(best, rows[i] + res);
        }
    }

    // three row, one col
    {
        for (int i = 0; i < m; i++) {
            priority_queue<ll, vector<ll>, greater<ll>> pq;
            for (int j = 0; j < n; j++) {
                ll val = rows[j] - a[j][i];
                if (pq.size() == 3 && pq.top() < val)
                    pq.pop(), pq.push(val);
                else if (pq.size() < 3)
                    pq.push(val);
            }
            ll res = 0;
            while (!pq.empty())
                res += pq.top(), pq.pop();
            best = max(best, cols[i] + res);
        }
    }

    // two row, two col
    {
        if (n <= m) {
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    priority_queue<ll, vector<ll>, greater<ll>> pq;
                    for (int k = 0; k < m; k++) {
                        ll val = cols[k] - a[i][k] - a[j][k];
                        if (pq.size() == 2 && pq.top() < val)
                            pq.pop(), pq.push(val);
                        else if (pq.size() < 2)
                            pq.push(val);
                    }
                    ll res = 0;
                    while (!pq.empty())
                        res += pq.top(), pq.pop();
                    best = max(best, rows[i] + rows[j] + res);
                }
            }
        } else {
            for (int i = 0; i < m; i++) {
                for (int j = i + 1; j < m; j++) {
                    priority_queue<ll, vector<ll>, greater<ll>> pq;
                    for (int k = 0; k < n; k++) {
                        ll val = rows[k] - a[k][i] - a[k][j];
                        if (pq.size() == 2 && pq.top() < val)
                            pq.pop(), pq.push(val);
                        else if (pq.size() < 2)
                            pq.push(val);
                    }
                    ll res = 0;
                    while (!pq.empty())
                        res += pq.top(), pq.pop();
                    best = max(best, cols[i] + cols[j] + res);
                }
            }
        }
    }

    sort(rows.begin(), rows.end(), greater<ll>());
    sort(cols.begin(), cols.end(), greater<ll>());

    // top rows
    {
        ll curr = 0;
        for (int i = 0; i < min(n, 4); i++) {
            curr += rows[i];
        }
        best = max(best, curr);
    }

    // top cols
    {
        ll curr = 0;
        for (int i = 0; i < min(m, 4); i++) {
            curr += cols[i];
        }
        best = max(best, curr);
    }

    cout << best << endl;
}

/*
#set, #binarysearch, #LIS
*/
#define taskname "ABC"
#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;
const int infty = 1e9 + 1;
const int maxN = 1e5 + 1;
int n, m;
struct TPair
{
    int x, y;
    inline bool operator < (const TPair& other) const
    {
        return x < other.x;
    }
};
typedef set<TPair> TSet;
typedef TSet::iterator TIter;
TPair a[maxN];
TSet Set[maxN];
int f[maxN];

void ReadInput()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i].x >> a[i].y;
}

inline bool Accept(const TPair& p, const TSet& Set)
{
    TIter it = Set.lower_bound(p);
    if (it == Set.begin()) return false;
    --it;
    return p.y > it->y;
}

void InsertToSet(TSet& Set, const TPair& p)
{
    /* Set: {(xi, yi)}
    x1 < x2 < ... < xn;
    y1 > y2 > ... > yn
    */
    TIter it;
    it = Set.upper_bound(p);
    if (it != Set.begin())
    {
        it = prev(it);
        if (it -> y <= p.y) return;
    }
    it = Set.lower_bound(p);
    while (it != Set.end())
    {
        if (it->y < p.y) break;
        TIter it2 = next(it);
        Set.erase(it);
        it = it2;
    }
    Set.insert(p);
}

void Solve()
{
    for (int i = 1; i <= n; ++i)
        Set[i].clear();
    m = 0;
    for (int i = 1; i <= n; ++i)
    {
        int low = 1, high = m;
        while (low <= high)
        {
            int middle = (low + high) / 2;
            if (Accept(a[i], Set[middle]))
                low = middle + 1;
            else
                high = middle - 1;
        }
        f[i] = low;
        if (f[i] > m) m = f[i];
        InsertToSet(Set[low], a[i]);
    }
}

void Print()
{
    cout << m << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen(taskname".INP", "r", stdin);
    // freopen(taskname".OUT", "w", stdout);
    int test;
    cin >> test;
    for(int te = 0 ; te < test; ++te){
        ReadInput();
        Solve();
        Print();
    }
}

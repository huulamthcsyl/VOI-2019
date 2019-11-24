#include <bits/stdc++.h>

using namespace std;

#define long long long
#define FOR(i, a, b) for(int i = a, _b = (b) ; i <= _b ; i++)
#define FORD(i, a, b) for(int i = a, _b = (b) ; i >= _b ; i--)

const int NX = 1e7 + 10;
const long inf = 1e18 + 10;
int d[NX];
int N;
long f[NX];
vector <pair <int, long> > primes;
int prime[NX];
void eratos ()
{
    int n_prime = 0;
    for (int i = 2; i < NX; i++)
    {
        if (d[i] == 0)
            d[i] = prime[++n_prime] = i;
        int k = 0;
        while (k < n_prime && prime[k] < d[i] && prime[k + 1] * i < NX)
        {
            d[prime[k + 1] * i] = prime[k + 1];
            k++;
        }
    }
}

long get (long n, int p)
{
    long res = 0;
    while (n)
    {
        res += n / p;
        n /= p;
    }
    return res;
}

bool can (long value)
{
    FOR (i, 0, primes.size() - 1)
    {
        if (get(value, primes[i].first) < primes[i].second)
            return false;
    }
    return true;
}

int main()
{
#define file "VPMINFACT"
    freopen(file".in","r",stdin);
    freopen(file".out","w", stdout);
    eratos();
    cin >> N;
    FOR (i, 1, N)
    {
        int x;
        cin >> x, f[1]++, f[x + 1]--;
    }
    FOR (i, 1, NX - 1)
    {
        f[i] += f[i - 1];
    }

    FORD (i, NX - 1, 2)
    {
        if (d[i] == i)
        {
            if (f[i] != 0)
                primes.push_back(make_pair(i, f[i]));
            continue;
        }
        f[i / d[i]] += f[i];
        f[d[i]] += f[i];
        f[i] = 0;
    }
    /*FOR (i, 0, primes.size() - 1) {
        cout << primes[i].first << " " << primes[i].second << endl;
    }*/
    long res = 0;
    long low = 0, high = inf;
    while (low <= high)
    {
        long mid = (low + high) / 2;
        if (can(mid))
        {
            res = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    cout << res;
    return 0;
}
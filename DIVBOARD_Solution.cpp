#define taskname "DIVBOARD"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
const int maxMN = 1000;
const int maxA = 1000;
const int infty = maxMN * maxMN * maxA;
int m, n, a[maxMN][maxMN];
int hupper[maxMN], hlower[maxMN];
int res;

inline int ReadInt()
{
    char ch;
    while (ch = getchar(), ch < '0' || ch > '9');
    int x = ch - '0';
    while (ch = getchar(), ch >= '0' && ch <= '9')
        x = x * 10 + ch - '0';
    return x;
}

inline void WriteInt(int x)
{
    if (x > 9) WriteInt(x / 10);
    putchar(x % 10 + '0');
}

void ReadInput()
{
    m = ReadInt();
    n = ReadInt();
    fill(hupper, hupper + n, 0);
    fill(hlower, hlower + n, 0);
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            hlower[j] += a[i][j] = ReadInt();
}

inline void Optimize(int& a, int& b, int c, int d)
{
    if (abs(c - d) < abs(a - b))
    {
        a = c; b = d;
    }
}

inline void Update(int a, int b, int c, int d)
{
    int m1 = min(min(a, b), min(c, d));
    int m2 = max(max(a, b), max(c, d));
    if (m2 - m1 < res) res = m2 - m1;
}

void Solve()
{
    res = infty;
    for (int i = 0; i < m - 1; ++i)
    {
        int lu = 0, ru = 0, ld = 0, rd = 0;
        int p = 0, q = infty, r = 0, s = infty;
        for (int j = 0; j < n; ++j)
        {
            hupper[j] += a[i][j];
            hlower[j] -= a[i][j];
            ru += hupper[j];
            rd += hlower[j];
        }
        for (int j = 0; j < n - 1; ++j)
        {
            lu += hupper[j]; ru -= hupper[j];
            Optimize(p, q, lu, ru);
            ld += hlower[j]; rd -= hlower[j];
            Optimize(r, s, ld, rd);
        }
        Update(p, q, r, s);
    }
    WriteInt(res);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(taskname".INP", "r", stdin);
    freopen(taskname".OUT", "w", stdout);
    ReadInput();
    Solve();
}
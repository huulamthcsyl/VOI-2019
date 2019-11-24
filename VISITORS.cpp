/*
#dynamic programming, #fenwick trees, #segment trees
*/

/*
Tọa độ các địa chỉ là a[1], a[2], ..., a[n], riêng a[0] = 0 là trường học.

Gọi w(i, j) là chi phí đi tuần tự i -> i + 1 -> ... -> j, w(i, j) có thể xác định trong O(1)
To màu +/- các chỉ số 1...n
+++----++-++++----++ (Giải thích: + = xe 1 thăm, - = xe 2 thăm)
f[i] là chi phí nhỏ nhất khi 2 xe xuất phát từ 0 trên trục số,
thăm hết các địa điểm từ 1 tới i, kết thúc ở trạng thái một xe ở i và một xe ở i - 1.
- Đáp số là min{f[i] + w(i, n)}
- Giải thích từ trạng thái 1 xe ở i, 1 xe ở i - 1 thì xe ở i có trách nhiệm đi nốt i + 1, i + 2, ..., n

Tính f[i]: Nếu chỗ ± liền trước là j thì
Xe ở j đi tiếp lần lượt j + 1,  j + 2, ..., i - 1: w(j, i - 1)
Xe ở j - 1 đi thẳng sang i: |a[i] - a[j - 1]|
Vậy
f[i] = f[j] + w(j, i - 1) + |a[i] - a[j - 1]|, dễ dàng tính bằng O(n^2)
Giảm ĐPT:
Nếu a[i] >= a[j - 1]
    f[i] = f[j] + w(j, i - 1) + a[i] - a[j - 1]
    Xét hàm g[i] = f[i] - w(1, i - 1) - a[i],
    rõ ràng f[i] nhỏ nhất nếu và chỉ nếu g[i] nhỏ nhất do biểu thức của g[i] chỉ phụ thuộc vào chỉ số i
    Thay biểu thức của f[i] vào có
    g[i] = f[j] - w(1, j) - a[j - 1] (Chú ý: vế phải chỉ phụ thuộc j, không phụ thuộc i)

Nếu a[i] < a[j - 1]
    f[i] = f[j] + w(j, i - 1) - a[i] + a[j - 1]
    Xét hàm h[i] = f[i] - w(1, i - 1) + a[i]
    tương tự, f[i] nhỏ nhất nếu và chỉ nếu h[i] nhỏ nhất do biểu thức của h[i] chỉ phụ thuộc vào chỉ số i
    Thay biểu thức của f[i] vào có
    h[i] = f[j] - w(1, j) + a[j - 1] (Chú ý: vế phải chỉ phụ thuộc j, không phụ thuộc i)

Vậy ta có giải pháp:
- Mỗi khi tính xong mỗi f[j],
  + Các điểm đứng bên phải a[j - 1] sẽ được gán nhãn g minimize theo f[j] - w(1, j) - a[j - 1]
  + Các điểm đứng bên trái a[j - 1] sẽ được gán nhãn h minimize theo f[j] - w(1, j) + a[j - 1]
  O(log n) bằng segment/fenwick trees
- Để tính f[i], truy vấn giá trị g[i] và h[i] (đã được cực tiểu hóa và đặt tại điểm a[i]), khi đó:
  f[i] = min{g[i] + w(1, i - 1) + a[i], h[i] + w(1, i - 1) - a[i])
  O(log n) bằng segment/fenwick trees
*/

#define taskname "VISITORS"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
typedef long long lli;
const int maxN = 1e5 + 2;
const int maxCoord = 1e9;
const lli infty = (lli) maxN * lli(maxCoord) * 2;
int n, a[maxN], id[maxN], pos[maxN];
lli SumW[maxN], f[maxN];

void Enter()
{
    cin >> n;
    a[0] = 0;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
}

void Init()
{
    for(int i = 1; i <= n; ++i) id[i] = i;
    sort(id + 1, id + n + 1, [](int i, int j)
    {
        return a[i] < a[j];
    });
    for(int i = 1; i <= n; ++i)
        pos[id[i]] = i;
    SumW[0] = 0;
    for(int i = 1; i <= n; ++i)
        SumW[i] = SumW[i - 1] + abs(a[i] - a[i - 1]);
}

inline lli w(int i, int j)
{
    return SumW[j] - SumW[i];
}

inline void Minimize(lli& Target, lli Value)
{
    if(Target > Value)
        Target = Value;
}

class TFenwickTree
{
public:
    lli MinVal[maxN];
    void Init()
    {
        fill_n(&MinVal[1], n, infty);
    }
};
class TGTree: public TFenwickTree
{
public:
    inline void Update(int x, lli NewVal)  //Cực tiểu hóa giá trị tại điểm x theo NewVal
    {
        for(; x <= n; x += x & -x)
            Minimize(MinVal[x], NewVal);
    }
    inline lli Query(int x)  //Tìm giá trị bé nhất đã đặt tại điểm bên trái x
    {
        lli res = infty;
        for(; x > 0; x &= x - 1)
            Minimize(res, MinVal[x]);
        return res;
    }
} GTree;

class THTree: public TFenwickTree
{
public:
    inline void Update(int x, lli NewVal)  //Cực tiểu hóa giá trị tại điểm x theo NewVal
    {
        for(; x > 0; x &= x - 1)
            Minimize(MinVal[x], NewVal);
    }
    inline lli Query(int x)  //Tìm giá trị bé nhất đã đặt tại điểm bên phải x
    {
        lli res = infty;
        for(; x <= n; x += x & -x)
            Minimize(res, MinVal[x]);
        return res;
    }
} HTree;

void Solve()
{
    GTree.Init();
    HTree.Init();
    f[1] = abs(a[1]);
    int pid = 1;
    while (pid <= n && a[id[pid]] <= 0) ++pid;
    if (pid <= n) GTree.Update(pid, f[1]);  //Các điểm bên phải điểm 0 được update nhãn g = f[1] - w(1, 1) - a[0]
    if (pid > 1) HTree.Update(pid - 1, f[1]);  //Các điểm bên trái điểm 0 được update nhãn h = f[1] - w(1, 1) + a[0]
    lli res = f[1] + w(1, n);
    for(int i = 2; i <= n; ++i)
    {
        lli gmin = GTree.Query(pos[i]);
        lli hmin = HTree.Query(pos[i]);
        f[i] = min(gmin + w(1, i - 1) + a[i], hmin + w(1, i - 1) - a[i]);
        Minimize(res, f[i] + w(i, n));
        GTree.Update(pos[i - 1], f[i] - w(1, i) - a[i - 1]);
        HTree.Update(pos[i - 1], f[i] - w(1, i) + a[i - 1]);
    }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    Enter();
    Init();
    Solve();
}

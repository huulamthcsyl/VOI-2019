// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> II;
const LL MaxN = 1 + 1e5;

LL n, kq[MaxN], x, y;

template <typename T> void read(T &t) {
    t = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    do { (t *= 10) += ch - '0'; ch = getchar(); } while (isdigit(ch)); t *= f;
}

struct Point{

    LL x, y, id;

    Point(LL _x = 0, LL _y = 0, LL _id = 0):x(_x), y(_y), id(_id){}

    bool operator < (const Point& op) const{
        return x < op.x;
    }

    void Print(){
        cout << x << " " << y << endl;
    }

} a[MaxN];

LL Check(Point x, Point y, Point z){
    LL k = (y.x - x.x) * (y.y + x.y) + (z.x - y.x) * (z.y + y.y) + (x.x - z.x) * (x.y + z.y);
    return k <= 0;
}

void InOut(){
    #define TASK "EXPER"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read(n);
    for(int i = 0 ; i < n ; ++i){
        read(x);
        read(y);
        a[i] = Point(x, y, i);
    }
    sort(a, a + n);
    // for(int i = 0 ; i < n ; ++i) a[i].Print();
    for(int i = 0 ; i < n ; ++i){
        // if(i != n - 1) kq[a[i].id]++;
        Point tg = a[i];
        for(int j = i + 1 ; j < n ; ++j){
            if(Check(a[i], tg, a[j])){
                kq[a[i].id]++;
                kq[a[j].id]++;
                tg = a[j];
            }
        }
    }
    for(int i = 0 ; i < n ; ++i) cout << kq[i] << endl;
    // cout << Check(a[0], a[2], a[3]) << endl;

    return 0;
}
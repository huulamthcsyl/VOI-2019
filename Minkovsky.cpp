#include <bits/stdc++.h>
using namespace std;
#define y1 A2Dalek
#define y0 Cyberman
#define yn RoseTyler
#define j1 JackHarkness
const int N = 2e5;
const long double oo = 1e17 + 5;
int du[] = {-1, 0, 0, 1};
int dv[] = {0, -1, 1, 0};
const long long mod = 1e9 + 7;
typedef pair<long double, int> LI;
long long sqr(long double x) { return x * x; }
int getbit(int state, int i) { return ((state >> i) & 1); }

int n, s, t;
long double d[205];
vector<LI> g[205];

struct Point{

    int x, y;

    Point(int _x = 0, int _y = 0):x(_x), y(_y){}

    bool operator > (const Point &op) const{
        if(x == op.x) return y > op.y;
        return x > op.x;
    }

    bool operator < (const Point &op) const{
        if(x == op.x) return y < op.y;
        return x < op.x;
    }

    Point operator + (const Point &op){
        return Point(x + op.x, y + op.y);
    }

    void operator += (const Point &op){
        *this = *this + op;
    }

    Point operator - (const Point &op){
        return Point(x - op.x, y - op.y);
    }

    void operator -= (const Point &op){
        *this = *this - op;
    }

};

class Polygon{

    Point a[505], origin;

    inline long double vohuong(Point X, Point Y) { return X.x * Y.x + X.y * Y.y; }

    inline long double cohuong(Point X, Point Y) { return X.x * Y.y - X.y * Y.x; }
    
    inline bool ccw(Point O, Point A, Point B){
        A -= O;
        B -= O;
        return A.x * B.y > A.y * B.x;
    }

    inline bool cmp(Point A, Point B) { return ccw(origin, A, B); }

    public:
        int n;

        void add(Point X, int vt){
            a[vt] = X;
            a[vt + n] = X;
        }

        void chuanhoa(){
            Point Min = a[1];
            int vt = 1;

            for (int i = 1; i <= n; i++)
            if (Min > a[i]){
                Min = a[i];
                vt = i;
            }
            for (int i = vt; i <= vt + n; i++) a[i - vt + 1] = a[i];
        }

        long double getdist(Polygon b1){
            int cnt = 1, m = b1.n;
            Point b[505], c[1005];

            for (int i = 1; i <= m + 1; i++) b[i] = b1.a[i];
            c[1] = Point(a[1].x + b[1].x, a[1].y + b[1].y);
            int i = 1, j = 1;

            while (1){
                Point tmp1 = Point(0, 0);
                Point tmp2 = Point(0, 0);
                if (i <= n) tmp1 = a[i + 1] - a[i];
                if (j <= m) tmp2 = b[j + 1] - b[j];
                if (j == m + 1 || ccw({0, 0}, tmp1, tmp2)){
                    cnt++;
                    i++;
                    c[cnt] = c[cnt - 1] + tmp1;
                }
                else{
                    cnt++;
                    j++;
                    c[cnt] = c[cnt - 1] + tmp2;
                }
                if (i == n + 1 && j == m + 1) break;
            }

            long double ans = oo;
            for (int i = 1; i <= cnt; i++) ans = min(ans, (long double)sqrt(sqr(c[i].x) + sqr(c[i].y)));
            for (int i = 1; i < cnt; i++){
                Point v = Point(0, 0) - c[i];
                Point u = c[i + 1] - c[i];
                long double lenu = (long double)sqrt(sqr(u.x) + sqr(u.y));
                long double now = vohuong(v, u) / lenu;
                if (0 < now && now < 1) ans = min(ans, abs(cohuong(v, u)) / lenu);
            }

            return ans;
        }

        Polygon nguoc(){
            Polygon b1;
            Point b[505];

            b1.n = n;
            for (int i = 1; i <= n; i++) b[i] = Point(-a[i].x, -a[i].y);
            sort(b + 1, b + 1 + n);
            origin = b[1];
            sort(b + 2, b + 1 + n, cmp);
            for (int i = 1; i <= n; i++) b1.add(b[i], i);

            return b1;
        }

} p[205], p2[205];

int main(){
    freopen("TAKEKOPUTA.inp", "r", stdin);
    freopen("TAKEKOPUTA.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    // cin >> n >> s >> t;
    // for (int i = 1; i <= n; i++){
    //     int u, v;
    //     cin >> p[i].n;
    //     for (int j = 1; j <= p[i].n; j++){
    //         cin >> u >> v;
    //         p[i].add(Point(u, v), j);
    //     }
    //     p2[i] = p[i].nguoc();
    //     p[i].chuanhoa();
    // }
    // for (int i = 1; i <= n; i++)
    // for (int j = i + 1; j <= n; j++){
    //     long double tmp = p[i].getdist(p2[j]);
    //     g[i].push_back({tmp, j});
    //     g[j].push_back({tmp, i});
    // }
    // for (int i = 1; i <= n; i++) d[i] = oo;
    // d[s] = 0;
    // priority_queue<LI, vector<LI>, greater<LI>> q;
    // q.push({0, s});
    // while (!q.empty()){
    //     LI now = q.top();
    //     q.pop();
    //     int u = now.second;
    //     long double du = now.first;
    //     if (d[u] != du) continue;
    //     for (int i = 0; i < g[u].size(); i++){
    //         int v = g[u][i].second;
    //         long double uv = g[u][i].first;
    //         if (d[v] > du + uv){
    //             d[v] = du + uv;
    //             q.push({d[v], v});
    //         }
    //     }
    // }
    // cout << fixed << setprecision(11) << d[t];

    return 0;
}

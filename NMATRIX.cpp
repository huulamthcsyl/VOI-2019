// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef int LL;
typedef pair<LL, LL> II;

#define y0 Sword_Art_Online
#define y1 Your_lie_in_April
#define yn Darling_in_the_Franxx
#define tm Plastic_Memories
#define lr Charlotte
#define norm Weathering_with_you
#define left Violet_Evergarden
#define have Date_a_live
#define ends Your_name
#define prev Five_centimeters_per_second
#define hash Slient_voice

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

LL Rand(LL l, LL h){
    return uniform_int_distribution<LL>(l, h)(rng);
}

template <typename T> void read(T &t){
    t = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    do { (t *= 10) += ch - '0'; ch = getchar(); } while (isdigit(ch)); t *= f;
}

const LL MaxN = 1 + 1e3;

LL n, a[MaxN][MaxN], x, y, m, t, d[MaxN][MaxN], f[MaxN][MaxN];

template<typename T> class Deque{
    T val[2 * MaxN];
    LL n, m;

    public:
        void clear(){
            n = 0;
            m = -1;
        }

        void push_back(II x){
            m++;
            val[m] = x;
        }

        void pop_back(){
            m--;
        }

        void pop_front(){
            n++;
        }

        inline T front(){
            return val[n];
        }

        inline T back(){
            return val[m];
        }

        inline LL size(){
            return m - n + 1;
        }

        inline bool empty(){
            return m < n;
        }
};

Deque<II> dq;

inline LL Calc(LL x, LL y, LL z, LL t){
    return d[z][t] - d[x - 1][t] - d[z][y - 1] + d[x - 1][y - 1];
}

void InOut(){
    #define TASK "ABC"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read(n);
    read(m);
    for(int i = 1 ; i <= n ; ++i)
    for(int j = 1 ; j <= m ; ++j) read(a[i][j]);
    for(int i = 1 ; i <= n ; ++i)
    for(int j = 1 ; j <= m ; ++j)
    d[i][j] = d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1] + a[i][j];
    read(t);
    for(int te = 0 ; te < t ; ++te){
        read(x);
        read(y);
        for(int j = 1 ; j <= m ; ++j){
            dq.clear();
            for(int i = 1 ; i <= n ; ++i){
                while(!dq.empty() && a[i][j] > dq.back().first) 
                    dq.pop_back();
                while(!dq.empty() && i - dq.front().second + 1 > x) 
                    dq.pop_front();
                dq.push_back({a[i][j], i});
                f[i][j] = dq.front().first;
            }
        }
        LL kq = 1e9;
        for(int i = x ; i <= n ; ++i){
            dq.clear();
            for(int j = 1 ; j <= m ; ++j){
                while(!dq.empty() && f[i][j] > dq.back().first) 
                    dq.pop_back();
                while(!dq.empty() && j - dq.front().second + 1 > y) 
                    dq.pop_front();
                dq.push_back({f[i][j], j});
                if(j < y) continue;
                kq = min(kq, dq.front().first * x * y - Calc(i - x + 1, j - y + 1, i, j));
            }
        }
        cout << kq << endl;
    }

    return 0;
}
// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
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
#define hash Slience_voice

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

LL Rand(LL l, LL h) {
    return uniform_int_distribution<LL>(l, h)(rng);
}

template <typename T> void read(T &t) {
    t = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    do { (t *= 10) += ch - '0'; ch = getchar(); } while (isdigit(ch)); t *= f;
}

const LL MaxN = 10 + 1e6;

LL n, a[MaxN], m, b[MaxN], l[MaxN], r[MaxN], ma;
stack<LL> s;
II kq1, kq2;

void InOut(){
    #define TASK "MAXRECT"
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
    for(int i = 1 ; i <= m ; ++i){
        read(a[i]);
        b[i] = n - a[i];
    }
    for(int i = 1 ; i <= m + 1 ; ++i){
        while(!s.empty() && a[i] < a[s.top()]){
            r[s.top()] = i - 1;
            s.pop();
        }
        if(i != m + 1) s.push(i);
    }
    for(int i = m ; i >= 0 ; --i){
        while(!s.empty() && a[i] < a[s.top()]){
            l[s.top()] = i + 1;
            s.pop();
        }
        if(i) s.push(i);
    }
    // for(int i = 1 ; i <= m ; ++i) cout << l[i] << " " << r[i] << endl;
    for(int i = 1 ; i <= m ; ++i){
        if((i - l[i] + r[i] - i - 1) * a[i] > ma){
            ma = (i - l[i] + r[i] - i + 1) * a[i];
            kq1 = {1, l[i]};
            kq2 = {a[i], r[i]};
        }
    }
    memset(l, 0, sizeof l);
    memset(r, 0, sizeof r);
    for(int i = 1 ; i <= m + 1 ; ++i){
        while(!s.empty() && b[i] < b[s.top()]){
            r[s.top()] = i - 1;
            s.pop();
        }
        if(i != m + 1) s.push(i);
    }
    for(int i = m ; i >= 0 ; --i){
        while(!s.empty() && b[i] < b[s.top()]){
            l[s.top()] = i + 1;
            s.pop();
        }
        if(i) s.push(i);
    }
    // for(int i = 1 ; i <= m ; ++i) cout << l[i] << " " << r[i] << endl;
    for(int i = 1 ; i <= m ; ++i){
        if((i- l[i] + r[i] - i - 1) * b[i] > ma){
            ma = (i - l[i] + r[i] - i + 1) * b[i];
            kq1 = {n - b[i] + 1, l[i]};
            kq2 = {n, r[i]};
        }
    }
    cout << ma << endl;
    cout << kq1.first << " " << kq1.second << endl;
    cout << kq2.first << " " << kq2.second << endl;

    return 0;
}
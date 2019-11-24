// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

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

const LL MaxN = 1 + 1e5;

LL n, a[MaxN], cnt, kq;
char ch;

LL Check(LL k){
    LL nxt = k % 10;
    k /= 10;
    while(k){
        if(k % 10 == nxt) return 0;
        nxt = k % 10;
        k /= 10;
    }
    return 1;
}

void InOut(){
    #define TASK "APLUSB"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ch = getchar();
    while(isdigit(ch)){
        cnt++;
        if(n == 0 && ch == '1'){
            cout << 0 << endl;
            return 0;
        }
        n = n * 10 + ch - '0';
        ch = getchar();
    }
    LL st = 1;
    for(int i = 0 ; i < cnt - 1 ; ++i) st *= 10;
    for(int i = st ; i <= n / 2 ; ++i)
    if(Check(i) && Check(n - i)) kq += 2;
    if(n % 2 == 0 && Check(n / 2)) kq--;
    cout << kq << endl;

    return 0;
}
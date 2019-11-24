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

const LL MaxN = 1 + 1e6;

LL n, a[MaxN], b[MaxN], kt;

void InOut(){
    #define TASK "Remittance"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0 ; i < n ; ++i){
        cin >> a[i] >> b[i];
        if(b[i] && kt == 0) kt = 1;
    }
    if(!kt){
        for(int i = 0 ; i < n ; ++i)
        if(a[i]){
            cout << "No" << endl;
            return 0;
        }
        cout << "Yes" << endl;
        return 0;
    }
    while(1){
        kt = 0;
        for(int i = 0 ; i < n ; ++i)
        if(a[i] > b[i]){
            LL k = (a[i] - b[i] + 1) / 2;
            a[i] -= 2 * k;
            a[(i + 1) % n] += k;
            kt = 1;
        }
        if(!kt) break;
    }
    for(int i = 0 ; i < n ; ++i)
    if(a[i] != b[i]){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;

    return 0;
}
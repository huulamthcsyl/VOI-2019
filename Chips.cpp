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

const LL MaxN = 10 + 2e5;

LL n, m, k, prv[MaxN], after[MaxN], d[MaxN], kt[MaxN];
string s;
char kq[MaxN];
vector<LL> q;

void InOut(){
    #define TASK "Chips"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    // InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    cin >> s;
    for(int i = 1 ; i < n ; ++i) prv[i] = i - 1;
    prv[0] = n - 1;
    for(int i = 0 ; i < n - 1 ; ++i) after[i] = i + 1;
    after[n - 1] = 0;
    for(int i = 0 ; i < n ; ++i)
    if(s[i] == s[prv[i]]){
        d[i] = 1;
        d[prv[i]] = 1;
        kq[i] = s[i];
        kq[prv[i]] = s[prv[i]];
    }
    // cout << kq << endl;
    for(int i = 0 ; i < n ; ++i)
    if(!d[i] && !kt[i]){
        LL l = i, r = i;
        while(s[l] != s[prv[l]] && !kt[prv[l]]){
            l = prv[l];
            kt[l] = 1;
        }
        while(s[r] != s[after[r]] && !kt[after[r]]){
            r = after[r];
            kt[r] = 1;
        }
        if(l == r){
            if(k % 2 == 0) cout << s << endl;
            else{
                for(int i = 0 ; i < n ; ++i)
                if(s[i] == 'B') s[i] = 'W';
                else s[i] = 'B';
                cout << s << endl;
            }
            return 0;
        }
        q.clear();
        LL x = after[l];
        while(x != r){
            q.push_back(x);
            x = after[x];
        }
        // for(int i : q) cout << i << " ";
        // cout << endl;
        if(s[l] == s[r]){
            if(q.size() <= k * 2){
                for(int j : q) kq[j] = s[l];
                continue;
            }
            for(int j = 0 ; j < k ; ++j) kq[q[q.size() - 1 - j]] = kq[q[j]] = s[l];
            for(int j = k ; j < q.size() - k ; ++j){
                if(k % 2){
                    if(s[q[j]] == 'B') kq[q[j]] = 'W';
                    else kq[q[j]] = 'B';
                }
                else{
                    if(s[q[j]] == 'B') kq[q[j]] = 'B';
                    else kq[q[j]] = 'W';
                }
            }
            continue;
        }
        if(q.size() / 2 <= k){
            for(int j = 0 ; j < q.size() / 2 ; ++j) kq[q[j]] = s[l];
            for(int j = q.size() - 1 ; j >= q.size() / 2 ; --j) kq[q[j]] = s[r];
            continue;
        }
        for(int j = 0 ; j < k ; ++j) kq[q[j]] = s[l];
        for(int j = q.size() - 1 ; j > q.size() - k - 1 ; --j) kq[q[j]] = s[r];
        for(int j = k ; j < q.size() - k ; ++j){
            if(k % 2){
                if(s[q[j]] == 'B') kq[q[j]] = 'W';
                else kq[q[j]] = 'B';
            }
            else{
                if(s[q[j]] == 'B') kq[q[j]] = 'B';
                else kq[q[j]] = 'W';
            }
        }
        continue;
    }
    cout << kq << endl;

    return 0;
}
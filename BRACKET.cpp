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

LL n, a[MaxN], sum, d[MaxN], t, x, y;
string s;

class Tree{

    LL minNode[4 * MaxN], le[4 * MaxN], ri[4 * MaxN], leaf[MaxN], qj, qi;

    LL Find(LL node){
        if(qi > ri[node] || qj < le[node]) return 1e18;
        if(qi <= le[node] && ri[node] <= qj) return minNode[node];
        return min(Find(node * 2), Find(node * 2 + 1));
    }

    public:
        void Build(LL node, LL l, LL r){
            le[node] = l;
            ri[node] = r;
            if(l == r){
                minNode[node] = d[l];
                leaf[l] = node;
                return;
            }
            Build(node * 2, l, (l + r) / 2);
            Build(node * 2 + 1, (l + r) / 2 + 1, r);
            minNode[node] = min(minNode[node * 2], minNode[node * 2 + 1]);
        }

        LL Query(LL x, LL y){
            qi = x;
            qj = y;
            return Find(1);
        }

} tree;

void InOut(){
    #define TASK "ABC"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    // InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> t;
    cin >> s;
    s = " " + s;
    for(int i = 1 ; i <= n ; ++i){
        if(s[i] == '(') d[i] = d[i - 1] + 1;
        else d[i] = d[i - 1] - 1;
    }
    // for(int i = 1 ; i <= n ; ++i) cout << d[i] << " ";
    // cout << endl;
    tree.Build(1, 1, n);
    for(int te = 0 ; te < t ; ++te){
        cin >> x >> y;
        if((y - x + 1) % 2){
            cout << "NO" << endl;
            continue;
        }
        if(d[y] - d[x - 1] != 0){
            cout << "NO" << endl;
            continue;
        }
        if(tree.Query(x, y) < d[x - 1]){
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
    }

    return 0;
}
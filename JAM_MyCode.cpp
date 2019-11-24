// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef int LL;

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

const LL MaxN = 1 + 1e5;

LL n, a[MaxN], m, x, y, ntime, tin[MaxN], tout[MaxN], num[MaxN], low[MaxN], dad[MaxN][21], t, query, z, test;
vector<LL> q[MaxN];

void DFS(LL u, LL pr){
    tin[u] = ++ntime;
    num[u] = ++num[0];
    low[u] = n + 1;
    dad[u][0] = pr;
    for(int i = 1 ; i <= 20 ; ++i) dad[u][i] = dad[dad[u][i - 1]][i - 1];
    for(int v : q[u])
    if(v != pr){
        if(num[v]){
            low[u] = min(low[u], num[v]);
            continue;
        }
        DFS(v, u);
        low[u] = min(low[u], low[v]);
    }
    tout[u] = ++ntime;
}

inline LL isChildern(LL x, LL y){
    // Kiêm tra xem y có thuộc gốc x hay không
    return tin[x] <= tin[y] && tout[y] <= tout[x];
}

LL findParent(LL x, LL y){
    //Tìm kiếm cha xa nhất của x mà nhỏ hơn y
    for(int i = 20 ; i >= 0 ; --i){
        LL v = dad[x][i];
        if(v > 0 && v != y && isChildern(y, v)) x = v;
    }
    return x;
}

LL Solve1(LL x, LL y, LL u, LL v){
    if(num[u] > num[v]) swap(u, v); // Luôn để u đến trước v trong thứ tự DFS
    if(low[v] <= num[u]) return 1; // Điều kiện đảm bảo u-v không phải là cầu
    if(isChildern(v, x) == isChildern(v, y)) return 1; // Cạnh u-v không có ảnh hưởng gì đến đường đi x-y
    return 0;
}

LL Solve2(LL x, LL y, LL z){
    if(num[x] > num[y]) swap(x, y); // Đảm bảo x đến trước y trong thứ tự DFS
    if(dad[y][0] == x) return 1; // x-y có cạnh nối trực tiếp
    // Trong các bước tiếp theo ta sẽ xem xét tương quan về mặt quan hệ của x, y, z để tìm ra kết quả
    if(isChildern(x, y)){
        if(isChildern(z, y) && isChildern(x, z)){
            // z nằm giữa x và y
            y = findParent(y, z);
            if(low[y] < num[z]) return 1;
            return 0; // Nếu đường nối giữa cha xa nhất của y nhỏ hơn z là một cầu thì khi xóa bỏ z sẽ không có cách đi từ x đến y
        }
        // z không có tác động gì đến đường đi x-y
        return 1;
    }
    if(isChildern(x, z) || isChildern(y, z)) return 1; // Do z không thể chen ngang giữa x và y nên nếu z là con của x hoặc y thì z không có tác động gì đến đường đi x-y
    if(isChildern(z, x) && isChildern(z, y)){
        // x vvà y đều thuộc gốc z
        x = findParent(x, z);
        y = findParent(y, z);
        if(x == y) return 1; // z không có ảnh hưởng đến đường đi x-y
        if(low[x] < num[z] && low[y] < num[z]) return 1; // Các đường nối x-z và y-z không phải là cầu
        return 0;
    }
    if(isChildern(z, x) || isChildern(z, y)){
        // x hoặc y là con của z
        if(isChildern(z, y)) swap(x, y); // Đỡ mất công xét hai trường hợp
        x = findParent(x, z);
        if(low[x] < num[z]) return 1; // x-z không là một cầu
        return 0;
    }
    return 1;
}

void InOut(){
    #define TASK "JAM"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    scanf("%d%d", &n, &m);
    for(int i = 0 ; i < m ; ++i){
        scanf("%d%d", &x, &y);
        q[x].push_back(y);
        q[y].push_back(x);
    }
    DFS(1, 0);
    scanf("%d", &test);
    for(int te = 0 ; te < test ; ++te){
        scanf("%d", &query);
        // cout << query << endl;
        if(query == 1){
            scanf("%d%d%d%d", &x, &y, &z, &t);
            if(Solve1(x, y, z, t)) printf("%s\n", "yes");
            else printf("%s\n", "no");
        } else{
            scanf("%d%d%d", &x, &y, &z);
            if(Solve2(x, y, z)) printf("%s\n", "yes");
            else printf("%s\n", "no");
        }
    }

    return 0;
}

// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MaxN = 1 + 2e7;

LL n, a[MaxN], root = 0, nt = 0, x;
stack<LL> s;

template <typename T> void read(T &t) {
	t = 0; char ch = getchar(); int f = 1;
	while (ch < '0'||ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	do { (t *= 10) += ch - '0'; ch = getchar(); } while ('0' <= ch && ch <= '9'); t *= f;
}

struct Node{
    LL pr, child[2], stop;
} node[MaxN];

struct Trie{

    LL kq = 0;

    LL createNewNode(){
        nt++;
        node[nt].pr = 0;
        node[nt].child[0] = node[nt].child[1] = 0;
        node[nt].stop = 0;
        return nt;
    }

    void addNewNode(LL k){
        LL r = root, n = 0, y;
        while(k){
            s.push(k % 2);
            k /= 2;
            n++;
        }
        for(int i = 0 ; i < n ; ++i){
            LL x = s.top();
            s.pop();
            if(node[r].child[x] == 0){
                kq++;
                y = createNewNode();
                node[r].child[x] = y;
                node[y].pr = r;
            }
            r = node[r].child[x];
        }
        node[r].stop = 1;
    }

    LL Query(){
        LL r = root;
        while(1){
            if((node[r].child[0] && node[r].child[1]) || node[r].stop == 1) break;
            kq--;
            if(node[r].child[0]) r = node[r].child[0];
            else r = node[r].child[1];
        }
        return kq;
    }

} trie;

void InOut(){
    #define TASK "UNION"
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
        cin >> x;
        trie.addNewNode(x);
    }
    cout << trie.Query() << endl;

    return 0;
}

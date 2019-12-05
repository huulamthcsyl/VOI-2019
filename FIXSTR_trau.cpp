// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
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

// #define ordered_set tree<LL, null_type, less<LL>, rb_tree_tag, tree_order_statistics_node_update>
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

LL n, a[MaxN], x, y, q;
string s, status[MaxN];
char quest;

void Subtask1(){
    for(int te = 0 ; te < q ; ++te){
        cin >> quest;
        status[te] = s;
        if(quest == 'C'){
            cin >> x;
            if(s[x] == '(') s[x] = ')';
            else s[x] = '(';
            continue;
        }
        if(quest == 'U'){
            cin >> x;
            s = status[x - 1];
            continue;
        }
        cin >> x >> y;
        // cout << s << endl;
        LL kq = 0,ans = 0;
        for(int i = x ; i <= y ; ++i){
            if(s[i] == '(') kq++;
            else kq--;
            if(kq < 0) ans++, kq++;
        }
        cout << ans + kq << endl;
	}   
}

struct Node{
    LL sum, mi, lazy;
};

class Tree{

    Node TNode[4 * MaxN];
    LL le[4 * MaxN], ri[4 * MaxN], qi, qj, inc;

    void Push(LL node){
        TNode[node * 2].lazy += TNode[node].lazy;
        TNode[node * 2].mi += TNode[node].lazy;
        TNode[node * 2].sum += TNode[node].lazy;

        TNode[node * 2 + 1].lazy += TNode[node].lazy;
        TNode[node * 2 + 1].mi += TNode[node].lazy;
        TNode[node * 2 + 1].sum += TNode[node].lazy;

        TNode[node].lazy = 0;
    }

    void Change(LL node){
        if(le[node] > qj || ri[node] < qi) return;
        if(qi <= le[node] && ri[node] <= qj){
            TNode[node].lazy += inc;
            TNode[node].sum += inc;
            TNode[node].mi += inc;
            return;
        }
        Push(node);
        Change(node * 2);
        Change(node * 2 + 1);
        TNode[node].mi = min(TNode[node * 2].mi, TNode[node * 2 + 1].mi);
        TNode[node].sum = TNode[node * 2].sum + TNode[node * 2 + 1].sum;
    }

    LL findMin(LL node){
        if(qi > ri[node] || qj < le[node]) return 1e18;
        if(qi <= le[node] && ri[node] <= qj) return TNode[node].mi;
        Push(node);
        return min(findMin(node * 2), findMin(node * 2 + 1));
    }

    LL findSum(LL node){
        if(ri[node] < qi || le[node] > qj) return 0;
        if(qi <= le[node] && ri[node] <= qj) return TNode[node].sum;
        Push(node);
        return findSum(node * 2) + findSum(node * 2 + 1);
    }

    public:
        void Build(LL node, LL l, LL r){
            le[node] = l;
            ri[node] = r;
            if(l == r){
                return;
            }
            Build(node * 2, l, (l + r) / 2);
            Build(node * 2 + 1, (l + r) / 2 + 1, r);
        }

        void Update(LL x, LL y, LL k){
            qi = x;
            qj = y;
            inc = k;
            Change(1);
        }

        LL QueryMin(LL x, LL y){
            qi = x;
            qj = y;
            return findMin(1);
        }

        LL QuerySum(LL x, LL y){
            qi = x;
            qj = y;
            return findSum(1);
        }

} tree;

void InOut(){
	#define TASK "FIXSTR"
	freopen(TASK".inp","r",stdin);
	freopen(TASK".ans","w",stdout);
}

int main(){
	InOut();
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	cin >> q;
	s = " " + s;
    Subtask1();

	return 0;
}

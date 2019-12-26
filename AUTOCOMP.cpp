#include<bits/stdc++.h>
using namespace std;

typedef int LL;

#define y0 Your_name
#define y1 Weathring_with_you
#define yn Your_lie_in_April

const LL MaxN = 1 + 1e5;

LL n, q, nNode = 0, x;
char query;
string s;
string a[MaxN];

struct Node{
    LL child[26], cnt, pr, ed, nChild;
} node[26 * MaxN];

class Trie{

    void resetNode(LL val){
        for(int i = 0 ; i < 26 ; ++i) node[val].child[i] = 0;
        node[val].cnt = 0;
        node[val].pr = 0;
        node[val].ed = 0;
    }

    LL addNewNode(){
        nNode++;
        resetNode(nNode);
        return nNode;
    }

    public:
        void addNewString(string &s){
            LL len = s.length(), r = 0;
            for(int i = 0 ; i < len ; ++i){
                LL x = s[i] - 'a';
                if(node[r].child[x] == 0){
                    LL temp = addNewNode();
                    // cout << temp << endl;
                    node[r].nChild++;
                    node[r].child[x] = temp;
                    node[temp].pr = r;
                }
                r = node[r].child[x];
            }
            node[r].ed = 1;
            while(r != 0){
                // cout << node[r].nChild << endl;
                node[r].cnt++;
                r = node[r].pr;
            }
            node[0].cnt++;
        }

        void deleteString(string &s){
            LL len = s.length(), r = 0;
            node[0].cnt--;
            for(int i = 0 ; i < len ; ++i){
                LL x = s[i] - 'a';
                r = node[r].child[x];
                node[r].cnt--;
                if(node[r].cnt == 0){
                    node[node[r].pr].nChild--;
                    node[node[r].pr].child[x] = 0;
                    // cout << r << endl;
                }
            }
        }

        LL Query(string &s){
            LL kq = 0, r = 0, i = 0, len = s.length();
            while(i < len){
                if(node[r].cnt == node[node[r].child[s[i] - 'a']].cnt) kq++;
                while(i < len && node[r].cnt == node[node[r].child[s[i] - 'a']].cnt){
                    r = node[r].child[s[i] - 'a'];
                    i++;
                }
                if(i == len) break;
                r = node[r].child[s[i] - 'a'];
                kq++;
                i++;
            }
            return kq;
        }

} trie;

void InOut(){
    #define TASK "AUTOCOMP"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> q;
    n = 1;
    for(int te = 0 ; te < q ; ++te){
        cin >> query;
        if(query == '+'){
            cin >> s;
            a[n] = s;
            n++;
            trie.addNewString(s);
            continue;
        }
        if(query == '?'){
            cin >> x;
            // cout << a[x] << endl;
            cout << trie.Query(a[x]) << endl;
            continue;
        }
        cin >> x;
        trie.deleteString(a[x]);
    }

    return 0;
}

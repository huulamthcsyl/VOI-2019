#include <bits/stdc++.h>
using namespace std;
// Tên chương trình
const string NAME = "RATING";
// Số test kiểm tra
const int NTEST = 100;

// Viết lại hàm random để sử dụng cho thuận tiện. Hàm random này sinh ngẫu nhiên số trong phạm vi long long, số sinh ra >= l và <= h.
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

long long Rand(long long l, long long h) {
    return uniform_int_distribution<long long>(l, h)(rng);
}

int main()
{
    for(int iTest = 1; iTest <= NTEST; iTest++)
    {
        ofstream inp((NAME + ".inp").c_str());
        // Code phần sinh test ở đây
        inp << 4 << endl;
        int n = Rand(1, 30000), q = Rand(1, 10000);
        inp << n << " " << q << endl;
        for(int i = 0 ; i < n ; ++i) inp << Rand(0, 100000000) << " ";
        inp << endl;
        for(int i = 0 ; i < q ; ++i){
            int x = Rand(-10000000, 200000000), l = Rand(1, n), r = Rand(l, n);
            inp << x << " " << l << " " << r << endl;
        }

        inp.close();

        // Nếu dùng Linux thì "./" + Tên chương trình
        system((NAME + ".exe").c_str());
        system((NAME + "_trau.exe").c_str());
        // Nếu dùng linux thì thay fc bằng diff
        if(system(("fc " + NAME + ".out " + NAME + ".ans").c_str()) != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}

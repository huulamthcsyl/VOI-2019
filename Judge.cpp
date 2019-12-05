#include <bits/stdc++.h>
using namespace std;
// Tên chương trình
const string NAME = "FIXSTR";
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

        int n = Rand( 1 , 6 ) ;

        int m = Rand( 1 , 6 ) ;

        for(int i = 1 ; i <= n ; ++i ) if( Rand( 1 , 1000 ) % 2 )  inp << '(' ; else inp << ')' ;

        inp << '\n' << m << '\n' ;

        for(int i = 1 ; i <= m ; ++i)
        {
            int type = Rand( 1 , 2 ) ;

            char c ;

            if( type == 1 ) c = 'C' ;
            else c = 'Q' ;

            inp << c << ' ' ;

            if( type == 1 ) inp << Rand( 1 , n ) << '\n' ;
            else
            {
                int l = Rand( 1 , n - 1 ) ;
                int r = Rand( l + 1 , n ) ;

                inp << l << ' ' << r << '\n' ;
            }
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

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <fstream>
//using namespace std;
typedef long long ll;

//#define N 9465786
#define N 14500001
#define K 1000000000

int tbl[N];

void solve() {
    int n, q;

    //std::ifstream infile("test_input.txt");
    std::cin >> n >> q;
    //infile >> n >> q;
    std::vector<int> G(n);
    std::vector<int> queries(2*q);

    for (int i = 0; i < n; i++)
        std::cin >> G[i];
    //infile >> G[i];


    for (int i = 0; i < q; i++)
        std::cin >> queries[2*i] >> queries[2*i + 1];
    //infile >> queries[2*i] >> queries[2*i + 1];

    int nn = K;
    int lg_2 = 0;

    while (nn)
    {lg_2++;nn>>=1;}


    for (int i = 0; i < n; i++)
        tbl[i + 0*n] = G[i] - 1;

    for (int i = 1; i < lg_2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int v = tbl[j + (i - 1) * n];
            tbl[j + i*n] = tbl[v + (i - 1) * n];
        }
    }


    for (int i = 0; i < q; i++)
    {
        int x = queries[2*i + 0] - 1;
        int k = queries[2*i + 1];

        int d = 0;
        while (k)
        {
            if (k&1)
                x = tbl[x + d*n];
            d++;
            k >>= 1;
        }

        std::cout << x + 1 << "\n";
    }
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int t = 1;

    while (t--)
        solve();

    return 0;
}

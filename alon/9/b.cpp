#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <fstream>
//using namespace std;
typedef long long ll;

#define N 34000010
#define LG 18

int tbl[N];

void solve() {
    int n, q;

    //std::ifstream infile("test_input.txt");
    std::cin >> n >> q;
    //infile >> n >> q;
    std::vector<int> G(n);
    std::vector<int> queries(q*2);

    G[0] = -1;

    for (int i = 1; i < n; i++)
        std::cin >> G[i];
    //infile >> G[i];

    for (int i = 0; i < q; i++)
        std::cin >> queries[2*i] >> queries[2*i + 1];
    //infile >> queries[2*i] >> queries[2*i + 1];

    for (int i = 0; i < n; i++)
        tbl[i + 0*n] = G[i] - 1;

    for (int i = 1; i < LG; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int v = tbl[j + (i - 1)*n];
            if (v == -2)
                tbl[j + i*n] = -2;
            else
                tbl[j + i*n] = tbl[v + (i - 1) * n];
        }
    }

    /*
        std::cout << "\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n; j++)
            std::cout << tbl[j + i*n] + 1 << " ";
        std::cout << "\n";
    }

    std::cout << "\n";*/

    for (int i = 0; i < q; i++)
    {
        int x = queries[2*i + 0] - 1;
        int k = queries[2*i + 1];
        int d = 0;
        while (k)
        {
            if (x == -2)
                k = 0;
            else if (k & 1)
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

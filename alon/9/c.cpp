#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
//using namespace std;
typedef long long ll;

#define N 34000010
#define LG 18

int tbl[N];



void solve() {
    int n, q;
    //std::ifstream infile("test_input.txt");
    //infile >> n >> q;
    std::cin >> n >> q;
    std::vector<int> G(n);
    std::vector<int> depth(n);


    G[0] = 0;
    depth[0] = 0;
    for (int i = 1; i < n; i++)
    {
        std::cin >> G[i];
        //infile >> G[i];
        depth[i] = depth[G[i] - 1] + 1;
    }

    std::vector<int> queries(2*q);



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
            if (v == -1)
                tbl[j + i*n] = -1;
            else
                tbl[j + i*n] = tbl[v + (i - 1) * n];
        }
    }

    for (int i = 0; i < q; i++)
    {
        int a = queries[2*i + 0] - 1;
        int b = queries[2*i + 1] - 1;


        int ans = -1;

        if (depth[b] > depth[a])
        {
            ans = a;
            a = b;
            b = ans;
        }

        // a is lower

        int k = depth[a] - depth[b];
        int d = 0;

        while (k)
        {
            if (k&1)
                a = tbl[a + d*n];
            d++;
            k >>= 1;
        }


        if (a == b)
        {
            std::cout << a + 1 << "\n";
            continue;
        }
        int dd = depth[a];
        int uu = 0;
        // binary search ? (log(n) * log(n))

        while (dd >= uu)
        {
            int mid = (dd + uu) / 2;
            int aa = a;
            int bb = b;
            int kk = depth[a] - mid;
            d = 0;
            while (kk)
            {
                if (kk&1)
                {
                    aa = tbl[aa + d*n];
                    bb = tbl[bb + d*n];
                }
                d++;
                kk>>=1;
            }

            if (aa == bb)
                uu = mid + 1;
            else
                dd = mid - 1;
        }

        int kk = depth[a] - std::max(dd, uu);//(dd + uu) / 2;
        d = 0;
        while (kk)
        {
            if (kk&1)
            {
                a = tbl[a + d*n];
                b = tbl[b + d*n];
            }
            d++;
            kk>>=1;
        }
        ans = std::max(1, G[a]);
        //std::cout << dd  << " " << uu << " " <<  ans << "\n";
        std::cout << ans << "\n";
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

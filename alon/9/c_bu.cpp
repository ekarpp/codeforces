#include <iostream>
#include <vector>
#include <algorithm>

//using namespace std;
typedef long long ll;

#define N 34000010
#define LG 18

int tbl[N];



void solve() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> G(n);
    std::vector<int> depth(n);


    G[0] = 0;
    depth[0] = 0;
    for (int i = 1; i < n; i++)
    {
        std::cin >> G[i];
        depth[i] = depth[G[i] - 1] + 1;
    }

    std::vector<int> queries(2*q);



    for (int i = 0; i < q; i++)
        std::cin >> queries[2*i] >> queries[2*i + 1];


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
        //std::cout << "a: " << a + 1 << " b: " << b + 1;
        if (depth[b] > depth[a])
        {
            ans = a;
            a = b;
            b = ans;
        }

        // a is lower
        //std::cout << " a: " << a + 1 << " b: " << b + 1;
        int k = depth[a] - depth[b];
        int d = 0;
        //std::cout << " k: " << k;
        while (k)
        {
            if (k&1)
                a = tbl[a + d*n];
            d++;
            k >>= 1;
        }

        //std::cout << " a: " << a + 1 << " b: " << b + 1;

        //int dd = depth[a];
        //int uu = 0;
        // binary search ? (log(n) * log(n))
        while (a != b)
        {
            a = G[a] - 1;
            b = G[b] - 1;
        }
        //std::cout << " a: " << a + 1 << " b: " << b + 1  << " ######## ";
        ans = a + 1;
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

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <queue>
//using namespace std;
typedef long long ll;

#define N 34000010
#define LG 18

int tbl[N];

const int root = 0;

void solve() {
    int n, q;
    //std::ifstream infile("test_input.txt");
    //infile >> n >> q;
    std::cin >> n >> q;
    std::vector<std::list<int>> preG(n);
    std::vector<int> G(n);
    std::vector<int> depth(n, 0);

    for (int i = 0; i < n; i++)
        preG[i] = {};


    int a,b;
    for (int i = 0; i < n - 1; i++)
    {
        //std::cin >> G[i];
        std::cin >> a >> b;
        preG[a - 1].push_back(b - 1);
        preG[b - 1].push_back(a - 1);
        //infile >> G[i];
    }

    std::vector<int> queries(2*q);
    for (int i = 0; i < q; i++)
        std::cin >> queries[2*i] >> queries[2*i + 1];
    //infile >> queries[2*i] >> queries[2*i + 1];

    std::queue<int> que;
    std::vector<bool> visited(n, false);
    visited[root] = true;
    depth[root] = 0;
    G[root] = 0;
    que.push(root);
    que.push(-1);
    int d = 0;
    while (que.size() > 1)
    {
        int node = que.front();
        que.pop();

        if (node == -1)
        {
            d++;
            que.push(-1);
            continue;
        }

        for (auto it = preG[node].begin(); it != preG[node].end(); it++)
            if (!visited[*it])
            {
                visited[*it] = true;
                que.push(*it);
                depth[*it] = d + 1;
                G[*it] = node + 1;
            }
    }

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

        int ao = a;
        int bo = b;

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
            std::cout << depth[ao] -  depth[bo] << "\n";
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

        int kk = depth[a] - std::max(dd, uu);
        d = 0;
        int aa = a;
        int bb = b;

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

        std::cout << depth[ao] + depth[bo] - 2*depth[ans - 1] << "\n";
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

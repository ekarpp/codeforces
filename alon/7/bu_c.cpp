#include <iostream>
#include <vector>
#include <algorithm>

//using namespace std;
typedef long long ll;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> list(n);
    std::vector<int> rm(n);

    for (int i = 0; i < n; i++)
        std::cin >> list[i];

    for (int i = 0; i < n; i++)
        std::cin >> rm[i];

    int nn = n;
    int lg_2 = 0;
    while (nn)
    {lg_2++; nn >>= 1;}
    int size = 1 << lg_2;

    // store which have been removed
    std::vector<int> tree(2*size + 1, 0);

    for (int i = 0; i < n; i++)
    {
        int idx = rm[i] + size - 1;
        // go right, add
        // go left dont add
        int p = idx;
        int rmd = 0;
        int addd = 0;
        while (tree[p])
        {addd += tree[p]; p += tree[p];}

        if (p % 2 == 0)
            p--;

        if (p >= size)
        {
            while (p & (p - 1))
            {
                if (p % 2 == 0)
                    p--;
                p /= 2;
            }

            rmd += tree[p];
        }
        int mid = size + size / 2;
        // over half way, add left side of tree

        if (idx + addd > mid)
            rmd += tree[1];

        std::cout << list[rm[i] - 1 + rmd] << " ";


        //for (int i = size; i <= size*2; i++)
        //std::cout << tree[i] << " ";

        //std::cout << "\n\n";
        // if right side of thee also add left side
        // now tree[idx] += 1; and update
        idx += rmd;
        tree[idx]++;
        for (idx /= 2; idx >= 1; idx /= 2)
            tree[idx] = tree[2*idx + 0] + tree[2*idx + 1];
    }
    std::cout << "\n";
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int t = 1;
    while (t--)
        solve();

    return 0;
}

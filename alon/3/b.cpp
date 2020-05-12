#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
//using namespace std;
typedef long long ll;

void solve() {
    int n, m;
    std::cin >> n;
    std::cin >> m;
    std::multiset<int> sizes;
    std::vector<int> demands(m);

    for (int i = 0; i < n; i++)
    {
        int k;
        std::cin >> k;
        sizes.insert(k);
    }

    for (int i = 0; i < m; i++)
        std::cin >> demands[i];

    for (int i = 0; i < m; i++)
    {
        int d = demands[i];
        auto it = sizes.lower_bound(d);
        if (it == sizes.end())
            std::cout << "-1 ";
        else
        {
            std::cout << *it << " ";
            sizes.erase(it);
        }
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

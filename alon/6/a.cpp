#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
//using namespace std;
typedef long long ll;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> vec(n);

    for (int i = 0; i < n; i++)
        std::cin >> vec[i];

    std::set<int> ans;
    ans.insert(vec[0]);
    for (int i = 1; i < n; i++)
    {
        int coin = vec[i];
        std::set<int> nww = ans;
        nww.insert(coin);
        for (auto it = ans.begin(); it != ans.end(); it++)
            nww.insert(coin + *it);
        ans = nww;
    }

    std::cout << ans.size() << "\n";
    std::vector<int> nass(ans.size());
    int i = 0;
    for (auto it = ans.begin(); it != ans.end(); it++)
    {
        nass[i] = *it;
        i++;
    }

    std::sort(nass.begin(), nass.end());
    for (int i = 0; i < ans.size(); i++)
        std::cout << nass[i] << " ";
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

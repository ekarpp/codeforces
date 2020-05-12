#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
//using namespace std;
typedef long long ll;

void solve() {
    int n, k;
    std::cin >> n;
    std::cin >> k;
    std::vector<ll> vec(n);

    for (int i = 0; i < n; i++)
        std::cin >> vec[i];

    std::map<int, int> mp;
    std::map<int, std::set<int>> inv;
    for (int i = 0; i < k; i++)
        mp[vec[i]]++;

    int m = -1;

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        if (it->second > m)
            m = it->second;
        inv[it->second].insert(it->first);
    }

    std::cout << *(inv[m].lower_bound(0)) << " ";

    for (int i = 1; i <= n - k; i++)
    {
        int old = vec[i - 1];
        int nw = vec[k + i - 1];

        int mp_old = mp[old];


        inv[mp_old].erase(old);
        inv[mp_old - 1].insert(old);
        mp[old]--;

        if (m == mp_old && inv[m].size() == 0)
            m--;

        int mp_new = mp[nw];
        inv[mp_new].erase(nw);
        inv[mp_new + 1].insert(nw);
        mp[nw]++;
        if (m == mp_new)
            m++;

        std::cout << *(inv[m].lower_bound(0)) << " ";
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

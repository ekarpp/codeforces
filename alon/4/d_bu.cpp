#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
//using namespace std;
typedef long long ll;



void solve() {
    int n;
    std::cin >> n;


    int a,b;
    std::vector<std::pair<int, int>> vec(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a >> b;
        vec[i] = std::make_pair(a, b);
    }

    std::vector<int> s(n);
    std::vector<int> e(n);

    for (int i = 0; i < n; i++)
        s[i] = e[i] = i;


    std::sort(s.begin(), s.end(),
         [&](const int& a, const int& b) {
             return (vec[a].first < vec[b].first);
         }
        );

    std::sort(e.begin(), e.end(),
         [&](const int& a, const int& b) {
             return (vec[a].second < vec[b].second);
         }
        );

    int l, r, m, val, ei, si;
    int start, end;

    for (int i = 0; i < n; i++)
    {
        l = 0;
        r = n - 1;

        start = vec[i].first;
        end = vec[i].second;

        // find smallest end time > start
        // find smallest start time > end

        while (l < r)
        {
            m = l + (r - l) / 2;
            val = vec[e[m]];

            if (val < start)
                l = m + 1;
            else
                r = m - 1;
        }
        ei = l + (r - l) / 2;

        l = 0;
        r = n - 1;

        while (l < r)
        {
            m = l + (r - l) / 2;
            val = vec[s[m]];

            if (val < end)
                l = m + 1;
            else
                r = m - 1;
        }
        si = l + (r - l) / 2;
        std::set<int> set;
        while (si
    }
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    while (t--)
        solve();

    return 0;
}

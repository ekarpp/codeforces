#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
//using namespace std;
typedef long long ll;

struct cmp_s {
    bool operator() (std::pair<int, int> a, std::pair<int, int> b) {
        return a.first < b.first;
    }
};

struct cmp_e {
    bool operator() (std::pair<int, int> a, std::pair<int, int> b) {
        return a.second < b.second;
    }
};

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


    std::set<std::pair<int, int>, cmp_s> set_s;
    set_s.insert(vec[0]);

    std::pair<int, int> p;

    for (int i = 1; i < n; i++)
    {
        p = vec[i];
        auto it_e = set_s.lower_bound(p);
        auto it_s = it_e;
        it_s--;

        if (it_s != set_s.end()
            && it_s->first <= p.second && it_s->second >= p.first)
        {
            std::cout << i+1 << "\n";
            return;
        }

        if (it_e != set_s.end()
            && it_e->second >= p.first && it_e->first <= p.second)
        {
            std::cout << i+1 << "\n";
            return;
        }

        set_s.insert(p);
    }

    std::cout  << -1 << "\n";
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int t = 1;
    while (t--)
        solve();

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

//using namespace std;
typedef long long ll;

ll count(ll c)
{
    if (c == 1)
        return 1;
    if (c == 2)
        return 3;
    return 3 + 2*count(c - 1);
}

// find all sequences, count their length. then combinatorics.
// hashmap?
void solve() {
    ll n,m;
    std::cin >> n;
    std::cin >> m;
    std::vector<std::set<ll>> not_know(n);

    for (ll i = 0; i < m; i++)
    {
        ll x, y;
        std::cin >> x;
        std::cin >> y;
        not_know[x-1].insert(y-1);
        not_know[y-1].insert(x-1);
    }


    ll len = 1;
    std::set<ll> uk;
    uk.insert(not_know[0].begin(), not_know[0].end());
    ll pairs = 0;
    for (ll i = 0; i < n-1; i++)
    {
        // i and i+1 know
        if (uk.count(i+1) == 0)
            len++;
        else
        {
            pairs += count(len);
            len = 1;
            uk.clear();
        }
        uk.insert(not_know[i+1].begin(), not_know[i+1].end());
    }
    pairs += count(len);

    std::cout << pairs << std::endl;
}


int main(int argc, char **argv) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    while (t--)
        solve();

    return 0;
}

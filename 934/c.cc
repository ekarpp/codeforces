#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    ll n;
    std::cin >> n;

    std::vector<ll> vec(n, 0);

    for (ll i = 0; i < n; i++)
    {
        ll v;
        std::cin >> v;
        vec[v]++;
    }

    bool found1 = false;

    ll i;
    for (i = 0; i < n; i++)
    {
        if (vec[i] == 0)
        {
            std::cout << i;
            break;
        }
        else if (vec[i] == 1 && found1)
        {
            std::cout << i;
            break;
        }
        else if (vec[i] == 1)
            found1 = true;
    }
    if (i == n)
        std::cout << i;
    std::cout << std::endl;
}


int main(int argc, char **argv) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    ll t;
    std::cin >> t;
    while (t--)
        solve();

    return 0;
}

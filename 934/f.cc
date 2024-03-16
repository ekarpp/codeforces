#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    ll n;
    std::cin >> n;
    std::vector<ll> vec(n);

    for (ll i = 0; i < n; i++)
        std::cin >> vec[i];

    for (ll i = 0; i < n; i++)
        std::cout << vec[i];
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

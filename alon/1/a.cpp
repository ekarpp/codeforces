#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

void solve() {
    ll n;
    std::cin >> n;

    ll res = (n * (n + 1)) / 2;
    std::cout << res << "\n";
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int t = 1;
    //std::cin >> t;
    while (t--)
        solve();

    return 0;
}

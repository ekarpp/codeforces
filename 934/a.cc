#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    ll n, k;
    std::cin >> n >> k;

    ll bridges = n * (n - 1) / 2;
    if (k >= n - 1)
        std::cout << 1;
    else
        std::cout << n;
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

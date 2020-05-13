#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

void solve() {
    int n, m;
    std::cin >> n;
    std::cin >> m;

    if (n == 1 || m == 1)
        std::cout << "YES" << "\n";
    else if (n == 2 && m == 2)
        std::cout << "YES" << "\n";
    else
        std::cout << "NO" << "\n";

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

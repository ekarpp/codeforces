#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

void solve() {
    int n;
    std::cin >> n;
    if (n == 1)
    {
        std::cout << 1 << "\n";
        return;
    }
    else if (n < 4)
    {
        std::cout << "NO SOLUTION" << "\n";
        return;
    }

    for (int i = 2; i <= n; i += 2)
        std::cout << i << " ";

    for (int i = 1; i <= n; i += 2)
        std::cout << i << " ";

    std::cout << "\n";
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

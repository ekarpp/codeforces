#include <iostream>
#include <vector>
#include <algorithm>

//using namespace std;
typedef long long ll;

void solve() {
    int n;
    std::cin >> n;

    int sum = 0;
    while (n >= 2)
    {
        int h = 1;
        while (2 + 2*(h - 1) + 3 * ((h * (h - 1)) / 2) <= n)
            h++;

        h--;

        sum++;
        n -= 2 + 2*(h - 1) + 3 * (h * (h - 1))/2;
//        std::cout << h << " " << n << "\n";
//n -= 2*h + (h*h + h) / 2 - 1;
    }
    std::cout << sum << "\n";
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

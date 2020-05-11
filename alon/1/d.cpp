#include <iostream>
#include <vector>
#include <algorithm>

//using namespace std;
typedef long long ll;

void solve() {
    int a, b;
    std::cin >> a;
    std::cin >> b;

    if ((2*a < b && b > a)|| (2*b < a && a > b))
    {
        std::cout << "NO" << "\n";
        return;
    }

    int d = (a > b) ? a - b : b - a;
    int left = (a > b) ? b - d : a - d;

    if (left % 3 == 0)
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
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

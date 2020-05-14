#include <iostream>
#include <vector>
#include <algorithm>

//using namespace std;
typedef long long ll;


const int mask = 0xFFFFF;

void solve() {
    ll n;
    std::cin >> n;

    ll l = 1;
    ll r = n*n;

    while (l <= r)
    {
        ll mid = l + (r - l) / 2;

        ll lt = -1;
        for (int i = 1; i <= n; i++)
            lt += std::min(mid / i, n);

        if (lt < (n*n) / 2)
            l = mid + 1;
        else if (lt > (n*n) / 2)
            r = mid - 1;
        else
            break;
    }

    std::cout << l + (r - l) / 2 << "\n";
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int t = 1;
    while (t--)
        solve();

    return 0;
}

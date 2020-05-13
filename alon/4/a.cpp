#include <iostream>
#include <vector>
#include <algorithm>

//using namespace std;
typedef long long ll;

void solve() {
    ll n, t;
    std::cin >> n >> t;

    std::vector<ll> vec(n);

    for (int i = 0; i < n; i++)
        std::cin >> vec[i];

    std::sort(vec.begin(), vec.end());

    ll right = vec[0] * t;
    ll left = 0;
    while (left <= right)
    {
        ll mid = left + (right - left) / 2;
        ll sum = 0;
        for (int i = 0; i < n; i++)
            sum += mid / vec[i];

        if (sum < t)
            left = mid + 1;
        else
            right = mid - 1;
    }

    std::cout << left << "\n";
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int t = 1;
    while (t--)
        solve();

    return 0;
}

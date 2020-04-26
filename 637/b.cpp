#include <iostream>
#include <vector>
#include <algorithm>

//using namespace std;
typedef long long ll;

void solve() {
    ll n, k;
    std::cin >> n;
    std::cin >> k;
    std::vector<ll> vec(n);
    std::vector<bool> peaks(n);

    for (ll i = 0; i < n; i++)
        std::cin >> vec[i];

    for (ll i = 1; i < n - 1; i++)
        peaks[i] = vec[i-1] < vec[i] && vec[i] > vec[i+1];

    peaks[n-1] = false;
    peaks[0] = false;

    ll maxidx = 1L;
    ll max = 1L;
    for (ll i = 0L; i < k - 2; i++)
        if (peaks[i + 1])
            max++;

    ll prev = max;
    for (ll l = 1L; l <= n - k; l++)
    {
        if (peaks[l])
            prev--;
        if (peaks[l + k - 2])
            prev++;

        if (prev > max)
        {
            maxidx = l + 1;
            max = prev;
        }
    }

    std::cout << max << ' ' << maxidx << '\n';
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

#include <iostream>
#include <vector>
#include <algorithm>

//using namespace std;
typedef long long ll;

void solve() {
    int n, w;
    std::cin >> w;
    std::cin >> n;
    std::vector<ll> vec(n);

    for (int i = 0; i < n; i++)
        std::cin >> vec[i];

    std::sort(vec.begin(), vec.end());

    int g, r;
    std::cin >> g;
    std::cin >> r;

    std::vector<ll> diff(n - 1);
    for (int i = 1; i < n; i++)
    {
        diff[i-1] = vec[i] - vec[i-1];
        if (diff[i - 1] > g)
        {
            std::cout << -1 << '\n';
            return;
        }
    }

    // dp[idx, t] = [idx * g + t] = shortest distance to n when
    // arrive with t moves before light go red

    std::vector<ll> dp((g + 1) * (n - 1), -2);

    // unreachables
    for (int i = 0; i < n - 1; i++)
    {
        ll d = i == 0 ? diff[0] : min(diff[i], diff[i-1]);
        for (int j = 1; j < d; j++)
            dp[i * (g + 1) + j] = -1;
    }

    // n - 1 island
    for (int i = diff[n - 1]; i <= g; i++)
        dp[(n - 2) * (g + 1) + i] = i;

    for (int t = 0; t <= g; t++)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (dp[i*(g+1) + t] == -1)
                continue;
            // infd max and set dp
            // first left then right
            int max = -1;
            int l = i - 1;
            while (l >= 0 && vec[i] - vec[l] >= t)
            {

            }
        }
    }

}

void bounce(int from, int to, int start)
{

}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int t = 1;
    while (t--)
        solve();

    return 0;
}

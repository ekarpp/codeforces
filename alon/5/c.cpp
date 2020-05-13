#include <iostream>
#include <vector>
#include <algorithm>

//using namespace std;
typedef long long ll;

ll dp[2500*2500];

void solve() {
    int n;
    std::cin >> n;
    std::vector<bool> vec(n * n);

    char c;
    for (int i = 0; i < n*n; i++)
    {
        std::cin >> c;
        vec[i] = c == '*';
    }


    dp[n*n - 1] = vec[n*n - 1];

    // bottom row frst

    for (int x = n - 2; x >= 0; x--)
    {
        int idx = x + n*(n - 1);
        dp[idx] = vec[idx] + dp[idx + 1];
    }



    for (int y = n - 2; y >= 0; y--)
    {
        for (int x = n - 1; x >= 0; x--)
        {
            int idx = x + y*n;
            dp[idx] = vec[idx] + std::min(dp[idx + 1], dp[idx + n]);
        }
    }

    std::cout << dp[0] << "\n";

}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int t = 1;
    while (t--)
        solve();

    return 0;
}

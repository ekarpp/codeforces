#include <iostream>
#include <vector>
#include <algorithm>

//using namespace std;
typedef long long ll;



ll dp[10000010];

void solve() {
    ll mod = 10;
    for (int i =0; i < 8; i++)
        mod *= 10;
    mod += 7;

    int n, k;
    std::cin >> n >> k;


    for (int kk = 0; kk < k; kk++)
        dp[kk] = (1L << (kk+1));

    for (int nn = k; nn < n; nn++)
    {
        dp[nn] = 0;
        for (int i = 1; i <= k; i++)
            dp[nn] = (dp[nn] + dp[nn - i]) % mod;
    }

    n--;
    std::cout << dp[n] << "\n";
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int t = 1;

    while (t--)
        solve();

    return 0;
}

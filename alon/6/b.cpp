#include <iostream>
#include <vector>
#include <algorithm>

//using namespace std;
typedef long long ll;

ll dp[100*100*1000 + 1];

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> vec(n);

    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        std::cin >> vec[i];
        sum += vec[i];
    }

    if (sum % 2)
    {
        std::cout << "0\n";
        return;
    }


    ll tar = sum / 2;
    ll K = tar + 1;
    int N = n - 1;
    dp[0 + K * N] = true;

    for (int i = 1; i <= K; i++)
        dp[i + K * N] = false;

    dp[0] = false;
    for (int i =
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int t = 1;

    while (t--)
        solve();

    return 0;
}

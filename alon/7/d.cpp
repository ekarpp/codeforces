#include <iostream>
#include <vector>
#include <algorithm>

//using namespace std;
typedef long long ll;
const ll M = 1000000007;
ll dp[10000001];

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> vec(n);

    for (int i = 0; i < n; i++)
        std::cin >> vec[i];

    int nn = n;
    int lg_2 = 0;
    while (nn)
    {lg_2++; nn >>= 1;}

    int size = 1 << lg_2;

    std::vector<std::pair<int, ll>> tree(2*size + 1);

    for (int i = 0; i < 2*size; i++)
        tree[i] = std::make_pair(0, 0);

    dp[n - 1] = 1;
    int idx = size + n - 1;
    tree[idx].first = vec[n - 1];
    tree[idx].second = 1;

    for (idx /= 2; idx >= 0; idx /= 2)
    {
        tree[idx].first = ;
        tree[idx].second = tree[2*idx + 0].second + tree[2*idx + 1].second;
    }
    // use tree to get all smaller than maybe??
    for (int i = n - 2; i >= 0; i--)
    {
        dp[i] = 1 + (vec[i] < vec[i+1] ? dp[i+1] : 0);
    }

    ll sum = 0;
    for (int i = 0; i < n; i++)
        sum += dp[i];

    std::cout << sum << "\n";
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int t = 1;

    while (t--)
        solve();

    return 0;
}

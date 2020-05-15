#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <unordered_map>
#include <queue>

//using namespace std;
typedef long long ll;

std::list<int> G[500011];

int dp[2*500011];

void dfs(int node, int prev)
{
    // 0 node not included, 1 node included
    dp[2*node + 0] = 0;
    dp[2*node + 1] = 0;

    for (auto next : G[node])
    {
        if (next == prev)
            continue;
        dfs(next, node);

        dp[2*node + 0] += std::max(dp[2*next + 0], dp[2*next + 1]);
    }

    for (auto next : G[node])
    {
        if (next == prev)
            continue;
        dp[2*node + 1] = std::max(dp[2*node + 1],
                                  1 + dp[2*node] + dp[2*next]
                                  - std::max(dp[2*next + 1], dp[2*next]));
    }
}

void solve() {
    int n;
    std::cin >> n;
    for (int i = 0 ; i < n; i++)
        G[i] = {};

    int from, to;
    for (int i = 0; i < n - 1; i++)
    {
        std::cin >> from >> to;
        G[from - 1].push_back(to - 1);
        G[to - 1].push_back(from - 1);
    }


    dfs(0, -1);

    std::cout << std::max(dp[0], dp[1]) << "\n";
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int t = 1;

    while (t--)
        solve();

    return 0;
}

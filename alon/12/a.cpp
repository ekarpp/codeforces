#include <iostream>
#include <vector>
#include <algorithm>

//using namespace std;
typedef long long ll;

std::vector<int> G[1 << 20];
std::vector<std::pair<int, int>> E[1 << 20];
int n;
bool visited[1 << 20];
void dfs(int node, ll w)
{
    visited[node] = true;

    for (int i = 0; i < G[node].size(); i++)
    {
        std::pair<int, int> p = E[node][i];
        int other = G[node][i];

    }
    for (auto p : G[node])
        if (!visited[p.first] && p.second <= w)
            dfs(p.first, w);
}

bool possible(ll  w)
{
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        for (int j = 0; j < G[i].size(); j++)
        {
            E[i][j].first += E[i][j].second;
            E[i][j].second = 0;
        }
    }

    dfs(0, w);
    std::cout << w  << " " << visited[n-1] << "\n";
    std::cout.flush();
    return visited[n - 1];
}

void solve() {
    int m;
    std::cin >> n >> m;

    int a,b,c;
    for (int i = 0; i < m; i++)
    {
        std::cin >> a >> b >> c;
        G[a - 1].push_back(b - 1);
        E[a - 1].push_back(std::make_pair(c, 0));
    }

    ll l = 0;

    for (ll r = 1000000000; r >= 1; r /= 2)
        while (possible(l + r))
            l += r;

    std::cout << l << "\n";
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int t = 1;

    while (t--)
        solve();

    return 0;
}

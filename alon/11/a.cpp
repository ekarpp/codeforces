#include <iostream>
#include <vector>
#include <algorithm>

//using namespace std;
typedef long long ll;

std::vector<int> G[1<<20];
bool visited[1<<20];
int pre[1<<20];
int post[1<<20];

int clk = 0;

void dfs(int node)
{

    visited[node] = true;
    clk++;
    pre[node] = clk;

    for (auto next : G[node])
        if (!visited[next])
            dfs(next);
    clk++;
    post[node] = clk;

}

void solve() {
    int n, m;
    std::cin >> n >> m;

    int a,b;
    for (int i = 0; i < m; i++)
    {
        std::cin >> a >> b;
        G[a - 1].push_back(b - 1);
    }

    for (int i =0 ; i < n; i++)
        if (!visited[i])
            dfs(i);

    std::vector<int> rank(n);

    for (int i = 0; i < n; i++)
        rank[i] = i;

    std::sort(rank.begin(), rank.end(),
              [&](const int& a, const int & b)
              {
                  return post[a] > post[b];
              }
        );

    for (int i =0 ; i < n; i++)
        std::cout << rank[i] + 1 << " ";
    std::cout << "\n";
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int t = 1;

    while (t--)
        solve();

    return 0;
}

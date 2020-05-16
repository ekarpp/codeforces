#include <iostream>
#include <vector>
#include <algorithm>

//using namespace std;
typedef long long ll;

std::vector<int> G[200010];
bool visited[200010];
int pre[200010];
int post[200010];

int pred[200010];

int clk = 0;

void dfs(int node)
{
    if (visited[node])
    {
        std::cout << "here\n";
        return;
    }

    clk++;
    pre[node] = clk;

    visited[node] = true;

    for (auto next : G[node])
        if (!visited[next])
        {
            pred[next] = node;
            dfs(next);
        }

    clk++;
    post[node] = clk;
}



void solve() {
    int n;
    std::cin >> n;

    int a, b;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a >> b;
        G[a - 1].push_back(b - 1);
        G[b - 1].push_back(a - 1);
        visited[i] = false;
    }


    dfs(0);
    /*
    for (int i = 0; i < n; i++)
    {
        std::vector<int> edges = tree[i];
        std::cout << "from " << i + 1 << " we can go to:\n";
        for (int j = 0; j < edges.size(); j++)
        {
            std::cout << edges[j] + 1 << " - " << te[i][j] << "\n";;
        }
        std::cout << "\n";
        }*/
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int t = 1;

    while (t--)
        solve();

    return 0;
}

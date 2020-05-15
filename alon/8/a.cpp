#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <queue>
#include <unordered_map>
//using namespace std;
typedef long long ll;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::list<int>> G(n);

    for (int i =0 ; i < n; i++)
        G[i] = {};

    int from, to;
    for (int i = 0; i < n - 1; i++)
    {
        std::cin >> from >> to;
        G[from - 1].push_front(to - 1);
        G[to - 1].push_front(from - 1);
    }

    int root = 0;




    int ans = 0;

    for (int i = 0; i < 2; i++)
    {
        std::queue<int> q;
    std::unordered_map<int, bool> visited;
        q.push(root);
    q.push(-1);
    int depth = 0;
    while (q.size() > 1)
    {
        int node = q.front();
        q.pop();

        if (node == -1)
        {
            depth++;
            q.push(-1);
            continue;
        }

        root = node;
        for (auto it = G[node].begin(); it != G[node].end(); it++)
        {
            if (visited[*it] == 0)
            {
                visited[*it] = 1;
                q.push(*it);
            }
        }
    }
    ans = depth;
    }

    std::cout << ans << "\n";
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int t = 1;
    while (t--)
        solve();

    return 0;
}

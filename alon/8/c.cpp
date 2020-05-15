#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <queue>
//using namespace std;
typedef long long ll;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::list<int>> G(n);

    for (int i =0 ;i < n; i++)
        G[i] = {};

    int a,b;
    for (int i = 0; i < n - 1; i++)
    {
        std::cin >> a >> b;
        G[a - 1].push_back(b - 1);
        G[b - 1].push_back(a - 1);
    }

    std::queue<int> q;
    std::vector<bool> visited(n,false);
    q.push(0);
    visited[0] = true;
    int root = -1;
    while (q.size())
    {
        int node = q.front();
        q.pop();
        root = node;
        visited[node] = true;
        for (auto it = G[node].begin(); it != G[node].end(); it++)
            if (!visited[*it])
            {
                visited[*it] = true;
                q.push(*it);
            }
    }

    std::vector<int> pred(n);
    int prev = -1;
    int depth = 0;
    for (int i = 0; i < n;i++)
        visited[i] = false;
    q.push(root);
    visited[root] = true;
    q.push(-1);
    while (q.size() > 1)
    {
        int node = q.front();
        q.pop();
        if (node == -1)
        {depth++;q.push(-1);continue;}
        pred[node] = prev;
        prev = node;
        for (auto it = G[node].begin(); it != G[node].end(); it++)
            if (!visited[*it])
            {
                visited[*it] = true;
                q.push(*it);
            }
    }

    q.pop();

    int start = root;
    int end = prev;

    std::vector<int> dist(n, 0);
    dist[start] = depth;
    dist[end] = depth;
    int node = pred[end];
    int d = depth;
    int pm = -1;

    while (node)
    {
        d += pm;
        dist[node] = d;
        node = pred[node];
        if (d == depth / 2)
            pm = -1;
    }
    for (int i = 0; i < n; i++)
        visited[i] = false;

    q.push(root);
    visited[root] = true;
    while (q.size())
    {
        node = q.front();
        q.pop();

        if (dist[node] == 0)
            dist[node] = dist[pred[node]] - 1;

        for (auto it = G[node].begin(); it != G[node].end(); it++)
            if (!visited[*it])
            {
                visited[*it] = true;
                q.push(*it);
            }
    }

    for (int i = 0; i < n; i++)
        std::cout << dist[i] << " ";
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

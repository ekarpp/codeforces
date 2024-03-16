#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void dfs(ll root, ll curr, ll n, vector<vector<ll>>& adjacency, vector<ll>& distances, ll depth)
{
    distances[curr + root * n] = depth;

    for (long unsigned int i = 0; i < adjacency[curr].size(); i++)
    {
        ll next = adjacency[curr][i];
        // have we been there yet?
        if (distances[next + root * n] == -1)
            dfs(root, next, n, adjacency, distances, depth + 1);
    }
}

void solve() {
    ll n;
    std::cin >> n;
    std::vector<std::vector<ll>> adjacency(n, std::vector<ll>(0, 0));
    std::vector<ll> distances(n * n, -1);


    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        std::cin >> u >> v;
        adjacency[u - 1].push_back(v - 1);
        adjacency[v - 1].push_back(u - 1);
    }

    for (int i = 0; i < n; i++)
        dfs(i, i, n, adjacency, distances, 0);

    // now find row that has most number of same distance repeated. then paint using it.
    // repeat until done.
    // this is greedy and it dont work?
    std::vector<std::pair<ll, ll>> ops;
    while (true)
    {
        ll global_max = -1;
        ll global_v = -1;
        ll global_d = -1;
        bool found = false;
        for (ll v = 0; v < n; v++)
        {
            std::vector<ll> distance_count(n, 0);
            // find counts for all distances
            for (ll u = 0; u < n; u++)
            {
                ll d = distances[u + v * n];
                if (d != -1)
                {
                    distance_count[d]++;
                    // atleast one vertex is not painted
                    found = true;
                }
            }
            // update max
            for (ll i = 0; i < distance_count.size(); i++)
            {
                if (distance_count[i] > global_max)
                {
                    global_d = i;
                    global_v = v;
                    global_max = distance_count[i];
                }
            }
        }

        if (!found)
        {
            std::cout << ops.size() << std::endl;
            for (ll i = 0; i < ops.size(); i++)
            {
                std::pair<ll, ll> op = ops[i];
                std::cout << op.first + 1 << " " << op.second << std::endl;
            }
            return;
        }
        ops.push_back(std::make_pair(global_v, global_d));

        // paint the vertices, i.e. make their distance -1
        for (ll u = 0; u < n; u++)
        {
            if (distances[u + global_v * n] == global_d)
            {
                for (ll uu = 0; uu < n; uu++)
                    distances[u + uu * n] = -1;
            }
        }
    }
}


int main(int argc, char **argv) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    ll t;
    std::cin >> t;
    while (t--)
        solve();

    return 0;
}

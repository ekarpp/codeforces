#include <iostream>
#include <vector>
#include <algorithm>

//using namespace std;
typedef long long ll;

void solve() {
    int n, m;
    std::cin >> n;
    std::cin >> m;
    std::vector<bool> vec(n*m);
    char c;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cin >> c;
            vec[j + i * n] = c == '.';
        }
    }

    bool found = false;
    for (int col = 0; col < m; col++)
    {
        found = vec[col + 0 * n];
        int row = 0;
        while (vec[col + row*n])
            row++;
        row++;
        for ( ; row < n; row++)
        {
            if (!vec[col + row*n])
                continue;
            if (!found)
            {
                found = true;
                continue;
            }
            if (!vec[col + row*n])
        }
    }
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int t = 1;
//    std::cin >> t;
    while (t--)
        solve();

    return 0;
}

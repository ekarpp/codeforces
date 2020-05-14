#include <iostream>
#include <vector>
#include <algorithm>

//using namespace std;
typedef long long ll;

void solve() {
    int n, m;
    std::cin >> n >> m;

    int nn = n;
    int lg_2 = 0;

    while (nn)
    {lg_2++; nn >>= 1;}

    int size = 1L << lg_2;

    std::vector<int> rooms(2*size + 1);
    std::vector<int> people(m);

    for (int i = size; i < size + n; i++)
        std::cin >> rooms[i];

    for (int i = size + n; i <= 2*size; i++)
        rooms[i] = 0;

    for (int i = size - 1; i > 0; i--)
        rooms[i] = std::max(rooms[2*i + 0], rooms[2*i + 1]);

    rooms[0] = 0;

    for (int i = 0; i < m; i++)
        std::cin >> people[i];

    for (int i = 0; i < m; i++)
    {
        int amnt = people[i];

        int idx = 1;
        while (idx < size)
        {
            int l = 2*idx;
            int r = 2*idx + 1;

            if (amnt <= rooms[l])
                idx = l;
            else if (amnt <= rooms[r])
                idx = r;
            else
            {
                idx = -1;
                break;
            }


        }

        if (idx == -1)
        {
            std::cout << idx << "\n";
            continue;
        }

        std::cout << idx - size + 1 << " ";

        rooms[idx] -= amnt;

        for (idx /= 2; idx >= 1; idx /= 2)
            rooms[idx] = std::max(rooms[2*idx], rooms[2*idx + 1]);
    }
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int t = 1;

    while (t--)
        solve();

    return 0;
}

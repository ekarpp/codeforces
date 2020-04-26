#include <iostream>
#include <vector>
#include <algorithm>

//using namespace std;
typedef int ll;

void solve() {
    int n;
    std::cin >> n;




    std::vector<ll> vec(n);
    for (int i = 0; i < n; i++)
        std::cin >> vec[i];

    if (n == 1)
    {
        std::cout << "Yes" << '\n';
        return;
    }

    int idx = 1;
    while (idx <= n)
    {
        int pos = 0;
        while (vec[pos] != idx)
            pos++;
        while (pos < n && idx <= n && vec[pos] >= idx)
        {
            if (vec[pos] != idx)
            {
                std::cout << "No" << '\n';
                return;
            }
            pos++;
            idx++;
        }
    }


    std::cout << "Yes" << '\n';

}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    while (t--)
        solve();

    return 0;
}

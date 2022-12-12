#include <iostream>
#include <vector>
#include <algorithm>

//using namespace std;
typedef long long ll;

ll choose(ll n, ll k)
{
    return n;
}

// always >= 2, symmetry
// find max, find min
// count max, count min
void solve() {
    int n;
    std::cin >> n;
    std::vector<ll> vec(n);

    for (int i = 0; i < n; i++)
        std::cin >> vec[i];

    ll max_cnt = 1;
    ll max = vec[0];
    ll min_cnt = 1;
    ll min = vec[0];
    for (int i = 1; i < n; i++)
    {
        if (vec[i] == max)
            max_cnt++;
        else if (vec[i] > max)
        {
            max = vec[i];
            max_cnt = 1;
        }

        if (vec[i] == min)
            min_cnt++;
        else if (vec[i] < min)
        {
            min = vec[i];
            min_cnt = 1;
        }
    }

    if (max == min)
        std::cout << max_cnt * (min_cnt - 1) << std::endl;
    else
        std::cout << 2 * max_cnt * min_cnt << std::endl;
}


int main(int argc, char **argv) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    while (t--)
        solve();

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

//using namespace std;
typedef long long ll;

void solve() {
    int n;
    std::cin >> n;

    std::vector<ll> vec(n);

    ll neg = 0;
    ll pos = 0;

    for (int i =0 ;i < n; i++)
    {
        std::cin >> vec[i];

        if (vec[i] > 0)
            pos += vec[i];
        else
            neg += vec[i];

        if (pos + neg < 0)
        {
            std::cout << -1 << "\n";
            return;
        }
    }


    neg = 0;

    for (int b = pos; b >= 1; b /= 2)
    {

    }

    while (neg <= pos)
    {
        ll m = neg + (pos - neg) / 2;
        //std::cout << neg << " " << pos << "\n";
        ll have = 0;
        int i = 0;
        while (have >= 0 && i < n)
            have = std::min(have + vec[i++], m);

        if (have < 0)
            neg = m + 1;
        else if (have > 0)
            pos = m - 1;
        else
        {
            neg = pos = m;
            break;
        }
    }

    std::cout << neg + (pos - neg) / 2 << "\n";
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int t = 1;
    while (t--)
        solve();

    return 0;
}

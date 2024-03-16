#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void handle(ll len, int i, vector<ll> &vec)
{
    if (len == 1)
    {

    }
}

void solve() {
    ll n;
    std::cin >> n;
    std::vector<ll> vec(n);

    for (ll i = 0; i < n; i++)
        std::cin >> vec[i];

    ll len = 0;
    if (vec[0] < 0)
    {
        if (vec[1] < 0)
            len++;
        else
        {

        }
    }

    for (int i = 1; i < n - 1; i++)
    {
        if (vec[i] < 0)
            len++;
        if (vec[i+1] >= 0)
        {
            handle(len, i, vec);
            len = 0;
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

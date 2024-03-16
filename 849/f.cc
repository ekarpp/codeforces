#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

constexpr ll LEN = 1e5;

ll sumv[LEN+1];

void solve() {
    ll n, q;
    std::cin >> n >> q;
    std::vector<ll> vec(n);

    for (ll i = 0; i < n; i++)
        std::cin >> vec[i];

    for (ll i = 0; i < q; i++)
    {
        int type;
        cin >> type;
        if (type == 2)
        {
            int idx;
            cin >> idx;
            cout << vec[idx-1] << endl;
        }
        else
        {
            int l,r;
            cin >> l >> r;
            l--;
            r--;
            while (l <= r)
            {
                vec[l] = sumv[vec[l] % LEN] + sumv[vec[l] / LEN];
                l++;
            }
        }
    }
}


int main(int argc, char **argv) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    ll sum = 0;
    ll cnt = 0;
    for (ll i = 0; i < 10; i++)
        sumv[i] = i;
    ll diff = 10;
    ll add = 0;
    for (ll i = 10; i <= LEN; i++)
    {
        if (i % diff == 0)
            add++;
        if (i == diff*10)
        {
            diff *= 10;
            add = 1;
        }
        sumv[i] = sumv[i - add*diff] + add;
    }

    ll t;
    std::cin >> t;
    while (t--)
        solve();

    return 0;
}

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    ll n,c;
    std::cin >> n >> c;
    std::vector<ll> vec(n);

    for (ll i = 0; i < n; i++)
        std::cin >> vec[i];

    set<ll> cost;
    for (ll i = 0; i < n; i++)
        cost.insert(i + 1 + vec[i]);


    ll mm = 0;
    ll num = -1;
    do {
        num++;
        c -= mm;
        if (cost.empty())
            break;
        auto ptr = cost.begin();
        mm = *ptr;
        cost.erase(ptr);
    }
    while (mm <= c);

    cout << num << endl;
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

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
//using namespace std;
typedef long long ll;

void solve() {
    ll n;
    std::cin >> n;
    std::vector<ll> vec(n);

    for (ll i = 0; i < n; i++)
        std::cin >> vec[i];
    ll count = 0;
    ll i = 0;


    while (i < n)
    {
        std::map<ll, ll> mp;
        ll j = i;
        while (j < n && !mp[vec[j]])
        {mp[vec[j]] = j + 1; j++;}
        ll idx = (j < n) ? mp[vec[j]]: j;
        ll diff = j - i;
        ll d = j - idx;

        count += (diff*(diff+1)) / 2 - (d * (d + 1)) / 2;

        i = idx;

    }
    std::cout << count << "\n";
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    ll t = 1;
    while (t--)
        solve();

    return 0;
}

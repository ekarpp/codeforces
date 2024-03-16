#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    ll n;
    std::cin >> n;

    string timur;
    cin >> timur;

    int l = 0;
    int r = n-1;
    while (((timur[l] == '0' && timur[r] == '1') || (timur[l] == '1' && timur[r] == '0')) && l < r)
    {
        l++;
        r--;
    }

    cout << n - 2*l << endl;
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

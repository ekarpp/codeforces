#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void yes() { cout << "YES" << endl; }
void no() { cout << "NO" << endl; }

void solve()
{
    ll n;
    cin >> n;
    vector<ll> vec(n);

    for (ll i = 0; i < n; i++)
        cin >> vec[i];

    for (ll i = 0; i < n; i++)
        cout << vec[i];
}


int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}

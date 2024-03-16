#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    ll n;
    std::cin >> n;
    string route;
    cin >> route;

    int x = 0;
    int y = 0;

    for (int i = 0; i < n; i++)
    {
        switch (route[i])
        {
        case 'L':
            x--;
            break;
        case 'R':
            x++;
            break;
        case 'U':
            y++;
            break;
        case 'D':
            y--;
            break;
        }
        if (x == 1 && y == 1)
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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

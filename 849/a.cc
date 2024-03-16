#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    char c;
    std::cin >> c;
    const string codef = "codeforces";
    if (codef.find(c) != string::npos)
        cout << "YES";
    else
        cout << "NO";
    cout << endl;
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

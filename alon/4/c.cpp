#include <iostream>
#include <vector>
#include <algorithm>

//using namespace std;
typedef long long ll;


const int mask = 0xFFFFF;

void solve() {
    int n;
    std::cin >> n;

    ll l = 1;
    ll r = n*n;

    while (l < r)
    {
        ll mid = (l + r) / 2;
        ll lt = mid / n;
    }
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int t = 1;
    while (t--)
        solve();

    return 0;
}

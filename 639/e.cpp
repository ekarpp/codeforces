#include <iostream>
#include <vector>
#include <algorithm>

//using namespace std;
typedef long long ll;

void solve() {
    int n, m;
    std::cin >> n;
    std::cin >> m;
    std::vector<ll> vec(n);

    for (int i = 0; i < n; i++)
        std::cin >> vec[i];

    for (int i = 0; i < n; i++)
        std::cout << vec[i];
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int t = 1;
    //std::cin >> t;
    while (t--)
        solve();

    return 0;
}

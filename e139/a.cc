#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
//
//using namespace std;
typedef long long ll;

void solve() {
    ll n;
    std::cin >> n;
    ll logg10 = log10(n);
    ll first = n / pow(10, logg10);
    std::cout << logg10*9 + first << std::endl;
}


int main(int argc, char **argv) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    while (t--)
        solve();

    return 0;
}

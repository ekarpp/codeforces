#include <iostream>
#include <vector>
#include <algorithm>

//using namespace std;
typedef int ll;

void solve() {
    int n = 5;
    std::vector<ll> vec(n);

    for (int i = 0; i < n; i++)
        std::cin >> vec[i];

    int mmin = vec[0] * (vec[1] - vec[2]);
    int mmax = vec[0] * (vec[1] + vec[2]);

    int tmin = vec[3] - vec[4];
    int tmax = vec[3] + vec[4];

    if (mmin <= tmax && tmin <= mmax)
        std::cout << "Yes" << '\n';
    else
        std::cout << "No" << '\n';

}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    while (t--)
        solve();

    return 0;
}

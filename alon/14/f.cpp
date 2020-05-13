#include <iostream>
#include <vector>
#include <algorithm>

//using namespace std;
typedef long long ll;

ll ans[2*2*100000];

void solve() {
    int n;
    std::cin >> n;
    std::vector<ll> vec(n);

    for (int i = 0; i < n; i++)
        std::cin >> vec[i];

    int swps = 0;

    for (int i = 0; i < n; i++)
    {
        while (vec[i] != i + 1)
        {

            int num = vec[i];
            vec[i] = vec[num - 1];
            vec[num - 1] = num;

            ans[2*swps] = i + 1;
            ans[2*swps + 1] = num;
            swps++;
        }
    }

    std::cout << swps << "\n";

    for (int i = 0; i < swps; i++)
        std::cout << ans[2*i] << " " << ans[2*i + 1] << "\n";

}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int t = 1;

    while (t--)
        solve();

    return 0;
}

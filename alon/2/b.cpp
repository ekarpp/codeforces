#include <iostream>
#include <vector>
#include <algorithm>

//using namespace std;
typedef long long ll;

void solve() {
    int n;
    std::cin >> n;
    std::vector<ll> vec(n + 1, 0);

    int num;
    for (int i = 0; i < n; i++)
    {
        std::cin >> num;
        num = std::min(n, num);
        vec[num]++;
    }

    if (n == 1 && vec[0] == 0)
    {
        std::cout << 0 << "\n";
        return;
    }

    std::vector<int> ans(n,0);
    ans[n] = vec[n];
    int i = n;
    if (vec[i] < i)
    {
    for (i = n - 1; i >= 0; i--)
    {
        ans[i] = vec[i] + ans[i + 1];
        if (ans[i] >= i)
            break;
    }
    }
    std::cout << i << "\n";

}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int t = 1;
    while (t--)
        solve();

    return 0;
}

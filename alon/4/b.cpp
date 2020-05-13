#include <iostream>
#include <vector>
#include <algorithm>

//using namespace std;
typedef long long ll;

void solve() {
    int n;
    std::cin >> n;
    std::vector<ll> pos(n);
    std::vector<ll> neg(n);

    //std::sort(vec.begin(), vec.end());
    int pp = 0;
    int nn = 0;
    ll num;
    ll tot = 0;
    for (int i = 0; i < n; i++)
    {
        std::cin >> num;
        tot += num;
        if (num == 0)
            n--;
        else if (num > 0)
            pos[pp++] = num;
        else
            neg[nn++] = num;
    }

    if (tot < 0)
    {
        std::cout << "-1\n";
        return;
    }

    std::sort(pos.begin(), pos.end());
    std::sort(neg.begin(), neg.end(), std::greater<int>());

}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int t = 1;
    while (t--)
        solve();

    return 0;
}

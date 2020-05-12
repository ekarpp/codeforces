#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
//using namespace std;
typedef long long ll;

void solve() {
    int n;
    std::cin >> n;
    std::priority_queue<ll, std::vector<ll>, std::greater<ll>> pq;

    for (int i = 0; i < n; i++)
    {
        ll k;
        std::cin >> k;
        pq.push(k);
    }

    for (int i = 0; i < n - 1; i++)
    {
        ll a = pq.top();
        pq.pop();
        ll b = pq.top();
        pq.pop();
        std::cout << a + b << " ";
        pq.push(a+b);
    }
    std::cout << "\n";
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int t = 1;
    while (t--)
        solve();

    return 0;
}

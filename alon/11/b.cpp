#include <iostream>
#include <vector>
#include <algorithm>

//using namespace std;
typedef long long ll;

int G[1 << 20];


void solve() {
    int n;
    std::cin >> n;

    int x;
    for (int i = 0; i < n; i++)
    {
        std::cin >> x;
        G[i] = x - 1;
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

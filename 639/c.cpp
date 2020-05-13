#include <iostream>
#include <vector>
#include <algorithm>

//using namespace std;
typedef long long ll;

int mod(int k, int n)
{
    if (k < 0)
        k += n * ((-k / n) + 1);

    return k % n;
}

void solve() {
    int n;
    std::cin >> n;



    std::vector<ll> vec(n);
    std::vector<bool> b(3*n);
    for (int i = 0; i < n; i++)
        std::cin >> vec[i];

    for (int i = 0; i < 3*n; i++)
        b[i] = false;

    if (n == 1)
    {
        std::cout << "YES" << "\n";
        return;
    }


    for (int i = -n; i < 2*n; i++)
    {
        int room = i + vec[mod(i, n)];
        if (b[mod(room, 3*n)])
        {
            std::cout << "NO" << "\n";
            return;
        }
        b[mod(room, 3*n)] = true;
    }
    std::cout << "YES" << "\n";
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

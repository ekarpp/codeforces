#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
/*

  get prime factorization, we are done

 */

#define DO(p) if (n % p == 0) { if (found.count(p) != 0) {return true;} else {found[p] = true;} while (n % p == 0) {n /= p;} }

//using namespace std;
typedef long long ll;

bool factor(ll n, std::unordered_map<ll,bool> &found)
{
    DO(2);
    DO(3);
    DO(5);
    DO(7);
    DO(11);
    DO(13);
    DO(17);
    DO(19);
    DO(23);

    ll lim = ceill(sqrtl(n));

    for (ll i = 30; i <= lim + 24; i+=6)
    {
        DO(i-1);
        DO(i+1);
    }

    if (n > 2)
    {
        if (found.count(n) != 0)
            return true;
        else
            found[n] = true;
    }
    return false;
}

void solve() {
    int n;
    std::cin >> n;
    bool match = false;
    std::unordered_map<ll,bool> found;

    for (int i = 0; i < n; i++)
    {

        ll x;
        std::cin >> x;
        if (!match)
            match = factor(x, found);
    }


    if (match)
        std::cout << "YES" << std::endl;
    else
        std::cout << "NO" << std::endl;
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

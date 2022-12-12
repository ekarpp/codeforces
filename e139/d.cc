#include <iostream>
#include <vector>
#include <algorithm>

//using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)
{
   if (b == 0)
       return a;
   a %= b;
   return gcd(b, a);
}

void chain(ll x, ll y)
{
    ll len = 0;
    ll xx = x;
    ll yy = y;
    ll lim = abs(x - y);
    while (gcd(x, y) == 1)
    {
        if (len > lim)
        {
            std::cout << -1 << std::endl;
            return;
        }
        len++; x++; y++;
    }

    if (len > 10000)
        std::cout << xx << " " << yy << " " << len << std::endl;
}

void solve() {
    ll n;
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        ll x,y;
        std::cin >> x >> y;
        chain(x, y);
    }
}


int main(int argc, char **argv) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}

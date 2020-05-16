#include <iostream>
#include <vector>
#include <algorithm>

//using namespace std;
typedef long long ll;

const int p = 47;

void solve() {
    std::string s;
    std::cin >> s;

    std::string ptrn;
    std::cin >> ptrn;

    ll hsh_s = 0;
    ll hsh_pt = 0;
    int c = 0;

    ll strt = p;
    ll end = p;

    for (int i = 0; i < ptrn.size(); i++)
    {
        hsh_s += end * ( (s[i] % 26) + 1);
        hsh_pt += end * ( (ptrn[i] % 26) + 1);
        end *= p;

    }

    if (hsh_s == hsh_pt)
        c++;

    for (int i = ptrn.size(); i < s.size(); i++)
    {
        hsh_s += end * ( (s[i] % 26) + 1);
        hsh_s -= strt * ( (s[i - ptrn.size()] % 26) + 1);
        hsh_pt *= p;
        if (hsh_s == hsh_pt)
            c++;
        strt *= p;
        end *= p;
    }

    std::cout << c << "\n";
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int t = 1;

    while (t--)
        solve();

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

//using namespace std;
typedef long long ll;

bool check(std::string &s, char c1, char c2, ll idx)
{
    while (idx < s.length() - 1)
    {
        if (s.at(idx) == c1 && s.at(idx+1) == c2)
            return true;
        idx++;
    }
    return false;
}

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;

    for (ll i = 0; i < n - 1; i++)
    {
        if (check(s, s.at(i), s.at(i+1), i+2))
        {
            std::cout << "YES" << std::endl;
            return;
        }
    }
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

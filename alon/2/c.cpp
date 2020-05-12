#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
//using namespace std;
typedef long long ll;

const int p[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};

void solve() {
    int n;
    std::cin >> n;

    std::set<ll> sett;

    std::string s;
    for (int i = 0; i < n; i++)
    {
        std::cin >> s;
        //std::sort(s.begin(), s.end());
        ll sum = 1;
        for (int j = 0; j < s.size(); j++)
            sum *= p[s[j] % 'A'];
        sett.insert(sum);
    }

    std::cout << sett.size() << "\n";
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int t = 1;
    while (t--)
        solve();

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

//using namespace std;
typedef long long ll;

bool cmp1(std::pair<std::string, int> p1, std::pair<std::string, int> p2)
{
    if (p1.second == p2.second)
        return p1.first < p2.first;
    else
        return p1.second > p2.second;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::pair<std::string, int>> vec(n);

    std::string s;
    int p;
    for (int i = 0; i < n; i++)
    {
        std::cin >> s;
        std::cin >> p;
        vec[i] = std::make_pair(s, p);
    }

    std::sort(vec.begin(), vec.end(), cmp1);
    //std::sort(vec.begin(), vec.end(), cmp2);

    for (int i = 0; i < n; i++)
    {
        std::pair<std::string, int> pair;
        pair = vec[i];
        std::cout << pair.first << " " << pair.second << "\n";
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

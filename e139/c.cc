#include <iostream>
#include <vector>
#include <algorithm>

//using namespace std;
typedef long long ll;

char getcharc(std::string &r1, std::string &r2, ll idx, bool up)
{
    return (up) ? r1.at(idx) : r2.at(idx);
}

char getcharo(std::string &r1, std::string &r2, ll idx, bool up)
{
    return (!up) ? r1.at(idx) : r2.at(idx);
}


bool solve2(std::string &r1, std::string &r2, ll idx, bool up)
{
    while (idx < r1.length())
    {
        if (getcharc(r1, r2, idx, up) == 'W')
            return false;

        if (getcharo(r1, r2, idx, up) == 'B')
            up = !up;
        idx++;
    }
    std::cout << "YES" << std::endl;
    return true;
}

void solve() {
    ll m;
    std::string r1, r2;
    std::cin >> m >> r1 >> r2;

    ll idx = 0;
    while (r1.at(idx) == 'W' && r2.at(idx) == 'W')
        idx++;

    if (r1.at(idx) == 'B' && solve2(r1, r2, idx, true))
        return;

    if (r2.at(idx) == 'B' && solve2(r1, r2, idx, false))
        return;


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

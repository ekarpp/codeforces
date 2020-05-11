#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

//using namespace std;
typedef long long ll;

void solve() {
    int n;
    std::vector<ll> vec(26, 0);


    std::string str;
    std::cin >> str;

    for (int i = 0; i < str.size(); i++)
        vec[str[i] % 'A'] += 1;

    std::vector<char> out(str.size());
    int len = str.size() - 1;
    int idx = 0;
    bool found = (len % 2) == 1;
    for (int i = 0; i < 26; i++)
    {
        if (vec[i] % 2)
        {
            if (found)
            {
                std::cout << "NO SOLUTION" << "\n";
                return;
            }
            else
            {
                out[len / 2] = 'A' + i;
                found = true;
                vec[i]--;
            }
        }
        while (vec[i])
        {
            out[idx] = 'A' + i;
            out[len - idx] = 'A' + i;
            idx++;
            vec[i] -= 2;
        }
    }

    for (int i = 0; i <= len;i++)
        std::cout << out[i];
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

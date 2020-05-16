#include <iostream>
#include <vector>
#include <algorithm>

//using namespace std;
typedef long long ll;

const int p = 49;

#define N 100002

#define M 9223372036854775807LL

ll pp[N];
ll hsh[N];
ll roll[N];
int occ[26];

void solve() {
    std::string s;
    std::cin >> s;
    int k;
    std::cin >> k;

    std::vector<std::string> ptrns(k);

    int len = 0;

    int i;

    for (i = 0; i < k; i++)
    {
        std::cin >> ptrns[i];
        len = std::max(len, (int) ptrns[i].size());
    }

    for (i = 0; i < 26; i++)
        occ[i] = -1;

    pp[0] = p;
    hsh[0] = pp[0] * s[0];
    roll[0] = hsh[0];
    occ[s[0] % 'a'] = 0;

    for (i = 1; i < len; i++)
    {
        pp[i] = p * pp[i - 1];
        hsh[i] = pp[i] * s[i];
        roll[i] = roll[i - 1] + hsh[i];
        if (occ[s[i] % 'a'] == -1)
            occ[s[i] % 'a'] = i;
    }


    for ( ; i < s.size(); i++)
    {
        pp[i] = p * pp[i - 1];
        hsh[i] = pp[i] * s[i];
        roll[i] = roll[i - 1] + hsh[i];
        if (occ[s[i] % 'a'] == -1)
            occ[s[i] % 'a'] = i;
    }

    for (i = 0; i < k; i++)
    {

        std::string ptrn = ptrns[i];


        ll hsh_pt = 0;
        int idx = occ[ptrn[0] % 'a'];
        int j = idx;

        if (j == -1)
        {
            std::cout << -1 << "\n";
            continue;
        }
        for ( ; j < ptrn.size() + idx; j++)
            hsh_pt += pp[j] * ptrn[j - idx];

        ll hsh_s;
        if (idx)
            hsh_s = roll[ptrn.size() + idx - 1] - roll[idx - 1];
        else
            hsh_s = roll[ptrn.size() - 1];

        if (hsh_pt == hsh_s)
        {
            std::cout << 1 + idx << "\n";
            continue;
        }

        for (; j < s.size(); j++)
        {
            hsh_pt *= p;
            hsh_s += hsh[j];
            hsh_s -= hsh[j - ptrn.size()];

            if (hsh_s == hsh_pt)
            {
                std::cout << j - ptrn.size() + 2 << "\n";
                break;
            }
        }

        if (j == s.size())
            std::cout << -1 << "\n";
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

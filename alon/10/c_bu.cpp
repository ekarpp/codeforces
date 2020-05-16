#include <iostream>
#include <vector>
#include <algorithm>

//using namespace std;
typedef long long ll;

const int p = 49;

#define N 100002

ll pp[N];
ll hsh[N];
ll roll[N];

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

    pp[0] = p;
    hsh[0] = pp[0] * s[0];//((s[0]%26) + 1);
    roll[0] = hsh[0];
    for (i = 1; i < len; i++)
    {
        pp[i] = p * pp[i - 1];
        hsh[i] = pp[i] * s[i];//((s[i]%26) + 1);
        roll[i] = roll[i - 1] + hsh[i];
    }


    for ( ; i < s.size(); i++)
    {
        pp[i] = p * pp[i - 1];
        hsh[i] = pp[i] * s[i];//((s[i]%26) + 1);
    }

    for (i = 0; i < k; i++)
    {

        std::string ptrn = ptrns[i];
        int c = 0;
        ll hsh_s = roll[ptrn.size() - 1];
        ll hsh_pt = 0;
        int j;
        for (j = 0; j < ptrn.size(); j++)
            hsh_pt += pp[j] * ptrn[j];//((ptrn[j]%26) + 1);


        if (hsh_pt == hsh_s)
            c++;

        for (; j < s.size(); j++)
        {
            hsh_pt *= p;
            hsh_s += hsh[j];
            hsh_s -= hsh[j - ptrn.size()];

            if (hsh_s == hsh_pt)
                c++;
        }

        std::cout << c << "\n";
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

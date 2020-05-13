#include <iostream>
#include <vector>
#include <algorithm>

//using namespace std;
typedef long long ll;

#define MX (1L << 60)

ll dp[2500*2500];

void solve() {
    int n;
    std::cin >> n;
    std::vector<bool> vec(n*n);

    char c;
    for (int i = 0; i < n*n; i++)
    {
        std::cin >> c;
        vec[i] = c == '*';
        if (vec[i])
            dp[i] = MX;
        else
            dp[i] = 0;
    }

    if (dp[n*n - 1] == MX)
    {
        std::cout << "-1" << "\n";
        return;
    }

    for (int nn = 2; nn <= n; nn++)
    {
        ll mm = MX;

        int x = n - nn;
        int y = n - nn;
        // go x
        x++;
        while (x < n && !vec[x + y*n])
        {
            mm = std::min(mm, dp[x + (y + 1)*n]);
            x++;
        }

        x = n - nn;
        // go y
        y++;
        while (y < n && !vec[x + y*n])
        {
            mm = std::min(mm, dp[x + 1 + y*n]);
            y++;
        }

        x = n - nn;
        y = n - nn;
        mm++;
        while (x < n && !vec[x + y*n])
        {dp[x + y*n] = mm; x++;}

        x = n - nn;

        while (y < n && !vec[x + y*n])
        {dp[x + y*n] = mm; y++;}

        // after blocks
        x = n - nn;
        y = n - nn;
        // first x
        while (x < n && !vec[x + y*n])
            x++;
        while (x < n)
        {
            x++;
            mm = MX;
            while (x < n && !vec[x + y*n])
            {mm = std::min(mm, dp[x + (y + 1) * n]); x++;}
            int end = x;
            x--;
            while (!vec[x + y*n])
            {
                dp[x + y*n] = mm;
                x--;
            }
            x = end;
        }


        // now y
        x = n - nn;
        y = n - nn;

        while (y < n && !vec[x + y*n])
            y++;
        while (y < n)
        {
            y++;
            mm = MX;
            while (y < n && !vec[x + y*n])
            {mm = std::min(mm, dp[x + 1 + y * n]); y++;}
            int end = y;
            y--;
            while (!vec[x + y*n])
            {
                dp[x + y*n] = mm;
                y--;
            }
            y = end;
        }
    }

    if (dp[0] >= MX)
        dp[0] = -1;

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
            std::cout << ((dp[x + y*n] == MX) ? -1 : dp[x + y*n]) << " ";
        std::cout << "\n";
    }


    std::cout << dp[0] << "\n";
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int t = 1;
    while (t--)
        solve();

    return 0;
}

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    ll n;
    std::cin >> n;
    string let;
    cin >> let;

    unordered_map<char,ll> cnta;
    unordered_map<char,ll> cntb;
    int mx = 0;
    int spl = 1;
    string ascii = "abcdefghijklmnopqrstuvwxyz";
    for (char &ch : ascii)
    {
        cnta[ch] = 0;
        cntb[ch] = 0;
    }
    cnta[let[0]]++;
    for (int i = 1; i < let.length(); i++)
        cntb[let[i]]++;
}


int main(int argc, char **argv) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    ll t;
    std::cin >> t;
    while (t--)
        solve();

    return 0;
}

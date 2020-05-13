#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int deg(vector<pair<int, int>> a, vector<pair<int, int>> b)
{
    int m = -1;
    for (int i = 0; i < a.size(); i++)
        m = max(a[i].second, m);
    int mm = -1;
    for (int i = 0; i < b.size(); i++)
        m = max(b[i].second, m);
    return 2 * max(m, mm);
}

vector<pair<int, int>> poly_mult(vector<pair<int, int>> a, pair<int, int> b)
{
    vector<pair<int, int>> out(a.size());
    for (int i = 0; i < a.size(); i++)
    {
        out[i].first *= b.first;
        a[i].second += b.second;
    }
    return out;
}



void prnt(vector<pair<int, int>> s)
{
    for (int i = 0; i < s.size(); i++)
        cout << s[i].first << "x^" << s[i].second << "+";
    cout << "\n";
}

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> vec(n);

    for (int i = 0; i < n; i++)
        cin >> vec[i];
    sort(vec.begin(), vec.end());


}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int t = 1;
    while (t--)
        solve();

    return 0;
}

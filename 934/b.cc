#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// take duplicates equal to the side that has least num of them. then pick ones that are in both.
void solve() {
    ll n, k;
    std::cin >> n >> k;
    std::vector<ll> vec1(n);
    std::vector<ll> vec2(n);

    for (ll i = 0; i < n; i++)
        std::cin >> vec1[i];

         for (ll i = 0; i < n; i++)
             std::cin >> vec2[i];

         std::vector<ll> both;
         std::vector<ll> dupes_in_v1;

         for (int i = 0; i < n; i++)
         {
             ll val = vec1[i];
             bool vec2_has = std::find(vec2.begin(), vec2.end(), val) != vec2.end();
             if (vec2_has)
                 both.push_back(val);
             else
                 dupes_in_v1.push_back(val);
         }

             ll v1_num_dupes = dupes_in_v1.size() / 2;
         ll v2_num_dupes = n - both.size() - v1_num_dupes;

         ll take_dupes = std::min(v1_num_dupes, v2_num_dupes);
         sort(dupes_in_v1.begin(), dupes_in_v1.end());
         std::vector<ll> dupes_in_v2;
         std::set_difference(
             vec2.begin(), vec2.end(),
             both.begin(), both.end(),
             std::back_inserter(dupes_in_v2)
             );

         for (int i = 0; i < take_dupes; i++)
         {
             std::cout << dupes_in_v1[2*i + 0] << " ";
             std::cout << dupes_in_v1[2*i + 1] << " ";
         }

             for (int i = 0; i < k - take_dupes; i++)
             {
                 std::cout << both[2*i + 0] << " ";
                 std::cout << both[2*i + 1] << " ";
             }

             std::cout << std::endl;

         for (int i = 0; i < take_dupes; i++)

         {
             std::cout << dupes_in_v2[i] << " ";
             std::cout << dupes_in_v2[i] << " ";
         }

             for (int i = 0; i < k - take_dupes; i++)
             {
                 std::cout << both[2*i + 0] << " ";
                 std::cout << both[2*i + 1] << " ";
             }

             std::cout << std::endl;
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

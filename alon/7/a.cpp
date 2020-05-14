#include <iostream>
#include <vector>
#include <algorithm>

//using namespace std;
typedef long long ll;

void solve() {
    int n, q;
    std::cin >> n >> q;;

    int lg_2 = 0;
    int nn = n;
    while (nn)
    {lg_2++; nn >>= 1;}

    int size = 1L << lg_2;

    std::vector<int> vec(2*size + 1);
    std::vector<int> queries(q*2);

    vec[0] = 0;

    int i;
    for (i = size; i < size + n; i++)
        std::cin >> vec[i];

    for (i = size + n; i <= 2*size; i++)
        vec[i] = 0;

    for (i = size - 1; i > 0; i--)
        vec[i] = std::max(vec[2*i + 1], vec[2*i]);


    for (i = 0; i < 2*q; i++)
        std::cin >> queries[i];

    int val;
    for (i = 0; i < q; i++)
    {
        int a = queries[2*i] + size - 1;
        int b = queries[2*i + 1] + size - 1;

        val = vec[a];
        while (a <= b)
        {
            if (a%2 == 1)
                val = std::max(val, vec[a++]);

            if (b%2 == 0)
                val = std::max(val, vec[b--]);

            a /= 2;
            b /= 2;
        }

        std::cout << val << "\n";
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

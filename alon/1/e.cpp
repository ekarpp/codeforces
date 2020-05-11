#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
//using namespace std;
typedef long long ll;

bool is_prime(int n)
{
    if (n == 2)
        return true;

    if (n % 2 == 0)
        return false;

    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return false;

    return true;
}

std::list<int> ans;

void solve(int n) {
    if (n == 0)
        return;
    int k = 1;

    while (!is_prime(n + k))
        k++;

    ans.push_back(n);
    ans.push_back(k);
    solve(k - 1);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int t = 1;

    //while (t--)
    int num;
    std::cin >> num;
    solve(num);

    std::vector<int> l1(num);
    std::vector<int> l2(num);
    int idx = 0;
    int len = ans.size();
    for (int i = 0; i < len / 2; i++)
    {
        int n = ans.front();
        ans.pop_front();
        int k = ans.front();
        ans.pop_front();

        int nn = n;
        int kk = k;
        for (int i = k; i <= nn; i++)
        {
            l1[idx] = k;
            l2[idx] = n;
            k++;
            n--;
            idx++;
        }

    }

    for (int i = 0; i < num; i++)
        std::cout << l1[i] << " ";
    std::cout << "\n";

    for (int i = 0; i < num; i++)
        std::cout << l2[i] << " ";
    std::cout << "\n";

    return 0;
}

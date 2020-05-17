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
int occ[26];

void solve() {
    std::string s;
    std::cin >> s;
    int k;
    std::cin >> k;

    std::vector<std::string> ptrns(k);

    for (int i = 0; i < k; i++)
        std::cin >> ptrns[i];



    int len = s.size();

    std::vector<std::pair<int,int>> pairs(len);
    std::vector<int> rank(len);
    std::vector<int> unrank(len);

    for (int i = 0; i < len; i++)
    {
        pairs[i].first = s[i];
        pairs[i].second = s[i];
        rank[i] = i;
    }



    for (int i = 0; len >> i; i++)
    {
        sort(rank.begin(), rank.end(),
             [&](const int& a, const int & b)
             {
                 if (pairs[a].first == pairs[b].first)
                     return pairs[a].second < pairs[b].second;
                 else
                     return pairs[a].first < pairs[b].first;
             }
            );


        int ii = -1;
        int min = -1;
        for (int j = 0; j < len; j++)
        {
            int k = rank[j];
            if (j == 0 || pairs[ii] < pairs[k])
                min = j;
            unrank[k] = min;
            ii = k;
        }

        int siz = 1 << i;
        for (int j = 0; j < len; j++)
        {
            pairs[j].first = unrank[j];
            if (j + siz < len)
                pairs[j].second = unrank[j + siz];
            else
                pairs[j].second = -1;
        }
    }

    sort(rank.begin(), rank.end(),
         [&](const int& a, const int & b)
         {
             if (pairs[a].first == pairs[b].first)
                 return pairs[a].second < pairs[b].second;
             else
                 return pairs[a].first < pairs[b].first;
         }
        );


    for (int i = 0; i < k; i++)
    {
        std::string ptrn = ptrns[i];
        int l = 0;
        int r = s.size() - 1;

        while (l <= r)
        {
            int mid = (l + r) / 2;
            int rnk = rank[mid];

            if (s.compare(rnk, ptrn.size(), ptrn) >= 0)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }

        }

        int start = r;//(l + r) / 2;


        l = start;
        r = s.size() - 1;

        while (l <= r)
        {
            int mid = (l + r) / 2;
            int rnk = rank[mid];
            int j = 0;
            while (j < ptrn.size() && s[mid + j] == ptrn[j])
                j++;
            if (s.compare(rnk, ptrn.size(), ptrn) <= 0)
                l = mid + 1;
            else
                r = mid - 1;
        }

        int end = l;//(l + r) / 2;

        int min;

        if (start != end && start < s.size() - 1)
            min = rank[start+1] + 1;
        else
            min = -1;

        std::cout << min << "\n";
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

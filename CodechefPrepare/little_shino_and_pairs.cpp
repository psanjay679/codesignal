#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;


int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    vector <int> ar(n);

    int d;

    for (int i = 0; i < n; i++)
    {
        cin >> d;
        ar.push_back(d);
    }

    unordered_set < pair<int, int> > mp;

    int f_max = max(ar[0], ar[1]), s_max = min(ar[0], ar[1]);
    int count = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // sub_arr = ar[i:j]

            if (ar[i] > f_max)
            {
                s_max = f_max;
                f_max = ar[i];
            }
            else if (ar[i] < f_max && ar[i] > s_max)
            {
                s_max = ar[i];
            }

            pair <int, int> p = make_pair(f_max, s_max);
            if (mp.find(p) == mp.end())
            {
                mp.insert(p);
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;


void find_largest(vector <long long int> v)
{
    stack <int> s;
    int i = 0, j = 0;
    long long int sum = 0;

    while (i < v.size())
    {
        if (s.empty() || v[i] > v[s.top()])
        {
            s.push(i);
            i++;
        }
        else
        {
            int t = s.top();
            s.pop();
            sum = max(sum, v[t] * (s.empty() ? i: (i - s.top() - 1 )));
        }
    }

    cout << sum << endl;
}


int main()
{
    while(true)
    {
        /* code */
        int n;
        cin >> n;
        if (n == 0)
        {
            break;
        }

        vector <long long int> v;
        long long int d;
        for (int i = 0; i < n; i++)
        {
            cin >> d;
            v.push_back(d);
        }

        v.push_back(0);

        find_largest(v);

    }

    return 0;
}
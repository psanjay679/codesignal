#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;


void print_secondary_max_xor_bruteforce(vector <long long int > v)
{
    int max_element = 0;
    for (int i = 0; i < v.size() - 1; i++)
    {
        int _max = max(v[i], v[i + 1]);
        int s_max = min(v[i], v[i + 1]);
        
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[j] > _max)
            {
                s_max = _max;
                _max = v[j];
            }
            else if (v[j] > s_max) 
            {
                s_max = v[j];
            }

            max_element = max(max_element, _max ^ s_max);
        }
    }

    cout << max_element << endl;
}

void print_secondary_max_xor_optimized(vector <long long int> v)
{
    long long int max_sum = 0;
    stack <long long int > s;
    for (int i = 0; i < v.size(); i++)
    {
        while (!s.empty())
        {
            if (s.top() < v[i])
            {
                max_sum = max(max_sum, s.top() ^ v[i]);
                s.pop();
            }
            else
            {
                max_sum = max(max_sum, s.top() ^ v[i]);
                break;
            }
        }
        s.push(v[i]);
    }
    
    cout << max_sum << endl;
}

    int
    main(int argc, char const *argv[])
{
    int n;
    vector <long long int> v;
    cin >> n;

    long long int d;
    for (int _ = 0; _ < n; _++)
    {
        cin >> d;
        v.push_back(d);
    }

    // print_secondary_max_xor_bruteforce(v);
    print_secondary_max_xor_optimized(v);
    return 0;
}

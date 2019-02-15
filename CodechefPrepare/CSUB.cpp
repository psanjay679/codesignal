#include <iostream>
#include <string>

using namespace std;


long long count_substrings(string s)
{
    int count_1s = 0;
    long long ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
        {
            count_1s += 1;
            ans += count_1s;
        }
    }
    
    return ans;
}


int main()
{
    int t;
    cin >> t;
    
    for (int _ = 0; _ < t; _++)
    {
        int n;
        cin >> n;
        
        string s;
        cin >> s;
        cout << count_substrings(s) << endl;
    }
    
    return 0;
}
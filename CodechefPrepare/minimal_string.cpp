#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string str;
    cin >> str;

    stack<char> stc;
    vector<char> ans;

    vector<char> v(str.length() + 1, 'z' + 1);

    for (int i = str.length() - 1; i >= 0; i--)
    {
        v[i] = min(v[i + 1], str[i]);
    }

    cout << endl << "V" << endl;

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    cout << endl;

    for (int i = 0; i < str.length(); i++)
    {

        while (!stc.empty() && stc.top() <= v[i])
        {

            cout << stc.top();
            stc.pop();
        }

        stc.push(str[i]);
    }

    while (!stc.empty())
    {
        cout << stc.top();
        stc.pop();
    }
    cout << endl;

    return 0;
}
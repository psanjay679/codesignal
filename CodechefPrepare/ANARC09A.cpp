#include <iostream>
#include <string>
#include <stack>


using namespace std;

void print_fixes(string str)
{
    stack <char> s;
    int count = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '}')
        {
            if (!s.empty())
            {
                s.pop();
            }
            else
            {
                count ++;
            }
        }
        else
        {
            s.push(str[i]);
        }
    }
    cout << s.size()<< endl;
}


int main(int argc, char const *argv[])
{
    while (true)
    {
        string s;
        cin >> s;

        if (s.find('-') != -1)
        {
            break;
        }
        else
        {
            print_fixes(s);
        }
        
    }    
    return 0;
}

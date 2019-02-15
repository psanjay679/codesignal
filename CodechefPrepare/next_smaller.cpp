#include <iostream>
#include <stack>

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    int n;
    cin >> n;

    long long ar[n];

    for (int i = 0; i < n; i++){
        cin >> ar[i];
    }

    int next_smaller[n];
    int next_greater[n];
    stack <int> s;
    s.push(0);
    for (int i = 1; i < n; i++)
    {
        while (!s.empty() && ar[s.top()] > ar[i]){
            next_smaller[s.top()] = i;
            s.pop();
        }

        s.push(i);
    }

    while (!s.empty()){
        next_smaller[s.top()] = -1;
        s.pop();
    }

    

    for (int i = 0; i < n; i++){
        cout << next_smaller[i] << " ";
    }

    cout << endl;

    return 0;
}

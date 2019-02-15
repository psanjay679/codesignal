#include <iostream>
#include <stack>

using namespace std;


int main(int argc, char const *argv[])
{
    /* code */

    int n, k;
    cin >> n >> k;

    long long ar[n];

    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }

    // for (int i = n - 1; i >= 0; i--)
    // {
    //     s.push(ar[i]);
    // }

    long long max_val = 1;
    for (int i = 0; i < n && i < k + 1; i++){
        if (ar[i] > max_val){
            max_val = ar[i];
        }
    }

    if (n == 1 && k == 1) max_val = -1;

    cout << max_val << endl;

    // long long max_num = s.top();

    return 0;
}
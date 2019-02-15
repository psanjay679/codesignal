#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

// int main(int argc, char const *argv[])
// {
//     int t;
//     cin >> t;

//     int ar[t + 1];
//     for (int i = 1; i <= t; i++){
//         cin >> ar[i];
//     }


//     ar[0] = INT_MIN;;

//     int x = -1;
//     int y = -1;
    
//     for(int i = 2; i <= t; i++){
//         if (ar[i] > ar[1]){
//             y = i;
//             break;
//         }
//     }

//     int max_left = ar[1];
//     int max_left_index = 1;
//     int max_right = ar[y];
//     int max_right_index = y;

//     cout << x + y << " ";

//     for(int i = 2; i < t; i++){
//         x = -1;
//         y = -1;

//         if (ar[i - 1] > max_left){
//             max_left = ar[i - 1];
//             max_left_index = i - 1;
//         }

//         if (ar[i + 1] > max_right){
//             max_right = ar[i + 1];
//             max_right_index = i + 1;
//         }

//         if (ar[i - 1] > ar[i]){
//             x = i - 1;
//         }
//         else if (max_left > ar[i]){
//             x = max_left_index;
//         }

//         if (ar[i + 1] > ar[i]){
//             y = i + 1;
//         }
//         else if (max_right > ar[i]){
//             y = max_right_index;
//         }

//         cout << endl << "*****" << endl;
//         cout << "Value of i: " << i << endl;
//         cout << "Value of x: " << x << endl;
//         cout << "Value of y: " << y << endl;
//         cout << x + y << " ";
//         cout << endl << "*****" << endl;
//     }

//     if (ar[t - 1] > ar[t]){
//         x = t - 1;
//     }
//     else if (max_left > ar[t]){
//         x = max_left_index;
//     }
//     else {
//         x = -1;
//     }

//     y = -1;

//     cout << x + y << endl;

//     return 0;
// }

#include <stack>

int main(int argc, char const *argv[])
{
    /* code */

    int n;
    cin >> n;
    long long ar[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> ar[i];
    }

    // finding next grater element...
    long long next_greatest[n + 1];
    long long prev_greatest[n + 1];
    stack <int> s;
    s.push(1);
    for(int i = 2; i <= n; i++)
    {
        while (!s.empty() && ar[s.top()] < ar[i]){
            next_greatest[s.top()] = i;
            s.pop();
        }

        s.push(i);
    }

    while (!s.empty()){
        next_greatest[s.top()] = -1;
        s.pop();
    }

    s.push(n);
    for (int i = n; i > 0; i--){
        while (!s.empty() && ar[s.top()] < ar[i]){
            prev_greatest[s.top()] = i;
            s.pop();
        }

        s.push(i);
    }

    while (!s.empty()){
        prev_greatest[s.top()] = -1;
        s.pop();
    }

    for (int i = 1; i <= n; i++){
        cout << next_greatest[i] + prev_greatest[i] << " ";
    }

    cout << endl;

    return 0;
}

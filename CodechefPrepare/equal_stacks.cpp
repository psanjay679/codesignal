#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;


int main(){
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    queue <int> q1, q2, q3;

    int num;
    int sum1 = 0, sum2 = 0, sum3 = 0;

    for (int i = 0; i < n1; i++){
        cin >> num;
        q1.push(num);
        sum1 += num;
    }

    for (int i = 0; i < n2; i++){
        cin >> num;
        q2.push(num);
        sum2 += num;
    }

    for (int i = 0; i < n3; i++){
        cin >> num;
        q3.push(num);
        sum3 += num;
    }

    int max_sum = 0;

    while (!(sum1 == sum2 && sum2 == sum3)){
        max_sum = max(sum1, max(sum2, sum3));
        if (max_sum == sum1){
            sum1 -= q1.front();
            q1.pop();
        }
        else if (max_sum == sum2){
            sum2 -= q2.front();
            q2.pop();
        }
        else {
            sum3 -= q3.front();
            q3.pop();
        }
    }

    // cout << "All sums are equal: "<< (sum1 == sum2 && sum2 == sum3) << endl;

    cout << sum1 << endl;
    return 0;
}
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;


int main(){
    int g;
    cin >> g;

    for (int _ = 0; _ < g; _++){
        int n1, n2, x;
        cin >> n1 >> n2 >> x;

        int num;
        int s1[n1];
        int s2[n2];
        for (int i = 0; i < n1; i++){
            cin >> s1[i];
        }

        for (int i = 0; i < n2; i++){
            cin >> s2[i];
        }

        int count = 0;
        int sum = 0;
        int i1 = 0, i2 = 0;

        while (i1 < n1 && sum + s1[i1]<= x){
            sum += s1[i1++];
        }

        count = i1;

        while(i2 < n2 && i1 >= 0){
            sum += s2[i2++];

            while(sum > x && i1 > 0){
                sum -= s1[--i1];
            }

            if (sum <= x){
                count = max(count, i1 + i2);
            }
        }

        // cout << "Sum: " << count << endl;
        cout << count << endl;
    }
    return 0;
}
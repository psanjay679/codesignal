#include <iostream>

using namespace std;

int main(){
    int T, N;
    long long int C, t_sum;
    int A[101];
    int ans;
    int i, j;

    cin >> T;

    for (i = 0; i < T; i++){
        cin >> N >> C;
        t_sum = 0;
        ans = 1;
        for (j = 0; j < N; j++){
            cin >> A[j];
            t_sum += A[j];
            if (t_sum > C) ans = 0;
        }

        if (ans == 0) cout << "No\n";
        else cout << "Yes\n";
    }
    return 0;
}

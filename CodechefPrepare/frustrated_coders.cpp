#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;


int main(){
    int N;
    cin >> N;

    int S[N];
    for (int i = 0; i < N; i++){
        cin >> S[i];
    }
    sort(S, S+N, greater<int>());
    
    int sum = S[0];

    int i = 0, j = 1;

    while ( j < N){
        if (S[j] < S[i]){
            i++;
            j++;
        }
        else{
            sum += S[j];
            j++;
        }
    }

    cout << sum << endl;
    return 0;
}
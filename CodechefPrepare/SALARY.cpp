#include <iostream>
#include <climits>

using namespace std;

// returns true if all elements of array are equal otherwise false
bool check_all_equal(int ar[], int size){

    for (int i = 1; i < size; i++){
        if (ar[i] != ar[0])
            return false;
    }

    return true;
}

// return index of max element
int find_max_index(int ar[], int size){

    int max_index = 0;
    int max_value = ar[0];

    for (int i = 1; i < size; i++){
        if (ar[i] > max_value){
            max_index = i;
            max_value = ar[i];
        }
    }

    return max_index;
}

//
// int main(){
//     int T, N;
//     int W[101];
//     int total_ops;
//     cin >> T;
//
//     while (T--){
//         cin >> N;
//         total_ops = 0;
//         for (int i = 0; i < N; i++){
//             cin >> W[i];
//         }
//
//         while (check_all_equal(W, N) == false){
//             int max_index = find_max_index(W, N);
//             W[max_index] -= 1;
//             total_ops++;
//         }
//
//         cout << total_ops << endl;
//     }
//
//     return 0;
// }

int find_min_value(int ar[], int size){

    int min_value = INT_MAX;

    for (int i = 0; i < size; i++){
        min_value = min_value < ar[i] ? min_value : ar[i];
    }

    return min_value;
}


int main(){

    int T, N;
    int W[101];

    cin >> T;

    int total_ops;

    for (int _ = 0; _ < T; _++){
        cin >> N;
        for (int i = 0; i < N; i++){
            cin >> W[i];
        }

        total_ops = 0;
        int min_value = find_min_value(W, N);

        for (int i = 0; i < N; i++){
            total_ops += W[i] - min_value;
        }

        cout << total_ops << endl;

    }

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;


void find_smallest_number(int N){
    
    vector<int> number;
    for (int i = 0; i < N; i++){
        number.push_back(0);
    }

    int number_of_nines = N / 9;
    int first_digit = N % 9;

    for (int i = 0; i < number_of_nines; i++){
        number.push_back(9);
    }

    if (first_digit != 0){
        number.push_back(first_digit);
    }

    reverse(number.begin(), number.end());

    for (vector<int>::iterator it = number.begin(); it != number.end(); it++){
        cout << *it;
    }

    cout << endl;
}


int main(){
    
    //Find the smallest number such that the sum of its digits is N and it is divisible by 10^N.
    
    int N;
    cin >> N;

    find_smallest_number(N);

    return 0;
}
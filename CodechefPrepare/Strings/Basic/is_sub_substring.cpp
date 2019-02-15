#include <iostream>
#include <string>

using namespace std;


int return_sum_str(string s1, string s2){
    int num1 = stoi(s1);
    int num2 = stoi(s2);
    return num1 + num2;
}


void is_sum_substr(string s){
    for (int i = 1; i < s.length() - 2; i++){
        for (int j = i + 1; j < s.length() - 1; j++){
            string num1 = s.substr(i, j - 1);
            string num2 = s.substr(j, )
        }
    }
}


int main(){
    int T;
    cin >> T;
    for (int _ = 0; _ < T; _++){
        string s;
        cin >> s;

        is_sum_substr(s);
    }
    return 0;
}
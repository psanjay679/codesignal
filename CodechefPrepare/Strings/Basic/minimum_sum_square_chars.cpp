#include <iostream>
#include <queue>
#include <string>

using namespace std;
int MAX_CHAR = 26;

int main(){
    string s;
    int k;
    cin >> s;
    cin >> k;

    int frequency[MAX_CHAR];

    for (int i = 0; i < MAX_CHAR; i++){
        frequency[i] = 0;
    }

    for (int i = 0; i < s.length(); i++){
        frequency[s[i] - 'a']++;
    }

    priority_queue<int> p_queue;

    for (int i = 0; i < MAX_CHAR; i++){
        p_queue.push(frequency[i]);
    }

    while(k--){
        int temp = p_queue.top();
        p_queue.pop();
        temp = temp - 1;
        p_queue.push(temp);
    }

    int result = 0;

    while (!p_queue.empty()){
        int temp = p_queue.top();
        result += temp * temp;
        p_queue.pop();
    }

    cout << "Minimum Sum: " << result << endl;

    return 0;
}
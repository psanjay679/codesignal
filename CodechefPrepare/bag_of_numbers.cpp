#include <iostream>
#include <string>

using namespace std;

int main(){

    string s;
    cout << "output: ";
    while (true){
        cin >> s;
        if (s.find("input:") == -1)
            cout << s << " ";
        if (s.find('.') != -1){
            break;
        }
    }
    return 0;
}
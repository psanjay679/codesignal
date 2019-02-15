#include <iostream>
#include <queue>

using namespace std;
const int MAX_CHAR = 26;

struct Key{
    int freq;
    char ch;

    bool operator<(const Key &key) const{
        return freq < key.freq;
    }
};

void rearrange_string(string str)
{
    int count[MAX_CHAR] = {0};

    for (int i = 0; i < str.length(); i++){
        count[str[i] - 'a']++;
    }

    priority_queue <Key> p_queue;
    for (char c = 'a'; c <= 'z'; c++){
        if (count[c - 'a']){
            p_queue.push( Key{count[c - 'a'], c} );
        }
    }

    string ans = "";
    Key prev = {-1, '#'};

    while (!p_queue.empty()){
        Key k = p_queue.top();
        p_queue.pop();
        ans = ans + k.ch;

        if (prev.freq > 0){
            p_queue.push(prev);
        }

        (k.freq)--;
        prev = k;
    }

    cout << "Rearranged Chars: " << ans << endl;
}


int main(){

    string s;
    cin >> s;
    rearrange_string(s);

    return 0;
}
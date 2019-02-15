#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <climits>

using namespace std;


// multimap<int, char> invert_map(map<char, int> const &map){
//     multimap <int, char> multimap;

//     for (auto const &pair: map){
//         multimap.insert(make_pair(pair.second, pair.first));
//     }

//     return multimap;
// }


void print_hashmap(map<char, int> hash_map){
    for (map<char, int>::iterator it = hash_map.begin(); it != hash_map.end(); it++){
        cout << "key: " << it->first << " value: " << it->second << endl; 
    }
}


vector <pair<char, int> > return_sorted(map<char, int> hash_map){
    
    vector <pair<char, int> > revsorted_vector;
    int max_value;
    char max_key;

    while (!hash_map.empty()){
        map<char, int>::iterator start = hash_map.begin();
        max_key  = start->first;
        max_value = start->second;

        for (map<char, int>::iterator it = hash_map.begin(); it != hash_map.end(); it++){
            if (it->second > max_value){
                max_value = it->second;
                max_key = it->first;
            }
        }

        revsorted_vector.push_back(make_pair(max_key, max_value));
        hash_map.erase(max_key);
    }

    return revsorted_vector;
}


char return_max_char(map <char, int> hash_map){
    char max_char;
    int max_int = 0;

    for (map<char, int>::iterator it = hash_map.begin(); it != hash_map.end(); it++){
        if (it->second > max_int) {
            max_char = it->first;
            max_int = it->second;
        }
    }

    return max_char;
}


char return_second_max_char(map<char, int> hash_map){
    char max_char;
    int max_int = 0;
    int second_max_int = 0;
    char second_max_char;

    for (map<char, int>::iterator it = hash_map.begin(); it != hash_map.end(); it++){
        if (it->second >= max_int){
            second_max_int = max_int;
            max_int = it->second;
            second_max_char = max_char;
            max_char = it->first;
        }
        else if (it->second > second_max_int && it->second != max_int) {
            second_max_int = it->second;
            second_max_char = it->first;
        }
    }

    return second_max_char;

}

string rearrange_chars(string s){

    map <char, int> hash_map;
    for (int i = 0; i < s.size(); i++){
        map<char, int>::iterator it = hash_map.find(s[i]);
        if (it != hash_map.end()){
            it->second ++;
        }
        else{
            hash_map.insert(pair<char, int>(s[i], 1));
        }
    }
    string ans;

    // cout << "Going to enter the while loop for rearranging..." << endl;

    while (hash_map.size() > 1){
        char max_char = return_max_char(hash_map);
        char s_max_char = return_second_max_char(hash_map);

        // cout << "max_char: " << max_char << " s_max_char: " << s_max_char << endl;

        char curr_char = max_char, prev_char = s_max_char, temp_char;

        // cout << "Curr_Char: " << curr_char << " Prev_Char: " << prev_char << endl;

        while (hash_map[s_max_char] > 0){
            ans += curr_char;
            hash_map[curr_char]--;
            temp_char = curr_char;
            curr_char = prev_char;
            prev_char = temp_char;
        }
        // hash_map.erase(s_max_char);
        // cout << "Answer String: " << ans << endl;
        // cout << "hash_map size: " << hash_map.size() << endl;
        // print_hashmap(hash_map);
        // char k;
        // cin >> k;
    }

    map <char, int>:: iterator it = hash_map.begin();
    while (it->second > 0){
        ans += it->first;
        it->second--;
    }

    return ans;

}


int main(){
    string s;

    cin >> s;

    cout << "Rearranged Characters: " << rearrange_chars(s) << endl;
    return 0;
}


// int main(){

//     map<char, int> hash_map;
//     vector<pair<char, int> > revsorted_vector;
//     vector<pair<char, int> >::iterator vector_it;
//     string s;
    
//     cin >> s;

//     for (int i = 0; i < s.size(); i++){
//         if (hash_map.find(s[i]) != hash_map.end()){
//             hash_map.find(s[i])->second += 1;
//         }
//         else{
//             hash_map.insert(pair<char, int>(s[i], 1));
//         }
//     }

//     revsorted_vector = return_sorted(hash_map);

//     for(vector<pair<char, int> >::iterator it = revsorted_vector.begin(); it != revsorted_vector.end(); it++){
//         cout << "key: " << it->first << " value: " << it->second << endl;
//     }

//     string ans;
//     vector_it = revsorted_vector.begin();
//     while (vector_it->second != 0){
//         for (vector<pair<char, int> >::iterator it = revsorted_vector.begin(); it != revsorted_vector.end(); it++){
//             if (it->second != 0){
//                 ans += it->first;
//                 it->second -= 1;
//             }
//             else{
//                 break;
//             }
//         }
//     }

//     cout << "Rearranged String is: " << ans << endl;

//     return 0;
// }
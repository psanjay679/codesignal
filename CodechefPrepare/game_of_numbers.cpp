#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void print_vector(vector <int> v)
{
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}


vector <int> F(vector <int> v)
{
    // this is function for next grater
    stack <int> s;
    s.push(0);
    vector <int> next_smaller(v.size());

    // cout << "In the functin F" << endl;

    for(int i = 1; i < v.size(); i++){
        // cout << "v[i]: " << v[i] << " ";
        while (!s.empty() && v[s.top()] < v[i]){
            next_smaller[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    while(!s.empty()){
        next_smaller[s.top()] = -1;
        s.pop();
    }

    // print_vector(next_smaller);
    return next_smaller;
}


vector <int> G(vector <int> v){
    // this is function for next smaller
    stack <int> s;
    vector <int> next_greater(v.size());
    s.push(0);

    for (int i = 1; i < v.size(); i++){
        while (!s.empty() && v[s.top()] > v[i]){
            next_greater[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    while (!s.empty()){
        next_greater[s.top()] = -1;
        s.pop();
    }

    // print_vector(next_greater);
    return next_greater;

}

int main(int argc, char const *argv[])
{
    /* code */

    int n;
    cin >> n;

    vector <int> v(n);
    for (int i = 0; i < n; i++){
        int num;
        cin >> num;
        v[i] = num;
    }

    vector <int> next_greater(n);
    next_greater = F(v);
    vector <int> next_smaller(n);
    next_smaller = G(v);

    // cout << "\n************" << endl;
    // cout << "Next Greater" << endl;
    // print_vector(next_greater);
    // cout << "Next Smaller" << endl;
    // print_vector(next_smaller);
    // cout << "************" << endl;

    for (int i = 0; i < n; i++){
        if (next_greater[i] == -1)
        {
            cout << -1 << " ";
        }
        else if (next_smaller[next_greater[i]] == -1)
        {
            cout << -1 << " ";
        }
        else
        {
            cout << v[next_smaller[next_greater[i]]] << " ";
        }
    }

    cout << endl;

    return 0;
}

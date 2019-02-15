#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;


void print_vector(vector <int> v)
{
    for (int i = 0 ; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}


int main()
{
    int t;
    cin >> t;
    for (int _ = 0; _ < t; _++)
    {
        int n;
        cin >> n;
        
        int ar[n];
        for (int i = 0; i < n; i++)
        {
            cin >> ar[i];
        }
        
        vector <int> v;
        v.push_back(ar[n - 1]);
        
        int k = n - 2;
        while (v[v.size() - 1] < ar[k] && k >= 0){
            v.push_back(ar[k]);
            k--;
        }
        
        // cout << "\nBefore checking -1\n";
        print_vector(v);
        
        if (k == -1)
        {
            cout << -1 << endl;
        }
        else
        {
            int value = v[v.size() - 1];
            v.pop_back();
            v.push_back(ar[k]);
            ar[k] = value;
            
            //cout << "\nAfter Checking -1\n";
            //print_vector(v);
            //cout << "\n value of k:" << k << endl;
            
            for (int i = 0; i < v.size(); i++)
            {
                ar[i + k + 1] = v[i];
            }
            
            for(int i = 0; i < n; i++)
            {
                cout << ar[i];
            }
            cout << endl;
        }
    }
    return 0;
}